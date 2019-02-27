#pragma once

#include "Libs.h"
#include "OkregWyborczy.h"

class Kandydat
{
private:
	std::string imie_;
	std::string nazwisko_;
	int glosy_;
	okreg_wyborczy okreg_wyborczy_;
public:
	Kandydat() = default;

	Kandydat(std::string imie, std::string nazwisko, const okreg_wyborczy okreg_wyborczy);

	std::string get_imie() const;
	void set_imie(const std::string& imie);
	std::string get_nazwisko() const;
	void set_nazwisko(const std::string& nazwisko);
	int get_glosy() const;
	void glosuj();
	void zeruj_glosy();
	okreg_wyborczy get_okreg_wyborczy() const;
	void set_okreg_wyborczy(const okreg_wyborczy okreg_wyborczy);

	bool operator==(const Kandydat& k) const;
	bool operator!=(const Kandydat& k) const;
	friend std::ostream& operator<<(std::ostream& out, const Kandydat& k);

	~Kandydat() = default;
};

struct KandydatLess
{
	bool operator()(const std::shared_ptr<Kandydat>& k1, const std::shared_ptr<Kandydat>& k2) const
	{
		if (k1->get_imie() == k2->get_imie())
		{
			if (k1->get_nazwisko() == k2->get_nazwisko())
			{
				return k1->get_okreg_wyborczy() < k2->get_okreg_wyborczy();
			}
			return k1->get_nazwisko() < k2->get_nazwisko();
		}
		return k1->get_imie() < k2->get_imie();
	}
};

