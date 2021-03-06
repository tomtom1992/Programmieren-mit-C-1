/*
* =====================================================================================
*
*      Dateiname:  02_GameOfLife.cpp
*
*   Beschreibung:  Aufgabe 2
*   				Game of Life
*
*   Erstelldatum:  14.03.2018
*        Version:  0.1
*       Compiler:  Visual C++
*
*          Autor:  Thomas Hahn
*
* =====================================================================================
*/

#include "stdafx.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

typedef unsigned int uint;

void zufallsbelegung(int** feld, uint hoehe, uint breite);
uint next_generation(int** feld1, int** feld2, uint breite, uint hoehe);
void print_feld(int** feld, uint hoehe, uint breite);
int** new_int_matrix(int rows, int columns);
void delete_int_matrix(int** m);



// === FUNCTION =================================================================================
//		Name: main
//		Description: Hauptfunktion und Einstiegspunkt des C++-Programms.
// ==============================================================================================
int main()
{
	// Einlesen der Spielfeldgröße

	uint hoehe = 0;
	uint breite = 0;
	int** feld1;
	int** feld2;

	std::cout << "Hallo. Welche Hoehe soll das Spielfeld haben?" << std::endl;
	std::cin >> hoehe;
	hoehe += 2;

	std::cout << "Und welche Breite soll das Spielfeld haben?" << std::endl;
	std::cin >> breite;
	breite += 2;

	// Zwei Spielfelder erstellen
	feld1 = new_int_matrix(hoehe, breite);
	feld2 = new_int_matrix(hoehe, breite);

	// Interne Zellen zufällgi initialisieren und Randzellen mit 0 initialisieren
	zufallsbelegung(feld1, hoehe, breite);

	// Schleife solange bis Benutzer mit "q" abbricht
	std::string userInput = "";
	while (userInput != "q")
	{
		print_feld(feld1, hoehe, breite);
		std::cout << "... weiter ...";
		std::string s;
		std::getline(std::cin,userInput);
		next_generation(feld1, feld2, hoehe, breite);
		for (int i = 0; i < hoehe; i++)
		{
			for (int k = 0; k < breite; k++)
			{
				feld1[i][k] = feld2[i][k];
			}
		}

	}

	return 0;
}

// === FUNCTION =================================================================================
//		Name: zufallsbelegung
//		Description: Belegt das Feld zufällig mit lebenden Zellen.
// ==============================================================================================
void zufallsbelegung(int ** feld, uint hoehe, uint breite)
{
	srand(time(NULL));
	for (int i = 0; i < hoehe; i++)
	{
		for (int k = 0; k < breite; k++)
		{
			if (i == 0 || k == 0 || i == hoehe - 1 || k == breite - 1)
			{
				feld[i][k] = 0;
			}
			else
			{
				feld[i][k] = rand() % 2;
			}
		}
	}
}

// === FUNCTION =================================================================================
//		Name: new_int_matrix
//		Description: Erzeugt eine neue integer matrix.
// ==============================================================================================
int ** new_int_matrix(int rows, int columns)
{
	size_t i;
	int **m;
	m = new int*[rows];
	*m = new int[rows*columns];
	for (i = 1; i < rows; i++)
	{
		m[i] = m[i - 1] + columns;
	}
	return m;
}

// === FUNCTION =================================================================================
//		Name: delete_int_matrix
//		Description: Löscht eine vorhandene integer matrix.
// ==============================================================================================
void delete_int_matrix(int** m)
{
	delete[] * m;
	delete[] m;
}

// === FUNCTION =================================================================================
//		Name: print_feld
//		Description: Druckt das Feld auf die Konsole.
// ==============================================================================================
void print_feld(int ** feld, uint hoehe, uint breite)
{
	uint population = 0;
	static uint generation = 0;

	for (int i = 1; i < hoehe - 1; i++)
	{
		for (int k = 1; k < breite - 1; k++)
		{
			if (feld[i][k] == 1)
			{
				std::cout << '#' << ' ';
				population++;
			}
			else
			{
				std::cout << '.' << ' ';
			}
		}
		std::cout << std::endl;
	}

	std::cout << "[" << hoehe - 2 << "," << breite - 2 << "]";
	std::cout << "Generation   " << generation++ << " / ";
	std::cout << "Population   " << population << " / ";
	std::cout << "(quit : 'q')" << std::endl;
}

// === FUNCTION =================================================================================
//		Name: next_generation
//		Description: Berechnet die nächste Generation.
// ==============================================================================================
uint next_generation(int ** feld1, int ** feld2, uint breite, uint hoehe)
{
	for (int i = 1; i < hoehe - 1; i++)
	{
		for (int k = 1; k < breite - 1; k++)
		{
			// Eine Zelle betrachten
			uint sum = feld1[i + 1][k] + feld1[i + 1][k + 1] + feld1[i][k + 1] + feld1[i - 1][k] + feld1[i - 1][k - 1] + feld1[i][k - 1] + feld1[i + 1][k - 1] + feld1[i - 1][k + 1];

			// Tote Zelle mit genau drei Nachbarn
			if (feld1[i][k] == 0)
			{
				
				if (sum == 3)
				{
					feld2[i][k] = 1;
				}
				else
				{
					feld2[i][k] = feld1[i][k];
				}
			}

			// Lebende Zelle
			if (feld1[i][k] == 1)
			{
				
				if (sum < 2)
				{
					// mit weniger als 2 Nachbarn stirbt
					feld2[i][k] = 0;
				}
				else if (sum == 2 || sum == 3)
				{
					// mit 2 oder 3 Nachbarn bleibt am Leben
					feld2[i][k] = 1;
				}
				else if (sum > 3)
				{
					// mit mehr als 3 Nachbarn stirbt an Überbevölkerung
					feld2[i][k] = 0;
				}
				else
				{
					feld2[i][k] = feld1[i][k];
				}
			}





		}
	}
	return 1;

	//int populationsGroesse = 0, anzahlDerNachbarn = 0;
	////Iterationsvariablen
	//int i, j;


	////nur innere plätze besetzten
	//for (i = 1; i < (breite - 1); i++)
	//{
	//	for (j = 1; j < (hoehe - 1); j++)
	//	{
	//		//Anzahl der Nachbarn ermitteln
	//		anzahlDerNachbarn = feld1[i - 1][j] + feld1[i + 1][j] + feld1[i][j - 1] + feld1[i][j + 1] +
	//			feld1[i - 1][j - 1] + feld1[i + 1][j + 1] + feld1[i - 1][j + 1] + feld1[i + 1][j - 1];

	//		//Populationsgroesse bestimmen
	//		if (feld1[i][j] == 1)
	//			populationsGroesse++;

	//		//Regel 1 Eine tote Zelle mit genu der Nachbarn wird in der nächsten Generation neu geboren
	//		if (feld1[i][j] == 0 && (anzahlDerNachbarn == 3))
	//			feld2[i][j] = 1;

	//		//Regel 2 Eine lebende Zelle mit weniger als zwei Nachbarn stirbt in der folgenden Generation an Verinsamung
	//		else if (feld1[i][j] == 1 && (anzahlDerNachbarn < 2))
	//			feld2[i][j] = 0;

	//		//Regel 3 Eine lebende Zelle mit zwei oder drei Nachgbarn bleibt in der folgenden Generation am Leben
	//		else if (feld1[i][j] == 1 && ((anzahlDerNachbarn == 3) || (anzahlDerNachbarn == 2)))
	//			feld2[i][j] = 1;

	//		//Regel 4 Eine lebende Zelle mit mehr als drei Nachbarn stirbt in der folgenden Generation an Überbevölkerung
	//		else if (feld1[i][j] == 1 && (anzahlDerNachbarn > 3))
	//			feld2[i][j] = 0;

	//		//Default Regel: Alle Zellen auf die keine Regel anzuwenden ist, werden unverändert in die nächste Generation übernommen
	//		else
	//			feld2[i][j] = feld1[i][j];
	//	}
	//}

	//
	//return populationsGroesse;
}

