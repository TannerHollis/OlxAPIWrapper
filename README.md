

# OlxAPIWrapper

This project is a wrapper for ASPEN Oneliner's c API. Currently using OlxAPI v15.7 ([Latest version](https://github.com/aspeninc/TestBenchOlxAPI/tree/master)).

- Easy to Use Classes
- Example Application Included

## Table of Contents
 - [Requirements](#requirements)
 - [Using OlxAPIWrapper](#using-olxapiwrapper)
    - [Getting Started](#getting-started)
    - [Editting Equipment Values](#editing-equipment-values)
	- [Get Unique Object String](#get-unique-formatted-object-id-string)
	- [Graphics Objects*](#edit-graphics-object-values)
		- [OlxAPIGraphicsType1Obj](#olxapigraphicstype1obj)
 - [Supported Oneliner Equipment](#supported-oneliner-equipment)
 - [TODO](/#todo)

**Experimental feature. May ruin Oneliner graphics display. Use with caution.*

## Requirements

- All `*.dll` files from the ASPEN Oneliner installation folder must be copied over to the output directory of the project.
- Must have `hasp_rt.exe` copied over to the output directory.
- Be sure to have an open license seat before running. It must also be available on the local computer.
- If there is a newer version of the library available and you want to use it, just swap out the `olxapi` folder files.

# Using OlxAPIWrapper
### Getting Started

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
### Editing Equipment Values
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

### Get Unique Formatted Object ID String
All objects have a unique id that can be formatted into a string. This string is useful for reverse lookups, which return handles if successful.

```cpp
string filePath = "C:/.../Example.olr";
bool readonly = true;
OlxAPIModelObj model(filePath, readonly);

vector<int> lineHandles = model.getLineHandles();

for(int = 0; i < lineHandles.size(); i++)
{
    cout << model.getLine(lineHandles[i])->getObjectIDString() << endl; // Print line name
}
```

### Edit Graphics Object Values
This is current under development, but this will allow the user to get positions of graphics objects within the model. Similar to other API objects, there are `get` and `set` for each graphics object value.

#### OlxAPIGraphicsType1Obj
This graphics object is associated with the following devices and has the following properties:

**Associated Devices**: `OlxAPIBusObj`

` OlxAPIGraphicsType1Obj* gfxObj = bus->gfxObj;`

|Property|Description|Data Type| Get Example | Set Example|
|--|--|--|--|--|
|`size`|Sets the length of the bus|`int`|`getSize();`| `setSize(10);`|
|`angle`|Sets the bus orientation (0-horizontal, 1-vertical)|`int`|`getAngle();`| `setAngle(1);`|
|`x`|Sets the x position of the bus|`int`|`getX();`| `setX(10);`|
|`y`|Sets the y position of the bus|`int`|`getY();`| `setY(10);`|
|`nameX`|Sets the x position of the display name |`int`|`getNameX();`| `setNameX(10);`|
|`nameY`|Sets the y position of the display name|`int`|`getNameY();`| `getNameY(10);`|


### Supported OneLiner Equipment
|ASPEN Equipment |OlxAPIWrapper Class | Implementation | Graphics Object|
|--|--|--|--|
|Bus| `OlxAPIBusObj` | 100% |`OlxAPIGraphicsType1Obj`|
|Line| `OlxAPILineObj` | 100%|`OlxAPIGraphicsType5Obj`|
|2-Winding Transformer| `OlxAPIXFMRObj` |100%|`OlxAPIGraphicsType3Obj`|
|3-Winding Transformer| `OlxAPIXFMR3WObj` |100%|`OlxAPIGraphicsType4Obj`|
|Series Reactor| `OlxAPISeriesReactorObj` |100%|`OlxAPIGraphicsType3Obj`|
|Shunt Capacitor| `OlxAPIShuntCapacitorObj` |100%|`OlxAPIGraphicsType2Obj`|

### TODO

 - Implement the following equipment
	 - [x] Transmission Line
	 - [x] Bus
	 - [X] 2W Transformer
	 - [x] 3W Transformer
	 - [ ] Generator
	 - [ ] Inverter-Based Resource
	 - [X] Shunt Capacitor/Reactor
	 - [X] Series Capacitor/Reactor
	 - [ ] Load ( Load Flow )
	 - [ ] Switch
	 - [ ] Breaker
 - Implement fault capabilities
	- Fault simulation capabilities with In-Service and OOS parameters
 - Implement protective devices
	 - Overcurrent (Phase/Ground)
	 - Distance (Phase/Ground)
	 - Recloser Relay (Phase/Ground)
	 - Fuse
 - Graphics Objects (Experimental)
 - Implement Adding/Removing Equipment
	 - Requires a lot of trial and error, likely to never be implemented

