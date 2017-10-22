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


/*  description:    Hauptmethode des C++ Programms.
	parameters:		na
	return value:	void
*/

int main()
{
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
	double am = 0;
	for (int i = 0; i < 100; ++i)
	{
		am += a[i];
	}

	am = am / 100.00;

	cout << "Arithmetisches Mittel:\t" << am << endl;

	// Minimum
	double min = a[0];
	for (int i = 0; i < 100; ++i)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	cout << "Minimum:\t\t" << min << endl;


	// Maxmimum
	double max = a[0];
	for (int i = 0; i < 100; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	cout << "Maximum:\t\t" << max << endl;

	return 0;
}
