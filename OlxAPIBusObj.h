#pragma once

#include "OlxAPIObj.h"
#include "OlxAPIGraphicsType1Obj.h"

class OlxAPIBusObj : public OlxAPIObj
{
public:
	OlxAPIBusObj(int handle);
	~OlxAPIBusObj();

	double getKVNominal();

	double getSPCx();
	int setSPCx(double value);

	double getSPCy();
	int setSPCy(double value);

	int getArea();

	int getNumber();
	int setNumber(int value);

	int getSlack();
	int setSlack(int value);

	int getSubGroup();
	int setSubGroup(int value);

	int getTapBus();
	int setTapBus(int value);

	int getVisible();
	int setVisible(int value);

	int getZone();
	int setZone(int value);

	string getComment();
	int setComment(string& value);

	string getLocation();
	int setLocation(string& value);

	string getName();
	int setName(string& value);

	OlxAPIGraphicsType1Obj* gfxObj;

private:
	double dKVNominal;
	double dSPCx;
	double dSPCy;
	int nArea;
	int nNumber;
	int nSlack;
	int nSubGroup;
	int nTapBus;
	int nVisible;
	int nZone;
	string sComment;
	string sLocation;
	string sName;
};

