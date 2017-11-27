/*=========================================================

Filename: 5_2_Caesar_Verschluesselung.cpp

Author: Thomas Hahn

Date: 27.11.2017

Description: "Aufgabe: Caesar-Verschlüsselung"

==========================================================*/


#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;




// char a[] - Das Char Feld, welches gewendet werden soll
// unsigned int n - Die Länge des Feldes
void feld_wenden(char a[], unsigned int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		char help = a[n - i];
		a[n - i] = a[i];
		a[i] = help;
	}
}

// char a[] - Das Char Feld, welches links rotiert werden soll
// unsigned int n - Die Länge des Feldes
// unsigned int shift - Gibt an, um wieviele Plätze rotiert werden soll
void feld_links_rotieren(char a[], unsigned int n, unsigned int shift)
{
	// Verschiebung muss kleiner als die Feldlänge sein, um Zugriffe außerhalb des Feldes zu verhindern
	shift = shift % n;

	if (shift == 0)
	{
		// Verschiebung um 0 Plätze ist zulässig. Funktion wird sofort verlassen.
		return;
	}

	// Ersten Teil isolieren
	char first_half[shift];
	for (int i = 0; i < shift; i++)
	{
		first_half[i] = a[i];
	}

	// Ersten Teil wenden
	feld_wenden(first_half, shift);

	// Ersten Teil mit zweitem Teil vereinigen (mergen)
	char merged[n];
	for (int i = 0; i < shift; i++)
	{
		merged[i] = first_half[i];
	}
	for (int i = shift; i < n; i++)
	{
		merged[i] = a[i];
	}

	// Gesamtes Array wenden
	feld_wenden(merged, n);

	// Ersten Teil isolieren
	char second_first_half[shift + 1];
	for (int i = 0; i < shift + 1; i++)
	{
		second_first_half[i] = merged[i];
	}

	// Ersten Teil wenden
	feld_wenden(second_first_half, shift);
}

void feld_rechts_rotieren(char a[], unsigned int n, unsigned int shift)
{
	// Verschiebung muss kleiner als die Feldlänge sein, um Zugriffe außerhalb des Feldes zu verhindern
	shift = shift % n;

	if (shift == 0)
	{
		// Verschiebung um 0 Plätze ist zulässig. Funktion wird sofort verlassen.
		return;
	}

	// Ersten Teil isolieren
	char second_half[shift];
	for (int i = n - shift; i < n; i++)
	{
		second_half[i] = a[i];
	}

	// Zweiten Teil wenden
	feld_wenden(second_half, shift);

	// Zweiten Teil mit ersten Teil vereinigen (mergen)
	char merged[n];
	for (int i = 0; i < n-shift; i++)
	{
		merged[i] = a[i];
	}
	for (int i = n-shift; i < n; i++)
	{
		merged[i] = second_half[i];
	}

	// Gesamtes Array wenden
	feld_wenden(merged, n);

	// Zweiten Teil isolieren
	char second_second_half[shift -1];
	for (int i = n - shift; i < n; i++)
	{
		second_half[i] = a[i];
	}

	// Ersten Teil wenden
	feld_wenden(second_second_half, shift);
}


/*  description:    Hauptmethode des C++ Programms.
parameters:			na
return value:		Gibt 0 zurück, wenn das Programm ohne Fehler gelaufen ist.
*/
int main()
{
	char c;
	char alphabet[] = {
		'A','B','C','D','E','F','G','H','I','J','K','L','M',
		'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
	};

	feld_links_rotieren(alphabet, 26, 5);

	string input_file_name = "C:\\Projects\\Programmieren-mit-C-1\\5_Verschluesselung\\klartext.txt";
	string output_file_name = "C:\\Projects\\Programmieren-mit-C-1\\5_Verschluesselung\\geheim_caesar.txt";

	ifstream ifs;
	ifs.open(input_file_name);

	ofstream ofs;
	ofs.open(output_file_name);

	if (!ofs)
	{
		cout << "Error while writing the file.";
	}

	if (ifs)
	{
		while ((c = ifs.get()) != EOF)
		{
			if (c > 'Z' || c < 'A')
			{
				ofs.put(c);
			}
			else {
				int index_in_rot = (c - 'A');
				ofs.put(alphabet[index_in_rot]);
			}

		}
	}
	else
	{
		cout << "Error openening file.";
	}


	return 0;
}

