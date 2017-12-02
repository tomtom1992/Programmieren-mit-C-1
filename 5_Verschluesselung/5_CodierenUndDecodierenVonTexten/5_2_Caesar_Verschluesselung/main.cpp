/*=========================================================

Filename: main.cpp

Author: Thomas Hahn

Date: 27.11.2017

Description: "L�sung zur Aufgabe: 5.2. Caesar-Verschl�sselung"

==========================================================*/


//Standard General Utilities Library
#include "stdafx.h"
//IO Stream Objects
#include <iostream>

using namespace std;

//Testfelder
char a[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G','X', 'Y', 'Z' };
char feldWenden[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G','X', 'Y', 'Z' };
char feldLinksSchieben[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G','X', 'Y', 'Z' };
char feldRechtsSchieben[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G','X', 'Y', 'Z' };

/* Beschreibung: wendet einen Bereich in einem Array
* �bergabeparameter: a: zu wendendes Feld; 
* n: L�nge des zu wendenden Bereichs
*/
void feld_wenden(char a[], unsigned int n)
{
	//Hilfsvariable
	char c;

	//�ber die H�lfte der L�nge des Feldes iterieren
	//n-1 => da bei a[0] angefangen wird
	for (int i = 0; i < n / 2; i++)
	{
		//Stelle merken die im n�chsten schritt �berschrieben wird
		c = a[i];
		//Erste H�lfte des Bereichs wenden
		a[i] = a[n - 1 - i];
		//Zweite H�lfte des Bereichs wenden
		a[n - 1 - i] = c;
	}
}

/* Beschreibung: l�sst ein Feld zyklisch nach links rotieren
* �bergabeparameter:
* a: Feld, welches zyklisch nach links verschoben werden soll
* n: L�nge des Feldes
* shift: Pl�tze, um die verschoben werden soll
*/
void feld_links_rotieren(char a[], unsigned int n, unsigned int shift)
{

	//verschiebung muss kleiner als feldl�nge sein
	shift = shift % n;

	//Verlassen falls shift=0
	if (shift == 0)
	{
		return;
	}

	

	//dreimaliger aufruf analog zu Abbildung 5.2 Lerneinheit 2
	feld_wenden(a, shift);
	feld_wenden(a, n);
	feld_wenden(a, n - shift);
}

/* Beschreibung: l�sst ein Feld zyklisch nach rechts rotieren
* �bergabeparameter:
* a: Feld, welches zyklisch nach rechts verschoben werden soll
* n: L�nge des Feldes
* shift: Pl�tze, um die verschoben werden soll
*/
void feld_rechts_rotieren(char a[], unsigned int n, unsigned int shift)
{

	//verschiebung muss kleiner als feldl�nge sein
	shift = shift % n;

	//Verlassen falls shift=0
	if (shift == 0)
	{
		return;
	}
	

	feld_wenden(a, n - shift);
	feld_wenden(a, n);
	feld_wenden(a, shift);
}


/*  description:    Hauptmethode des C++ Programms.
parameters:			na
return value:		Gibt 0 zur�ck, wenn das Programm ohne Fehler gelaufen ist.
*/
int main()
{
	//!!Testszenario

	//Originales Test Feld ausgeben
	cout << "Test-Feld: " << endl;
	for (int i = 0; i<sizeof(a); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	feld_wenden(feldWenden, 5);

	//Gewendetes Feld ausgeben
	cout << "feld_wenden:" << endl;
	for (int i = 0; i<sizeof(feldWenden); i++)
	{
		cout << feldWenden[i] << " ";
	}
	cout << endl;

	feld_links_rotieren(feldLinksSchieben, sizeof(feldLinksSchieben), 3);

	//Ausgabe
	cout << "feld_links_rotieren" << endl;
	for (int i = 0; i<sizeof(feldLinksSchieben); i++)
	{
		cout << feldLinksSchieben[i] << " ";
	}
	cout << endl;

	feld_rechts_rotieren(feldRechtsSchieben, sizeof(feldRechtsSchieben), 3);

	//Ausgabe
	cout << "feld_rechts_rotieren" << endl;
	for (int i = 0; i<sizeof(feldRechtsSchieben); i++)
	{
		cout << feldRechtsSchieben[i] << " ";
	}

	return 0;
}

