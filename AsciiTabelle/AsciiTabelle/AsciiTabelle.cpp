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

/*  description:    Funktion, die einen Dezimalwert in einen Oktalwert konvertiert.
parameters:     n: Eine Dezimalzahl.
return value:   Das Ergebnis im Oktalsystem.
*/
long decimalToOctal(long n)
{
	long octal = 0, i = 1;

	// Solange wie n ungleich 0 ist...
	while (n != 0)
	{
		// der Rest von der Division von n durch 8 wird zwischengespeichert
		const int remainder = n % 8;

		// n wird auf das Ergebnis der ganzzahligen Division durch 8 gesetzt
		n = n / 8;

		// zur Ergebnisvariable octal wird der Rest, multipliziert mit i, addiert. 
		octal = octal + remainder * i;

		// i wird bei jedem Schleifendurchlauf mit 10 multipliziert und gibt somit die Stelle vor, an der die Ziffer stehen soll.
		i = i * 10;
	}
	return octal;
}


/*  description:    Funktion, die die Grundstruktur der Tabelle erstellt, die im Lehrbrief erwartet wird.
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

	for (int zeilenIndex = -2; zeilenIndex < 32; zeilenIndex++)

	{
		// Zeilen
		for (int spaltenIndex = 0; spaltenIndex < 4; spaltenIndex++)
		{
			// Spalten
			if (zeilenIndex == -2)
			{
				// Header
				std::cout << "Okt Dez Hex Zch   ";
			}

			else if (zeilenIndex == -1)
			{
				// Der Abschlussstrich unter dem Header
				if (spaltenIndex == 3)
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
				int dez1 = zeilenIndex + 32 * spaltenIndex;

				// Das Schriftzeichen (Char) wird aus der Dezimalzahl gecastet.
				char character1 = char(dez1);

				// Es wird überprüft, ob es sich bei dem Schriftzeichen mit der Dezimaldarstellung dez1 um einen unsichtbaren Kontrollcharakter handelt.
				if (iscntrl(dez1))
				{
					// Ist dies der Fall, wird anstelle eines sichtbaren Zeichens in der Ascii-Tabelle ein Leerzeichen dargestellt.
					character1 = ' ';
				}

				// Die Ausgabe der Zeile erfolgt. Dabei werden die folgenden Methoden verwendet:
				// std::setfill('0') - sorgt dafür, dass der auszugebende String mit nullen aufgefüllt wird.
				// std::setw(3) - gibt an, wieviele Stellen der auszugebende String insgesamt haben soll, und beeinflusst damit die Methode std::setfill().
				// std::uppercase - sorgt dafür, dass der auszugebende String nur Grossbuchstaben enthaelt.
				// std::hex - wandelt die gegebene Dezimalzahl in eine Hexadezimalzahl um.
				std::cout << std::setfill('0') << std::setw(3) << decimalToOctal(dez1) << " " << std::setfill('0') << std::setw(3)
					<< dez1 << " " << std::setfill('0') << std::setw(3) << std::uppercase << std::hex << dez1 << " " << " " <<
					character1 << "    ";
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
