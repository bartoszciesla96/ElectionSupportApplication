#include "Wyborca.h"

Wyborca::Wyborca(const okreg_wyborczy okreg_wyborczy)
	: okreg_wyborczy_(okreg_wyborczy)
{
	id_ = sid_++;
}

int Wyborca::get_id() const
{
	return id_;
}

void Wyborca::set_id(const int id)
{
	id_ = id;
}

okreg_wyborczy Wyborca::get_okreg_wyborczy() const
{
	return okreg_wyborczy_;
}

void Wyborca::set_okreg_wyborczy(const okreg_wyborczy okreg_wyborczy)
{
	okreg_wyborczy_ = okreg_wyborczy;
}

std::set<std::shared_ptr<Kandydat>, KandydatLess> Wyborca::get_kandydaci() const
{
	return kandydaci;
}

void Wyborca::set_kandydaci(const std::set<std::shared_ptr<Kandydat>, KandydatLess>& shared_ptrs)
{
	kandydaci = shared_ptrs;
}

std::ostream& operator<<(std::ostream& out, const Wyborca& w)
{
	out << w.id_ << " " << okreg_wyborczy_str(w.okreg_wyborczy_) << std::endl;

	for (const auto& k : w.kandydaci)
	{
		out << *k << std::endl;
	}

	return out;
};

int Wyborca::sid_ = 1;

