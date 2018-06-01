#pragma once

#include "FehlerDatum.h"

class FehlerMonat : public FehlerDatum
{
public:
	FehlerMonat (std::string msg = "Falsche Monatsangabe") : FehlerDatum(msg){}
};

