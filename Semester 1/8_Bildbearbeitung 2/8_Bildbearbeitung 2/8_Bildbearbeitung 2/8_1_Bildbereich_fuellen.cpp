/*
* =====================================================================================
*
*      Dateiname:  8_1_Bildbereich_fuellen.cpp
*
*   Beschreibung:  Aufgabe 8.1
*   				Bildbereich fuellen
*
*   Erstelldatum:  25.01.2018
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



								// TYPE Definitions
typedef unsigned char Pixel;

// Prototypen
void glaetten(Pixel** bild1, Pixel** bild2, int zeile, int spalte);
void invertieren(Pixel** bild1, Pixel** bild2, int zeile, int spalte, int graumax);
void kantenbildung(Pixel** bild1, Pixel** bild2, int zeile, int spalte);
void schaerfen(Pixel** bild1, Pixel** bild2, int zeile, int spalte, int graumax);
void fill(Pixel** bild, int nz, int ns, int inz, int ins, Pixel oldval, Pixel newval);

int main()
{
	int zeile = 0;                     // Anzahl der Bildzeilen wird ausgelesen
	int spalte = 0;                     // Anzahl der Bildspalten wird ausgelesen
	int maxzeile = N;                     // Max Groesse Zeilen
	int maxspalte = N;                     // Max Groesse Spalten
	int maxgrey = 0;                     // Grauwerte wird ausgelesen
	string    c;                                // Variable fuer den ersten eingelesenen Wert aus pgm Datei
	int tempix;                                 // Hilfsvariable zum zwischenspeichern und berechnen

	string  ifs_filename = "kunst.pgm";     //Einzulesende Datei
	string  ofs_filename = "kunst.out.pgm"; //Ausgabe Datei

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

	// Array1 allokieren
	Pixel** bild1 = new Pixel*[N];
	for (int i = 0; i < N; i++)
		bild1[i] = new Pixel[N];

	// Array2 allokieren
	Pixel** bild2 = new Pixel*[N];
	for (int i = 0; i < N; i++)
		bild2[i] = new Pixel[N];

	//var bild1 und bild2 mit den eingelesen Bildwerten fuellen
	for (int i = 0; i < N; i += 1)
	{
		for (int j = 0; j < N; j += 1)
		{
			ifs >> tempix;
			bild1[i][j] = tempix;
			bild2[i][j] = tempix;
		}
	}
	ifs.close();        // Close ifstream


						// Bildbearbeitungsmenü

	cout << "Bitte wählen Sie eine Funktion:" << endl;
	cout << "g Glaettung" << endl;
	cout << "i Invertierung" << endl;
	cout << "k Kantenbildung" << endl;
	cout << "s Schaerfung" << endl;
	cout << "f Fuellen" << endl;
	cout << "e ENDE" << endl;

	char input;
	cin >> input;

	switch (input) {
	case 'e': break;
	case 'g': glaetten(bild1, bild2, N, N); break;
	case 'i': invertieren(bild1, bild2, N, N, maxgrey); break;
	case 'k': kantenbildung(bild1, bild2, N, N); break;
	case 's': schaerfen(bild1, bild2, N, N, maxgrey); break;
	case 'f': fill(bild2, N, N, 10, 10, Pixel(255), Pixel(127)); break;
	}


	// Bild schreiben
	for (int i = 0; i < N; i += 1)
	{
		for (int j = 0; j < N; j += 1)
		{
			ofs << setw(4) << int(bild2[i][j]);
		}
		ofs << endl;
	}
	ifs.close();        // Close ifstream
	ofs.close();        // Close ofstream

						// Arrays deallokieren
	for (int i = 0; i < zeile; i++)
		delete[] bild1[i];
	delete[] bild1;

	for (int i = 0; i < zeile; i++)
		delete[] bild2[i];
	delete[] bild2;

	return 0;
}

/*
#################################################################################################
# FUNKTION fill
#################################################################################################
#  Funktion fuer das Füllen eines eingelesenen Bildes kunst.pgm und der Ausgabe in die Datei kunst.out.pgm mit ifstream und ofstream an einem bestimmten Impfpixel.
#
# bild: Originalbild
# nz: Bildhöhe
# ns: Bildbreite
# inz: Zeilenindex Impfpixel
# ins: Spaltenindex Impfpixel
# oldval: alter Farbwert
# newval: neuer Farbwert
#  Es wird kein Wert zurückgegeben.
#################################################################################################
*/
void fill(Pixel** bild, int nz, int ns, int inz, int ins, Pixel oldval, Pixel newval)
{
	/*int zahl = 0;

	zahl = (int)bild[inz][ins];
	
	if (zahl == (int)oldval)
	{
		bild[inz][ins] = newval;
	}
	else {

		return;
	}

	if (inz - 1 >= 0)
		fill(bild, nz, ns, inz - 1, ins, oldval, newval);
	if (inz + 1 < nz)
		fill(bild, nz, ns, inz + 1, ins, oldval, newval);
	if (ins - 1 >= 0)
		fill(bild, nz, ns, inz, ins + 1, oldval, newval);
	if (ins + 1 < ns)
		fill(bild, nz, ns, inz, ins - 1, oldval, newval);*/

	// Impfpixel setzen
	if (bild[inz][ins] == (int)oldval)
	{
		bild[inz][ins] = newval;
	}
	else {

		return;
	}
	

	// Links prüfen
	if (ins > 0)
	{
			fill(bild, nz, ns, inz , ins-1, Pixel(255), Pixel(127));
	}

	// Rechts prüfen
	if (ins < ns-1)
	{
			fill(bild, nz, ns, inz, ins + 1, Pixel(255), Pixel(127));
	}

	// Oben prüfen
	if (inz > 0)
	{
			fill(bild, nz, ns, inz-1, ins , Pixel(255), Pixel(127));
	}

	// Unten prüfen
	if (inz < nz-1)
	{
			fill(bild, nz, ns, inz + 1, ins, Pixel(255), Pixel(127));
	}

}

/*
#################################################################################################
# FUNKTION invertieren
#################################################################################################
#  Funktion fuer das invertieren eines eingelesenen Bildes dreifach.pgm und der Ausgabe in die Datei dreifach.out.pgm mit ifstream und ofstream
#  Beim Aufruf werden 2 char Array uebergeben. Diese enthalten das Originalbild (bild1) und das zu bearbeitende Bild (bild2)
#
#  Die Übergebenen Variablen int Zeile und int Spalte enthalten die Pixel des aktuell eingelesene Bildes
#  graumax den eingelesenen maximalen Grauwert
#  Es wird kein Wert zurückgegeben.
#################################################################################################
*/
void invertieren(Pixel** bild1, Pixel** bild2, int zeile, int spalte, int graumax)
{
	int tempix = 0;
	for (int i = 0; i < zeile; i += 1)
	{
		for (int j = 0; j < spalte; j += 1)
		{
			tempix = bild1[i][j];
			bild2[i][j] = graumax - tempix;
		}
	}
}

/*
#################################################################################################
# FUNKTION glaetten
#################################################################################################
#  Funktion fuer das glaetten eines eingelesenen Bildes dreifach.pgm
#  Beim Aufruf werden 2 char Array uebergeben. Diese enthalten das Originalbild (bild1) und das zu bearbeitende Bild (bild2)
#  Die Übergebenen Variablen int Zeile und int Spalte enthalten die Pixel des aktuell eingelesene Bildes
#  Anhand des Mittelwertes eines 3x3 Felder Arrays wird der Grauwert berechnet. Der Rand wird geschwaertzt und somit 0 gesetzt.
#  Die Übergebenen Variablen int Zeile und int Spalte enthalten die Pixel des aktuell eingelesene Bildes
#  Es wird kein Wert zurückgegeben.
#################################################################################################
*/
void glaetten(Pixel** bild1, Pixel** bild2, int zeile, int spalte)
{
	int tempix = 0;
	int destpix = 0;
	for (int i = 0; i < zeile; i += 1)
	{
		for (int j = 0; j < spalte; j += 1)
		{
			if ((i < 1) || (j < 1) || (i > zeile - 2) || (j > spalte - 2))
			{
				bild2[i][j] = 0;
				continue;
			}

			destpix = (bild1[i - 1][j - 1] + bild1[i - 1][j] + bild1[i][j - 1] + bild1[i][j] + bild1[i + 1][j + 1] + bild1[i + 1][j] + bild1[i][j + 1] + bild1[i + 1][j - 1] + bild1[i - 1][j + 1]) / 9;
			bild2[i][j] = destpix;

		}
	}
}

/*
#################################################################################################
# FUNKTION kantenbildung
#################################################################################################
#  Funktion fuer die Kantenbildung eines eingelesenen Bildes dreifach.pgm
#  Beim Aufruf werden 2 char Array uebergeben. Diese enthalten das Originalbild (bild1) und das zu bearbeitende Bild (bild2)
#  Die Übergebenen Variablen int Zeile und int Spalte enthalten die Pixel des aktuell eingelesene Bildes
#  Durch die Berechnung eines 3x3 Felder Arrays wird der Grauwert berechnet. Der Rand wird geschwaertzt und somit 0 gesetzt.
#  Die Übergebenen Variablen int Zeile und int Spalte enthalten die Pixel des aktuell eingelesene Bildes
#  Es wird kein Wert zurückgegeben.
#################################################################################################
*/
void kantenbildung(Pixel** bild1, Pixel** bild2, int zeile, int spalte)
{
	int tempix = 0;
	int destpix = 0;
	for (int i = 0; i < zeile; i += 1)
	{
		for (int j = 0; j < spalte; j += 1)
		{
			if ((i < 1) || (j < 1) || (i > zeile - 2) || (j > spalte - 2))
			{
				bild2[i][j] = 0;
				continue;
			}

			tempix = bild1[i][j];
			destpix = abs((-1 * bild1[i - 1][j] - 1 * bild1[i][j - 1] + 4 * bild1[i][j] - 1 * bild1[i + 1][j] - 1 * bild1[i][j + 1]) / 9);
			bild2[i][j] = destpix;

		}
	}
}

/*
#################################################################################################
# FUNKTION schaerfen
#################################################################################################
#  Funktion fuer das schaerfen eines eingelesenen Bildes dreifach.pgm
#  Beim Aufruf werden 2 char Array uebergeben. Diese enthalten das Originalbild (bild1) und das zu bearbeitende Bild (bild2)
#  Die Übergebenen Variablen int Zeile und int Spalte enthalten die Pixel des aktuell eingelesene Bildes
#  Durch die Berechnung eines 3x3 Felder Arrays wird der Grauwert berechnet. Der Rand wird geschwaertzt und somit 0 gesetzt.
#  Die Übergebenen Variablen int Zeile und int Spalte enthalten die Pixel des aktuell eingelesene Bildes
#  graumax den eingelesenen maximalen Grauwert
#  Es wird kein Wert zurückgegeben.
#################################################################################################
*/
void schaerfen(Pixel** bild1, Pixel** bild2, int zeile, int spalte, int graumax)
{
	int tempix = 0;
	int destpix = 0;
	for (int i = 0; i < zeile; i += 1)
	{
		for (int j = 0; j < spalte; j += 1)
		{
			//Falls Werte unter 0 und ueber graumax ist, dann anpassen
			if (destpix < 0)
			{
				destpix = 0;
			}
			if (destpix > graumax)
			{
				destpix = graumax;
			}
			bild2[i][j] = destpix;
			if ((i < 1) || (j < 1) || (i > zeile - 2) || (j > spalte - 2))
			{
				bild2[i][j] = 0;
				continue;
			}

			tempix = bild1[i][j];
			destpix = (-1 * bild1[i - 1][j - 1] - 1 * bild1[i - 1][j] - 1 * bild1[i][j - 1] + 9 * bild1[i][j] - 1 * bild1[i + 1][j + 1] - 1 * bild1[i + 1][j] - 1 * bild1[i][j + 1] - 1 * bild1[i + 1][j - 1] - 1 * bild1[i - 1][j + 1]);

		}
	}
}