#pragma once

#include "OlxAPIGraphicsObj.h"
#include <vector>

class OlxAPIGraphicsType3Obj : public OlxAPIGraphicsObj
{
    /*
    TC_XFMR, TC_PS, TC_SCAP, TC_SWITCH, TC_DCLINE2 :
    noSegs, p1X, p1Y, p2X, p2Y, p3X, p3Y, p4X, p4Y, text1X, text1Y, text2X, text2Y
    !!!noSegs determines if p3and p4 are being used
    */
public:
    OlxAPIGraphicsType3Obj(int handle, int objType);

    int getNSegments();
    int setNSegments(int value);

    int getPointX(int index);
    int setPointX(int index, int value);

    int getPointY(int index);
    int setPointY(int index, int value);

    int getText1X();
    int setText1X(int value);

    int getText1Y();
    int setText1Y(int value);

    int getText2X();
    int setText2X(int value);

    int getText2Y();
    int setText2Y(int value);

private:
    vector<int> pointsX;
    vector<int> pointsY;
};