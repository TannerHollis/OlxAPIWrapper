#include "OlxAPIFault.h"

OlxAPIFault::OlxAPIFault(int devHandle)
{
	// Store faulted device handle
	this->devHandle = devHandle;
	this->fltHandleMin = -1; // No fault run
	this->fltHandleMax = -1; // No fault run

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
	
	nResults = 0;
	results = nullptr;
}

OlxAPIFault::OlxAPIFault(OlxAPIBusObj* bus) : OlxAPIFault(bus->getHandle())
{
	// Default constructor gets called for a bus fault
}

OlxAPIFault::OlxAPIFault(OlxAPIBranchObj* branch) : OlxAPIFault(branch->getHandle())
{
	// Default constructor gets called for a "branch" fault
}

OlxAPIFault::~OlxAPIFault()
{
	if (nResults > 0)
		free(results);
}

int OlxAPIFault::runFault()
{
	int ret = OlxAPIGetData(HND_SC, FT_nNOfaults, &fltHandleMin);
	fltHandleMax = OlxAPIDoFault(devHandle,
		faultConnections._fltConns,
		faultOptions._fltOpts,
		outageOptions._outageOpts,
		outageList,
		faultResistance.r,
		faultResistance.x,
		clearPrevious);

	if (nResults > 0)
	{
		free(results);		
	}

	nResults = fltHandleMax - fltHandleMin;
	if (nResults > 0)
	{
		results = (OlxAPIFaultResult*)malloc(sizeof(OlxAPIFaultResult) * nResults);
		for (int i = 0; i < nResults; i++)
		{
			results[i] = OlxAPIFaultResult(fltHandleMax - i);
		}
	}

	return nResults;
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

int OlxAPIFault::getNResults()
{
	return nResults;
}
