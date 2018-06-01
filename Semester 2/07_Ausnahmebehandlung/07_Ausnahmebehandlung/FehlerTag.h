#pragma once
#include "FehlerDatum.h"

class FehlerTag : public FehlerDatum
{
public:
	FehlerTag (std::string msg = "Falsche Tagesangabe") : FehlerDatum(msg){}
};

