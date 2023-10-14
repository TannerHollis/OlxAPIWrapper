#pragma once

#include "OlxAPIObj.h"
#include "OlxAPIGraphicsType2Obj.h"

class OlxAPIShuntCapacitorObj : public OlxAPIObj
{
public:
	OlxAPIShuntCapacitorObj(int handle);
	~OlxAPIShuntCapacitorObj();

	double getB();
	int setB(double value);

	double getB0();
	int setB0(double value);

	double getG();
	int setG(double value);

	double getG0();
	int setG0(double value);

	int get3WFlag();

	int getOnline();
	int setOnline(int value);

	int getShuntHandle();

	string getCktID();

	OlxAPIGraphicsType2Obj* gfxObj;

private:
	double dB;
	double dB0;
	double dG;
	double dG0;
	int n3WX;
	int nOnline;
	int nShuntHandle;
	string sID;
};

