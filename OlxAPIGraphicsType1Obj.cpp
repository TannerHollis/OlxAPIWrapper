#include "OlxAPIGraphicsType1Obj.h"

int OlxAPIGraphicsType1Obj::getSize()
{
    return getData(0);
}

int OlxAPIGraphicsType1Obj::setSize(int value)
{
    return setData(0, value);
}

int OlxAPIGraphicsType1Obj::getAngle()
{
    return getData(1);
}

int OlxAPIGraphicsType1Obj::setAngle(int value)
{
    return setData(1, value);
}

int OlxAPIGraphicsType1Obj::getX()
{
    return getData(2);
}

int OlxAPIGraphicsType1Obj::setX(int value)
{
    return setData(2, value);
}

int OlxAPIGraphicsType1Obj::getY()
{
    return getData(3);
}

int OlxAPIGraphicsType1Obj::setY(int value)
{
    return setData(3, value);
}

int OlxAPIGraphicsType1Obj::getNameX()
{
    return getData(4);
}

int OlxAPIGraphicsType1Obj::setNameX(int value)
{
    return setData(4, value);
}

int OlxAPIGraphicsType1Obj::getNameY()
{
    return getData(5);
}

int OlxAPIGraphicsType1Obj::setNameY(int value)
{
    return setData(5, value);
}

int OlxAPIGraphicsType1Obj::getHideID()
{
    return getData(6);
}

int OlxAPIGraphicsType1Obj::setHideID(int value)
{
    return setData(6, value);
}