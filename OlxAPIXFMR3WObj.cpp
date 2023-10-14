#include "OlxAPIXFMR3WObj.h"

OlxAPIXFMR3WObj::OlxAPIXFMR3WObj(int handle) : OlxAPIObj(handle)
{
    getBaseMVA();
    getLTCCenterTap();
    getB();
    getB0();
    getLTCStep();
    getMaxTap();
    getMaxVW();
    getMinTap();
    getMinVW();
    getMVAn(0); getMVAn(1); getMVAn(2);
    for (int i = 0; i < 4; i++)
    {
        if (i < 3)
        {
            getR((WindingImpedance)i);
            getX((WindingImpedance)i);
            getR0((WindingImpedance)i);
            getX0((WindingImpedance)i);
        }
        getGR((GroundingImpedance)i);
        getGX((GroundingImpedance)i);
    }
    getTap1();
    getTap2();
    getTap3();
    getAuto();
    getBus1Handle();
    getBus2Handle();
    getBus3Handle();
    getFicticiousBusNumber();
    getInService();
    getLTCGanged();
    getRelayGroup1Handle();
    getRelayGroup2Handle();
    getRelayGroup3Handle();
    getLTCSide();
    getLTCType();
    getWinding1Cfg();
    getWinding2Cfg();
    getWinding2CfgTest();
    getWinding3Cfg();
    getWinding3CfgTest();
    getCktID();
    getName();
    getOffDate();
    getOnDate();
}

double OlxAPIXFMR3WObj::getBaseMVA() {
    getDoubleParameter(X3_dBaseMVA, &dBaseMVA);
    return dBaseMVA;
}

int OlxAPIXFMR3WObj::setBaseMVA(double value) {
    dBaseMVA = value;
    return setDoubleParameter(X3_dBaseMVA, &dBaseMVA);
}

double OlxAPIXFMR3WObj::getLTCCenterTap() {
    getDoubleParameter(X3_dLTCCenterTap, &dLTCCenterTap);
    return dLTCCenterTap;
}

int OlxAPIXFMR3WObj::setLTCCenterTap(double value) {
    dLTCCenterTap = value;
    return setDoubleParameter(X3_dLTCCenterTap, &dLTCCenterTap);
}

double OlxAPIXFMR3WObj::getR(WindingImpedance winding)
{
    switch (winding)
    {
    case PS:
        getDoubleParameter(X3_dRps, &dRps);
        return dRps;

    case PT:
        getDoubleParameter(X3_dRpt, &dRpt);
        return dRpt;

    case ST:
        getDoubleParameter(X3_dRst, &dRst);
        return dRst;
    }

    return -1;
}

int OlxAPIXFMR3WObj::setR(WindingImpedance winding, double value)
{
    switch (winding)
    {
    case PS:
        dRps = value;
        return setDoubleParameter(X3_dRps, &dRps);

    case PT:
        dRpt = value;
        return setDoubleParameter(X3_dRpt, &dRpt);

    case ST:
        dRst = value;
        return setDoubleParameter(X3_dRst, &dRst);
    }

    return OLXAPI_FAILURE;
}

double OlxAPIXFMR3WObj::getX(WindingImpedance winding)
{
    switch (winding)
    {
    case PS:
        getDoubleParameter(X3_dXps, &dXps);
        return dXps;

    case PT:
        getDoubleParameter(X3_dXpt, &dXpt);
        return dXpt;

    case ST:
        getDoubleParameter(X3_dXst, &dXst);
        return dXst;
    }

    return -1;
}

int OlxAPIXFMR3WObj::setX(WindingImpedance winding, double value)
{
    switch (winding)
    {
    case PS:
        dXps = value;
        return setDoubleParameter(X3_dXps, &dXps);

    case PT:
        dXpt = value;
        return setDoubleParameter(X3_dXpt, &dXpt);

    case ST:
        dXst = value;
        return setDoubleParameter(X3_dXst, &dXst);
    }

    return OLXAPI_FAILURE;
}

double OlxAPIXFMR3WObj::getR0(WindingImpedance winding)
{
    switch (winding)
    {
    case PS:
        getDoubleParameter(X3_dR0ps, &dR0ps);
        return dR0ps;

    case PT:
        getDoubleParameter(X3_dR0pt, &dR0pt);
        return dR0pt;

    case ST:
        getDoubleParameter(X3_dR0st, &dR0st);
        return dR0st;
    }

    return -1;
}

int OlxAPIXFMR3WObj::setR0(WindingImpedance winding, double value)
{
    switch (winding)
    {
    case PS:
        dR0ps = value;
        return setDoubleParameter(X3_dR0ps, &dR0ps);

    case PT:
        dRpt = value;
        return setDoubleParameter(X3_dR0pt, &dR0pt);

    case ST:
        dR0st = value;
        return setDoubleParameter(X3_dR0st, &dR0st);
    }
    return OLXAPI_FAILURE;
}

double OlxAPIXFMR3WObj::getX0(WindingImpedance winding)
{
    switch (winding)
    {
    case PS:
        getDoubleParameter(X3_dX0ps, &dX0ps);
        return dX0ps;

    case PT:
        getDoubleParameter(X3_dX0pt, &dX0pt);
        return dX0pt;

    case ST:
        getDoubleParameter(X3_dX0st, &dX0st);
        return dX0st;
    }

    return -1;
}

int OlxAPIXFMR3WObj::setX0(WindingImpedance winding, double value)
{
    switch (winding)
    {
    case PS:
        dX0ps = value;
        return setDoubleParameter(X3_dX0ps, &dX0ps);

    case PT:
        dX0pt = value;
        return setDoubleParameter(X3_dX0pt, &dX0pt);

    case ST:
        dX0st = value;
        return setDoubleParameter(X3_dX0st, &dX0st);
    }

    return OLXAPI_FAILURE;
}

double OlxAPIXFMR3WObj::getGR(GroundingImpedance winding)
{
    switch (winding)
    {
    case GND_1:
        getDoubleParameter(X3_dRG1, &dRG1);
        return dRG1;

    case GND_2:
        getDoubleParameter(X3_dRG2, &dRG2);
        return dRG2;

    case GND_3:
        getDoubleParameter(X3_dRG3, &dRG3);
        return dRG3;

    case GND_N:
        getDoubleParameter(X3_dRGN, &dRGn);
        return dRGn;
    }

    return -1;
}

int OlxAPIXFMR3WObj::setGR(GroundingImpedance winding, double value)
{
    switch (winding)
    {
    case GND_1:
        dRG1 = value;
        return setDoubleParameter(X3_dRG1, &dRG1);

    case GND_2:
        dRG2 = value;
        return setDoubleParameter(X3_dRG2, &dRG2);

    case GND_3:
        dRG3 = value;
        return setDoubleParameter(X3_dRG3, &dRG3);

    case GND_N:
        dRGn = value;
        return setDoubleParameter(X3_dRGN, &dRGn);
    }

    return OLXAPI_FAILURE;
}

double OlxAPIXFMR3WObj::getGX(GroundingImpedance winding)
{
    switch (winding)
    {
    case GND_1:
        getDoubleParameter(X3_dXG1, &dXG1);
        return dXG1;

    case GND_2:
        getDoubleParameter(X3_dXG2, &dXG2);
        return dXG2;

    case GND_3:
        getDoubleParameter(X3_dXG3, &dXG3);
        return dXG3;

    case GND_N:
        getDoubleParameter(X3_dXGN, &dXGn);
        return dXGn;
    }

    return -1;
}

int OlxAPIXFMR3WObj::setGX(GroundingImpedance winding, double value)
{
    switch (winding)
    {
    case GND_1:
        dXG1 = value;
        return setDoubleParameter(X3_dXG1, &dXG1);

    case GND_2:
        dXG2 = value;
        return setDoubleParameter(X3_dXG2, &dXG2);

    case GND_3:
        dXG3 = value;
        return setDoubleParameter(X3_dXG3, &dXG3);

    case GND_N:
        dXGn = value;
        return setDoubleParameter(X3_dXGN, &dXGn);
    }

    return OLXAPI_FAILURE;
}

double OlxAPIXFMR3WObj::getB() {
    getDoubleParameter(X3_dB, &dB);
    return dB;
}

int OlxAPIXFMR3WObj::setB(double value) {
    dB = value;
    return setDoubleParameter(X3_dB, &dB);
}

double OlxAPIXFMR3WObj::getB0() {
    getDoubleParameter(X3_dB0, &dB0);
    return dB0;
}

int OlxAPIXFMR3WObj::setB0(double value) {
    dB0 = value;
    return setDoubleParameter(X3_dB0, &dB0);
}

double OlxAPIXFMR3WObj::getLTCStep() {
    getDoubleParameter(X3_dLTCstep, &dLTCstep);
    return dLTCstep;
}

int OlxAPIXFMR3WObj::setLTCStep(double value) {
    dLTCstep = value;
    return setDoubleParameter(X3_dLTCstep, &dLTCstep);
}

double OlxAPIXFMR3WObj::getMaxTap() {
    getDoubleParameter(X3_dMaxTap, &dMaxTap);
    return dMaxTap;
}

int OlxAPIXFMR3WObj::setMaxTap(double value) {
    dMaxTap = value;
    return setDoubleParameter(X3_dMaxTap, &dMaxTap);
}

double OlxAPIXFMR3WObj::getMaxVW() {
    getDoubleParameter(X3_dMaxVW, &dMaxVW);
    return dMaxVW;
}

int OlxAPIXFMR3WObj::setMaxVW(double value) {
    dMaxVW = value;
    return setDoubleParameter(X3_dMaxVW, &dMaxVW);
}

double OlxAPIXFMR3WObj::getMinTap() {
    getDoubleParameter(X3_dMinTap, &dMinTap);
    return dMinTap;
}

int OlxAPIXFMR3WObj::setMinTap(double value) {
    dMinTap = value;
    return setDoubleParameter(X3_dMinTap, &dMinTap);
}

double OlxAPIXFMR3WObj::getMinVW() {
    getDoubleParameter(X3_dMinVW, &dMinVW);
    return dMinVW;
}

int OlxAPIXFMR3WObj::setMinVW(double value) {
    dMinVW = value;
    return setDoubleParameter(X3_dMinVW, &dMinVW);
}

double OlxAPIXFMR3WObj::getMVAn(int index) {
    switch (index)
    {
    case 0:
        getDoubleParameter(X3_dMVA1, &dMVAn[0]);
        return dMVAn[0];

    case 1:
        getDoubleParameter(X3_dMVA2, &dMVAn[1]);
        return dMVAn[1];

    case 2:
        getDoubleParameter(X3_dMVA3, &dMVAn[2]);
        return dMVAn[2];
    }
    
    return 0;
}

int OlxAPIXFMR3WObj::setMVAn(int index, double value) {
    switch (index)
    {
    case 0:
        dMVAn[0] = value;
        return setDoubleParameter(X3_dMVA1, &dMVAn[0]);

    case 1:
        dMVAn[1] = value;
        return setDoubleParameter(X3_dMVA2, &dMVAn[1]);

    case 2:
        dMVAn[2] = value;
        return setDoubleParameter(X3_dMVA3, &dMVAn[2]);
    }

    return 0;
}

double OlxAPIXFMR3WObj::getTap1() {
    getDoubleParameter(X3_dTap1, &dTap1);
    return dTap1;
}

int OlxAPIXFMR3WObj::setTap1(double value) {
    dTap1 = value;
    return setDoubleParameter(X3_dTap1, &dTap1);
}

double OlxAPIXFMR3WObj::getTap2() {
    getDoubleParameter(X3_dTap2, &dTap2);
    return dTap2;
}

int OlxAPIXFMR3WObj::setTap2(double value) {
    dTap2 = value;
    return setDoubleParameter(X3_dTap2, &dTap2);
}

double OlxAPIXFMR3WObj::getTap3() {
    getDoubleParameter(X3_dTap2, &dTap2);
    return dTap2;
}

int OlxAPIXFMR3WObj::setTap3(double value) {
    dTap3 = value;
    return setDoubleParameter(X3_dTap3, &dTap3);
}

int OlxAPIXFMR3WObj::getAuto() {
    getIntParameter(X3_nAuto, &nAuto);
    return nAuto;
}

int OlxAPIXFMR3WObj::setAuto(int value) {
    nAuto = value;
    return setIntParameter(X3_nAuto, &nAuto);
}

int OlxAPIXFMR3WObj::getBus1Handle() {
    getIntParameter(X3_nBus1Hnd, &nBus1Handle);
    return nBus1Handle;
}

int OlxAPIXFMR3WObj::getBus2Handle() {
    getIntParameter(X3_nBus2Hnd, &nBus2Handle);
    return nBus2Handle;
}

int OlxAPIXFMR3WObj::getBus3Handle() {
    getIntParameter(X3_nBus3Hnd, &nBus3Handle);
    return nBus3Handle;
}

int OlxAPIXFMR3WObj::getFicticiousBusNumber() {
    getIntParameter(X3_nFictBusNo, &nFicticiousBusHandle);
    return nFicticiousBusHandle;
}

int OlxAPIXFMR3WObj::getInService() {
    getIntParameter(X3_nInService, &nInService);
    return nInService;
}

int OlxAPIXFMR3WObj::setInService(int value) {
    nInService = value;
    return setIntParameter(X3_nInService, &nInService);
}

int OlxAPIXFMR3WObj::getLTCGanged() {
    getIntParameter(X3_nLTCGanged, &nLTCGanged);
    return nLTCGanged;
}

int OlxAPIXFMR3WObj::setLTCGanged(int value) {
    nLTCGanged = value;
    return setIntParameter(X3_nLTCGanged, &nLTCGanged);
}

int OlxAPIXFMR3WObj::getRelayGroup1Handle() {
    getIntParameter(X3_nRlyGr1Hnd, &nRlyGr1Handle);
    return nRlyGr1Handle;
}

int OlxAPIXFMR3WObj::getRelayGroup2Handle() {
    getIntParameter(X3_nRlyGr2Hnd, &nRlyGr2Handle);
    return nRlyGr2Handle;
}

int OlxAPIXFMR3WObj::getRelayGroup3Handle() {
    getIntParameter(X3_nRlyGr3Hnd, &nRlyGr3Handle);
    return nRlyGr3Handle;
}

int OlxAPIXFMR3WObj::getLTCSide()
{
    getIntParameter(X3_nLTCside, &nLTCside);
    return nLTCside;
}

int OlxAPIXFMR3WObj::setLTCSide(int value) {
    nLTCside = value;
    return setIntParameter(X3_nLTCside, &nLTCside);
}

int OlxAPIXFMR3WObj::getLTCType()
{
    getIntParameter(X3_nLTCtype, &nLTCtype);
    return nLTCtype;
}

int OlxAPIXFMR3WObj::setLTCType(int value) {
    nLTCtype = value;
    return setIntParameter(X3_nLTCtype, &nLTCtype);
}

string OlxAPIXFMR3WObj::getWinding1Cfg()
{
    getStringParameter(X3_sCfg1, &sCfg1);
    return sCfg1;
}

int OlxAPIXFMR3WObj::setWinding1Cfg(string& value)
{
    sCfg1 = value;
    return setStringParameter(X3_sCfg1, &sCfg1);
}

string OlxAPIXFMR3WObj::getWinding2Cfg()
{
    getStringParameter(X3_sCfg2, &sCfg2);
    return sCfg2;
}

int OlxAPIXFMR3WObj::setWinding2Cfg(string& value)
{
    sCfg2 = value;
    return setStringParameter(X3_sCfg2, &sCfg2);
}

string OlxAPIXFMR3WObj::getWinding3Cfg()
{
    getStringParameter(X3_sCfg3, &sCfg3);
    return sCfg3;
}

int OlxAPIXFMR3WObj::setWinding3Cfg(string& value)
{
    sCfg3 = value;
    return setStringParameter(X3_sCfg3, &sCfg3);
}

string OlxAPIXFMR3WObj::getWinding2CfgTest()
{
    getStringParameter(X3_sCfg2T, &sCfg2T);
    return sCfg2T;
}

int OlxAPIXFMR3WObj::setWinding2CfgTest(string& value)
{
    sCfg2T = value;
    return setStringParameter(X3_sCfg2T, &sCfg2T);
}

string OlxAPIXFMR3WObj::getWinding3CfgTest()
{
    getStringParameter(X3_sCfg3T, &sCfg3T);
    return sCfg3T;
}

int OlxAPIXFMR3WObj::setWinding3CfgTest(string& value)
{
    sCfg3T = value;
    return setStringParameter(X3_sCfg3T, &sCfg3T);
}

string OlxAPIXFMR3WObj::getCktID()
{
    getStringParameter(X3_sID, &sID);
    return sID;
}

string OlxAPIXFMR3WObj::getName()
{
    getStringParameter(X3_sName, &sName);
    return sName;
}

int OlxAPIXFMR3WObj::setName(string& value)
{
    sName = value;
    return setStringParameter(X3_sName, &sName);
}

string OlxAPIXFMR3WObj::getOffDate()
{
    getStringParameter(X3_sOffDate, &sOffDate);
    return sOffDate;
}

int OlxAPIXFMR3WObj::setOffDate(string& value)
{
    sOffDate = value;
    return setStringParameter(X3_sOffDate, &sOffDate);
}

string OlxAPIXFMR3WObj::getOnDate()
{
    getStringParameter(X3_sOnDate, &sOnDate);
    return sOnDate;
}

int OlxAPIXFMR3WObj::setOnDate(string& value)
{
    sOnDate = value;
    return setStringParameter(X3_sOnDate, &sOnDate);
}