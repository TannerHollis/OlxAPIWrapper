#pragma once

#include "olxapi/include/olxapi.h"
#include <string>

using namespace std;

class OlxAPIVersion
{
public:
	static int getVersion(string *version)
	{
        // Get version info
        char versionString[2000];
        int ret = OlxAPIVersionInfo(versionString);

        if (ret != OLXAPI_OK)
            return ret;
        
        version->assign(versionString);
        return ret;
	}
};

