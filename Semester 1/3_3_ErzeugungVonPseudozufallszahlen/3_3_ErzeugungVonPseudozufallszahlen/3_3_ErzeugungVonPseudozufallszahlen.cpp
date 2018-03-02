/*=========================================================

Filename: 3_3_ErzeugungVonPseudozufallszahlen.cpp

Author: Thomas Hahn

Date: 24.10.2017

Description: "Aufgabe: Erzeugung von Pseudozufallszahlen"

==========================================================*/


#include "stdafx.h"
//#include <math.h>
#include <iostream>
#include <iomanip>

int pow(int x, int y)
{
	if (y == 0)
	{
		return 1;
	}
	if (y == 1)
	{
		return x;
	}
	return x * pow(x, y - 1);
}


/*  description:    Hauptmethode des C++ Programms.
parameters:			na
return value:		Gibt 0 zurück, wenn das Programm ohne Fehler gelaufen ist.
*/
int main()
{
	const double a = 16333;
	const double b = 25887;
	const double m = pow(2, 15);

	std::cout << "10 Zufallszahlen:" << std::endl;

	double zufallswert = 0;
	for (int i = 0; i < 10; ++i)
	{
		zufallswert = fmod(a * zufallswert + b, m);

		std::cout << std::setw(6) << zufallswert << std::endl;
	}

	return 0;
}

