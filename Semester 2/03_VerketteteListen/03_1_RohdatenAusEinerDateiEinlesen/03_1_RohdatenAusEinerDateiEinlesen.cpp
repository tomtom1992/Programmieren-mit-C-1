// 03_1_RohdatenAusEinerDateiEinlesen.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main()
{
	char identnummer[] = "";
	char nachname[] = "";
	char vorname[] = "";
	char abteilung[] = "";
	unsigned int	durchwahl;
	unsigned int	satz = 0;

	ifstream ifs;
	ifs.open("personen.dat");
	//so?
	// So kenne ich das nur. Heißt aber nix, ich kenne mich nicht supergut aus
	if (!ifs)
	{
		cout << "Fehler beim Lesen der Datei" << endl;
		return 1;
	}

	ofstream ofs;
	ofs.open("personenOut.dat");
	if (!ofs)
	{
		cout << "Fehler beim Schreiben der Datei" << endl;
		return 1;
	}
	// Sowas habe ich noch nicht gesehen. Kann man in der while Anweisung bereits den ifs beschreiben?
	// Beschreiben nicht, aber einlesen. Ich zeigs dir mit den Breakpoints
	while (!ifs.eof() && ifs >> identnummer >> nachname >> vorname >> abteilung >> durchwahl)
	{
		satz++;
		ofs << identnummer << '\t' << nachname << '\t' << '\t' << '\t' << vorname << '\t' << abteilung << '\t' << durchwahl << endl;
		// Wenn ich debugge bekomme ich einen Fehler, wenn die Datei am Ende ist
	}


	/*delete[] &identnummer;
	delete[] &nachname;
	delete[] &vorname;
	delete[] &abteilung;*/

	ifs.close();
	ofs.close();

	return 0;
}

