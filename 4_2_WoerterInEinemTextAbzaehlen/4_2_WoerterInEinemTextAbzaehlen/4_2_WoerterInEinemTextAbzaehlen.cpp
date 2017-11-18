/*=========================================================

Filename: 4_2_WoerterInEinemTextAbzaehlen.cpp

Author: Thomas Hahn

Date: 07.11.2017

Description: "Aufgabe: Wörter in einem Text abzählen"

==========================================================*/


#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*  description:    Hauptmethode des C++ Programms.
parameters:			na
return value:		Gibt 0 zurück, wenn das Programm ohne Fehler gelaufen ist.
*/
int main()
{
	int   maxstring = 256;                      // Puffergröße
	char  text[256];                      // Eingabepuffer
	char  c;                                    // Hilfsvariable
	int   i, summewoerter;                 // Schleifenzähler,Buchstabezähler
	int	  zustand;

	const int LEER = 0;
	const int WORT = 1;

	zustand = LEER;

	cout << "***** Klein- und Großbuchstaben abzählen *****\n";
	cout << "Geben Sie eine Textzeile ein: ";

	i = 0;
	while ((c = cin.get()) != '\n') {       // Einzelzeichen lesen
		text[i] = c;                              //  und im Feld ablegen
		i = i + 1;                            // Schleifenzähler erhöhen
	}
	text[i] = '\0';                             // Zeichenkette abschließen

	cout << "Der eingegebene Text lautet '" << text << "'\n";

	summewoerter = 0;
	for (i = 0; text[i] != '\0'; i += 1) {
		/*if (islower(text[i])) summekl = summekl + 1;
		if (isupper(text[i])) summegr = summegr + 1;*/
		/*if (isalpha(text[i])) summeal = summeal + 1;
		if (isdigit(text[i])) summezif = summezif + 1;*/
		if (isalpha(text[i]))
		{
			if (zustand == LEER)
			{
				zustand = WORT;
				summewoerter++;
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
	/*cout << setw(6) << summekl << " Kleinbuchstaben\n";
	cout << setw(6) << summegr << " Grossbuchstaben\n";*/
	cout << setw(6) << summewoerter << " Woerter\n";
	//cout << setw(6) << summezif << " Ziffern\n";

	return 0;
}

