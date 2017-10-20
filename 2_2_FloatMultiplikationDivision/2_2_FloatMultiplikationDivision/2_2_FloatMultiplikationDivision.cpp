/*=========================================================

Filename: 2_2_FloatMultiplikationDivision.cpp

Author: Thomas Hahn

Date: 14.10.2017

Description: "Aufgabe: Rundungsfehler durch fortegesetzte Multiplikation/Division"

==========================================================*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
//#include <iomanip>
//#include <locale>



/*  description:    Funktion, die 10^6 10 mal mit einem Faktor k multipliziert und wieder dividiert , die im Lehrbrief erwartet wird.
parameters:     na
return value:   void
*/
void grundStruktur()
{
	float x = 1E6;
	float k = 0.1693f;

	std::cout << std::fixed;

	//Anfangswert
	std::cout << "Anfangswert: " << std::setprecision(8) << x << std::endl;

	for (int i = 0; i < 10; i++)
	{
		x = x * k;
	}

	//Ergebnis nach Multiplikation
	std::cout << "Ergebnis nach 10 facher Multiplikation: " << std::setprecision(8) << x << std::endl;

	for (int i = 0; i < 10; i++)
	{
		x = x / k;
	}

	//Ergebnis nach Division
	std::cout << "Ergebnis nach 10 facher Division: " << std::setprecision(8) << x << std::endl;
	bool vorherNachherGleich = x == 1E6;

	if (vorherNachherGleich)
	{
		std::cout << "x vorher und nacher sind gleich!"<< std::endl;
	}
	else
	{
		std::cout << "x vorher und nacher sind NICHT gleich!" << std::endl;
	}
}


// Hauptmethode des C++ Programms
int main()
{
	grundStruktur();
	return 0;
}
