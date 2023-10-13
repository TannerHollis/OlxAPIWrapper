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

protected:
	int getIntParameter(int paramToken, int* data);
	int setIntParameter(int paramToken, int* data);
	
	int getDoubleParameter(int paramToken, double* data);
	int setDoubleParameter(int paramToken, double* data);

	int getStringParameter(int paramToken, string* data);
	int setStringParameter(int paramToken, string* data);

private:
	int handle;
};

