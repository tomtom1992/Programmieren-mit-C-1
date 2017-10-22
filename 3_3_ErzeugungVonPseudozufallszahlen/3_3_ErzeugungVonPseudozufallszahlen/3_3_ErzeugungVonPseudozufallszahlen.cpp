// 3_3_ErzeugungVonPseudozufallszahlen.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <iomanip>


int main()
{
	double a = 16333;
	double b = 25887;
	double m = pow(2, 15);

	double x = 0;

	std::cout << "10 Zufallszahlen:" << std::endl;

	double zufallswert = 0;
	for (int i = 0; i < 10;++i)
	{
		zufallswert = fmod((a * zufallswert + b) , m);

		std::cout << std::setw(6)<<zufallswert << std::endl;

	}

    return 0;
}

