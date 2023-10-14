#pragma once

#include "OlxAPIGraphicsObj.h"

class OlxAPIGraphicsType2Obj : public OlxAPIGraphicsObj
{
    /*
    TC_GEN, TC_GENW3, TC_GENW4, TC_CCGEN, TC_LOAD, TC_SHUNT, TC_SVD :
    x | y, angle, textX, textY
    */
public:
    OlxAPIGraphicsType2Obj(int handle, int objType) : OlxAPIGraphicsObj(handle, objType)
    {
        // Do nothing...
    }

    int getX();
    int setX(int value);

    int getY();
    int setY(int value);

    int getAngle();
    int setAngle(int value);

    int getTextX();
    int setTextX(int value);

    int getTextY();
    int setTextY(int value);
};