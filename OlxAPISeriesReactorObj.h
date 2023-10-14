#pragma once

#include "OlxAPIObj.h"

class OlxAPISeriesReactorObj : public OlxAPIObj
{
public:
	OlxAPISeriesReactorObj(int handle);

	double getProtectiveLevelCurrent();
	int setProtectiveLevelCurrent(double value);

	double getR();
	int setR(double value);

	double getX();
	int setX(double value);

	int getBus1Handle();
	int getBus2Handle();

	int getInService();
	int setInService(int value);

	int getRelayGroup1Handle();
	int getRelayGroup2Handle();

	string getCktID();

	string getName();
	int setName(string& value);

	string getOffDate();
	int setOffDate(string& value);

	string getOnDate();
	int setOnDate(string& value);

private:
	double dIpr;
	double dR;
	double dX;
	int nBus1Handle;
	int nBus2Handle;
	int nInService;
	int nRelayGroup1Handle;
	int nRelayGroup2Handle;
	string sID;
	string sName;
	string sOffDate;
	string sOnDate;
};

