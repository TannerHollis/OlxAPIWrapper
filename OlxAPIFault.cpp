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

OlxAPIFault::OlxAPIFault(OlxAPIObj* branch) : OlxAPIFault(branch->getHandle())
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

OlxAPIFaultResult* OlxAPIFault::getResult(int index)
{
	if (index > nResults || index < 0)
		return nullptr;
	else
		return &results[index];
}

void OlxAPIFault::setFaultConnection(FaultConnection connection)
{
	switch (connection)
	{
		case FLT_1LG_A:
			faultConnections.flt1lg = 1;
			break;
		case FLT_1LG_B:
			faultConnections.flt1lg = 2;
			break;
		case FLT_1LG_C:
			faultConnections.flt1lg = 3;
			break;
		case FLT_2LG_AB:
			faultConnections.flt2lg = 1;
			break;
		case FLT_2LG_BC:
			faultConnections.flt2lg = 2;
			break;
		case FLT_2LG_CA:
			faultConnections.flt2lg = 3;
			break;
		case FLT_LL_AB:
			faultConnections.fltll = 1;
			break;
		case FLT_LL_BC:
			faultConnections.fltll = 2;
			break;
		case FLT_LL_CA:
			faultConnections.fltll = 3;
			break;
		case FLT_3LG:
			faultConnections.flt3lg = 1;
			break;
	}
}

void OlxAPIFault::setFaultType(FaultType type, double intPct)
{
	switch (type)
	{
	case FLT_CLOSE_IN:
		faultOptions.closeIn = 1;
		break;
	case FLT_CLOSE_IN_WO:
		faultOptions.closeInWOutage = 1;
		break;
	case FLT_CLOSE_IN_EO:
		faultOptions.closeInWEndOpen = 1;
		break;
	case FLT_CLOSE_IN_EO_WO:
		faultOptions.closeInWEndOpenWOutage = 1;
		break;
	case FLT_INT:
		faultOptions.intermediate = intPct;
		break;
	case FLT_INT_WO:
		faultOptions.intermediateWOutage = intPct;
		break;
	case FLT_INT_EO:
		faultOptions.intermediateWEndOpen = intPct;
		break;
	case FLT_INT_EO_WO:
		faultOptions.intermediateWEndOpenWOutage = intPct;
		break;
	}
}

int OlxAPIFault::getNResults()
{
	return nResults;
}
