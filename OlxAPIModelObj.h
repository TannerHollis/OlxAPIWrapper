#pragma once

#include "olxapi/include/olxapi.h"

#include "OlxAPILineObj.h"
#include "OlxAPIBusObj.h"
#include "OlxAPIXFMRObj.h"
#include "OlxAPIXFMR3WObj.h"
#include "OlxAPISeriesReactorObj.h"
#include "OlxAPIShuntCapacitorObj.h"

#include <vector>
#include <map>
#include <iostream>

using namespace std;

class OlxAPIModelObj
{
public:
	OlxAPIModelObj(string& filePath, bool readonly);

	~OlxAPIModelObj();

	int saveFile(); // Save overwrite
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

	OlxAPIXFMR3WObj* get3WXFMR(int handle);
	int find3WXFMRHandleByName(string& name);
	vector<int> get3WXFMRHandles();

	OlxAPISeriesReactorObj* getSeriesReactor(int handle);
	int findSeriesReactorHandleByName(string& name);
	vector<int> getSeriesReactorHandles();

	OlxAPIShuntCapacitorObj* getShuntCapacitor(int handle);
	vector<int> getShuntCapacitorHandles();

private:
	void openFile(string& filePath, bool readonly);
	void closeFile();

	template <typename T> vector<int> getHandles(T* mapIn);
	template <typename T> int findByName(T* mapIn, string& name);
	template <typename T> void clearMap(T* mapIn);
	template <typename T> void loadMap(map<int, T*>* mapIn, int objCountToken, int objToken);

	string filePath;
	bool fileIsOpened;

	map<int, OlxAPILineObj*> lines;

	map<int, OlxAPIBusObj*> busses;

	map<int, OlxAPIXFMRObj*> XFMRs;

	map<int, OlxAPIXFMR3WObj*> XFMRs3W;

	map<int, OlxAPISeriesReactorObj*> seriesReactors;

	map<int, OlxAPIShuntCapacitorObj*> shuntCapacitors;
};


