#pragma once

#include "olxapi/include/olxapi.h"

#include <iostream>

using namespace std;

class OlxAPIGraphicsObj
{
/*  TC_BUS: size, angle, x, y, nameX, nameY, hideID
    !!!when size is Zero, the bus had never been placed on the 1 - line and
    therefore the rest of the data are just junk
    when size is negative, the bus is not displayed on the 1 - line(hidden)
    TC_GEN, TC_GENW3, TC_GENW4, TC_CCGEN, TC_LOAD, TC_SHUNT, TC_SVD :
    x | y, angle, textX, textY
    TC_XFMR, TC_PS, TC_SCAP, TC_SWITCH, TC_DCLINE2 :
    noSegs, p1X, p1Y, p2X, p2Y, p3X, p3Y, p4X, p4Y, text1X, text1Y, text2X, text2Y
    !!!noSegs determines if p3and p4 are being used
    TC_XFMR3 : noSegs, p1X, p1Y, p2X, p2Y, p3X, p3Y, p4X, p4Y, p5X, p5Y, p6X, p6Y,
    text1X, text1Y, text2X, text2Y, text3X, text3Y
    !!!noSegs determines if p3and p4 are being used
    TC_LINE, TC_SCAP : noSegs, p1X, p2X...., text1X, text1Y, text2X, text2Y
    TC_SYS : windowCenterX, windowCenterY, fontSizeMainWindow, fontSizeOCWindow, fontSizeDSWindow,
    xfmrStyle, colorkV1, ...., colorkV13, colorIndex1, ..., colorIndex13
    */

public:
    typedef enum GraphicsObjType
    {
        GFXOBJ_TYPE_0 = 0, // TC_BUS
        GFXOBJ_TYPE_1 = 1, // TC_GEN, TC_GENW3, TC_GENW4, TC_CCGEN, TC_LOAD, TC_SHUNT, TC_SVD
        GFXOBJ_TYPE_2 = 2, // TC_XFMR, TC_PS, TC_SCAP, TC_SWITCH, TC_DCLINE2
        GFXOBJ_TYPE_3 = 3, // TC_XFMR3
        GFXOBJ_TYPE_4 = 4, // TC_LINE, TC_SCAP* already in Type 2
        GFXOBJ_TYPE_5 = 5, // TC_SYS
        GFXOBJ_TYPE_UNKNOWN = 99
    }GraphicsObjType;

    OlxAPIGraphicsObj(int handle, int objType);

protected:
    int getData(int offset);
    int setData(int offset, int value);

    int data[500];

private:
    GraphicsObjType getGraphicsObjType(int objType);

    int handle;
	int objType;
    GraphicsObjType gfxObjType;
    
};



