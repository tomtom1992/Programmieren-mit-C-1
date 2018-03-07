// 02_GameOfLife.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef unsigned int uint;

void zufallsbelegung(int** feld, uint hoehe, uint breite);
uint next_generation(int** feld1, int** feld2, uint breite, uint hoehe);
void print_feld(int** feld, uint hoehe, uint breite);
int** new_int_matrix(int rows, int columns);
void delete_int_matrix(int** m);

uint generation = 0;


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
	unsigned char userInput = 0;
	while (userInput != 'q')
	{
		print_feld(feld1, hoehe, breite);
		std::cout << "... weiter ...";
		std::cin >> userInput;
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

void delete_int_matrix(int** m)
{
	delete[] * m;
	delete[] m;
}

void print_feld(int ** feld, uint hoehe, uint breite)
{
	uint population = 0;

	for (int i = 1; i < hoehe - 1; i++)
	{
		for (int k = 1; k < breite - 1; k++)
		{
			if (feld[i][k] == 1)
			{
				std::cout << '#';
				population++;
			}
			else
			{
				std::cout << '.';
			}
		}
		std::cout << std::endl;
	}

	std::cout << "[" << hoehe - 2 << "," << breite - 2 << "]";
	std::cout << "Generation   " << generation << " / ";
	std::cout << "Population   " << population << " / ";
	std::cout << "(quit : 'q')" << std::endl;
}

uint next_generation(int ** feld1, int ** feld2, uint breite, uint hoehe)
{
	for (int i = 1; i < hoehe - 1; i++)
	{
		for (int k = 1; k < breite - 1; k++)
		{
			// Eine Zelle betrachten

			// Tote Zelle mit genau drei Nachbarn
			if (feld1[i][k] == 0)
			{
				uint sum = feld1[i + 1][k] + feld1[i + 1][k + 1] + feld1[i][k + 1] + feld1[i - 1][k] + feld1[i - 1][k - 1] + feld1[i][k - 1] + feld1[i + 1][k - 1] + feld1[i - 1][k + 1];
				if (sum == 3)
				{
					feld2[i][k] = 1;
				}
			}

			// Lebende Zelle
			if (feld1[i][k] == 1)
			{
				uint sum = feld1[i + 1][k] + feld1[i + 1][k + 1] + feld1[i][k + 1] + feld1[i - 1][k] + feld1[i - 1][k - 1] + feld1[i][k - 1] + feld1[i + 1][k - 1] + feld1[i - 1][k + 1];
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
			}





		}
	}
	return uint();
}

