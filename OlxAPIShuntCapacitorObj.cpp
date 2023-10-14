#include "OlxAPIShuntCapacitorObj.h"

OlxAPIShuntCapacitorObj::OlxAPIShuntCapacitorObj(int handle) : OlxAPIObj(handle)
{
    getB();
    getB0();
    getG();
    getG0();
    get3WFlag();
    getOnline();
    getShuntHandle();
    getCktID();
    gfxObj = new OlxAPIGraphicsType2Obj(handle, TC_SHUNTUNIT);
}

OlxAPIShuntCapacitorObj::~OlxAPIShuntCapacitorObj()
{
    delete gfxObj;
}

double OlxAPIShuntCapacitorObj::getB()
{
    getDoubleParameter(SU_dB, &dB);
    return dB;
}

int OlxAPIShuntCapacitorObj::setB(double value)
{
    dB = value;
    return setDoubleParameter(SU_dB, &dB);
}

double OlxAPIShuntCapacitorObj::getB0()
{
    getDoubleParameter(SU_dB0, &dB0);
    return dB0;
}

int OlxAPIShuntCapacitorObj::setB0(double value)
{
    dB0 = value;
    return setDoubleParameter(SU_dB0, &dB0);
}

double OlxAPIShuntCapacitorObj::getG()
{
    getDoubleParameter(SU_dG, &dG);
    return dG;
}

int OlxAPIShuntCapacitorObj::setG(double value)
{
    dG = value;
    return setDoubleParameter(SU_dG, &dG);
}

double OlxAPIShuntCapacitorObj::getG0()
{
    getDoubleParameter(SU_dG0, &dG0);
    return dG0;
}

int OlxAPIShuntCapacitorObj::setG0(double value)
{
    dG0 = value;
    return setDoubleParameter(SU_dG0, &dG0);
}

int OlxAPIShuntCapacitorObj::get3WFlag()
{
    getIntParameter(SU_n3WX, &n3WX);
    return n3WX;
}

int OlxAPIShuntCapacitorObj::getOnline()
{
    getIntParameter(SU_nOnline, &nOnline);
    return nOnline;
}

int OlxAPIShuntCapacitorObj::setOnline(int value)
{
    nOnline = value;
    return setIntParameter(SU_nOnline, &nOnline);
}

int OlxAPIShuntCapacitorObj::getShuntHandle()
{
    getIntParameter(SU_nShuntHnd, &nShuntHandle);
    return nShuntHandle;
}

string OlxAPIShuntCapacitorObj::getCktID()
{
    getStringParameter(SU_sID, &sID);
    return sID;
}
