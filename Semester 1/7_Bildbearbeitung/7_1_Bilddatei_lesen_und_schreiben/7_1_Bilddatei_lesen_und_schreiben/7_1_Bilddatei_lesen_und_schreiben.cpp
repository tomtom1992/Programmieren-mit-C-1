/*
* =====================================================================================
*
*      Dateiname:  7_1_Bilddatei_lesen_und_schreiben.cpp
*
*   Beschreibung:  Aufgabe 7.1
*   				Bilddatei lesen und schreiben
*
*   Erstelldatum:  12.01.2018
*        Version:  0.1
*       Compiler:  Visual C++
*
*          Autor:  Thomas Hahn
*
* =====================================================================================
*/

#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

const int N = 1000;             //max. Bildhoehe und Bildbreite

								// TYPE Definitions
//typedef unsigned char uchar;

int main()
{
	int zeile = 0;                     // Anzahl der Bildzeilen wird ausgelesen
	int spalte = 0;                     // Anzahl der Bildspalten wird ausgelesen
	int maxzeile = N;                     // Max Groesse Zeilen
	int maxspalte = N;                     // Max Groesse Spalten
	int maxgrey = 0;                     // Grauwerte wird ausgelesen
	string    c;                                // Variable fuer den ersten eingelesenen Wert aus pgm Datei
	int tempix;                                 // Hilfsvariable zum zwischenspeichern und berechnen

	string  ifs_filename = "dreifach.pgm";     //Einzulesende Datei
	string  ofs_filename = "dreifach.out.pgm"; //Ausgabe Datei

	ifstream ifs;                               // create ifstream
	ofstream ofs;                               // create ofstream

	ifs.open(ifs_filename.c_str());            // open ifstream
	if (!ifs)
	{
		cerr << "\nFEHLER: Die einzulesende Datei konnte nicht geoeffnet werden. Dateiname: " << ifs_filename << endl;
		exit(1);
	}
	ofs.open(ofs_filename.c_str());           // open ofstream
	if (!ofs)
	{
		cerr << "\nFEHLER: Die Ausgabe Datei konnte nicht geoeffnet werden. Dateiname: " << ofs_filename << endl;
		exit(1);
	}

	//Auslesen der ersten Zeile des Bildes und Format pruefen
	getline(ifs, c);
	if (c.compare("P2") != 0)
	{
		cerr << "Falsches Dateiformat" << endl;
		exit(1);
	}
	else
	{
		cout << "Codierung : " << c << endl;
		ofs << c << endl;
	}
	//Bildzeilen und -spalten auslesen und mit max Wert vergleichen
	ifs >> tempix;
	spalte = tempix;
	ifs >> tempix;
	zeile = tempix;

	if (zeile > maxzeile)
	{
		cerr << "Maximale Zeilengroesse ueberschritten. ";
		exit(1);
	}
	if (spalte > maxspalte)
	{
		cerr << "Maximale Spaltengroesse ueberschritten. ";
		exit(1);
	}
	cout << "Zeilen: " << zeile << " Spalten: " << spalte << endl;
	ofs << spalte << " " << zeile << endl;           //Zeilen und Spalten in die Ausgabedatei schreiben
													 // Zeile 3 max Grauwert auslesen
	ifs >> tempix;
	maxgrey = tempix;
	cout << "Grauwert: " << maxgrey << endl;
	ofs << maxgrey << endl;                         //Grauwert in die Ausgabedatei schreiben
	tempix = 0;
	//uchar bild[zeile][spalte];

	// Array allokieren
	int** bild = new int*[zeile];
	for (int i = 0; i < zeile; i++)
		bild[i] = new int[spalte];


	// Bild schreiben
	for (int i = 0; i < zeile; i += 1)
	{
		for (int j = 0; j < spalte; j += 1)
		{
			ifs >> tempix;
			bild[i][j] = tempix;
			ofs << setw(4) << int(bild[i][j]);
		}
		ofs << endl;
	}
	ifs.close();        // Close ifstream
	ofs.close();        // Close ofstream

	// Array deallokieren
	for (int i = 0; i < zeile; i++)
		delete[] bild[i];
	delete[] bild;

	return 0;
}