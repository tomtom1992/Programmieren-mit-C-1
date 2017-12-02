/*=========================================================

Filename: 5_1_ROT13.cpp

Author: Thomas Hahn

Date: 27.11.2017

Description: "Aufgabe: Die Verschiebechiffre ROT13"

==========================================================*/


#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/*  description:    Hauptmethode des C++ Programms.
parameters:			na
return value:		Gibt 0 zurück, wenn das Programm ohne Fehler gelaufen ist.
*/
int main()
{
	char c;
	char rot13[] = {
	'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
		'A','B','C','D','E','F','G','H','I','J','K','L','M'
	};

	string input_file_name = "C:\\Projects\\Programmieren-mit-C-1\\5_Verschluesselung\\klartext.txt";
	string output_file_name = "C:\\Projects\\Programmieren-mit-C-1\\5_Verschluesselung\\geheim.txt";

	ifstream ifs;
	ifs.open(input_file_name);

	ofstream ofs;
	ofs.open(output_file_name);

	if (!ofs)
	{
		cout << "Error while writing the file.";
	}

	if (ifs)
	{
		while ((c = ifs.get()) != EOF)
		{
			if (c > 'Z' || c < 'A')
			{
				ofs.put(c);
			}
			else {
				int index_in_rot = (c - 'A');
				ofs.put(rot13[index_in_rot]);
			}

		}
	}
	else
	{
		cout << "Error openening file.";
	}


	return 0;
}

