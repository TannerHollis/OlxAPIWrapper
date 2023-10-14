#include "OlxAPIGraphicsType4Obj.h"

OlxAPIGraphicsType4Obj::OlxAPIGraphicsType4Obj(int handle, int objType) : OlxAPIGraphicsObj(handle, objType)
{
    for (int i = 0; i < 6; i++) //  maximum of 6 points, 5 segments
    {
        pointsX.push_back(getData(i + 1));
        pointsY.push_back(getData(i * 2 + 2));
    }
}

int OlxAPIGraphicsType4Obj::getNSegments()
{
    return getData(0);
}

int OlxAPIGraphicsType4Obj::setNSegments(int value)
{
    if (value == 1 || value == 3)
    {
        return setData(0, value);
    }
    else
        OLXAPI_FAILURE;
}

int OlxAPIGraphicsType4Obj::getPointX(int index)
{
    if (index < 4)
        return pointsX[index];
    else
        return OLXAPI_FAILURE;
}

int OlxAPIGraphicsType4Obj::setPointX(int index, int value)
{
    pointsX[index] = value;
    return setData(index * 2 + 1, value);
}

int OlxAPIGraphicsType4Obj::getPointY(int index)
{
    return pointsY[index];
}

int OlxAPIGraphicsType4Obj::setPointY(int index, int value)
{
    pointsY[index] = value;
    return setData(index * 2 + 2, value);
}

int OlxAPIGraphicsType4Obj::getText1X()
{
    return getData(13);
}

int OlxAPIGraphicsType4Obj::setText1X(int value)
{
    return setData(13, value);
}

int OlxAPIGraphicsType4Obj::getText1Y()
{
    return getData(14);
}

int OlxAPIGraphicsType4Obj::setText1Y(int value)
{
    return setData(14, value);
}

int OlxAPIGraphicsType4Obj::getText2X()
{
    return getData(15);
}

int OlxAPIGraphicsType4Obj::setText2X(int value)
{
    return setData(15, value);
}

int OlxAPIGraphicsType4Obj::getText2Y()
{
    return getData(16);
}

int OlxAPIGraphicsType4Obj::setText2Y(int value)
{
    return setData(16, value);
}

int OlxAPIGraphicsType4Obj::getText3X()
{
    return getData(17);
}

int OlxAPIGraphicsType4Obj::setText3X(int value)
{
    return setData(17, value);
}

int OlxAPIGraphicsType4Obj::getText3Y()
{
    return getData(18);
}

int OlxAPIGraphicsType4Obj::setText3Y(int value)
{
    return setData(18, value);
}
