#include "OlxAPISeriesReactorObj.h"

OlxAPISeriesReactorObj::OlxAPISeriesReactorObj(int handle) : OlxAPIObj(handle)
{
	getProtectiveLevelCurrent();
	getR();
	getX();
	getBus1Handle();
	getBus2Handle();
	getInService();
	getRelayGroup1Handle();
	getRelayGroup2Handle();
	getCktID();
	getName();
	getOffDate();
	getOnDate();
}

double OlxAPISeriesReactorObj::getProtectiveLevelCurrent()
{
	getDoubleParameter(SC_dIpr, &dIpr);
	return dIpr;
}

int OlxAPISeriesReactorObj::setProtectiveLevelCurrent(double value)
{
	dIpr = value;
	return setDoubleParameter(SC_dIpr, &dIpr);
}

double OlxAPISeriesReactorObj::getR()
{
	getDoubleParameter(SC_dR, &dR);
	return dR;
}

int OlxAPISeriesReactorObj::setR(double value)
{
	dR = value;
	return setDoubleParameter(SC_dR, &dR);
}

double OlxAPISeriesReactorObj::getX()
{
	getDoubleParameter(SC_dX, &dX);
	return dX;
}

int OlxAPISeriesReactorObj::setX(double value)
{
	dX = value;
	return setDoubleParameter(SC_dR, &dX);
}

int OlxAPISeriesReactorObj::getBus1Handle()
{
	getIntParameter(SC_nBus1Hnd, &nBus1Handle);
	return nBus1Handle;
}

int OlxAPISeriesReactorObj::getBus2Handle()
{
	getIntParameter(SC_nBus2Hnd, &nBus2Handle);
	return nBus2Handle;
}

int OlxAPISeriesReactorObj::getInService()
{
	getIntParameter(SC_nInService, &nInService);
	return nInService;
}

int OlxAPISeriesReactorObj::setInService(int value)
{
	nInService = value;
	return setIntParameter(SC_nInService, &nInService);
}

int OlxAPISeriesReactorObj::getRelayGroup1Handle()
{
	getIntParameter(SC_nRlyGr1Hnd, &nRelayGroup1Handle);
	return nRelayGroup1Handle;
}

int OlxAPISeriesReactorObj::getRelayGroup2Handle()
{
	getIntParameter(SC_nRlyGr2Hnd, &nRelayGroup2Handle);
	return nRelayGroup2Handle;
}

string OlxAPISeriesReactorObj::getCktID()
{
	getStringParameter(SC_sID, &sID);
	return sID;
}

string OlxAPISeriesReactorObj::getName()
{
	getStringParameter(SC_sName, &sName);
	return sName;
}

int OlxAPISeriesReactorObj::setName(string& value)
{
	sName = value;
	return setStringParameter(SC_sName, &sName);
}

string OlxAPISeriesReactorObj::getOffDate()
{
	getStringParameter(SC_sOffDate, &sOffDate);
	return sOffDate;
}

int OlxAPISeriesReactorObj::setOffDate(string& value)
{
	sOffDate = value;
	return setStringParameter(SC_sOffDate, &sOffDate);
}

string OlxAPISeriesReactorObj::getOnDate()
{
	getStringParameter(SC_sOnDate, &sOnDate);
	return sOnDate;
}

int OlxAPISeriesReactorObj::setOnDate(string& value)
{
	sOnDate = value;
	return setStringParameter(SC_sOnDate, &sOnDate);
}