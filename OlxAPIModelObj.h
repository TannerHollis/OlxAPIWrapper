#pragma once

#include "olxapi/include/olxapi.h"

#include "OlxAPILineObj.h"
#include "OlxAPIBusObj.h"
#include "OlxAPI3WXFMRObj.h"
#include "OlxAPIXFMRObj.h"

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
	bool isOpened();

	OlxAPILineObj* getLine(int handle);
	int findLineHandleByName(string& name);
	vector<int> getLineHandles();

	OlxAPIBusObj* getBus(int handle);
	int findBusHandleByName(string& name);
	vector<int> getBusHandles();

	OlxAPIXFMRObj* getXFMR(int handle);
	int findXFMRHandleByName(string& name);
	vector<int> getXFMRHandles();

	OlxAPI3WXFMRObj* get3WXFMR(int handle);
	int find3WXFMRHandleByName(string& name);
	vector<int> get3WXFMRHandles();

private:
	void openFile(string& filePath, bool readonly);
	void closeFile();

	template <typename T> vector<int> getHandles(T* mapIn);
	template <typename T> int findByName(T* mapIn, string& name);
	template <typename T> void clearMap(T* mapIn);
	template <typename T> void loadMap(map<int, T*>* mapIn, int* nObj, int objCountToken, int objToken);

	string filePath;
	bool fileIsOpened;

	int nLines;
	map<int, OlxAPILineObj*> lines;

	int nBusses;
	map<int, OlxAPIBusObj*> busses;

	int nXFMRs;
	map<int, OlxAPIXFMRObj*> XFMRs;

	int nXFMRs3W;
	map<int, OlxAPI3WXFMRObj*> XFMRs3W;
};


