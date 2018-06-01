#include "stdafx.h"
#include "Datum.h"
#include <iostream>
#include "FehlerTag.h"
#include "FehlerMonat.h"


Datum::Datum(uint tg, uint mnt, uint jhr) {
	
	tag = tg;
	monat = mnt;
	jahr = jhr;

	if (!tagOk())
	{
		throw FehlerTag();
		//std::cout << "Tag nicht OK!";
	}

	
	if (!monatOk())
	{
		throw FehlerMonat();
		//std::cout << "Monat nicht OK!";
	}
};

bool Datum::monatOk() {
	if (monat > 0 && monat < 13)
		return true;

	return false;
}

bool Datum::tagOk() {
	if (!monatOk()) {
		throw FehlerMonat();
	}

	if (monat == 2) // Februar
	{
		if (schaltjahr())
		{
			return tag < 30 && tag > 0;
		}
		else {
			return tag < 29 && tag > 0;
		}

	}
	else
	{
		if (monat % 2 == 1) {
			return monat > 0 && monat < 32;
		}
		else
		{
			return monat > 0 && monat < 31;
		}
	}
}

bool Datum::schaltjahr() {
	if (jahr % 4 == 0)
	{
		// Vielleicht Schaltjahr
		if (jahr % 100 == 0 && jahr % 400 != 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

