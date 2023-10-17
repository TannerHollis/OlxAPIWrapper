#include "OlxAPILineObj.h"

OlxAPILineObj::OlxAPILineObj(int handle) : OlxAPIBranchObj(handle)
{
	getR();
	getX();
	getR0();
	getX0();
	getB1();
	getB10();
	getB2();
	getB20();
	getG1();
	getG10();
	getG2();
	getG20();
	getLength();
	getName();
	getBus1Handle();
	getBus2Handle();
	getRelayGroup1Handle();
	getRelayGroup2Handle();
	getCktID();
	getLengthUnit();
	getOffDate();
	getOnDate();
	getType();
	getRatings();

	gfxObj = new OlxAPIGraphicsType5Obj(handle, TC_LINE);
}

OlxAPILineObj::~OlxAPILineObj()
{
	delete gfxObj;
}

double OlxAPILineObj::getB1()
{
	getDoubleParameter(LN_dB1, &dB1);
	return dB1;
}

int OlxAPILineObj::setB1(double value)
{
	dB1 = value;
	return setDoubleParameter(LN_dB1, &dB1);
}

double OlxAPILineObj::getB10()
{
	getDoubleParameter(LN_dB10, &dB10);
	return dB10;
}

int OlxAPILineObj::setB10(double value)
{
	dB10 = value;
	return setDoubleParameter(LN_dB10, &dB10);
}

double OlxAPILineObj::getB2()
{
	getDoubleParameter(LN_dB2, &dB2);
	return dB2;
}

int OlxAPILineObj::setB2(double value)
{
	dB2 = value;
	return setDoubleParameter(LN_dB2, &dB2);
}

double OlxAPILineObj::getB20()
{
	getDoubleParameter(LN_dB20, &dB20);
	return dB20;
}

int OlxAPILineObj::setB20(double value)
{
	dB20 = value;
	return setDoubleParameter(LN_dB20, &dB20);
}

double OlxAPILineObj::getG1()
{
	getDoubleParameter(LN_dG1, &dG1);
	return dG1;
}

int OlxAPILineObj::setG1(double value)
{
	dG1 = value;
	return setDoubleParameter(LN_dG1, &dG1);
}

double OlxAPILineObj::getG10()
{
	getDoubleParameter(LN_dG10, &dG10);
	return dG10;
}

int OlxAPILineObj::setG10(double value)
{
	dG10 = value;
	return setDoubleParameter(LN_dG10, &dG10);
}

double OlxAPILineObj::getG2()
{
	getDoubleParameter(LN_dG2, &dG2);
	return dG2;
}

int OlxAPILineObj::setG2(double value)
{
	dG2 = value;
	return setDoubleParameter(LN_dG2, &dG2);
}

double OlxAPILineObj::getG20()
{
	getDoubleParameter(LN_dG20, &dG20);
	return dG20;
}

int OlxAPILineObj::setG20(double value)
{
	dG20 = value;
	return setDoubleParameter(LN_dG20, &dG20);
}

double OlxAPILineObj::getR()
{
	getDoubleParameter(LN_dR, &dR);
	return dR;
}

int OlxAPILineObj::setR(double value)
{
	dR = value;
	return setDoubleParameter(LN_dR, &dR);
}

double OlxAPILineObj::getX()
{
	getDoubleParameter(LN_dX, &dX);
	return dX;
}

int OlxAPILineObj::setX(double value)
{
	dX = value;
	return setDoubleParameter(LN_dX, &dX);
}

double OlxAPILineObj::getR0()
{
	getDoubleParameter(LN_dR0, &dR0);
	return dR0;
}

int OlxAPILineObj::setR0(double value)
{
	dR0 = value;
	return setDoubleParameter(LN_dR0, &dR0);
}

double OlxAPILineObj::getX0()
{
	getDoubleParameter(LN_dX0, &dX0);
	return dX0;
}

int OlxAPILineObj::setX0(double value)
{
	dX0 = value;
	return setDoubleParameter(LN_dX0, &dX0);
}

double OlxAPILineObj::getLength()
{
	getDoubleParameter(LN_dLength, &dLength);
	return dLength;
}

int OlxAPILineObj::setLength(double value)
{
	dLength = value;
	return setDoubleParameter(LN_dLength, &dLength);
}

string OlxAPILineObj::getName()
{
	getStringParameter(LN_sName, &sName);
	return sName;
}

int OlxAPILineObj::setName(std::string& value)
{
	sName = value;
	return setStringParameter(LN_sName, &sName);
}

int OlxAPILineObj::getBus1Handle()
{
	getIntParameter(LN_nBus1Hnd, &nBus1Handle);
	return nBus1Handle;
}

int OlxAPILineObj::getBus2Handle()
{
	getIntParameter(LN_nBus2Hnd, &nBus2Handle);
	return nBus2Handle;
}

int OlxAPILineObj::getRelayGroup1Handle()
{
	getIntParameter(LN_nRlyGr1Hnd, &nRlyGr1Handle);
	return nRlyGr1Handle;
}

int OlxAPILineObj::getRelayGroup2Handle()
{
	getIntParameter(LN_nRlyGr2Hnd, &nRlyGr2Handle);
	return nRlyGr2Handle;
}

string OlxAPILineObj::getCktID()
{
	getStringParameter(LN_sID, &sCktID);
	return sCktID;
}

int OlxAPILineObj::setCktID(string& value)
{
	sCktID = value;
	return setStringParameter(LN_sID, &sCktID);
}

string OlxAPILineObj::getLengthUnit()
{
	getStringParameter(LN_sLengthUnit, &sLengthUnit);
	return sLengthUnit;
}

int OlxAPILineObj::setLengthUnit(string& value)
{
	sLengthUnit = value;
	return setStringParameter(LN_sLengthUnit, &sLengthUnit);
}

string OlxAPILineObj::getOffDate()
{
	getStringParameter(LN_sOffDate, &sOffDate);
	return sOffDate;
}

int OlxAPILineObj::setOffDate(string& value)
{
	sOffDate = value;
	return setStringParameter(LN_sOffDate, &sOffDate);
}

string OlxAPILineObj::getOnDate()
{
	getStringParameter(LN_sOnDate, &sOnDate);
	return sOnDate;
}

int OlxAPILineObj::setOnDate(string& value)
{
	sOnDate = value;
	return setStringParameter(LN_sOnDate, &sOnDate);
}

string OlxAPILineObj::getType()
{
	getStringParameter(LN_sType, &sType);
	return sType;
}

int OlxAPILineObj::setType(string& value)
{
	sType = value;
	return setStringParameter(LN_sType, &sType);
}

double* OlxAPILineObj::getRatings()
{
	getDoubleArrayParameter(LN_vdRating, dRatings, 4);
	return dRatings;
}

int OlxAPILineObj::setRatings(double* value)
{
	memcpy(dRatings, value, 4);
	return setDoubleArrayParameter(LN_vdRating, dRatings, 4);
}

int OlxAPILineObj::getBranchHandle()
{
	int nBranchHandle = 0;
	while (nBranchHandle >= 0)
	{
		int ret = OlxAPIGetEquipment(TC_BRANCH, &nBranchHandle);
		if (ret != OLXAPI_OK)
			break;

		int nEquipmentHandle = 0;
		ret = OlxAPIGetData(nBranchHandle, BR_nHandle, &nEquipmentHandle);
		if (nEquipmentHandle == getHandle())
			return nBranchHandle;
	}

	return -1;
}
