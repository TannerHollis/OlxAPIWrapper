#pragma once

#include "OlxAPIGraphicsObj.h"
#include <vector>

class OlxAPIGraphicsType4Obj : public OlxAPIGraphicsObj
{
    /*
    TC_XFMR3 : noSegs, p1X, p1Y, p2X, p2Y, p3X, p3Y, p4X, p4Y, p5X, p5Y, p6X, p6Y,
    text1X, text1Y, text2X, text2Y, text3X, text3Y
    !!!noSegs determines if p3and p4 are being used
    */
public:
    OlxAPIGraphicsType4Obj(int handle, int objType);

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

    int getText3X();
    int setText3X(int value);

    int getText3Y();
    int setText3Y(int value);

private:
    vector<int> pointsX;
    vector<int> pointsY;
};