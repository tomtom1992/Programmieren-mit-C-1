/*=========================================================

Filename: 4_2_WoerterInEinemTextAbzaehlen.cpp

Author: Thomas Hahn

Date: 07.11.2017

Description: "Aufgabe: W�rter in einem Text abz�hlen"

==========================================================*/


#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

/*  description:    Hauptmethode des C++ Programms.
parameters:			na
return value:		Gibt 0 zur�ck, wenn das Programm ohne Fehler gelaufen ist.
*/
int main()
{
	int   summewoerter, summezahlen;                 // Schleifenz�hler,Buchstabez�hler
	int	  zustand;

	const int LEER = 0;
	const int WORT = 1;
	const int ZAHL = 2;

	zustand = LEER;


	const string ifs_file_name = "text.txt";
	ifstream ifs;
	ifs.open(ifs_file_name.c_str());

	if (!ifs)
	{
		cerr << "\nERROR: failed to open input file " << ifs_file_name << endl;
		exit(1);
	}

	summewoerter = summezahlen = 0;

	//Eingabedatei lesen

	char wert;
	//i = 0;
	while (ifs >> wert) {       // Einzelzeichen lesen

		if (isalpha(wert))
		{
			if (zustand == LEER)
			{
				zustand = WORT;
				summewoerter++;
			}
			if (zustand == ZAHL)
			{
				// In einer Zahl tritt ein Wort auf -> Fehler
				exit(1);
			}
		}
		else if (isdigit(wert))
		{
			if (zustand == LEER)
			{
				zustand = ZAHL;
				summezahlen++;
			}
			if (zustand == WORT)
			{
				// In einem Wort tritt eine Ziffer auf -> Fehler
				exit(1);
			}
		}
		else
		{
			if (zustand == WORT)
			{
				zustand = LEER;
			}
		}


	}
	// Zeichenkette abschlie�en

	ifs.close();

	cout << setw(6) << summewoerter << " Woerter\n";
	cout << setw(6) << summezahlen << " Zahlen\n";

	return 0;
}

