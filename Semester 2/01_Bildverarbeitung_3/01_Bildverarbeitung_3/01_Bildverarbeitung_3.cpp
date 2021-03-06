/*
* =====================================================================================
*
*      Dateiname:  01_Bildverarbeitung_3.cpp
*
*   Beschreibung:  Aufgabe 1.1
*   				Bildverarbeitung 3
*
*   Erstelldatum:  01.03.2018
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


// #### TYPE DEFINITIONS ############################################################
typedef unsigned char Pixel;

// #### DATA TYPES - LOCAL TO THIS SOURCE FILE ######################################
struct pgm_bild
{
	char magic[2];			// Bildtyp
	int nZeilen;			// Zeilenanzahl
	int nSpalten;			// Spaltenanzahl
	int graumax;			// max. Grauwert
	Pixel **bild;			// Bildmatrix
};			// ---------- end of struct pgm_bild ----------

// #### LOCAL PROTOTYPES ###########################################################
void	bild_lesen(pgm_bild *bild, std::string ifs_file_name);
void	bild_schreiben(pgm_bild *bild, std::string ofs_file_name);
void	delete_pixel_matrix(Pixel **m);
Pixel** new_pixel_matrix(size_t rows, size_t columns);
void	glaetten(pgm_bild *bild1, pgm_bild *bild2);
void	invertieren(pgm_bild *bild1, pgm_bild *bild2);
void	kantenbildung(pgm_bild *bild1, pgm_bild *bild2);
void	kopiere_bildkopf(pgm_bild *bild1, pgm_bild *bild2);
void	schaerfen(pgm_bild *bild1, pgm_bild *bild2);

// #### IMPLEMENTATIONS ############################################################



// === FUNCTION =================================================================================
//		Name: main
//		Description: Hauptfunktion und Einstiegspunkt des C++-Programms.
// ==============================================================================================
int main()
{
	pgm_bild* bild1 = new pgm_bild;
	pgm_bild* bild2 = new pgm_bild;

	bild_lesen(bild1, "bild.pgm");
	bild2->bild = new_pixel_matrix(bild1->nZeilen, bild1->nSpalten);
	kopiere_bildkopf(bild1, bild2);

	// Bildbearbeitungsmenü

	std::cout << "Bitte wählen Sie eine Funktion:" << std::endl;
	std::cout << "g Glaettung" << std::endl;
	std::cout << "i Invertierung" << std::endl;
	std::cout << "k Kantenbildung" << std::endl;
	std::cout << "s Schaerfung" << std::endl;
	std::cout << "e ENDE" << std::endl;

	char input;
	std::cin >> input;

	switch (input) {
	case 'e': break;
	case 'g': glaetten(bild1, bild2); break;
	case 'i': invertieren(bild1, bild2); break;
	case 'k': kantenbildung(bild1, bild2); break;
	case 's': schaerfen(bild1, bild2); break;
	}

	bild_schreiben(bild2, "bild2.pgm");

	delete_pixel_matrix(bild1->bild);
	delete_pixel_matrix(bild2->bild);
	return 0;
}

// === FUNCTION =================================================================================
//		Name: kopiere_bildkopf
//		Description: Kopiert den Bildkopf / die Headerinformationen
// ==============================================================================================
void kopiere_bildkopf(pgm_bild * bild1, pgm_bild * bild2)
{
	bild2->magic[0] = bild1->magic[0];
	bild2->magic[1] = bild1->magic[1];
	bild2->graumax = bild1->graumax;
	bild2->nSpalten = bild1->nSpalten;
	bild2->nZeilen = bild1->nZeilen;
}

// === FUNCTION =================================================================================
//		Name: schaerfen
//		Description: Schärft das Bild
// ==============================================================================================
void schaerfen(pgm_bild * bild1, pgm_bild * bild2)
{
	int tempix = 0;
	int destpix = 0;
	for (int i = 0; i < bild1->nZeilen; i += 1)
	{
		for (int j = 0; j < bild1->nSpalten; j += 1)
		{
			//Falls Werte unter 0 und ueber graumax ist, dann anpassen
			if (destpix < 0)
			{
				destpix = 0;
			}
			if (destpix > bild1->graumax)
			{
				destpix = bild1->graumax;
			}
			bild2->bild[i][j] = destpix;
			if ((i < 1) || (j < 1) || (i > bild1->nZeilen - 2) || (j > bild1->nSpalten - 2))
			{
				bild2->bild[i][j] = 0;
				continue;
			}

			tempix = bild1->bild[i][j];
			destpix = (-1 * bild1->bild[i - 1][j - 1] - 1 * bild1->bild[i - 1][j] - 1 * bild1->bild[i][j - 1] + 9 * bild1->bild[i][j] - 1 * bild1->bild[i + 1][j + 1] - 1 * bild1->bild[i + 1][j] - 1 * bild1->bild[i][j + 1] - 1 * bild1->bild[i + 1][j - 1] - 1 * bild1->bild[i - 1][j + 1]);

			bild2->bild[i][j] = destpix;
		}
	}
}

// === FUNCTION =================================================================================
//		Name: kantenbildung
//		Description: Verstärkt Kanten im Bild
// ==============================================================================================
void kantenbildung(pgm_bild * bild1, pgm_bild * bild2)
{
	int tempix = 0;
	int destpix = 0;
	for (int i = 0; i < bild1->nZeilen; i += 1)
	{
		for (int j = 0; j < bild1->nSpalten; j += 1)
		{
			if ((i < 1) || (j < 1) || (i > bild1->nZeilen - 2) || (j > bild1->nSpalten - 2))
			{
				bild2->bild[i][j] = 0;
				continue;
			}

			tempix = bild1->bild[i][j];
			destpix = abs((-1 * bild1->bild[i - 1][j] - 1 * bild1->bild[i][j - 1] + 4 * bild1->bild[i][j] - 1 * bild1->bild[i + 1][j] - 1 * bild1->bild[i][j + 1]) / 9);
			bild2->bild[i][j] = destpix;

		}
	}
}

// === FUNCTION =================================================================================
//		Name: invertieren
//		Description: Invertiert das Bild
// ==============================================================================================
void invertieren(pgm_bild * bild1, pgm_bild * bild2)
{
	int tempix = 0;
	for (int i = 0; i < bild1->nZeilen; i += 1)
	{
		for (int j = 0; j < bild1->nSpalten; j += 1)

		{
			tempix = bild1->bild[i][j];
			bild2->bild[i][j] = bild1->graumax - tempix;
		}
	}
}

// === FUNCTION =================================================================================
//		Name: glaetten
//		Description: Glättet das Bild
// ==============================================================================================
void glaetten(pgm_bild * bild1, pgm_bild * bild2)
{
	int tempix = 0;
	int destpix = 0;
	for (int i = 0; i < bild1->nZeilen; i += 1)
	{
		for (int j = 0; j < bild1->nSpalten; j += 1)
		{
			if ((i < 1) || (j < 1) || (i > bild1->nZeilen - 2) || (j > bild1->nSpalten - 2))
			{
				bild2->bild[i][j] = 0;
				continue;
			}

			destpix = (bild1->bild[i - 1][j - 1] + bild1->bild[i - 1][j] + bild1->bild[i][j - 1] + bild1->bild[i][j] + bild1->bild[i + 1][j + 1] + bild1->bild[i + 1][j] + bild1->bild[i][j + 1] + bild1->bild[i + 1][j - 1] + bild1->bild[i - 1][j + 1]) / 9;
			bild2->bild[i][j] = destpix;

		}
	}
}

// === FUNCTION =================================================================================
//		Name: bild_schreiben
//		Description: Schreibt das Bild in eine Datei
// ==============================================================================================
void	bild_schreiben(pgm_bild *bild, std::string ofs_file_name)
{
	std::ofstream ofs;
	ofs.open(ofs_file_name);
	if (!ofs)
	{
		std::cerr << "\nFEHLER: Die zu schreibende Datei konnte nicht geoeffnet werden. Dateiname: " << ofs_file_name << std::endl;
		exit(1);
	}

	// Bild schreiben

	ofs << bild->magic[0] << bild->magic[1] << std::endl; // Dateiformat schreiben
	ofs << bild->nSpalten << " " << bild->nZeilen << std::endl; // Zeilen und Spalten schreiben
	ofs << bild->graumax << std::endl;                       //Grauwert in die Ausgabedatei schreiben

	for (int i = 0; i < bild->nZeilen; i += 1)
	{
		for (int j = 0; j < bild->nSpalten; j += 1)
		{
			ofs << std::setfill(' ') << std::setw(4) << int(bild->bild[i][j]);
		}
		ofs << std::endl;
	}
	ofs.close();        // Close ofstream
}

// === FUNCTION =================================================================================
//		Name: bild_lesen
//		Description: Liest das Bild aus einer Datei in das struct
// ==============================================================================================
void bild_lesen(pgm_bild *bild, std::string ifs_file_name)
{
	//std::string c = ""; // Variable für den ersten eingelesenen Wert aus pgm Datei

	//std::ifstream ifs;	// create ifstream
	//ifs.open(ifs_file_name);
	//if (!ifs)
	//{
	//	std::cerr << "\nFEHLER: Die einzulesende Datei konnte nicht geoeffnet werden. Dateiname: " << ifs_file_name << std::endl;
	//	exit(1);
	//}

	////Auslesen der ersten Zeile des Bildes und Format pruefen
	//std::getline(ifs, c);
	//if (c.compare("P2") != 0)
	//{
	//	std::cerr << "Falsches Dateiformat" << std::endl;
	//	exit(1);
	//}
	//else
	//{
	//	bild->magic[0] = 'P'; // Dateiformat in struct speichern
	//	bild->magic[1] = '2';
	//	std::cout << "Codierung : " << c << std::endl;
	//}
	//// Bildzeilen und -spalten auslesen und mit max Wert vergleichen
	//ifs >> bild->nSpalten;
	//ifs >> bild->nZeilen;


	//std::cout << "Zeilen: " << bild->nZeilen << " Spalten: " << bild->nSpalten << std::endl;

	//ifs >> bild->graumax; // Maxgrauwert auslesen

	//bild->bild = new_pixel_matrix(bild->nZeilen, bild->nSpalten);

	//// Read image
	//for (int i = 0; i < bild->nZeilen; i += 1)
	//{
	//	for (int j = 0; j < bild->nSpalten; j += 1)
	//	{
	//		ifs >> bild->bild[i][j];
	//	}
	//}
	//ifs.close();        // Close ifstream
	//ifstream Objekt erstellen
	std::ifstream eingabeDatei;

	//Datei öffnen
	eingabeDatei.open(ifs_file_name);

	//Abfragen ob eingabeDatei geöffnet werden konnte
	if (!eingabeDatei)
	{
		std::cerr << std::endl << "Error: failed to open input file ! " << std::endl;
		exit(1);
	}

	//Einzulesendes Element
	std::string element;

	//Array dynamisch allokieren und mit Nullpointer initialisieren.
	//Sonst ist die Zuweisung später nicht möglich.
	Pixel **eingabeFeld = nullptr;

	//ElementZähler ersten 4 elemente abziehen
	int elementCounter = -3;

	int i = 0, j = 0, maxZeilen = 1000;

	//eingabeDatei einlesen
	while (eingabeDatei >> element)
	{

		//Array füllen nach dem header
		if (elementCounter > 0)
		{
			eingabeFeld[i][j] = stoi(element);
			j++;
			//Nach x Zeilen in nächste Spalte springen
			if (j == bild->nSpalten)
			{
				i++;
				j = 0;
			}
		}
		else
		{
			//Ausgabe
			std::cout << element;

			//Kodierung überprüfen
			if (elementCounter == -3)
			{
				//Kodierung in Struct übernehmen
				bild->magic[0] = element[0];
				bild->magic[1] = element[1];
				if (element != "P2")
				{
					std::cout << "Falsche Kodierung";
					break;
				}
				//newline nach kodierung
				std::cout << std::endl;
			}
			//Zeilenanzahl lesen und neues Feld allokieren
			if (elementCounter == -1)
			{
				std::cout << std::endl;
				bild->nZeilen = stoi(element);

				//sobald zeilen und spalten infos gelesen wurden wird ein neues feld dynamisch allokiert
				eingabeFeld = new_pixel_matrix(bild->nZeilen, bild->nSpalten);
			}

			//Spaltenanzahl lesen und überprüfen
			if (elementCounter == -2)
			{
				std::cout << " ";
				bild->nSpalten = stoi(element);
			}
			//nach Element graustufen nächste zeile
			if (elementCounter == 0)
			{
				bild->graumax = stoi(element);
				std::cout << std::endl;
			}
		}
		elementCounter++;
	}
	//Stream schließen
	eingabeDatei.close();

	//Array an Struct übergeben
	bild->bild = eingabeFeld;

	//eingabeFeld speicher freigeben
	/*delete_pixel_matrix(eingabeFeld);*/
}

// === FUNCTION =================================================================================
//		Name: new_pixel_matrix
//		Description: Allokiert eine dynamische Pixel-Matrix der Größe rows*columns
// ==============================================================================================
Pixel** new_pixel_matrix(size_t rows, size_t columns)
{
	size_t i;
	Pixel **m;
	m = new Pixel*[rows];
	*m = new Pixel[rows*columns];
	for (i = 1; i < rows; i++)
	{
		m[i] = m[i - 1] + columns;
	}
	return m;
}

// === FUNCTION =================================================================================
//		Name: delete_pixel_matrix
//		Description: Löscht eine dynamische Pixel-Matrix
// ==============================================================================================
void delete_pixel_matrix(Pixel **m)
{
	delete[] * m;
	delete[] m;
}
