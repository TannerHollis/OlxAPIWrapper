#include "OlxAPIModelObj.h"

OlxAPIModelObj::OlxAPIModelObj(string& filePath, bool readonly)
{
	openFile(filePath, readonly);

	if (fileIsOpened)
	{
		loadMap(&busses, SY_nNObus, TC_BUS);
		loadMap(&lines, SY_nNOline, TC_LINE);
		loadMap(&XFMRs, SY_nNOxfmr, TC_XFMR);
		loadMap(&XFMRs3W, SY_nNOxfmr3, TC_XFMR3);
		loadMap(&seriesReactors, SY_nNOseriescap, TC_SCAP);
		loadMap(&shuntCapacitors, SY_nNOshuntUnit, TC_SHUNTUNIT);
	}
}

OlxAPIModelObj::~OlxAPIModelObj()
{
	clearMap(&busses);
	clearMap(&lines);
	clearMap(&XFMRs);
	clearMap(&XFMRs3W);
	clearMap(&seriesReactors);
	clearMap(&shuntCapacitors);
	closeFile();
}

int OlxAPIModelObj::saveFile()
{
	return saveFile(filePath);
}

int OlxAPIModelObj::saveFile(string& filePath)
{
	this->filePath = filePath;
	return OlxAPISaveDataFile((char*)filePath.c_str());
}

bool OlxAPIModelObj::isOpened()
{
	return fileIsOpened;
}

OlxAPILineObj* OlxAPIModelObj::getLine(int handle)
{
	return lines[handle];
}

int OlxAPIModelObj::findLineHandleByName(string& name)
{
	return findByName(&lines, name);
}

vector<int> OlxAPIModelObj::getLineHandles()
{
	return getHandles(&lines);
}

OlxAPIBusObj* OlxAPIModelObj::getBus(int handle)
{
	return busses[handle];
}

int OlxAPIModelObj::findBusHandleByName(string& name)
{
	return findByName(&busses, name);
}

vector<int> OlxAPIModelObj::getBusHandles()
{
	return getHandles(&busses);
}

OlxAPIXFMRObj* OlxAPIModelObj::getXFMR(int handle)
{
	return XFMRs[handle];
}

int OlxAPIModelObj::findXFMRHandleByName(string& name)
{
	return findByName(&XFMRs, name);
}

vector<int> OlxAPIModelObj::getXFMRHandles()
{
	return getHandles(&XFMRs);
}

OlxAPIXFMR3WObj* OlxAPIModelObj::get3WXFMR(int handle)
{
	return XFMRs3W[handle];
}

int OlxAPIModelObj::find3WXFMRHandleByName(string& name)
{
	return findByName(&XFMRs3W, name);
}

vector<int> OlxAPIModelObj::get3WXFMRHandles()
{
	return getHandles(&XFMRs3W);
}

OlxAPISeriesReactorObj* OlxAPIModelObj::getSeriesReactor(int handle)
{
	return seriesReactors[handle];
}

int OlxAPIModelObj::findSeriesReactorHandleByName(string& name)
{
	return findByName(&seriesReactors, name);
}

vector<int> OlxAPIModelObj::getSeriesReactorHandles()
{
	return getHandles(&seriesReactors);
}

OlxAPIShuntCapacitorObj* OlxAPIModelObj::getShuntCapacitor(int handle)
{
	return shuntCapacitors[handle];
}

vector<int> OlxAPIModelObj::getShuntCapacitorHandles()
{
	return getHandles(&shuntCapacitors);
}

template <typename T> vector<int> OlxAPIModelObj::getHandles(T* mapIn)
{
	vector<int> handles;
	typename T::iterator it = mapIn->begin();
	while (it != mapIn->end())
	{
		int handle = it->first;
		handles.push_back(handle);
		it++;
	}
	return handles;
}

template <typename T> int OlxAPIModelObj::findByName(T* mapIn, string& name)
{
	typename T::iterator it = mapIn->begin();
	while (it != mapIn->end())
	{
		int handle = it->first;
		string busName = it->second->getName();

		if (busName == name)
			return handle;

		it++;
	}
	return -1;
}

template <typename T> void OlxAPIModelObj::clearMap(T* mapIn)
{
	typename T::iterator it = mapIn->begin();
	while (it != mapIn->end())
	{
		int handle = it->first;
		delete it->second;
		it++;
	}
	mapIn->clear();
}

template <typename T> void OlxAPIModelObj::loadMap(map<int, T*>* mapIn, int objCountToken, int objToken)
{
	clearMap(mapIn);

	// Get Number of lines
	int nObj;
	OlxAPIGetData(HND_SYS, objCountToken, &nObj);

	int handle = 0;
	for (uint16_t i = 0; i < nObj; i++)
	{
		int ret = OlxAPIGetEquipment(objToken, &handle);

		if (ret != OLXAPI_OK)
			continue;

		mapIn->insert({ handle, new T(handle) });
	}
}



void OlxAPIModelObj::openFile(string& filePath, bool readonly)
{
	this->filePath = filePath;
	int ret = OlxAPILoadDataFile((char*)filePath.c_str(), readonly ? 1 : 0);
	if (ret == OLXAPI_OK)
	{
		fileIsOpened = true;
	}
	else
	{
		cout << "Could not open file: " << filePath << endl;
	}
}

void OlxAPIModelObj::closeFile()
{
	if (fileIsOpened)
	{
		int ret = OlxAPICloseDataFile();
		if (ret == OLXAPI_OK)
			fileIsOpened = false;
	}
}