#include "OlxAPIBusObj.h"

#include "OlxAPIGraphicsObj.h"

OlxAPIBusObj::OlxAPIBusObj(int handle) : OlxAPIObj(handle)
{
	getKVNominal();
	getSPCx();
	getSPCy();
	getArea();
	getNumber();
	getSlack();
	getSubGroup();
	getTapBus();
	getVisible();
	getZone();
	getComment();
	getLocation();
	getName();
	gfxObj = new OlxAPIGraphicsType1Obj(handle, TC_BUS);
}

OlxAPIBusObj::~OlxAPIBusObj()
{
	delete gfxObj;
}

double OlxAPIBusObj::getKVNominal()
{
	getDoubleParameter(BUS_dKVnominal, &dKVNominal);
	return dKVNominal;
}

double OlxAPIBusObj::getSPCx()
{
	getDoubleParameter(BUS_dSPCx, &dSPCx);
	return dSPCx;
}

int OlxAPIBusObj::setSPCx(double value)
{
	dSPCx = value;
	return setDoubleParameter(BUS_dSPCx, &dSPCx);
}

double OlxAPIBusObj::getSPCy()
{
	getDoubleParameter(BUS_dSPCy, &dSPCy);
	return dSPCy;
}

int OlxAPIBusObj::setSPCy(double value)
{
	dSPCy = value;
	return setDoubleParameter(BUS_dSPCy, &dSPCy);
}

int OlxAPIBusObj::getArea()
{
	getIntParameter(BUS_nArea, &nArea);
	return nArea;
}

int OlxAPIBusObj::getNumber()
{
	getIntParameter(BUS_nNumber, &nNumber);
	return nNumber;
}

int OlxAPIBusObj::setNumber(int value)
{
	nNumber = value;
	return setIntParameter(BUS_nNumber, &nNumber);
}

int OlxAPIBusObj::getSlack()
{
	getIntParameter(BUS_nSlack, &nSlack);
	return nSlack;
}

int OlxAPIBusObj::setSlack(int value)
{
	nSlack = value;
	return setIntParameter(BUS_nSlack, &nSlack);
}

int OlxAPIBusObj::getSubGroup()
{
	getIntParameter(BUS_nSubGroup, &nSubGroup);
	return nSubGroup;
}

int OlxAPIBusObj::setSubGroup(int value)
{
	nSubGroup = value;
	return setIntParameter(BUS_nSubGroup, &nSubGroup);
}

int OlxAPIBusObj::getTapBus()
{
	getIntParameter(BUS_nTapBus, &nTapBus);
	return nTapBus;
}

int OlxAPIBusObj::setTapBus(int value)
{
	nTapBus = value;
	return setIntParameter(BUS_nTapBus, &nTapBus);
}

int OlxAPIBusObj::getVisible()
{
	getIntParameter(BUS_nVisible, &nVisible);
	return nVisible;
}

int OlxAPIBusObj::setVisible(int value)
{
	nVisible = value;
	return setIntParameter(BUS_nVisible, &nVisible);
}

int OlxAPIBusObj::getZone()
{
	getIntParameter(BUS_nZone, &nZone);
	return nZone;
}

int OlxAPIBusObj::setZone(int value)
{
	nZone = value;
	return setIntParameter(BUS_nZone, &nZone);
}

string OlxAPIBusObj::getComment()
{
	getStringParameter(BUS_sComment, &sComment);
	return sComment;
}

int OlxAPIBusObj::setComment(string& value)
{
	sComment = value;
	return setStringParameter(BUS_sComment, &sComment);
}

string OlxAPIBusObj::getLocation()
{
	getStringParameter(BUS_sLocation, &sLocation);
	return sLocation;
}

int OlxAPIBusObj::setLocation(string& value)
{
	sLocation = value;
	return setStringParameter(BUS_sLocation, &sLocation);
}

string OlxAPIBusObj::getName()
{
	getStringParameter(BUS_sName, &sName);
	return sName;
}

int OlxAPIBusObj::setName(string& value)
{
	sName = value;
	return setStringParameter(BUS_sName, &sName);
}
