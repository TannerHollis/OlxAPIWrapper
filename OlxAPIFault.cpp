#include "OlxAPIFault.h"

OlxAPIFault::OlxAPIFault(int devHandle)
{
	// Store faulted device handle
	this->devHandle = devHandle;
	this->fltHandle = -1; // No fault run

	// Create zero terminated outage list
	nOutages = 0;
	this->outageList = (int*)malloc(sizeof(int) * 100);
	memset(outageList, 0, sizeof(int) * 100);

	// Initialize all variables
	faultConnections = {};
	faultResistance = {};
	faultOptions = {};
	outageOptions = {};
	clearPrevious = 0;
}

int OlxAPIFault::runFault()
{
	return OlxAPIDoFault(devHandle,
		faultConnections._fltConns,
		faultOptions._fltOpts,
		outageOptions._outageOpts,
		outageList,
		faultResistance.r,
		faultResistance.x,
		clearPrevious);
}

void OlxAPIFault::setCloseInFault(bool withOutage)
{
	if (!withOutage)
	{
		faultOptions.closeIn = 1;
	}
	else if (withOutage)
	{
		faultOptions.closeInWOutage = 1;
	}
}

void OlxAPIFault::setCloseInFaultWithEndOpen(bool withOutage)
{
	if (!withOutage)
	{
		faultOptions.closeInWEndOpen = 1;
	}
	else if (withOutage)
	{
		faultOptions.closeInWEndOpenWOutage = 1;
	}
}

void OlxAPIFault::addOutage(int handle)
{
	outageList[nOutages] = handle;
	nOutages++;
	outageList[nOutages] = 0;
}

void OlxAPIFault::setFaultImpedance(double r, double x)
{
	faultResistance.r = r;
	faultResistance.x = x;
}

void OlxAPIFault::setFaultConnection3LG(FaultConnection connection)
{
	faultConnections.flt3lg = connection;
}

void OlxAPIFault::setFaultConnection1LG(FaultConnection connection)
{
	faultConnections.flt1lg = connection;
}

void OlxAPIFault::setFaultConnection2LG(FaultConnection connection)
{
	faultConnections.flt2lg = connection;
}

void OlxAPIFault::setFaultConnectionLL(FaultConnection connection)
{
	faultConnections.fltll = connection;
}
