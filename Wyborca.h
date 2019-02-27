#pragma once

#include"Libs.h"
#include "OkregWyborczy.h"
#include "Kandydat.h"

class Wyborca
{
private:
	int id_;
	okreg_wyborczy okreg_wyborczy_;
	std::set<std::shared_ptr<Kandydat>, KandydatLess> kandydaci;
	static int sid_; //zmienna statyczna - kolejne get_id dla kolejnego wyborcy
public:
	Wyborca() = default;


	explicit Wyborca(const okreg_wyborczy okreg_wyborczy);


	int get_id() const;
	void set_id(const int id);
	okreg_wyborczy get_okreg_wyborczy() const;
	void set_okreg_wyborczy(const okreg_wyborczy okreg_wyborczy);
	std::set<std::shared_ptr<Kandydat>, KandydatLess> get_kandydaci() const;
	void set_kandydaci(const std::set<std::shared_ptr<Kandydat>, KandydatLess>& shared_ptrs);

	friend std::ostream& operator<<(std::ostream& out, const Wyborca& w);

	~Wyborca() = default;
};

struct WyborcaCmp
{
	bool operator()(const std::shared_ptr<Wyborca>& w1, const std::shared_ptr<Wyborca>& w2) const
	{
		if (w1->get_kandydaci().size() != w2->get_kandydaci().size())
		{
			return false;
		}

		std::vector<std::shared_ptr<Kandydat>> v2;
		for (auto x : w2->get_kandydaci())
		{
			v2.push_back(x);
		}std::vector<std::shared_ptr<Kandydat>> v1;
		for (auto x : w1->get_kandydaci())
		{
			v1.push_back(x);
		}




		return std::equal(v1.begin(), v1.end(), v2.begin()) && w1->get_id() == w2->get_id() && w1->get_okreg_wyborczy() == w2->get_okreg_wyborczy();
	}
};

struct WyborcaHash
{
	size_t operator()(const std::shared_ptr<Wyborca>& w) const
	{
		return std::hash<int>()(w->get_id()) + 31 * std::hash<okreg_wyborczy>()(w->get_okreg_wyborczy());
	}
};

