#pragma once

#include "olxapi/include/olxapi.h"

#include "OlxAPILineObj.h"
#include "OlxAPIBusObj.h"
#include "OlxAPI3WXFMRObj.h"

#include <vector>
#include <map>
#include <iostream>

using namespace std;

class OlxAPIModelObj
{
public:
	OlxAPIModelObj(string& filePath, bool readonly);

	~OlxAPIModelObj();

	int saveFile(); //Save overwrite
	int saveFile(string& filePath); // Save as new file

	OlxAPILineObj* getLine(int handle);
	int findLineHandleByName(string& name);
	vector<int> getLineHandles();

	OlxAPIBusObj* getBus(int handle);
	int findBusHandleByName(string& name);
	vector<int> getBusHandles();

	bool isOpened();

private:
	void openFile(string& filePath, bool readonly);
	void closeFile();

	void loadBusses();
	void clearBusses();

	void loadLines();
	void clearLines();

	void load3WXFMRs();
	void clear3WXFMRs();

	string filePath;
	bool fileIsOpened;

	int nLines;
	map<int, OlxAPILineObj*> lines;

	int nBusses;
	map<int, OlxAPIBusObj*> busses;

	int nXFMRs3W;
	map<int, OlxAPI3WXFMRObj*> XFMRs3W;
};

