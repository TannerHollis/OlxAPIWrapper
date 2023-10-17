#include "OlxAPIXFMRObj.h"

OlxAPIXFMRObj::OlxAPIXFMRObj(int handle) : OlxAPIBranchObj(handle)
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
    getR();
    getX();
    getR0();
    getX0();
    getMVAn(0); getMVAn(1); getMVAn(2);
    for (int i = 0; i < 3; i++)
    {
        getGR((GroundingImpedance)i);
        getGX((GroundingImpedance)i);
    }
    getTap1();
    getTap2();
    getAuto();
    getBus1Handle();
    getBus2Handle();
    getInService();
    getLTCGanged();
    getLTCCtrlBusHandle();
    getRelayGroup1Handle();
    getRelayGroup2Handle();
    getLTCSide();
    getLTCType();
    getWinding1Cfg();
    getWinding2Cfg();
    getWinding2CfgTest();
    getCktID();
    getName();
    getOffDate();
    getOnDate();
    gfxObj = new OlxAPIGraphicsType3Obj(handle, TC_XFMR);
}

OlxAPIXFMRObj::~OlxAPIXFMRObj()
{
    delete gfxObj;
}

double OlxAPIXFMRObj::getB() {
    getDoubleParameter(XR_dB, &dB);
    return dB;
}

int OlxAPIXFMRObj::setB(double value) {
    dB = value;
    return setDoubleParameter(XR_dB, &dB);
}

double OlxAPIXFMRObj::getB0() {
    getDoubleParameter(XR_dB0, &dB0);
    return dB0;
}

int OlxAPIXFMRObj::setB0(double value) {
    dB0 = value;
    return setDoubleParameter(XR_dB0, &dB0);
}

double OlxAPIXFMRObj::getB1() {
    getDoubleParameter(XR_dB1, &dB1);
    return dB1;
}

int OlxAPIXFMRObj::setB1(double value) {
    dB1 = value;
    return setDoubleParameter(XR_dB1, &dB1);
}

double OlxAPIXFMRObj::getB10() {
    getDoubleParameter(XR_dB10, &dB10);
    return dB10;
}

int OlxAPIXFMRObj::setB10(double value) {
    dB10 = value;
    return setDoubleParameter(XR_dB10, &dB10);
}

double OlxAPIXFMRObj::getB2() {
    getDoubleParameter(XR_dB2, &dB2);
    return dB2;
}

int OlxAPIXFMRObj::setB2(double value) {
    dB2 = value;
    return setDoubleParameter(XR_dB2, &dB2);
}

double OlxAPIXFMRObj::getB20() {
    getDoubleParameter(XR_dB20, &dB20);
    return dB20;
}

int OlxAPIXFMRObj::setB20(double value) {
    dB20 = value;
    return setDoubleParameter(XR_dB20, &dB20);
}

double OlxAPIXFMRObj::getG1() {
    getDoubleParameter(XR_dG1, &dG1);
    return dG1;
}

int OlxAPIXFMRObj::setG1(double value) {
    dG1 = value;
    return setDoubleParameter(XR_dG1, &dG1);
}

double OlxAPIXFMRObj::getG10() {
    getDoubleParameter(XR_dG10, &dG10);
    return dG10;
}

int OlxAPIXFMRObj::setG10(double value) {
    dG10 = value;
    return setDoubleParameter(XR_dG10, &dG10);
}

double OlxAPIXFMRObj::getG2() {
    getDoubleParameter(XR_dG2, &dG2);
    return dG2;
}

int OlxAPIXFMRObj::setG2(double value) {
    dG2 = value;
    return setDoubleParameter(XR_dG2, &dG2);
}

double OlxAPIXFMRObj::getG20() {
    getDoubleParameter(XR_dG20, &dG20);
    return dG20;
}

int OlxAPIXFMRObj::setG20(double value) {
    dG20 = value;
    return setDoubleParameter(XR_dG20, &dG20);
}

double OlxAPIXFMRObj::getBaseMVA() {
    getDoubleParameter(XR_dBaseMVA, &dBaseMVA);
    return dBaseMVA;
}

int OlxAPIXFMRObj::setBaseMVA(double value) {
    dBaseMVA = value;
    return setDoubleParameter(XR_dBaseMVA, &dBaseMVA);
}

double OlxAPIXFMRObj::getLTCCenterTap() {
    getDoubleParameter(XR_dLTCCenterTap, &dLTCCenterTap);
    return dLTCCenterTap;
}

int OlxAPIXFMRObj::setLTCCenterTap(double value) {
    dLTCCenterTap = value;
    return setDoubleParameter(XR_dLTCCenterTap, &dLTCCenterTap);
}

double OlxAPIXFMRObj::getLTCStep() {
    getDoubleParameter(XR_dLTCstep, &dLTCstep);
    return dLTCstep;
}

int OlxAPIXFMRObj::setLTCStep(double value) {
    dLTCstep = value;
    return setDoubleParameter(XR_dLTCstep, &dLTCstep);
}

double OlxAPIXFMRObj::getMaxTap() {
    getDoubleParameter(XR_dMaxTap, &dMaxTap);
    return dMaxTap;
}

int OlxAPIXFMRObj::setMaxTap(double value) {
    dMaxTap = value;
    return setDoubleParameter(XR_dMaxTap, &dMaxTap);
}

double OlxAPIXFMRObj::getMinTap() {
    getDoubleParameter(XR_dMinTap, &dMinTap);
    return dMinTap;
}

int OlxAPIXFMRObj::setMinTap(double value) {
    dMinTap = value;
    return setDoubleParameter(XR_dMinTap, &dMinTap);
}

double OlxAPIXFMRObj::getMaxVW() {
    getDoubleParameter(XR_dMaxVW, &dMaxVW);
    return dMaxVW;
}

int OlxAPIXFMRObj::setMaxVW(double value) {
    dMaxVW = value;
    return setDoubleParameter(XR_dMaxVW, &dMaxVW);
}

double OlxAPIXFMRObj::getMinVW() {
    getDoubleParameter(XR_dMinVW, &dMinVW);
    return dMinVW;
}

int OlxAPIXFMRObj::setMinVW(double value) {
    dMinVW = value;
    return setDoubleParameter(XR_dMinVW, &dMinVW);
}

double OlxAPIXFMRObj::getMVAn(int index) {
    switch (index)
    {
    case 0:
        getDoubleParameter(XR_dMVA1, &dMVAn[0]);
        return dMVAn[0];

    case 1:
        getDoubleParameter(XR_dMVA2, &dMVAn[1]);
        return dMVAn[1];

    case 2:
        getDoubleParameter(XR_dMVA3, &dMVAn[2]);
        return dMVAn[2];
    }

    return 0;
}

int OlxAPIXFMRObj::setMVAn(int index, double value) {
    switch (index)
    {
    case 0:
        dMVAn[0] = value;
        return setDoubleParameter(XR_dMVA1, &dMVAn[0]);

    case 1:
        dMVAn[1] = value;
        return setDoubleParameter(XR_dMVA2, &dMVAn[1]);

    case 2:
        dMVAn[2] = value;
        return setDoubleParameter(XR_dMVA3, &dMVAn[2]);
    }

    return 0;
}

double OlxAPIXFMRObj::getR() {
    getDoubleParameter(XR_dR, &dR);
    return dR;
}

int OlxAPIXFMRObj::setR(double value) {
    dR = value;
    return setDoubleParameter(XR_dR, &dR);
}

double OlxAPIXFMRObj::getX() {
    getDoubleParameter(XR_dX, &dX);
    return dX;
}

int OlxAPIXFMRObj::setX(double value) {
    dX = value;
    return setDoubleParameter(XR_dX, &dX);
}

double OlxAPIXFMRObj::getR0() {
    getDoubleParameter(XR_dR0, &dR0);
    return dR0;
}

int OlxAPIXFMRObj::setR0(double value) {
    dR0 = value;
    return setDoubleParameter(XR_dR0, &dR0);
}

double OlxAPIXFMRObj::getX0() {
    getDoubleParameter(XR_dX0, &dX0);
    return dX0;
}

int OlxAPIXFMRObj::setX0(double value) {
    dX0 = value;
    return setDoubleParameter(XR_dX0, &dX0);
}

int OlxAPIXFMRObj::setGR(GroundingImpedance winding, double value)
{
    switch (winding)
    {
    case GND_1:
        dRG1 = value;
        return setDoubleParameter(XR_dRG1, &dRG1);

    case GND_2:
        dRG2 = value;
        return setDoubleParameter(XR_dRG2, &dRG2);

    case GND_N:
        dRGn = value;
        return setDoubleParameter(XR_dRGN, &dRGn);
    }

    return OLXAPI_FAILURE;
}

double OlxAPIXFMRObj::getGR(GroundingImpedance winding)
{
    switch (winding)
    {
    case GND_1:
        getDoubleParameter(XR_dRG1, &dRG1);
        return dRG1;

    case GND_2:
        getDoubleParameter(XR_dRG2, &dRG2);
        return dRG2;

    case GND_N:
        getDoubleParameter(XR_dRGN, &dRGn);
        return dRGn;
    }

    return -1;
}

int OlxAPIXFMRObj::setGX(GroundingImpedance winding, double value)
{
    switch (winding)
    {
    case GND_1:
        dXG1 = value;
        return setDoubleParameter(XR_dXG1, &dXG1);

    case GND_2:
        dXG2 = value;
        return setDoubleParameter(XR_dXG2, &dXG2);

    case GND_N:
        dXGn = value;
        return setDoubleParameter(XR_dXGN, &dXGn);
    }

    return OLXAPI_FAILURE;
}

double OlxAPIXFMRObj::getGX(GroundingImpedance winding)
{
    switch (winding)
    {
    case GND_1:
        getDoubleParameter(XR_dXG1, &dXG1);
        return dXG1;

    case GND_2:
        getDoubleParameter(XR_dXG2, &dXG2);
        return dXG2;

    case GND_N:
        getDoubleParameter(XR_dXGN, &dXGn);
        return dXGn;
    }

    return -1;
}

double OlxAPIXFMRObj::getTap1() {
    getDoubleParameter(XR_dTap1, &dTap1);
    return dTap1;
}

int OlxAPIXFMRObj::setTap1(double value) {
    dTap1 = value;
    return setDoubleParameter(XR_dTap1, &dTap1);
}

double OlxAPIXFMRObj::getTap2() {
    getDoubleParameter(XR_dTap2, &dTap2);
    return dTap2;
}

int OlxAPIXFMRObj::setTap2(double value) {
    dTap2 = value;
    return setDoubleParameter(XR_dTap2, &dTap2);
}

int OlxAPIXFMRObj::getAuto() {
    getIntParameter(XR_nAuto, &nAuto);
    return nAuto;
}

int OlxAPIXFMRObj::setAuto(int value) {
    nAuto = value;
    return setIntParameter(XR_nAuto, &nAuto);
}

int OlxAPIXFMRObj::getBus1Handle() {
    getIntParameter(XR_nBus1Hnd, &nBus1Handle);
    return nBus1Handle;
}

int OlxAPIXFMRObj::getBus2Handle() {
    getIntParameter(XR_nBus2Hnd, &nBus2Handle);
    return nBus2Handle;
}

int OlxAPIXFMRObj::getInService() {
    getIntParameter(XR_nInService, &nInService);
    return nInService;
}

int OlxAPIXFMRObj::setInService(int value) {
    nInService = value;
    return setIntParameter(XR_nInService, &nInService);
}

int OlxAPIXFMRObj::getLTCCtrlBusHandle() {
    getIntParameter(XR_nLTCCtrlBusHnd, &nLTCCtrlBusHandle);
    return nLTCCtrlBusHandle;
}

int OlxAPIXFMRObj::getLTCGanged() {
    getIntParameter(XR_nLTCGanged, &nLTCGanged);
    return nLTCGanged;
}

int OlxAPIXFMRObj::setLTCGanged(int value) {
    nLTCGanged = value;
    return setIntParameter(XR_nLTCGanged, &nLTCGanged);
}

int OlxAPIXFMRObj::getLTCPriority() {
    getIntParameter(XR_nLTCPriority, &nLTCPriority);
    return nLTCPriority;
}

int OlxAPIXFMRObj::setLTCPriority(int value) {
    nLTCPriority = value;
    return setIntParameter(XR_nLTCPriority, &nLTCPriority);
}

int OlxAPIXFMRObj::getLTCSide() {
    getIntParameter(XR_nLTCside, &nLTCside);
    return nLTCside;
}

int OlxAPIXFMRObj::setLTCSide(int value) {
    nLTCside = value;
    return setIntParameter(XR_nLTCside, &nLTCside);
}

int OlxAPIXFMRObj::getLTCType() {
    getIntParameter(XR_nLTCtype, &nLTCtype);
    return nLTCtype;
}

int OlxAPIXFMRObj::setLTCType(int value) {
    nLTCtype = value;
    return setIntParameter(XR_nLTCtype, &nLTCtype);
}

int OlxAPIXFMRObj::getMeteredBusHandle() {
    getIntParameter(XR_nMeteredEnd, &nMetered);
    return nMetered;
}

int OlxAPIXFMRObj::setMeteredBusHandle(int value) {
    nMetered = value;
    return setIntParameter(XR_nMeteredEnd, &nMetered);
}

int OlxAPIXFMRObj::getRelayGroup1Handle() {
    getIntParameter(XR_nRlyGr1Hnd, &nRlyGr1Handle);
    return nRlyGr1Handle;
}

int OlxAPIXFMRObj::getRelayGroup2Handle() {
    getIntParameter(XR_nRlyGr2Hnd, &nRlyGr2Handle);
    return nRlyGr2Handle;
}

string OlxAPIXFMRObj::getWinding1Cfg()
{
    getStringParameter(XR_sCfg1, &sCfg1);
    return sCfg1;
}

int OlxAPIXFMRObj::setWinding1Cfg(string& value)
{
    sCfg1 = value;
    return setStringParameter(XR_sCfg1, &sCfg1);
}

string OlxAPIXFMRObj::getWinding2Cfg()
{
    getStringParameter(XR_sCfg2, &sCfg2);
    return sCfg2;
}

int OlxAPIXFMRObj::setWinding2Cfg(string& value)
{
    sCfg2 = value;
    return setStringParameter(XR_sCfg2, &sCfg2);
}

string OlxAPIXFMRObj::getWinding2CfgTest()
{
    getStringParameter(XR_sCfg2T, &sCfg2T);
    return sCfg2T;
}

int OlxAPIXFMRObj::setWinding2CfgTest(string& value)
{
    sCfg2T = value;
    return setStringParameter(XR_sCfg2T, &sCfg2T);
}

string OlxAPIXFMRObj::getCktID()
{
    getStringParameter(XR_sID, &sID);
    return sID;
}

string OlxAPIXFMRObj::getName()
{
    getStringParameter(XR_sName, &sName);
    return sName;
}

int OlxAPIXFMRObj::setName(string& value)
{
    sName = value;
    return setStringParameter(XR_sName, &sName);
}

string OlxAPIXFMRObj::getOffDate()
{
    getStringParameter(XR_sOffDate, &sOffDate);
    return sOffDate;
}

int OlxAPIXFMRObj::setOffDate(string& value)
{
    sOffDate = value;
    return setStringParameter(XR_sOffDate, &sOffDate);
}

string OlxAPIXFMRObj::getOnDate()
{
    getStringParameter(XR_sOnDate, &sOnDate);
    return sOnDate;
}

int OlxAPIXFMRObj::setOnDate(string& value)
{
    sOnDate = value;
    return setStringParameter(XR_sOnDate, &sOnDate);
}