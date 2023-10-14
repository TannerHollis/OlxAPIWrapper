

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
	- [Graphics Objects](#edit-graphics-object-values)
		- [OlxAPIGraphicsType1Obj](#olxapigraphicstype1obj)
 		- [OlxAPIGraphicsType2Obj](#olxapigraphicstype2obj)
  		- [OlxAPIGraphicsType3Obj](#olxapigraphicstype3obj)
 		- [OlxAPIGraphicsType4Obj](#olxapigraphicstype4obj)
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
[Back to top](#table-of-contents)
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
[Back to top](#table-of-contents)
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
[Back to top](#top)
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

[Back to top](#table-of-contents)
#### OlxAPIGraphicsType2Obj
This graphics object is associated with the following devices and has the following properties:

**Associated Devices**: `OlxAPIShuntCapacitorObj`

` OlxAPIGraphicsType2Obj* gfxObj = shuntCapacitor->gfxObj;`

|Property|Description|Data Type| Get Example | Set Example|
|--|--|--|--|--|
|`x`|Sets the x position of the device|`int`|`getX();`| `setX(10);`|
|`y`|Sets the y position of the device|`int`|`getY();`| `setY(10);`|
|`textX`|Sets the x position of the display text |`int`|`getTextX();`| `setTextX(10);`|
|`textY`|Sets the y position of the display text |`int`|`getTextY();`| `getTextY(10);`|

[Back to top](#table-of-contents)
#### OlxAPIGraphicsType3Obj
This graphics object is associated with the following devices and has the following properties:

**Associated Devices**: `OlxAPIXFMRObj`,`OlxAPISeriesReactorObj`

` OlxAPIGraphicsType3Obj* gfxObj = xfmr->gfxObj;`

|Property|Description|Data Type| Get Example | Set Example|
|--|--|--|--|--|
|`segments`|Sets the number of segments (1, if connected between two busses without a *kink*, or 3, if a *kink* is present).|`int`|`getNSegments();`| `setNSegments(1);`|
|`pointsX`|Sets the x position of a segment point. Maximum of 4 points (3 segments).|`int`|`getPointX(0);`| `setPointX(0,10);`|
|`pointsY`|Sets the y position of a segment point. Maximum of 4 points (3 segments)|`int`|`getPointY(0);`| `setPointY(0,10);`|
|`text1X`|Sets the x position of the display text near bus 1 |`int`|`getText1X();`| `setText1X(10);`|
|`text1Y`|Sets the y position of the display text near bus 1|`int`|`getText1Y();`| `getText1Y(10);`|
|`text2X`|Sets the x position of the display text near bus 2|`int`|`getText2X();`| `setText2X(10);`|
|`text2Y`|Sets the y position of the display text near bus 2|`int`|`getText2Y();`| `getText2Y(10);`|

[Back to top](#table-of-contents)
#### OlxAPIGraphicsType4Obj
This graphics object is associated with the following devices and has the following properties:

**Associated Devices**: `OlxAPIXFMR3WObj`

` OlxAPIGraphicsType4Obj* gfxObj = xfmr3w->gfxObj;`

|Property|Description|Data Type| Get Example | Set Example|
|--|--|--|--|--|
|`segments`|Sets the number of segments (2, if tertiary winding is no *kinks* are present. Otherwise, use with caution. A *kink* controls the use of points 3 and 4).|`int`|`getNSegments();`| `setNSegments(1);`|
|`pointsX`|Sets the x position of a segment point. Maximum of 6 points (5 segments).|`int`|`getPointX(0);`| `setPointX(0,10);`|
|`pointsY`|Sets the y position of a segment point. Maximum of 6 points (5 segments)|`int`|`getPointY(0);`| `setPointY(0,10);`|
|`text1X`|Sets the x position of the display text near bus 1 |`int`|`getText1X();`| `setText1X(10);`|
|`text1Y`|Sets the y position of the display text near bus 1|`int`|`getText1Y();`| `getText1Y(10);`|
|`text2X`|Sets the x position of the display text near bus 2|`int`|`getText2X();`| `setText2X(10);`|
|`text2Y`|Sets the y position of the display text near bus 2|`int`|`getText2Y();`| `getText2Y(10);`|
|`text3X`|Sets the x position of the display text near bus 3|`int`|`getText3X();`| `setText3X(10);`|
|`text3Y`|Sets the y position of the display text near bus 3|`int`|`getText3Y();`| `getText3Y(10);`|

[Back to top](#table-of-contents)
### Supported OneLiner Equipment
|ASPEN Equipment |OlxAPIWrapper Class | Implementation | Graphics Object|
|--|--|--|--|
|Bus| `OlxAPIBusObj` | 100% |[`OlxAPIGraphicsType1Obj`](#olxapigraphicstype1obj)|
|Line| `OlxAPILineObj` | 100%|`OlxAPIGraphicsType5Obj`|
|2-Winding Transformer| `OlxAPIXFMRObj` |100%|[`OlxAPIGraphicsType3Obj`](#olxapigraphicstype3obj)|
|3-Winding Transformer| `OlxAPIXFMR3WObj` |100%|[`OlxAPIGraphicsType4Obj`](#olxapigraphicstype4obj)|
|Series Reactor| `OlxAPISeriesReactorObj` |100%|[`OlxAPIGraphicsType3Obj`](#olxapigraphicstype3obj)|
|Shunt Capacitor| `OlxAPIShuntCapacitorObj` |100%|[`OlxAPIGraphicsType2Obj`](#olxapigraphicstype2obj)|

[Back to top](#table-of-contents)
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
 - Finish Graphics Objects
 - Implement Adding/Removing Equipment
	 - Requires a lot of trial and error, likely to never be implemented

[Back to top](#table-of-contents)