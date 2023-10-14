#pragma once

#include "OlxAPIObj.h"
#include "OlxAPIGraphicsType4Obj.h"

class OlxAPIXFMR3WObj : public OlxAPIObj
{
public:
	typedef enum WindingImpedance
	{
		PS = 0, // Primary to Secondary
		PT = 1, // Primary to Tertiary
		ST = 2 // Secondary to Tertiary
	}WindingImpedance;

	typedef enum GroundingImpedance
	{
		GND_1 = 0,
		GND_2 = 1,
		GND_3 = 2,
		GND_N = 3
	} GroundingImpedance;

	OlxAPIXFMR3WObj(int handle);
	~OlxAPIXFMR3WObj();

	double getBaseMVA();
	int setBaseMVA(double value);

	double getR(WindingImpedance winding);
	int setR(WindingImpedance winding, double value);

	double getX(WindingImpedance winding);
	int setX(WindingImpedance winding, double value);
	
	double getR0(WindingImpedance winding);
	int setR0(WindingImpedance winding, double value);

	double getX0(WindingImpedance winding);
	int setX0(WindingImpedance winding, double value);

	double getGR(GroundingImpedance ground);
	int setGR(GroundingImpedance ground, double value);

	double getGX(GroundingImpedance winding);
	int setGX(GroundingImpedance winding, double value);

	double getB();
	int setB(double value);

	double getB0();
	int setB0(double value);

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
	int getBus3Handle();
	int getFicticiousBusNumber();

	int getInService();
	int setInService(int value);

	int getLTCGanged();
	int setLTCGanged(int value);

	int getRelayGroup1Handle();
	int getRelayGroup2Handle();
	int getRelayGroup3Handle();

	double getTap1();
	int setTap1(double value);

	double getTap2();
	int setTap2(double value);

	double getTap3();
	int setTap3(double value);

	int getLTCSide();
	int setLTCSide(int value);

	int getLTCType();
	int setLTCType(int value);

	string getWinding1Cfg();
	int setWinding1Cfg(string& value);

	string getWinding2Cfg();
	int setWinding2Cfg(string& value);

	string getWinding3Cfg();
	int setWinding3Cfg(string& value);

	string getWinding2CfgTest();
	int setWinding2CfgTest(string& value);

	string getWinding3CfgTest();
	int setWinding3CfgTest(string& value);

	string getCktID();

	string getName();
	int setName(string& value);

	string getOffDate();
	int setOffDate(string& value);

	string getOnDate();
	int setOnDate(string& value);

	OlxAPIGraphicsType4Obj* gfxObj;

private:
	double dBaseMVA;
	double dLTCCenterTap;
	double dB;
	double dB0;
	double dLTCstep;
	double dMaxTap;
	double dMaxVW;
	double dMinTap;
	double dMinVW;
	double dMVAn[3];
	double dR0ps;
	double dR0pt;
	double dR0st;
	double dRG1;
	double dRG2;
	double dRG3;
	double dRGn;
	double dRps;
	double dRpt;
	double dRst;
	double dTap1;
	double dTap2;
	double dTap3;
	double dX0ps;
	double dX0pt;
	double dX0st;
	double dXG1;
	double dXG2;
	double dXG3;
	double dXGn;
	double dXps;
	double dXpt;
	double dXst;
	int nAuto;
	int nBus1Handle;
	int nBus2Handle;
	int nBus3Handle;
	int nFicticiousBusHandle;
	int nInService;
	int nLTCGanged;
	int nRlyGr1Handle;
	int nRlyGr2Handle;
	int nRlyGr3Handle;
	int nLTCside;
	int nLTCtype;
	string sCfg1;
	string sCfg2;
	string sCfg2T;
	string sCfg3;
	string sCfg3T;
	string sID;
	string sName;
	string sOffDate;
	string sOnDate;
};

