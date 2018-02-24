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
void	bild_lesen(pgm_bild *bild, string ifs_file_name);
void	bild_schreiben(pgm_bild *bild, string ofs_file_name);
void	delete_pixel_matrix(Pixel **m);
Pixel** new_pixel_matrix(size_t rows, size_t columns);
void	glaetten(pgm_bild *bild1, pgm_bild *bild2);
void	invertieren(pgm_bild *bild1, pgm_bild *bild2);
void	kantenbildung(pgm_bild *bild1, pgm_bild *bild2);
void	kopiere_bildkopf(pgm_bild *bild1, pgm_bild *bild2);
void	schaerfen(pgm_bild *bild1, pgm_bild *bild2);

// #### IMPLEMENTATIONS ############################################################

