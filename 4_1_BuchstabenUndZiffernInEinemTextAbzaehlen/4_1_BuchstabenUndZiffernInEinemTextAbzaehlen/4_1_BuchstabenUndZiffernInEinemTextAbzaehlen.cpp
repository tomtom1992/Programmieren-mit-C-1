/*=========================================================

Filename: 4_1_BuchstabenUndZiffernInEinemTextAbzaehlen.cpp

Author: Thomas Hahn

Date: 07.11.2017

Description: "Aufgabe: Buchstaben und Ziffern in einem Text abz�hlen"

==========================================================*/


#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*  description:    Hauptmethode des C++ Programms.
parameters:			na
return value:		Gibt 0 zur�ck, wenn das Programm ohne Fehler gelaufen ist.
*/
int main()
{
	int   maxstring = 256;                      // Puffergr��e
	char  text[256];                      // Eingabepuffer
	char  c;                                    // Hilfsvariable
	int   i, summekl, summegr, summezif, summeal;                  // Schleifenz�hler,Buchstabez�hler

	cout << "***** Klein- und Gro�buchstaben abz�hlen *****\n";
	cout << "Geben Sie eine Textzeile ein: ";

	i = 0;
	while ((c = cin.get()) != '\n') {       // Einzelzeichen lesen
		text[i] = c;                              //  und im Feld ablegen
		i = i + 1;                            // Schleifenz�hler erh�hen
	}
	text[i] = '\0';                             // Zeichenkette abschlie�en

	cout << "Der eingegebene Text lautet '" << text << "'\n";

	summekl = summegr = summezif = summeal = 0;
	for (i = 0; text[i] != '\0'; i += 1) {
		/*if (islower(text[i])) summekl = summekl + 1;
		if (isupper(text[i])) summegr = summegr + 1;*/
		if (isalpha(text[i])) summeal = summeal + 1;
		if (isdigit(text[i])) summezif = summezif + 1;
	}
	/*cout << setw(6) << summekl << " Kleinbuchstaben\n";
	cout << setw(6) << summegr << " Grossbuchstaben\n";*/
	cout << setw(6) << summeal << " Buchstaben\n";
	cout << setw(6) << summezif << " Ziffern\n";

	return 0;
}

