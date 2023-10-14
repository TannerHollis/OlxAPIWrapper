#pragma once

#include "OlxAPIObj.h"

class OlxAPIXFMRObj : public OlxAPIObj
{
public:
	typedef enum GroundingImpedance
	{
		GND_1 = 0,
		GND_2 = 1,
		GND_N = 3
	} GroundingImpedance;

	OlxAPIXFMRObj(int handle);

	double getB();
	int setB(double value);

	double getB0();
	int setB0(double value);

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

	double getGR(GroundingImpedance ground);
	int setGR(GroundingImpedance ground, double value);

	double getGX(GroundingImpedance winding);
	int setGX(GroundingImpedance winding, double value);

	double getBaseMVA();
	int setBaseMVA(double value);

	double getLTCStep();
	int setLTCStep(double value);

	double getMaxTap();
	int setMaxTap(double value);

	double getMaxVW();
	int setMaxVW(double value);

	double getMinTap();
	int setMinTap(double value);

	double getMinVW();
	int setMinVW(double value);

	double getMVAn(int index);
	int setMVAn(int index, double value);

	double getLTCCenterTap();
	int setLTCCenterTap(double value);

	int getAuto();
	int setAuto(int value);

	int getBus1Handle();
	int getBus2Handle();

	int getInService();
	int setInService(int value);

	int getLTCCtrlBusHandle();

	int getLTCGanged();
	int setLTCGanged(int value);

	int getLTCPriority();
	int setLTCPriority(int value);

	int getRelayGroup1Handle();
	int getRelayGroup2Handle();

	double getTap1();
	int setTap1(double value);

	double getTap2();
	int setTap2(double value);

	int getLTCSide();
	int setLTCSide(int value);

	int getLTCType();
	int setLTCType(int value);

	int getMeteredBusHandle();
	int setMeteredBusHandle(int value);

	string getWinding1Cfg();
	int setWinding1Cfg(string& value);

	string getWinding2Cfg();
	int setWinding2Cfg(string& value);

	string getWinding2CfgTest();
	int setWinding2CfgTest(string& value);

	string getCktID();

	string getName();
	int setName(string& value);

	string getOffDate();
	int setOffDate(string& value);

	string getOnDate();
	int setOnDate(string& value);

private:
	double dB;
	double dB0;
	double dB1;
	double dB10;
	double dB2;
	double dB20;
	double dG1;
	double dG10;
	double dG2;
	double dG20;
	double dBaseMVA;
	double dLTCCenterTap;
	double dLTCstep;
	double dMaxTap;
	double dMaxVW;
	double dMinTap;
	double dMinVW;
	double dMVAn[3];
	double dR;
	double dR0;
	double dRG1;
	double dRG2;
	double dRGn;
	double dTap1;
	double dTap2;
	double dX;
	double dX0;
	double dXG1;
	double dXG2;
	double dXGn;
	int nAuto;
	int nBus1Handle;
	int nBus2Handle;
	int nInService;
	int nLTCCtrlBusHandle;
	int nLTCGanged;
	int nLTCPriority;
	int nLTCside;
	int nLTCtype;
	int nMetered;
	int nRlyGr1Handle;
	int nRlyGr2Handle;
	string sCfg1;
	string sCfg2;
	string sCfg2T;
	string sID;
	string sName;
	string sOffDate;
	string sOnDate;
};

