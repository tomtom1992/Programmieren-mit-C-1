/*=========================================================

Filename: SummationUnendlicherReihen_1_1.cpp

Author: Thomas Hahn

Date: 05.10.2017

Description: "Aufgabe: Summation unendlicher Reihen - Aufgabe 2"

==========================================================*/

#include "stdafx.h"
#include "iostream"
#include <iomanip>

/*  description:    Berechnet den Grenzwert der Harmonischen Reihe
parameters:     n/a
return value:   Das Ergebnis wird auf der Konsole ausgegeben. Der Rückgabewert der Funktion ist immer 0.
*/
int geometrischeReihe()
{
	double summand = 1.0;
	double alteSumme = -1;
	double result = 1.0;
	double anzahlSummanden = 0;
	int i = 0;
	while (summand != alteSumme)
	{
		alteSumme = summand;
		summand = 0.5*summand;
		result += summand;
		anzahlSummanden++;
	}

	std::cout << "Geometrische Reihe: Ergebnis: " << std::setprecision(16) << result <<" Anzahl Summanden:"  << anzahlSummanden << "\n";

	return 0;
}

/*  description: main method of the application
parameters: n/a
return value: 0, if the application ran without exceptions.
*/
int main()
{
	geometrischeReihe();
	return 0;
}