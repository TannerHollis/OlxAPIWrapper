#pragma once

#include "OlxAPIGraphicsObj.h"
#include <vector>

class OlxAPIGraphicsType5Obj : public OlxAPIGraphicsObj
{
    /*
    TC_LINE, TC_SCAP : noSegs, p1X, p2X...., text1X, text1Y, text2X, text2Y
    */
public:
    OlxAPIGraphicsType5Obj(int handle, int objType);

    int getNSegments();
    int setNSegments(int value);

    int addSegment(int index, int x0, int y0, int x1, int y1);
    int removeSegment(int index);

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
    int getTextPositionOffset(int offset);

    vector<int> pointsX;
    vector<int> pointsY;
};