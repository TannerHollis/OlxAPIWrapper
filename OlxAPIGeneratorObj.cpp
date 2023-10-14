#include "OlxAPIGeneratorObj.h"

OlxAPIGeneratorObj::OlxAPIGeneratorObj(int handle) : OlxAPIObj(handle)
{
	getMVARating();
	getPMax();
	getPMin();
	getQMax();
	getQMin();
	getRz();
	getXz();
	getScheduledP();
	getScheduledQ();
	getOnline();
	getGeneratorHandle();
	getGenID();
	getOffDate();
	getOnDate();
	getR((GeneratorImpedance)0);
	getX((GeneratorImpedance)0);
	setR(GeneratorImpedance::GEN_SUBTRANSIENT, 0.5);

	gfxObj = new OlxAPIGraphicsType2Obj(handle, TC_GEN);
}

OlxAPIGeneratorObj::~OlxAPIGeneratorObj()
{
	delete gfxObj;
}

double OlxAPIGeneratorObj::getMVARating()
{
	getDoubleParameter(GU_dMVArating, &dMVARating);
	return dMVARating;
}

int OlxAPIGeneratorObj::setMVARating(double value)
{
	dMVARating = value;
	return setDoubleParameter(GU_dMVArating, &dMVARating);
}

double OlxAPIGeneratorObj::getPMax()
{
	getDoubleParameter(GU_dPmax, &dPmax);
	return dPmax;
}

int OlxAPIGeneratorObj::setPMax(double value)
{
	dPmax = value;
	return setDoubleParameter(GU_dPmax, &dPmax);
}

double OlxAPIGeneratorObj::getPMin()
{
	getDoubleParameter(GU_dPmin, &dPmin);
	return dPmin;
}

int OlxAPIGeneratorObj::setPMin(double value)
{
	dPmin = value;
	return setDoubleParameter(GU_dPmin, &dPmin);
}

double OlxAPIGeneratorObj::getQMax()
{
	getDoubleParameter(GU_dQmax, &dQmax);
	return dQmax;
}

int OlxAPIGeneratorObj::setQMax(double value)
{
	dQmax = value;
	return setDoubleParameter(GU_dQmax, &dQmax);
}

double OlxAPIGeneratorObj::getQMin()
{
	getDoubleParameter(GU_dQmin, &dQmin);
	return dQmin;
}

int OlxAPIGeneratorObj::setQMin(double value)
{
	dQmin = value;
	return setDoubleParameter(GU_dQmin, &dQmin);
}

double OlxAPIGeneratorObj::getRz()
{
	getDoubleParameter(GU_dRz, &dRz);
	return dRz;
}

int OlxAPIGeneratorObj::setRz(double value)
{
	dRz = value;
	return setDoubleParameter(GU_dRz, &dRz);
}

double OlxAPIGeneratorObj::getXz()
{
	getDoubleParameter(GU_dXz, &dXz);
	return dXz;
}

int OlxAPIGeneratorObj::setXz(double value)
{
	dXz = value;
	return setDoubleParameter(GU_dXz, &dXz);
}

double OlxAPIGeneratorObj::getScheduledP()
{
	getDoubleParameter(GU_dSchedP, &dSchedP);
	return dSchedP;
}

int OlxAPIGeneratorObj::setScheduledP(double value)
{
	dSchedP = value;
	return setDoubleParameter(GU_dSchedP, &dSchedP);
}

double OlxAPIGeneratorObj::getScheduledQ()
{
	getDoubleParameter(GU_dSchedQ, &dSchedQ);
	return dSchedQ;
}

int OlxAPIGeneratorObj::setScheduledQ(double value)
{
	dSchedQ = value;
	return setDoubleParameter(GU_dSchedQ, &dSchedQ);
}

int OlxAPIGeneratorObj::getOnline()
{
	getIntParameter(GU_nOnline, &nOnline);
	return nOnline;
}

int OlxAPIGeneratorObj::setOnline(int value)
{
	nOnline = value;
	return setIntParameter(GU_nOnline, &nOnline);
}

int OlxAPIGeneratorObj::getGeneratorHandle()
{
	getIntParameter(GU_nGenHnd, &nGenUnitHandle);
	return nGenUnitHandle;
}

string OlxAPIGeneratorObj::getGenID()
{
	getStringParameter(GU_sID, &sID);
	return sID;
}

string OlxAPIGeneratorObj::getOffDate()
{
	getStringParameter(XR_sOffDate, &sOffDate);
	return sOffDate;
}

int OlxAPIGeneratorObj::setOffDate(string& value)
{
	sOffDate = value;
	return setStringParameter(XR_sOffDate, &sOffDate);
}

string OlxAPIGeneratorObj::getOnDate()
{
	getStringParameter(XR_sOnDate, &sOnDate);
	return sOnDate;
}

int OlxAPIGeneratorObj::setOnDate(string& value)
{
	sOnDate = value;
	return setStringParameter(XR_sOnDate, &sOnDate);
}

double OlxAPIGeneratorObj::getR(GeneratorImpedance impedance)
{
	getDoubleArrayParameter(GU_vdR, dR, 5);
	switch (impedance)
	{
	case GEN_SUBTRANSIENT:
		return dR[0];
	case GEN_SYNCHRONOUS:
		return dR[1];
	case GEN_TRANSIENT:
		return dR[2];
	case GEN_NEG_SEQ:
		return dR[3];
	case GEN_ZERO_SEQ:
		return dR[4];
	default:
		return 0;
	}
}

int OlxAPIGeneratorObj::setR(GeneratorImpedance impedance, double value)
{
	getDoubleArrayParameter(GU_vdR, dR, 5);
	switch (impedance)
	{
	case GEN_SUBTRANSIENT:
		dR[0] = value;
		break;
	case GEN_SYNCHRONOUS:
		dR[1] = value;
		break;
	case GEN_TRANSIENT:
		dR[2] = value;
		break;
	case GEN_NEG_SEQ:
		dR[3] = value;
		break;
	case GEN_ZERO_SEQ:
		dR[4] = value;
		break;
	default:
		return 0;
	}
	return setDoubleArrayParameter(GU_vdR, dR, 5);
}

double OlxAPIGeneratorObj::getX(GeneratorImpedance impedance)
{
	getDoubleArrayParameter(GU_vdX, dX, 5);
	switch (impedance)
	{
	case GEN_SUBTRANSIENT:
		return dX[0];
	case GEN_SYNCHRONOUS:
		return dX[1];
	case GEN_TRANSIENT:
		return dX[2];
	case GEN_NEG_SEQ:
		return dX[3];
	case GEN_ZERO_SEQ:
		return dX[4];
	default:
		return 0;
	}
}

int OlxAPIGeneratorObj::setX(GeneratorImpedance impedance, double value)
{
	double** data;
	getDoubleArrayParameter(GU_vdX, dX, 5);
	switch (impedance)
	{
	case GEN_SUBTRANSIENT:
		dX[0] = value;
		break;
	case GEN_SYNCHRONOUS:
		dX[1] = value;
		break;
	case GEN_TRANSIENT:
		dX[2] = value;
		break;
	case GEN_NEG_SEQ:
		dX[3] = value;
		break;
	case GEN_ZERO_SEQ:
		dX[4] = value;
		break;
	default:
		return 0;
	}

	return setDoubleArrayParameter(GU_vdX, dX, 5);
}
