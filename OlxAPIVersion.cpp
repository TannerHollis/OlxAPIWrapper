#include "OlxAPIVersion.h"

int OlxAPIVersion::getVersion(string* version)
{
    // Get version info
    char versionString[2000];
    int ret = OlxAPIVersionInfo(versionString);

    if (ret != OLXAPI_OK)
        return ret;

    version->assign(versionString);
    return ret;
}
