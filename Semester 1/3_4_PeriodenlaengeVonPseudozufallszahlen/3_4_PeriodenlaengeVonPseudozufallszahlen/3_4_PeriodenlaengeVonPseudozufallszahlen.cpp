/*=========================================================

Filename: 3_4_PeriodenlaengeVonPseudozufallszahlen.cpp

Author: Thomas Hahn

Date: 24.10.2017

Description: "Aufgabe: Periodenlänge von Pseudozufallszahlen"

==========================================================*/


#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

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
	double a = 16333;
	double b = 25887;
	double m = pow(2, 15);

	double x = 0;

	cout << "10 Zufallszahlen:" << endl;

	double zufallswert = 0;
	int durchlaufe = 0;
	while (durchlaufe == 0 || durchlaufe > 0 && zufallswert != 0)
	{
		zufallswert = fmod((a * zufallswert + b), m);
		durchlaufe++;
	}

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "m = " << m << endl << endl;
	cout << "Die Periodenlaenge betraegt: " << durchlaufe-1 << endl;

	return 0;
}

