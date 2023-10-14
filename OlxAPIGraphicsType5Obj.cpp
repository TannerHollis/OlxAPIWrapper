#include "OlxAPIGraphicsType5Obj.h"

OlxAPIGraphicsType5Obj::OlxAPIGraphicsType5Obj(int handle, int objType) : OlxAPIGraphicsObj(handle, objType)
{
    int segments = getNSegments();
    for (int i = 0; i < segments + 1; i++) //  maximum of n points, n-1 segments
    {
        pointsX.push_back(getData(i * 2 + 1));
        pointsY.push_back(getData(i * 2 + 2));
    }
}

int OlxAPIGraphicsType5Obj::getNSegments()
{
    return getData(0);
}

int OlxAPIGraphicsType5Obj::setNSegments(int value)
{
    if (value == 1 || value == 3)
    {
        return setData(0, value);
    }
    else
        OLXAPI_FAILURE;
}

int OlxAPIGraphicsType5Obj::addSegment(int index, int x, int y, int x1, int y1)
{
    // Does not work
    return OLXAPI_OK;
}

int OlxAPIGraphicsType5Obj::removeSegment(int index)
{
    // Does not work
    return OLXAPI_OK;
}

int OlxAPIGraphicsType5Obj::getPointX(int index)
{
    if (index < 4)
        return pointsX[index];
    else
        return OLXAPI_FAILURE;
}

int OlxAPIGraphicsType5Obj::setPointX(int index, int value)
{
    pointsX[index] = value;
    return setData(index * 2 + 1, value);
}

int OlxAPIGraphicsType5Obj::getPointY(int index)
{
    return pointsY[index];
}

int OlxAPIGraphicsType5Obj::setPointY(int index, int value)
{
    pointsY[index] = value;
    return setData(index * 2 + 2, value);
}

int OlxAPIGraphicsType5Obj::getText1X()
{
    return getData(getTextPositionOffset(0));
}

int OlxAPIGraphicsType5Obj::setText1X(int value)
{
    return setData(getTextPositionOffset(0), value);
}

int OlxAPIGraphicsType5Obj::getText1Y()
{
    return getData(getTextPositionOffset(1));
}

int OlxAPIGraphicsType5Obj::setText1Y(int value)
{
    return setData(getTextPositionOffset(1), value);
}

int OlxAPIGraphicsType5Obj::getText2X()
{
    return getData(getTextPositionOffset(2));
}

int OlxAPIGraphicsType5Obj::setText2X(int value)
{
    return setData(getTextPositionOffset(2), value);
}

int OlxAPIGraphicsType5Obj::getText2Y()
{
    return getData(getTextPositionOffset(3));
}

int OlxAPIGraphicsType5Obj::setText2Y(int value)
{
    return setData(getTextPositionOffset(3), value);
}

int OlxAPIGraphicsType5Obj::getTextPositionOffset(int offset)
{
    return (getNSegments() + 1) * 2 + 1 + offset;
}
