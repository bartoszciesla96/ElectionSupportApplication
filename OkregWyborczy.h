#pragma once

#include <string>

enum class okreg_wyborczy
{
	WARSZAWA, KRAKOW, POZNAN, GDANSK
};

inline std::string okreg_wyborczy_str(const okreg_wyborczy o)
{
	switch (o)
	{
	case okreg_wyborczy::WARSZAWA:
		return "WARSZAWA";
	case okreg_wyborczy::KRAKOW:
		return "KRAKOW";
	case okreg_wyborczy::POZNAN:
		return "POZNAN";
	default:
		return "GDANSK";
	}
}
