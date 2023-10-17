#pragma once

#include "OlxAPIObj.h"

using namespace std;

class OlxAPIBranchObj : public OlxAPIObj
{
public:
	OlxAPIBranchObj(int devHandle);

	int getBus1Handle();

	int getBus2Handle();

	int getBus3Handle();

	int getEquipmentHandle();

	int getInService();

	int getRelayGroup1Handle();

	int getRelayGroup2Handle();

	int getRelayGroup3Handle();

	int getEquipmentType();

private:
	int nBus1Handle;
	int nBus2Handle;
	int nBus3Handle;
	int nEquipmentHandle;
	int nInservice;
	int nRelayGroup1Handle;
	int nRelayGroup2Handle;
	int nRelayGroup3Handle;
	int nType;
};

