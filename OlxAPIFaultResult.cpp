#include "OlxAPIFaultResult.h"

OlxAPIFaultResult::OlxAPIFaultResult(int fltHandle)
{
	this->fltHandle = fltHandle;
}

string OlxAPIFaultResult::getDescription()
{
	const char* response = OlxAPIFaultDescription(fltHandle);
	return string(response);
}

double OlxAPIFaultResult::getMVA()
{
	return getDoubleParameter(FT_dMVA);
}

double OlxAPIFaultResult::getThevNegR()
{
	return getDoubleParameter(FT_dRNt);
}

double OlxAPIFaultResult::getThevPosR()
{
	return getDoubleParameter(FT_dRPt);
}

double OlxAPIFaultResult::getThevZeroR()
{
	return getDoubleParameter(FT_dRZt);
}

double OlxAPIFaultResult::getThevPosX()
{
	return getDoubleParameter(FT_dXPt);
}

double OlxAPIFaultResult::getThevNegX()
{
	return getDoubleParameter(FT_dXNt);
}

double OlxAPIFaultResult::getThevZeroX()
{
	return getDoubleParameter(FT_dXZt);
}

double OlxAPIFaultResult::getXRRatio()
{
	return getDoubleParameter(FT_dXR);
}

double OlxAPIFaultResult::getXRANSIRatio()
{
	return getDoubleParameter(FT_dXRANSI);
}

OlxAPI3PValue OlxAPIFaultResult::getCurrentAt(int handle)
{
	int ret = OlxAPIPickFault(fltHandle, 0);
	double real[20] = {};
	double imag[20] = {};
	ret = OlxAPIGetSCCurrent(handle, real, imag, 3);

	OlxAPI3PValue value = OlxAPI3PValue(real, imag);
	return value;
}

OlxAPI3PValue OlxAPIFaultResult::getCurrentAt(OlxAPIObj* obj)
{
	return getCurrentAt(obj->getHandle());
}

OlxAPI3PValue OlxAPIFaultResult::getVoltageAt(int handle)
{
	int ret = OlxAPIPickFault(fltHandle, 0);
	double real[9] = { 0, 0, 0 };
	double imag[9] = { 0, 0, 0 };
	ret = OlxAPIGetSCVoltage(handle, real, imag, 3);

	OlxAPI3PValue value = OlxAPI3PValue(real, imag);
	return value;
}

OlxAPI3PValue OlxAPIFaultResult::getVoltageAt(OlxAPIObj* obj)
{
	return getVoltageAt(obj->getHandle());
}

double OlxAPIFaultResult::getDoubleParameter(int paramToken)
{
	double param = 0;
	int ret = OlxAPIPickFault(fltHandle, 1);
	ret = OlxAPIGetData(HND_SC, paramToken, &param);
	return param;
}
