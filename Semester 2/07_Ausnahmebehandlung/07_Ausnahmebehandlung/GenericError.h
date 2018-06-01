#pragma once

#include <string>

class GenericError
{
public:
	GenericError(std::string msg = "UNSPECIFIED") :message(msg) {}
	virtual ~GenericError(void) {}
	virtual std::string what(void) const { return "ERROR : " + message; }
protected:
	std::string message;
};

