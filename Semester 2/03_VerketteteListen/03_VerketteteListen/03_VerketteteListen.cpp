// 03_VerketteteListen.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "iostream"


struct Element {
	long key;
	long info;
	struct Element *next;
};

int main()
{
	Element* L;
	Element* cursor;

	// Vier Listenelemente anlegen
	Element x1;
	x1.key = 1;
	x1.info = 11;

	Element x2;
	x2.key = 2;
	x2.info = 22;

	Element x3;
	x3.key = 3;
	x3.info = 33;

	Element x4;
	x4.key = 4;
	x4.info = 44;

	// Elemente verketten
	L = &x1;
	x1.next = &x2;
	x2.next = &x3;
	x3.next = &x4;
	x4.next = NULL;

	// Element mit Schlüssel 3 suchen

	cursor = L;
	while (cursor->key != 3 && cursor->next != NULL) {
		cursor = cursor->next;
	}

	// Gefundenes Element ausgeben
	std::cout << "Listenelement gefunden : " << &cursor << std::endl;
	std::cout << std::endl;
	std::cout << "key	= " << cursor->key << std::endl;
	std::cout << "info	= " << cursor->info << std::endl;
	std::cout << "next	= " << &cursor->next << std::endl;

	return 0;
}



