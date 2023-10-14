
# OlxAPIWrapper

This project is a wrapper for ASPEN Oneliner's c API. Currently using OlxAPI v15.7 ([Latest version](https://github.com/aspeninc/TestBenchOlxAPI/tree/master)).

- Easy to Use Classes
- Example Application Included

## Table of Contents
 - [Requirements](#requirements)
 - [Using OlxAPIWrapper](#using-olxapiwrapper)
    - [Getting Started](#getting-started)
    - [Editting Equipment Values](#editing-equipment-values)
 - [Supported Oneliner Equipment](#supported-oneliner-equipment)
 - [TODO](/#todo)

## Requirements

- All `*.dll` files from the ASPEN Oneliner installation folder must be copied over to the output directory of the project.
- Must have `hasp_rt.exe` copied over to the output directory.
- Be sure to have an open license seat before running. It must also be available on the local computer.
- If there is a newer version of the library available and you want to use it, just swap out the `olxapi` folder files.

# Using OlxAPIWrapper<a name="using-olxapiwrapper"></a>
### Getting Started<a name="getting-started"></a>

It is very easy to start using, simply load an entire model using the ```OlxAPIModelObj``` class. All elements are loaded into this object and some objects are searchable via names, otherwise ```handle``` are used exclusively.

```cpp
#include "OlxAPIModelObj.h"
...
string filePath = "C:/.../Example.olr";
bool readonly = true;
OlxAPIModelObj model(filePath, readonly);

vector<int> lineHandles = model.getLineHandles();

for(int = 0; i < lineHandles.size(); i++)
{
    cout << "Line Name: " << model.getLine(lineHandles[i])->getName() << endl; // Print line name
}
```
### Editing Equipment Values<a name="editing-equipment-values"></a>
All elements editable within Oneliner are available to the user via unique ```get``` and ```set``` like used in the following:

```cpp
...
string cable = "Cable 1.1";
int lineHandle = model.findLineHandleByName(cable);
if(handle < 0) // Check for valid handle returned
    continue;
    
OlxAPILineObj* line = model.getLine(lineHandle);
double length = line->getLength();
int ret = line->setLength(length + 100);
if(ret == OLXAPI_OK) // Check write was successful
    cout << "Successful write to cable: " << cable << endl;
...
```

### Supported OneLiner Equipment<a name="supported-oneliner-equipment"></a>
|ASPEN Equipment |OlxAPIWrapper Class | Implementation |
|--|--|--|
|Bus| ``` OlxAPIBusObj ``` | 100% |
|Line| ``` OlxAPILineObj ``` | 100%|
|2 Winding Transformer| ``` OlxAPIXFMRObj ``` |0%|
|3 Winding Transformer| ``` OlxAPI3WXFMRObj ``` |100%|

### TODO

 - Implement the following equipment
	 - [x] Transmission Line
	 - [x] Bus
	 - [X] 2W Transformer
	 - [x] 3W Transformer
	 - [ ] Generator
	 - [ ] Shunt Capacitor/Reactor
	 - [ ] Series Capacitor/Reactor
	 - [ ] Load ( Load Flow )
	 - [ ] Switch
	 - [ ] Breaker
 - Implement fault capabilities
 - Implement protective devices
	 - Overcurrent (Phase/Ground)
	 - Distance (Phase/Ground)
	 - Recloser Relay (Phase/Ground)
	 - Fuse
 - Implement Adding/Removing Equipment
	 - Requires a lot of trial and error, likely to never be implemented

