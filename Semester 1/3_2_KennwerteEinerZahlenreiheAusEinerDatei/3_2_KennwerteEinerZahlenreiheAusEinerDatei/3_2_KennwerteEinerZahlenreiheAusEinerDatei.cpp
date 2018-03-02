/*=========================================================

Filename: 3_2_KennwerteEinerZahlenreiheAusEinerDatei.cpp

Author: Thomas Hahn

Date: 22.10.2017

Description: "Aufgabe: Kennwerte einer Zahlenreihe aus einer Datei"

==========================================================*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;


/*  description:    Gibt den größten Wert aus einem double Feld zurück.
parameters:			Ein double Feld. Die Anzahl der Elemente im Feld.
return value:		Der größte Wert als double.
*/

double maximum(double a[100], int anzahl)
{
	double max = a[0];
	for (int i = 0; i < anzahl; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	return max;
}


/*  description:    Gibt den kleinsten Wert aus einem double Feld zurück.
parameters:			Ein double Feld. Die Anzahl der Elemente im Feld.
return value:		Der kleinste Wert als double.
*/
double minimum(double a[100], int anzahl)
{
	double min = a[0];
	for (int i = 0; i < anzahl; ++i)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	return min;
}

/*  description:    Gibt den arithmetischen Mittelwert aus einem double Feld zurück.
parameters:			Ein double Feld.
return value:		Der arithemetische Mittelwert als double.
*/
double mean(double a[100], int anzahl)
{
	double am = 0;
	for (int i = 0; i < anzahl; ++i)
	{
		am += a[i];
	}

	am = am / anzahl;

	return am;
}


string datei_einlesen(const string datei_name)
{
	ifstream eingabe;
	if (!eingabe)
	{
		cerr << "Fehler beim Oeffnen der Datei " << datei_name << "\n";
		return "";
	}

	eingabe.open(datei_name);

	string zeile;
	string inhalt;

	while (getline(eingabe, zeile))
	{
		inhalt += zeile + "\n";
	}

	eingabe.close();
	return inhalt;
}

/*  description:    Hauptmethode des C++ Programms.
parameters:			na
return value:		Wenn das Programm ohne Fehler durchläuft, wird 0 zurückgegeben.
*/
int main()
{
	int number_of_lines = 0;
	string line;
	ifstream myfile("C:\\Projects\\Programmieren-mit-C-1\\3_2_KennwerteEinerZahlenreiheAusEinerDatei\\Debug\\daten-3-2.txt");

	while (getline(myfile, line))
		++number_of_lines;

	// Array deklarieren und initialisieren
	//double a[number_of_lines];
	double* a = new double[number_of_lines];
	for (int i = 0; i < number_of_lines; ++i)
	{
		a[i] = 0;
	}

	string inhalt = datei_einlesen("C:\\Projects\\Programmieren-mit-C-1\\3_2_KennwerteEinerZahlenreiheAusEinerDatei\\Debug\\daten-3-2.txt");

	int i = 0;
	while (inhalt != "" && i<number_of_lines)
	{
		// vom Anfang den Index des nächsten Zeilenumbruchs finden
		const int index = inhalt.find('\n');

		// nur die aktuelle Zeile über substr erhalten
		const string aktuelle_zeile = inhalt.substr(0, index);

		// String zu double konvertieren
		a[i++] = stod(aktuelle_zeile);

		// den Inhalt String verkleinern
		inhalt = inhalt.substr(index+1);
	}

	const int anzahl_double_werte_in_datei = i;

	cout << "Anzahl Werte:\t" << anzahl_double_werte_in_datei;
	
	for (int i = 0; i < anzahl_double_werte_in_datei; i++)
	{
		if (i % 10 == 0)
		{
			cout << endl;
		}

		cout << setfill('0') << setw(2) << a[i] << " ";
	}

	cout << endl << endl;

	// Arithmetisches Mittel
	const double am = mean(a, anzahl_double_werte_in_datei);

	cout << "Arithmetisches Mittel:\t" << am << endl;

	// Minimum
	const double min = minimum(a, anzahl_double_werte_in_datei);

	cout << "Minimum:\t\t" << min << endl;


	// Maxmimum
	const double max = maximum(a, anzahl_double_werte_in_datei);

	cout << "Maximum:\t\t" << max << endl;

	return 0;
}
