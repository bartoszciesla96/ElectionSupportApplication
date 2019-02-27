#include "Wybory.h"


void Wybory::wypelnij_listy_wyborcze(const kandydaci_set& kandydaci, const wyborcy_uset& wyborcy)
{
	{
		//kopiujemy kandydatow
		for (auto k : kandydaci)
		{
			kandydaci_.insert(k);
		}
		//kopiujemy wyborcow		
		for (auto w : wyborcy)
		{
			wyborcy_.insert(w);
		}
	}
}

void Wybory::podzial_kandydatow(const kandydaci_set& kandydaci, const wyborcy_uset& wyborcy)
{
	wypelnij_listy_wyborcze(kandydaci, wyborcy);

	//zrobimy mape, w ktorej kluczem bedzie okrag wyborczy, natomiast
	//wartoscia bedzie kolekcja posortowana kandydatow nalezacych
	//do tego okregu wyborczego
	std::map<okreg_wyborczy, std::set<std::shared_ptr<Kandydat>, KandydatLess>> m;

	//przegladam kolekcje kandydatow i ich porzadkuje w mapy
	for (const auto& k : kandydaci_)
	{
		m[k->get_okreg_wyborczy()].insert(k);
	}

	//teraz tak podzielone listy kandydatow przypiszemy do listy kandydatow kazdego
	//z wyborcow
	for (const auto& w : wyborcy_)
	{
		w->set_kandydaci(m[w->get_okreg_wyborczy()]);
	}

}

mapa_zwyciezcy Wybory::generowanie_mapy_zwyciezcow()
{
	std::map<okreg_wyborczy, std::shared_ptr<Kandydat>> zwyciezcy;
	for (auto o = 0; o < 4; ++o)
	{
		zwyciezcy[static_cast<okreg_wyborczy>(o)] = nullptr;
	}
	return zwyciezcy;
}

mapa_glosy Wybory::generowanie_mapy_glosow()
{
	std::map<okreg_wyborczy, int> glosy;
	for (auto o = 0; o < 4; ++o)
	{
		glosy[static_cast<okreg_wyborczy>(o)] = 0;
	}
	return glosy;
}

bool Wybory::czy_koniec_wyborow(const mapa_zwyciezcy& zwyciezcy)
{
	for (const auto& p : zwyciezcy)
	{
		if (p.second == nullptr)
		{
			return false; //nie wszedzie jeszcze wybrano zwyciezcow
		}
	}
	return true;
}

mapa_zwyciezcy Wybory::glosowanie(const kandydaci_set& kandydaci, const wyborcy_uset& wyborcy)
{
	podzial_kandydatow(kandydaci, wyborcy);
	auto zwyciezcy = generowanie_mapy_zwyciezcow();
	auto glosy = generowanie_mapy_glosow();

	auto numer_kandydata = 1, wybor = 1, numer_tury = 1;

	do
	{
		std::cout << "----------------------- TURA NR " << numer_tury << " -----------------" << std::endl;
		for (const auto& w : wyborcy_)
		{
			if (zwyciezcy[w->get_okreg_wyborczy()] == nullptr)
			{
				std::cout << "Glosuje wyborca o id = " << w->get_id() << ", okreg wyborczy: " << okreg_wyborczy_str(w->get_okreg_wyborczy()) << std::endl;

				// pokazujemy kolejnych kandydatow danego wyborcy
				numer_kandydata = 1;
				for (const auto& k : w->get_kandydaci())
				{
					std::cout << numer_kandydata << ". " << k->get_imie() << " " << k->get_nazwisko() << std::endl;
					++numer_kandydata;
				}

				// wybieramy kandydata
				do
				{
					std::cout << "Wybierz kandydata: ";
					std::cin >> wybor; std::cin.get();
				} while (wybor < 1 || wybor > w->get_kandydaci().size());

				// zwiekszamy ilosc glosow wybranemu kandydatowi
				numer_kandydata = 1;
				for (const auto& k : w->get_kandydaci())
				{
					if (numer_kandydata == wybor)
					{
						k->glosuj();
						glosy[k->get_okreg_wyborczy()]++;
						break;
					}
					++numer_kandydata;
				}
			}
		}

		//wyznaczamy zwyciezcow
		for (const auto& k : kandydaci_)
		{
			if (k->get_glosy() * 2 > glosy[k->get_okreg_wyborczy()])
			{
				zwyciezcy[k->get_okreg_wyborczy()] = k;
			}
		}

		++numer_tury;

		// zerujemy glosy kandydatow
		for (const auto& k : kandydaci_)
		{
			k->zeruj_glosy();
		}

		//zerujemy glosy w okregach wyborczych
		glosy = generowanie_mapy_glosow();

		//wypisywanie zwyciezcow
		std::cout << "ZWYCIEZCY PO TURZE NR " << numer_tury << std::endl;
		for (const auto& z : zwyciezcy)
		{
			if (z.second != nullptr)
			{
				std::cout << okreg_wyborczy_str(z.first) << " ::: " << *z.second << std::endl;
			}
		}

		if (czy_koniec_wyborow(zwyciezcy))
		{
			std::cout << "Nacisnij enter zeby zakonczyc program ....." << std::endl;
		}
		else
		{
			std::cout << "Nacisnij enter zeby rozpoczac kolejne ture wyborow ....." << std::endl;
		}

		std::cin.get();
		for (auto i = 0; i < 500; ++i) { std::cout << "\n"; }

	} while (!czy_koniec_wyborow(zwyciezcy));



	return zwyciezcy;
}

kandydaci_set Wybory::kandydaci_;
wyborcy_uset Wybory::wyborcy_;
