#pragma once

#include "OlxAPIGraphicsObj.h"

class OlxAPIGraphicsType1Obj : public OlxAPIGraphicsObj
{
    /*
    TC_BUS: size, angle, x, y, nameX, nameY, hideID
    !!!when size is Zero, the bus had never been placed on the 1 - line and
    therefore the rest of the data are just junk
    when size is negative, the bus is not displayed on the 1 - line(hidden)
    */
public:
    OlxAPIGraphicsType1Obj(int handle, int objType) : OlxAPIGraphicsObj(handle, objType)
    {
        // Do nothing...
    }

    int getSize();
    int setSize(int value);

    int getAngle();
    int setAngle(int value);

    int getX();
    int setX(int value);

    int getY();
    int setY(int value);

    int getNameX();
    int setNameX(int value);

    int getNameY();
    int setNameY(int value);

    int getHideID();
    int setHideID(int value);
};