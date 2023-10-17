#include "OlxAPIBranchObj.h"

OlxAPIBranchObj::OlxAPIBranchObj(int handle) : OlxAPIObj(handle)
{
	getBus1Handle();
	getBus2Handle();
	getBus3Handle();
	getEquipmentHandle();
	getInService();
	getRelayGroup1Handle();
	getRelayGroup2Handle();
	getRelayGroup3Handle();
	getEquipmentType();
}

int OlxAPIBranchObj::getBus1Handle()
{
	getIntParameter(BR_nBus1Hnd, &nBus1Handle);
	return nBus1Handle;
}

int OlxAPIBranchObj::getBus2Handle()
{
	getIntParameter(BR_nBus2Hnd, &nBus2Handle);
	return nBus2Handle;
}

int OlxAPIBranchObj::getBus3Handle()
{
	getIntParameter(BR_nBus3Hnd, &nBus3Handle);
	return nBus3Handle;
}

int OlxAPIBranchObj::getEquipmentHandle()
{
	getIntParameter(BR_nHandle, &nEquipmentHandle);
	return nEquipmentHandle;
}

int OlxAPIBranchObj::getInService()
{
	getIntParameter(BR_nInService, &nInservice);
	return nInservice;
}

int OlxAPIBranchObj::getRelayGroup1Handle()
{
	getIntParameter(BR_nRlyGrp1Hnd, &nRelayGroup1Handle);
	return nRelayGroup1Handle;
}

int OlxAPIBranchObj::getRelayGroup2Handle()
{
	getIntParameter(BR_nRlyGrp2Hnd, &nRelayGroup2Handle);
	return nRelayGroup2Handle;
}

int OlxAPIBranchObj::getRelayGroup3Handle()
{
	getIntParameter(BR_nRlyGrp3Hnd, &nRelayGroup3Handle);
	return nRelayGroup3Handle;
}

int OlxAPIBranchObj::getEquipmentType()
{
	getIntParameter(BR_nType, &nType);
	return nType;
}
