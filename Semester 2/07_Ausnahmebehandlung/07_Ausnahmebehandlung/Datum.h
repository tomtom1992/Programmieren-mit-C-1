#include <ostream>

typedef unsigned int uint;

class Datum
{
public:
	Datum() {};
	Datum(uint tg, uint mnt, uint jhr);

	uint getTag() const { return tag; }
	uint getMonat() const { return monat; }
	uint getJahr() const { return jahr; }

	

private:
	bool monatOk();
	bool tagOk();
	bool schaltjahr();

private:
	uint tag;
	uint monat;
	uint jahr;


};