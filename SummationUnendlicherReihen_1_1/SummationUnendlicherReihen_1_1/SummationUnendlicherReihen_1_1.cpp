/*=========================================================

Filename: SummationUnendlicherReihen_1_1.cpp

Author: Thomas Hahn

Date: 05.10.2017

Description: "Aufgabe: Summation unendlicher Reihen"

==========================================================*/

#include "stdafx.h"
#include "iostream"

/*  description:    Berechnet die ersten 1000 Summanden der Harmonischen Reihe
parameters:     n/a
return value:   Das Ergebnis wird auf der Konsole ausgegeben. Der Rückgabewert der Funktion ist immer 0.
*/
int harmonischeReihe()
{
	double summe = 0;
	for (int i = 1; i < 1001; i++)
	{
		summe += 1.0 / i;
	}

	std::cout << "Harmonische Reihe: " << summe << "\n";

	return 0;
}

/*  description:    Berechnet die ersten 1000 Summanden der ALternierenden harmonischen Reihe
parameters:     n/a
return value:   Das Ergebnis wird auf der Konsole ausgegeben. Der Rückgabewert der Funktion ist immer 0.
*/
int alternierendeHarmonischeReihe()
{
	double summe = 0;
	double v = 1.0;
	for (int i = 1; i < 1001; i++)
	{
		summe += (v) / static_cast<double>(i);
		v = -v;
	}

	std::cout << "Alternierende harmonische Reihe: " << summe << "\n";

	return 0;
}

/*  description:    Berechnet die ersten 1000 Summanden der Leibnizschen Reihe
parameters:     n/a
return value:   Das Ergebnis wird auf der Konsole ausgegeben. Der Rückgabewert der Funktion ist immer 0.
*/
int leibnizscheReihe()
{
	double summe = 0;
	double v = 1.0;
	for (int i = 1; i < 1001; i++)
	{
		summe += (v) / (2.0 * static_cast<double>(i) - 1.0);
		v = -v;
	}

	std::cout << "Leibnizsche Reihe: " << summe << "\n";

	return 0;
}

/*  description:    Berechnet die ersten 1000 Summanden der Geometrischen Reihe
parameters:     n/a
return value:   Das Ergebnis wird auf der Konsole ausgegeben. Der Rückgabewert der Funktion ist immer 0.
*/
int geometrischeReihe()
{
	double summand = 1.0;
	double result = 1.0;
	for (int i = 0; i < 1000; i++)
	{
		summand = 0.5*summand;
		result += summand;
	}

	std::cout << "Geometrische Reihe: " << result << "\n";

	return 0;
}

/*  description: main method of the application
parameters: n/a
return value: 0, if the application ran without exceptions.
*/
int main()
{
	harmonischeReihe();
	alternierendeHarmonischeReihe();
	leibnizscheReihe();
	geometrischeReihe();
	return 0;
}



