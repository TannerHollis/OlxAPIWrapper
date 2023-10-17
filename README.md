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
 - [Documentation](https://tannerhollis.github.io/OlxAPIWrapper/)
 - [Using the Example Application](#using-the-example-application)
 - [Supported Oneliner Equipment](#supported-oneliner-equipment)
 - [TODO](#todo)

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
This is currently under development, but this will allow the user to get positions of graphics objects within the model. Similar to other API objects, there are `get` and `set` for each graphics object value.

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

**Associated Devices**: `OlxAPIShuntCapacitorObj`, `OlxAPIGeneratorObj`

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

#### OlxAPIGraphicsType5Obj
This graphics object is associated with the following devices and has the following properties:

**Associated Devices**: `OlxAPILineObj`

` OlxAPIGraphicsType5Obj* gfxObj = line->gfxObj;`

|Property|Description|Data Type| Get Example | Set Example|
|--|--|--|--|--|
|`segments`|Sets the number of segments (2, if tertiary winding is no *kinks* are present. Otherwise, use with caution. A *kink* controls the use of points 3 and 4).|`int`|`getNSegments();`| `setNSegments(1);`|
|`pointsX`|Sets the x position of a segment point. Maximum of 6 points (5 segments).|`int`|`getPointX(0);`| `setPointX(0,10);`|
|`pointsY`|Sets the y position of a segment point. Maximum of 6 points (5 segments)|`int`|`getPointY(0);`| `setPointY(0,10);`|
|`addPoint`*|Inserts a point after the index provided |`int`|| `addPoint(0, 0, 100, 100, 100);`|
|`removePoint`*|Inserts a point at the index provided |`int`|| `removePoint(0);`|
|`text1X`|Sets the x position of the display text near bus 1 |`int`|`getText1X();`| `setText1X(10);`|
|`text1Y`|Sets the y position of the display text near bus 1|`int`|`getText1Y();`| `getText1Y(10);`|
|`text2X`|Sets the x position of the display text near bus 2|`int`|`getText2X();`| `setText2X(10);`|
|`text2Y`|Sets the y position of the display text near bus 2|`int`|`getText2Y();`| `getText2Y(10);`|

**Do not use. Will corrupt surrounding data.*

[Back to top](#table-of-contents)

### Supported OneLiner Equipment
|ASPEN Equipment |OlxAPIWrapper Class | Implementation | Graphics Object|
|--|--|--|--|
|Bus| `OlxAPIBusObj` | 100% |[`OlxAPIGraphicsType1Obj`](#olxapigraphicstype1obj)|
|Line| `OlxAPILineObj` | 100%|[`OlxAPIGraphicsType5Obj`](#olcapigraphicstype5obj)|
|2-Winding Transformer| `OlxAPIXFMRObj` |100%|[`OlxAPIGraphicsType3Obj`](#olxapigraphicstype3obj)|
|3-Winding Transformer| `OlxAPIXFMR3WObj` |100%|[`OlxAPIGraphicsType4Obj`](#olxapigraphicstype4obj)|
|Series Reactor| `OlxAPISeriesReactorObj` |100%|[`OlxAPIGraphicsType3Obj`](#olxapigraphicstype3obj)|
|Shunt Capacitor| `OlxAPIShuntCapacitorObj` |100%|[`OlxAPIGraphicsType2Obj`](#olxapigraphicstype2obj)|
|Generator (Synchronous)| `OlxAPIGeneratorObj` |100%|[`OlxAPIGraphicsType2Obj`](#olxapigraphicstype2obj)|
[Back to top](#table-of-contents)

## Using the Example Application
The example application, when compiled, replaces cable lengths, types, and impedances via a lookup routine using the cable names, given that each cable has a unique name. 

### Command Line Arguments
```bash
> ./OlxAPIWrapperTest.exe -i "../<input_model.olr>" -csv "../<input_csv.csv>" -o "./<output_model.olr>"
```
This directs the application to open the `input_model.olr` model file and use the `input_csv.csv` csv file to replace cable properties. If no `-o` is used, the model will be overwritten, therefore the output file is specified to prevent overwriting the same file.
[Back to top](#table-of-contents)

#### Other Arguments

 - `-h` Display help
 - `-v` Display the version of the OxlAPI c library.
 - `-i` without `-csv` will simply print all lines and busses in the model.
 - `-i`with `-csv` will overwrite cable properties in the same model
	 - If cables are not found, they are skipped
 - `-i` with `-csv` and `-o` will write cable properties to the `output_model.olr`
	 - ASPEN Oneliner needs a full path for the `-i` but does not require a full path for the save, if no full path is provided, it will save in the same directory as the `-i` input model directory.

[Back to top](#table-of-contents)

### CSV Input File
The CSV input file template is as follows
|Name | Length | Type | R | X | R0 | X0 | G1| B1 | G2 | B2 | G10 | B10 | G20 | B20 |
|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|
|F11.1|5930|IWP 500|0.01875|0.02406|0.13957|0.05338|0|0.00114|0|0.00114|0|0.00114|0|0.00114|
|F11.2|2320|IWP 500|0.00654|0.00839|0.04867|0.01861|0|0.0004|0|0.0004|0|0.0004|0|0.0004|
|F11.3|1770|IWP 500|0.00594|0.00543|0.03197|0.01175|0|0.00021|0|0.00021|0|0.00021|0|0.00021|
|F11.4|1274|IWP 500|0.01922|0.01758|0.10348|0.03803|0|0.00069|0|0.00069|0|0.00069|0|0.00069|
|F11.5|6766|IWP 4/0|0.00991|0.00907|0.05335|0.01961|0|0.00035|0|0.00035|0|0.00035|0|0.00035|
|F11.6|3304|IWP 4/0|0.01295|0.01185|0.06972|0.02563|0|0.00046|0|0.00046|0|0.00046|0|0.00046|
[Back to top](#table-of-contents)

### TODO

 - Implement the following equipment
	 - [x] Transmission Line
	 - [x] Bus
	 - [x] 2W Transformer
	 - [x] 3W Transformer
	 - [x] Generator
	 - [ ] Inverter-Based Resource
	 - [x] Shunt Capacitor/Reactor
	 - [x] Series Capacitor/Reactor
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