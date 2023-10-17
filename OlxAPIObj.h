#pragma once

#include "olxapi/include/olxapi.h"
#include <string>

using namespace std;

class OlxAPIObj
{
public:
	OlxAPIObj(int handle);

	int setObjMemo(string& memo);

	int getHandle()	{ return handle; }

	string getObjectIDString();

	int getEquipmentType();

protected:
	int getIntParameter(int paramToken, int* data);
	int setIntParameter(int paramToken, int* data);
	
	int getDoubleParameter(int paramToken, double* data);
	int setDoubleParameter(int paramToken, double* data);

	int getStringParameter(int paramToken, string* data);
	int setStringParameter(int paramToken, string* data);

	int getDoubleArrayParameter(int paramToken, double* data, int length);
	int setDoubleArrayParameter(int paramToken, double* data, int length);

private:
	int handle;
};

