/*=========================================================

Filename: 3_1_FeldMitZufallszahlenBelegen.cpp

Author: Thomas Hahn

Date: 22.10.2017

Description: "Aufgabe: Feld mit Zufallszahlen belegen - Kennwerte ermitteln"

==========================================================*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;


/*  description:    Gibt den größten Wert aus einem double Feld zurück.
	parameters:		Ein double Feld.
	return value:	Der größte Wert als double.
*/

double maximum(double a[100])
{
	double max = a[0];
	for (int i = 0; i < 100; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	return max;
}


/*  description:    Gibt den kleinsten Wert aus einem double Feld zurück.
parameters:		Ein double Feld.
return value:	Der kleinste Wert als double.
*/
double minimum(double a[100])
{
	double min = a[0];
	for (int i = 0; i < 100; ++i)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	return min;
}

/*  description:    Gibt den arithmetischen Mittelwert aus einem double Feld zurück.
parameters:		Ein double Feld.
return value:	Der arithemetische Mittelwert als double.
*/
double mean(double a[100])
{
	double am = 0;
	for (int i = 0; i < 100; ++i)
	{
		am += a[i];
	}

	am = am / 100.00;

	return am;
}

/*  description:    Hauptmethode des C++ Programms.
parameters:			na
return value:		Wenn das Programm ohne Fehler durchläuft, wird 0 zurückgegeben.
*/
int main()
{
	srand(time(NULL));

	double a[100];
	for (int i = 0; i < 100; ++i)
	{
		a[i] = rand() % 51;
	}

	for (int i = 0; i < 100; i++)
	{
		if (i % 10 == 0)
		{
			cout << endl;
		}

		cout << setfill('0') << setw(2) << a[i] << " ";
	}

	cout << endl << endl;

	// Arithmetisches Mittel
	const double am = mean(a);

	cout << "Arithmetisches Mittel:\t" << am << endl;

	// Minimum
	const double min = minimum(a);

	cout << "Minimum:\t\t" << min << endl;


	// Maxmimum
	const double max = maximum(a);

	cout << "Maximum:\t\t" << max << endl;

	return 0;
}
