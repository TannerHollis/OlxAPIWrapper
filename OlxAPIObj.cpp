#include "OlxAPIObj.h"

OlxAPIObj::OlxAPIObj(int handle)
{
	this->handle = handle;
}

int OlxAPIObj::setObjMemo(string& memo)
{
	return OlxAPISetObjMemo(handle, (char*)memo.c_str());
}

int OlxAPIObj::getIntParameter(int paramToken, int* data)
{
	return OlxAPIGetData(handle, paramToken, data);
}

int OlxAPIObj::setIntParameter(int paramToken, int* data)
{
	int ret = OlxAPISetData(handle, paramToken, data);
	if (ret == OLXAPI_OK)
		return ret;

	return OlxAPIPostData(handle);
}

int OlxAPIObj::getDoubleParameter(int paramToken, double* data)
{
	return OlxAPIGetData(handle, paramToken, data);
}

int OlxAPIObj::setDoubleParameter(int paramToken, double* data)
{
	int ret = OlxAPISetData(handle, paramToken, data);
	if (ret == OLXAPI_OK)
		return ret;

	return OlxAPIPostData(handle);
}

int OlxAPIObj::getStringParameter(int paramToken, string* data)
{
	char tmp[1000];
	int ret = OlxAPIGetData(handle, paramToken, tmp);
	if (ret == OLXAPI_OK)
		data->assign(tmp);
	return ret;
}

int OlxAPIObj::setStringParameter(int paramToken, string* data)
{
	int ret = OlxAPISetDataEx(handle, paramToken, (char*)data->c_str());
	if (ret != OLXAPI_OK)
		return ret;

	return OlxAPIPostData(handle);
}
