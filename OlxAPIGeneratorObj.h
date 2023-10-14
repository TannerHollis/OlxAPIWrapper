#pragma once

#include "OlxAPIObj.h"
#include "OlxAPIGraphicsType2Obj.h"

class OlxAPIGeneratorObj : public OlxAPIObj
{
public:
	typedef enum GeneratorImpedance
	{
		GEN_SUBTRANSIENT = 0,
		GEN_SYNCHRONOUS = 1,
		GEN_TRANSIENT = 2,
		GEN_NEG_SEQ = 3,
		GEN_ZERO_SEQ = 4
	}GeneratorImpedance;

	OlxAPIGeneratorObj(int handle);

	~OlxAPIGeneratorObj();

	double getMVARating();
	int setMVARating(double value);

	double getPMax();
	int setPMax(double value);

	double getPMin();
	int setPMin(double value);

	double getQMax();
	int setQMax(double value);

	double getQMin();
	int setQMin(double value);

	double getRz();
	int setRz(double value);

	double getXz();
	int setXz(double value);

	double getScheduledP();
	int setScheduledP(double value);

	double getScheduledQ();
	int setScheduledQ(double value);

	int getOnline();
	int setOnline(int value);

	int getGeneratorHandle();
	
	string getGenID();

	string getOffDate();
	int setOffDate(string& value);

	string getOnDate();
	int setOnDate(string& value);

	double getR(GeneratorImpedance impedance);
	int setR(GeneratorImpedance impedance, double value);

	double getX(GeneratorImpedance impedance);
	int setX(GeneratorImpedance impedance, double value);

	OlxAPIGraphicsType2Obj* gfxObj;

private:
	double dMVARating;
	double dPmax;
	double dPmin;
	double dQmax;
	double dQmin;
	double dRz;
	double dXz;
	double dSchedP;
	double dSchedQ;
	int nOnline;
	int nGenUnitHandle;
	string sID;
	string sOffDate;
	string sOnDate;
	double dR[5]; // Subtransient, synchronous, transient, negative, zero sequence
	double dX[5]; // Subtransient, synchronous, transient, negative, zero sequence
};

