/*=========================================================

Filename: 3_3_ErzeugungVonPseudozufallszahlen.cpp

Author: Thomas Hahn

Date: 24.10.2017

Description: "Aufgabe: Erzeugung von Pseudozufallszahlen"

==========================================================*/


#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <iomanip>

/*  description:    Hauptmethode des C++ Programms.
parameters:			na
return value:		Gibt 0 zur�ck, wenn das Programm ohne Fehler gelaufen ist.
*/
int main()
{
	double a = 16333;
	double b = 25887;
	double m = pow(2, 15);

	double x = 0;

	std::cout << "10 Zufallszahlen:" << std::endl;

	double zufallswert = 0;
	for (int i = 0; i < 10;++i)
	{
		zufallswert = fmod((a * zufallswert + b) , m);

		std::cout << std::setw(6)<<zufallswert << std::endl;
	}

    return 0;
}
