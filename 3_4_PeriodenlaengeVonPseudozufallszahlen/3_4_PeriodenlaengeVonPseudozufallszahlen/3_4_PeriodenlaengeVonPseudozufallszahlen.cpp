/*=========================================================

Filename: 3_4_PeriodenlaengeVonPseudozufallszahlen.cpp

Author: Thomas Hahn

Date: 24.10.2017

Description: "Aufgabe: Periodenlänge von Pseudozufallszahlen"

==========================================================*/


#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <iomanip>

/*  description:    Hauptmethode des C++ Programms.
parameters:			na
return value:		Gibt 0 zurück, wenn das Programm ohne Fehler gelaufen ist.
*/
int main()
{
	double a = 16333;
	double b = 25887;
	double m = pow(2, 15);

	double x = 0;

	std::cout << "10 Zufallszahlen:" << std::endl;

	double zufallswert = 0;
	int durchlaufe = 0;
	while (durchlaufe == 0 || durchlaufe > 0 && zufallswert != 0)
	{
		zufallswert = fmod((a * zufallswert + b), m);
		durchlaufe++;
		//std::cout << std::setw(6) << zufallswert << std::endl;
	}

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "m = " << m << std::endl << std::endl;
	std::cout << "Die Periodenlaenge betraegt: " << durchlaufe << std::endl;

	return 0;
}

