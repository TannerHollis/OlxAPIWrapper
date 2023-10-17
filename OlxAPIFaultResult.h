#pragma once

#include "OlxAPI3PValue.h"
#include "OlxAPIObj.h"

#include "olxapi/include/olxapi.h"
#include <string>

using namespace std;

class OlxAPIFaultResult
{
public:
	OlxAPIFaultResult(int fltHandle);

	string getDescription();

	double getMVA();

	double getThevNegR();
	double getThevPosR();
	double getThevZeroR();

	double getThevPosX();
	double getThevNegX();
	double getThevZeroX();

	double getXRRatio();
	double getXRANSIRatio();

	OlxAPI3PValue getCurrentAt(int handle);
	OlxAPI3PValue getCurrentAt(OlxAPIObj* obj);

	OlxAPI3PValue getVoltageAt(int handle);
	OlxAPI3PValue getVoltageAt(OlxAPIObj* obj);

protected:
	double getDoubleParameter(int paramToken);

private:
	int fltHandle;

};

