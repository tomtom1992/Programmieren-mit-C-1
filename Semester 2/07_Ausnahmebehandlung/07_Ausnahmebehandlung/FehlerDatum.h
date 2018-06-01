#pragma once

#include <stdio.h>
#include "GenericError.h"

class FehlerDatum : public GenericError
{
public:
	FehlerDatum(std::string msg = "Datumsfehler") : GenericError(msg) {}
};

