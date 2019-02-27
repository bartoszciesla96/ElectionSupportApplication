#pragma once

#include "Kandydat.h"
#include "Wyborca.h"

//ALIASY
using wyborcy_uset = std::unordered_set<std::shared_ptr<Wyborca>, WyborcaHash, WyborcaCmp>;
using kandydaci_set = std::set<std::shared_ptr<Kandydat>, KandydatLess>;
using mapa_zwyciezcy = std::map<okreg_wyborczy, std::shared_ptr<Kandydat>>;
using mapa_glosy = std::map<okreg_wyborczy, int>;

class Wybory
{
private:
	static kandydaci_set kandydaci_;
	static wyborcy_uset wyborcy_;
	static void wypelnij_listy_wyborcze(const kandydaci_set& kandydaci, const wyborcy_uset& wyborcy);
	static void podzial_kandydatow(const kandydaci_set& kandydaci, const wyborcy_uset& wyborcy);
	static mapa_zwyciezcy generowanie_mapy_zwyciezcow();
	static mapa_glosy generowanie_mapy_glosow();
	static bool czy_koniec_wyborow(const mapa_zwyciezcy& zwyciezcy);
public:
	static mapa_zwyciezcy glosowanie(const kandydaci_set& kandydaci, const wyborcy_uset& wyborcy);


};

