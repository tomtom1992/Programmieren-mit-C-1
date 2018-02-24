// 01_Bildverarbeitung_3.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "pgm_bild.cpp"


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




int main()
{
	pgm_bild* bild = new pgm_bild;
	bild_lesen(bild, "bild.pgm");
	bild_schreiben(bild, "bild2.pgm");
	return 0;
}

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

	ofs << bild->magic << std::endl; // Dateiformat schreiben
	ofs << bild->nSpalten << " " << bild->nZeilen << std::endl; // Zeilen und Spalten schreiben
	ofs << bild->graumax << std::endl;                       //Grauwert in die Ausgabedatei schreiben

	for (int i = 0; i < bild->nZeilen; i += 1)
	{
		for (int j = 0; j < bild->nSpalten; j += 1)
		{
			ofs << std::setw(4) << int(bild->bild[i][j]);
		}
		ofs << std::endl;
	}
	ofs.close();        // Close ofstream
}


void bild_lesen(pgm_bild *bild, std::string ifs_file_name)
{
	std::string c = ""; // Variable für den ersten eingelesenen Wert aus pgm Datei

	std::ifstream ifs;	// create ifstream
	ifs.open(ifs_file_name);
	if (!ifs)
	{
		std::cerr << "\nFEHLER: Die einzulesende Datei konnte nicht geoeffnet werden. Dateiname: " << ifs_file_name << std::endl;
		exit(1);
	}

	//Auslesen der ersten Zeile des Bildes und Format pruefen
	std::getline(ifs, c);
	if (c.compare("P2") != 0)
	{
		std::cerr << "Falsches Dateiformat" << std::endl;
		exit(1);
	}
	else
	{
		bild->magic = c.c_str(); // Dateiformat in struct speichern
		std::cout << "Codierung : " << c << std::endl;
	}
	//Bildzeilen und -spalten auslesen und mit max Wert vergleichen
	ifs >> bild->nSpalten;
	ifs >> bild->nZeilen;


	std::cout << "Zeilen: " << bild->nZeilen << " Spalten: " << bild->nSpalten << std::endl;

	ifs >> bild->graumax; // Maxgrauwert auslesen

	bild->bild = new_pixel_matrix(bild->nZeilen, bild->nSpalten);

	// Read image
	for (int i = 0; i < bild->nZeilen; i += 1)
	{
		for (int j = 0; j < bild->nSpalten; j += 1)
		{
			ifs >> bild->bild[i][j];
		}
	}
	ifs.close();        // Close ifstream

}

// === FUNCTION =================================================================================
//		Name: new_pixel_matrix
//		Description: Allocate a dynamic Pixel-matrix of size rows*columns
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
//		Description: Free a dynamic Pixel-matrix
// ==============================================================================================
void delete_pixel_matrix(Pixel **m)
{
	delete[] * m;
	delete[] m;
}
