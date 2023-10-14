#pragma once

#include "olxapi/include/olxapi.h"
#include <string>

using namespace std;

class OlxAPIVersion
{
public:
	static int getVersion(string* version);
};

