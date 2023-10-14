#include "OlxAPIGraphicsType3Obj.h"

OlxAPIGraphicsType3Obj::OlxAPIGraphicsType3Obj(int handle, int objType) : OlxAPIGraphicsObj(handle, objType)
{
    for (int i = 0; i < 4; i++) //  maximum of 4 points, 3 segments
    {
        pointsX.push_back(getData(i + 1));
        pointsY.push_back(getData(i * 2 + 2));
    }
}

int OlxAPIGraphicsType3Obj::getNSegments()
{
    return getData(0);
}

int OlxAPIGraphicsType3Obj::setNSegments(int value)
{
    if (value == 1 || value == 3)
    {
        return setData(0, value);
    }
    else
        OLXAPI_FAILURE;
}

int OlxAPIGraphicsType3Obj::getPointX(int index)
{
    if (index < 4)
        return pointsX[index];
    else
        return OLXAPI_FAILURE;
}

int OlxAPIGraphicsType3Obj::setPointX(int index, int value)
{
    pointsX[index] = value;
    return setData(index * 2 + 1, value);
}

int OlxAPIGraphicsType3Obj::getPointY(int index)
{
    return pointsY[index];
}

int OlxAPIGraphicsType3Obj::setPointY(int index, int value)
{
    pointsY[index] = value;
    return setData(index * 2 + 2, value);
}

int OlxAPIGraphicsType3Obj::getText1X()
{
    return getData(9);
}

int OlxAPIGraphicsType3Obj::setText1X(int value)
{
    return setData(9, value);
}

int OlxAPIGraphicsType3Obj::getText1Y()
{
    return getData(10);
}

int OlxAPIGraphicsType3Obj::setText1Y(int value)
{
    return setData(10, value);
}

int OlxAPIGraphicsType3Obj::getText2X()
{
    return getData(11);
}

int OlxAPIGraphicsType3Obj::setText2X(int value)
{
    return setData(11, value);
}

int OlxAPIGraphicsType3Obj::getText2Y()
{
    return getData(12);
}

int OlxAPIGraphicsType3Obj::setText2Y(int value)
{
    return setData(12, value);
}
