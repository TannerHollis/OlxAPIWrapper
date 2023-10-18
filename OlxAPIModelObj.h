#pragma once

#include "olxapi/include/olxapi.h"

#include "OlxAPIBusObj.h"
#include "OlxAPIBranchObj.h"
#include "OlxAPILineObj.h"
#include "OlxAPIXFMRObj.h"
#include "OlxAPIXFMR3WObj.h"
#include "OlxAPISeriesReactorObj.h"
#include "OlxAPIShuntCapacitorObj.h"
#include "OlxAPIGeneratorObj.h"

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
	int findLineHandleByName(string& name); // Returns first instance, not ideal
	vector<int> getLineHandles();

	OlxAPIBusObj* getBus(int handle);
	int findBusHandleByName(string& name); // Returns first instance, not ideal
	vector<int> getBusHandles();

	OlxAPIXFMRObj* getXFMR(int handle);
	int findXFMRHandleByName(string& name); // Returns first instance, not ideal
	vector<int> getXFMRHandles();

	OlxAPIXFMR3WObj* get3WXFMR(int handle);
	int find3WXFMRHandleByName(string& name); // Returns first instance, not ideal
	vector<int> get3WXFMRHandles();

	OlxAPISeriesReactorObj* getSeriesReactor(int handle);
	int findSeriesReactorHandleByName(string& name); // Returns first instance, not ideal
	vector<int> getSeriesReactorHandles();

	OlxAPIShuntCapacitorObj* getShuntCapacitor(int handle);
	vector<int> getShuntCapacitorHandles();

	OlxAPIGeneratorObj* getGenerator(int handle);
	vector<int> getGeneratorHandles();

	OlxAPIBranchObj* getBranch(int handle);
	int findBranchHandleByDeviceHandle(int devHandle);
	vector<int> getBranchHandles();

private:
	void openFile(string& filePath, bool readonly);
	void closeFile();

	template <typename T> vector<int> getHandles(T* mapIn);
	template <typename T> int findByName(T* mapIn, string& name);
	template <typename T> void clearMap(T* mapIn);
	template <typename T> void loadMap(map<int, T*>* mapIn, int objCountToken, int objToken);

	string filePath;
	bool fileIsOpened;

	map<int, OlxAPIBusObj*> busses;

	map<int, OlxAPIBranchObj*> branches;

	map<int, OlxAPILineObj*> lines;

	map<int, OlxAPIXFMRObj*> XFMRs;

	map<int, OlxAPIXFMR3WObj*> XFMRs3W;

	map<int, OlxAPISeriesReactorObj*> seriesReactors;

	map<int, OlxAPIShuntCapacitorObj*> shuntCapacitors;

	map<int, OlxAPIGeneratorObj*> generators;
};


