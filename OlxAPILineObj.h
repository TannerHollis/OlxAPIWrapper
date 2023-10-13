#pragma once

#include "OlxAPIObj.h"

class OlxAPILineObj : public OlxAPIObj
{
public:
	OlxAPILineObj(int handle);

	double getB1();
	int setB1(double value);

	double getB10();
	int setB10(double value);

	double getB2();
	int setB2(double value);

	double getB20();
	int setB20(double value);

	double getG1();
	int setG1(double value);

	double getG10();
	int setG10(double value);

	double getG2();
	int setG2(double value);

	double getG20();
	int setG20(double value);

	double getR();
	int setR(double value);

	double getX();
	int setX(double value);

	double getR0();
	int setR0(double value);

	double getX0();
	int setX0(double value);

	double getLength();
	int setLength(double value);

	string getName();
	int setName(string& value);

	int getBus1Handle();
	int getBus2Handle();
	int getRelayGroup1Handle();
	int getRelayGroup2Handle();

	string getCktID();
	int setCktID(string& value);

	string getLengthUnit();
	int setLengthUnit(string& value);

	string getOutOfServiceDate();
	int setOutOfServiceDate(string& value);

	string getInServiceDate();
	int setInServiceDate(string& value);

	string getType();
	int setType(string& value);

	double* getRatings();
	int setRatings(double* value);

private:
	double dB1;
	double dB10;
	double dB2;
	double dB20;
	double dG1;
	double dG10;
	double dG2;
	double dG20;
	double dR;
	double dX;
	double dR0;
	double dX0;
	double dLength;
	int nBus1Handle;
	int nBus2Handle;
	int nRlyGr1Handle;
	int nRlyGr2Handle;
	string sCktID;
	string sLengthUnit;
	string sOffDate;
	string sOnDate;
	string sType;
	string sName;
	double dRatings[4];
};

