#include "Kandydat.h"


Kandydat::Kandydat(std::string imie, std::string nazwisko, const okreg_wyborczy okreg_wyborczy)
	: imie_(std::move(imie)), nazwisko_(std::move(nazwisko)), glosy_(0), okreg_wyborczy_(okreg_wyborczy)
{
}

std::string Kandydat::get_imie() const
{
	return imie_;
}

void Kandydat::set_imie(const std::string& imie)
{
	imie_ = imie;
}

std::string Kandydat::get_nazwisko() const
{
	return nazwisko_;
}

void Kandydat::set_nazwisko(const std::string& nazwisko)
{
	nazwisko_ = nazwisko;
}

int Kandydat::get_glosy() const
{
	return glosy_;
}

void Kandydat::glosuj() { ++glosy_; };
void Kandydat::zeruj_glosy() { glosy_ = 0; };

okreg_wyborczy Kandydat::get_okreg_wyborczy() const
{
	return okreg_wyborczy_;
}

void Kandydat::set_okreg_wyborczy(const okreg_wyborczy okreg_wyborczy)
{
	okreg_wyborczy_ = okreg_wyborczy;
}

bool Kandydat::operator==(const Kandydat& k) const
{
	return this->imie_ == k.imie_ && this->nazwisko_ == k.nazwisko_ && this->okreg_wyborczy_ == k.okreg_wyborczy_;
}

bool Kandydat::operator!=(const Kandydat& k) const
{
	return !(*this == k);
}

std::ostream& operator<<(std::ostream& out, const Kandydat& k)
{
	return out
		<< k.imie_
		<< " " << k.nazwisko_;
}
