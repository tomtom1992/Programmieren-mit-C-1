/*=========================================================

Filename: 4_3_WoerterInEinerDateiAbzaehlen.cpp

Author: Thomas Hahn

Date: 07.11.2017

Description: "Aufgabe: Wörter in einer Datei abzählen"

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
return value:		Gibt 0 zurück, wenn das Programm ohne Fehler gelaufen ist.
*/
int main()
{
	int   summewoerter, summezahlen;                 // Schleifenzähler,Buchstabezähler
	int	  zustand;

	const int LEER = 0;
	const int WORT = 1;
	const int ZAHL = 2;

	zustand = LEER;


	const string ifs_file_name = "C:\\Projects\\Programmieren-mit-C-1\\4_3_WoerterInEinerDateiAbzaehlen\\Debug\\text.txt";
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
				cout << "Fehler: in einer Zahl tritt ein Wort auf." << endl;
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
				cout << "Fehler: in einem Wort tritt eine Zahl auf." << endl;
				exit(1);
			}
		}
		else
		{
			zustand = LEER;
		}
	}

	ifs.close();

	cout << setw(6) << summewoerter << " Woerter" << endl;
	cout << setw(6) << summezahlen << " Zahlen" << endl;

	return 0;
}

