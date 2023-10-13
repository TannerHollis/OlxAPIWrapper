#include "OlxAPIModelObj.h"

OlxAPIModelObj::OlxAPIModelObj(string& filePath, bool readonly)
{
	openFile(filePath, readonly);

	if (fileIsOpened)
	{
		loadBusses();
		loadLines();
		load3WXFMRs();
	}
}

OlxAPIModelObj::~OlxAPIModelObj()
{
	clearBusses();
	clearLines();
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

OlxAPILineObj* OlxAPIModelObj::getLine(int handle)
{
	return lines[handle];
}

int OlxAPIModelObj::findLineHandleByName(string& name)
{
	map<int, OlxAPILineObj*>::iterator it = lines.begin();
	while (it != lines.end())
	{
		int handle = it->first;
		string lineName = it->second->getName();

		if (lineName == name)
			return handle;

		it++;
	}
	return -1;
}

vector<int> OlxAPIModelObj::getLineHandles()
{
	vector<int> lineHandles;
	map<int, OlxAPILineObj*>::iterator it = lines.begin();
	while (it != lines.end())
	{
		int handle = it->first;
		lineHandles.push_back(handle);
		it++;
	}
	return lineHandles;
}

OlxAPIBusObj* OlxAPIModelObj::getBus(int handle)
{
	return busses[handle];
}

int OlxAPIModelObj::findBusHandleByName(string& name)
{
	map<int, OlxAPIBusObj*>::iterator it = busses.begin();
	while (it != busses.end())
	{
		int handle = it->first;
		string busName = it->second->getName();

		if (busName == name)
			return handle;

		it++;
	}
	return -1;
}

vector<int> OlxAPIModelObj::getBusHandles()
{
	vector<int> busHandles;
	map<int, OlxAPIBusObj*>::iterator it = busses.begin();
	while (it != busses.end())
	{
		int handle = it->first;
		busHandles.push_back(handle);
		it++;
	}
	return busHandles;
}

bool OlxAPIModelObj::isOpened()
{
	return fileIsOpened;
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

void OlxAPIModelObj::loadBusses()
{
	clearBusses();

	// Get Number of lines
	OlxAPIGetData(HND_SYS, SY_nNObus, &nBusses);

	int handle = 0;
	for (uint16_t bus = 0; bus < nBusses; bus++)
	{
		int ret = OlxAPIGetEquipment(TC_BUS, &handle);

		if (ret != OLXAPI_OK)
			continue;

		busses.insert(pair<int, OlxAPIBusObj*>(handle, new OlxAPIBusObj(handle)));
	}
}

void OlxAPIModelObj::clearBusses()
{
	map<int, OlxAPIBusObj*>::iterator it = busses.begin();
	while (it != busses.end())
	{
		int handle = it->first;
		OlxAPIBusObj* bus = it->second;
		delete bus;
		it++;
	}

	busses.clear();
}

void OlxAPIModelObj::loadLines()
{
	clearLines();

	// Get Number of lines
	OlxAPIGetData(HND_SYS, SY_nNOline, &nLines);

	int handle = 0;
	for (uint16_t line = 0; line < nLines; line++)
	{
		int ret = OlxAPIGetEquipment(TC_LINE, &handle);

		if (ret != OLXAPI_OK)
			continue;

		lines.insert(pair<int, OlxAPILineObj*>(handle, new OlxAPILineObj(handle)));
	}
}

void OlxAPIModelObj::clearLines()
{
	map<int, OlxAPILineObj*>::iterator it = lines.begin();
	while (it != lines.end())
	{
		int handle = it->first;
		OlxAPILineObj* line = it->second;
		delete line;
		it++;
	}
	lines.clear();
}

void OlxAPIModelObj::load3WXFMRs()
{
	clear3WXFMRs();

	// Get Number of lines
	OlxAPIGetData(HND_SYS, SY_nNOxfmr3, &nXFMRs3W);

	int handle = 0;
	for (uint16_t xfmr = 0; xfmr < nXFMRs3W; xfmr++)
	{
		int ret = OlxAPIGetEquipment(TC_XFMR3, &handle);

		if (ret != OLXAPI_OK)
			continue;

		XFMRs3W.insert(pair<int, OlxAPI3WXFMRObj*>(handle, new OlxAPI3WXFMRObj(handle)));
	}
}

void OlxAPIModelObj::clear3WXFMRs()
{
	map<int, OlxAPI3WXFMRObj*>::iterator it = XFMRs3W.begin();
	while (it != XFMRs3W.end())
	{
		int handle = it->first;
		OlxAPI3WXFMRObj* xfmr = it->second;
		delete xfmr;
		it++;
	}
	lines.clear();
}


