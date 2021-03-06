// 07_Ausnahmebehandlung.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Datum.h"
#include <fstream>
#include <iostream>
#include <string>
#include "FehlerTag.h"
#include "FehlerMonat.h"
#include <iomanip>




std::ostream & operator << (std::ostream & os, const Datum & obj) {
	os << obj.getTag() << "." << obj.getMonat() << "." << obj.getJahr();
	return os;
};

int main()
{
	Datum *array = new Datum[1000000];

	std::ifstream ifs;
	ifs.open("datumsliste.dat");
	if (!ifs)
	{
		std::cout << "Error opening file";

	}

	std::string tag;
	std::string monat;
	std::string jahr;
	uint i = 0;
	uint err_count = 0;
	while (ifs >> tag >> monat >> jahr) {


		uint iTag = std::stoul(tag, nullptr, 0);
		uint iMonat = std::stoul(monat, nullptr, 0);
		uint iJahr = std::stoul(jahr, nullptr, 0);
		try
		{
			Datum datum = Datum(iTag, iMonat, iJahr);
			array[i] = datum;

			//std::cout << datum << std::endl;
		}
		catch (const FehlerTag& f)
		{
			std::cout << "Satz Nr." << std::setw(6) << i + 1 << " : " << f.what() << " : " << iTag << std::endl;
			err_count++;
		}
		catch (const FehlerMonat& f)
		{
			std::cout << "Satz Nr." << std::setw(6) << i + 1 << " : " << f.what() << " : " << iMonat << std::endl;
			err_count++;
		}
		i++;



	}

	std::cout << i - err_count << " von " << i << " Datensätzen eingelesen" << std::endl;;

	delete[] array;
	return 0;
}

