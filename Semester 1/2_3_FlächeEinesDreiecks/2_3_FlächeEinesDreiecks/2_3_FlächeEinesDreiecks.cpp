/*=========================================================

Filename: 2_3_FlächeEinesDreiecks.cpp

Author: Thomas Hahn

Date: 14.10.2017

Description: "Aufgabe: Fläche eines Dreiecks berechnen"

==========================================================*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath> // cmath includieren um sqrt zu verwenden

// Hauptmethode des C++ Programms
int main()
{
	// Seitenlängen a,b,c von der Konsole einlesen
	double a = 0;
	double b = 0;
	double c = 0;

	std::cout << "Bitte Wert fuer a eingeben:" << std::endl;
	std::cin >> a;

	std::cout << "Bitte Wert fuer b eingeben:" << std::endl;
	std::cin >> b;

	std::cout << "Bitte Wert fuer c eingeben:" << std::endl;
	std::cin >> c;

	std::cout << "Vielen Dank. Sie haben die folgenden Werte eingegeben:" << std::endl;

	// Seitenlängen zur Kontrolle ausgeben
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;

	// Berechnung nach Formel 2.1
	// Vor Berechnung prüfen, ob Ausdruck unter der Wurzel 0 ist.
	const double s = 1.0 / 2.0 * (a + b + c);
	const double wert_unter_wurzel1 = s * (s - a)*(s - b)*(s - c);
	double ergebnis1 = 0;
	if (wert_unter_wurzel1 != 0)
	{
		ergebnis1 = sqrt(wert_unter_wurzel1);
	}

	// Berechnung nach Formel 2.2
	// Vor Berechnung prüfen, ob Ausdruck unter der Wurzel 0 ist.
	const double wert_unter_wurzel2 = (a + b + c)*(a + b - c)*(b + c - a)*(c + a - b);
	double ergebnis2 = 0;
	if (wert_unter_wurzel2 != 0)
	{
		ergebnis2 = 1.0 / 4.0 * sqrt(wert_unter_wurzel2);
	}

	// Ausgabe der beiden Ergebnisse
	std::cout << "Ergebnis mit Formel 2.1: " << ergebnis1 << std::endl;
	std::cout << "Ergebnis mit Formel 2.2: " << ergebnis2 << std::endl;
	// 
	return 0;
}
