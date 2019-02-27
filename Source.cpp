#include "Wybory.h"

int main()
{

	std::set<std::shared_ptr<Kandydat>, KandydatLess> kandydaci = {
		std::make_shared<Kandydat>(Kandydat("Jan", "Nowak", okreg_wyborczy::WARSZAWA)),
		std::make_shared<Kandydat>(Kandydat("Iza", "Kowalski", okreg_wyborczy::WARSZAWA)),
		std::make_shared<Kandydat>(Kandydat("Ewa", "Guzik", okreg_wyborczy::KRAKOW)),
		std::make_shared<Kandydat>(Kandydat("Pawel", "Bocian", okreg_wyborczy::KRAKOW)),
		std::make_shared<Kandydat>(Kandydat("Karol", "Trawka", okreg_wyborczy::POZNAN)),
		std::make_shared<Kandydat>(Kandydat("Piotr", "Kowal", okreg_wyborczy::POZNAN)),
		std::make_shared<Kandydat>(Kandydat("Adam", "Nowakowski", okreg_wyborczy::GDANSK)),
		std::make_shared<Kandydat>(Kandydat("Ula", "Okno", okreg_wyborczy::GDANSK))
	};

	std::unordered_set<std::shared_ptr<Wyborca>, WyborcaHash, WyborcaCmp> wyborcy = {
		std::make_shared<Wyborca>(Wyborca(okreg_wyborczy::WARSZAWA)),
		std::make_shared<Wyborca>(Wyborca(okreg_wyborczy::WARSZAWA)),
		std::make_shared<Wyborca>(Wyborca(okreg_wyborczy::WARSZAWA)),
		std::make_shared<Wyborca>(Wyborca(okreg_wyborczy::WARSZAWA)),
		std::make_shared<Wyborca>(Wyborca(okreg_wyborczy::KRAKOW)),
		std::make_shared<Wyborca>(Wyborca(okreg_wyborczy::KRAKOW)),
		std::make_shared<Wyborca>(Wyborca(okreg_wyborczy::KRAKOW)),
		std::make_shared<Wyborca>(Wyborca(okreg_wyborczy::KRAKOW)),
		std::make_shared<Wyborca>(Wyborca(okreg_wyborczy::POZNAN)),
		std::make_shared<Wyborca>(Wyborca(okreg_wyborczy::POZNAN)),
		std::make_shared<Wyborca>(Wyborca(okreg_wyborczy::POZNAN)),
		std::make_shared<Wyborca>(Wyborca(okreg_wyborczy::POZNAN)),
		std::make_shared<Wyborca>(Wyborca(okreg_wyborczy::GDANSK)),
		std::make_shared<Wyborca>(Wyborca(okreg_wyborczy::GDANSK)),
		std::make_shared<Wyborca>(Wyborca(okreg_wyborczy::GDANSK)),
		std::make_shared<Wyborca>(Wyborca(okreg_wyborczy::GDANSK))
	};

	Wybory::glosowanie(kandydaci, wyborcy);

	/*for (auto w : wyborcy)
	{
		std::cout << *w << std::endl;
	}*/

	std::cin.get();
	return 0;
}