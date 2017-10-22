/*=========================================================

Filename: AsciiTabelle.cpp

Author: Thomas Hahn

Date: 14.10.2017

Description: "Aufgabe: Verwendung von Schleifen: ASCII-Tabelle"

==========================================================*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <locale>


/*
description:	Funktion, die die Grundstruktur der Tabelle erstellt, die im Lehrbrief erwartet wird.
parameters:     na
return value:   void
*/
void grundStruktur()
{
	// Header der Tabelle wird geschrieben
	std::cout << "*** Grundstruktur ***" << std::endl;
	std::cout << std::endl;

	for (int zeilenIndex = 0; zeilenIndex < 32; ++zeilenIndex)
	{
		std::cout << std::setfill('0') << std::setw(3) << zeilenIndex << "  ";
		std::cout << std::setfill('0') << std::setw(3) << zeilenIndex + 32 << "  ";
		std::cout << std::setfill('0') << std::setw(3) << zeilenIndex + 64 << "  ";
		std::cout << std::setfill('0') << std::setw(3) << zeilenIndex + 96 << "  ";
		std::cout << std::endl;
	}
}

/*  description:    Funktion, die die ASCII-Tabelle erstellt, die im Lehrbrief erwartet wird.
parameters:     na
return value:   void
*/
void asciiTabelle()
{
	// Header der Tabelle wird geschrieben
	std::cout << "*** ASCII-Tabelle ***" << std::endl;

	std::cout << std::endl;

	for (int zeilen_index = -2; zeilen_index < 32; zeilen_index++)

	{
		// Zeilen
		for (int spalten_index = 0; spalten_index < 4; spalten_index++)
		{
			// Spalten
			if (zeilen_index == -2)
			{
				// Header
				std::cout << "Okt Dez Hex Zch   ";
			}

			else if (zeilen_index == -1)
			{
				// Der Abschlussstrich unter dem Header
				if (spalten_index == 3)
				{
					// Fallunterscheidung, da der Abschlusstrich in der letzten Spalte kürzer sein soll
					std::cout << "---------------";
				}
				else
				{
					std::cout << "------------------";
				}
			}
			else
			{
				// Der Dezimalwert wird anhand des Zeilen- und Spaltenindexes berechnet.
				const int dez1 = zeilen_index + 32 * spalten_index;

				// Das Schriftzeichen (Char) wird aus der Dezimalzahl gecastet.
				char character1 = char(dez1);

				// Es wird überprüft, ob es sich bei dem Schriftzeichen mit der Dezimaldarstellung dez1 um einen unsichtbaren Kontrollcharakter handelt.
				if (iscntrl(dez1))
				{
					// Ist dies der Fall, wird anstelle eines sichtbaren Zeichens in der Ascii-Tabelle "..." dargestellt.
					character1 = ' ';
				}

				std::string character_string = "...";

				if (character1 != ' ')
				{
					character_string = ' ' + character1 + ' ';
				}

				// Die Ausgabe der Zeile erfolgt. Dabei werden die folgenden Methoden verwendet:
				// std::setfill('0') - sorgt dafür, dass der auszugebende String mit nullen aufgefüllt wird.
				// std::setw(3) - gibt an, wieviele Stellen der auszugebende String insgesamt haben soll, und beeinflusst damit die Methode std::setfill().
				// std::uppercase - sorgt dafür, dass der auszugebende String nur Grossbuchstaben enthaelt.
				// std::hex - wandelt die gegebene Dezimalzahl in eine Hexadezimalzahl um.
				std::cout << std::setfill('0') << std::setw(3) << std::oct << (dez1) << std::dec << " " << std::setfill('0') << std::setw(3)
					<< dez1 << " " << std::setfill('0') << std::setw(3) << std::uppercase << std::hex << dez1 << " " << character_string << "   ";
			}
		}

		// Schlussendlich wird die Methode std::endl verwendet, um einen Zeilenumbruch am Ende der Schleife zu realisieren, damit im nächsten Durchlauf in einer neuen Zeile begonnen wird.
		std::cout << std::endl;
	}
}


// Hauptmethode des C++ Programms
int main()
{
	grundStruktur();
	std::cout << std::endl;
	std::cout << std::endl;
	asciiTabelle();

	return 0;
}
