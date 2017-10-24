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


string datei_einlesen(string datei_name)
{
	ifstream eingabe(datei_name);
	if (!eingabe)
	{
		std::cerr << "Fehler beim Oeffnen der Datei " << datei_name << "\n";
		return "";
	}

	std::string zeile;
	std::string inhalt;

	while (std::getline(eingabe, zeile))
	{
		inhalt += zeile + "\n";
	}
	return inhalt;
}

/*  description:    Hauptmethode des C++ Programms.
parameters:			na
return value:		Wenn das Programm ohne Fehler durchläuft, wird 0 zurückgegeben.
*/
int main()
{
	double a[100];
	for (int i = 0; i < 100; ++i)
	{
		a[i] = 0;
	}

	string inhalt = datei_einlesen("C:\\Projects\\Programmieren-mit-C-1\\3_2_KennwerteEinerZahlenreiheAusEinerDatei\\Debug\\daten-3-2.txt");

	int i = 0;
	while (inhalt != "" && i<100)
	{
		int index = inhalt.find('\n');

		string aktuelle_zeile = inhalt.substr(0, index);

		//aktuelle_zeile.erase(0, aktuelle_zeile.find_first_not_of(" ")); //führende Leerzeichen entfernen
		//aktuelle_zeile.erase(aktuelle_zeile.find_last_not_of(" ") + 1);  //Leerzeichen am Ende entfernen

		a[i++] = stod(aktuelle_zeile);

		inhalt = inhalt.substr(index+1);
	}

	int anzahl_double_werte_in_datei = i;

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
