#include "OlxAPIGraphicsType2Obj.h"

int OlxAPIGraphicsType2Obj::getX()
{
    return getData(0);
}

int OlxAPIGraphicsType2Obj::setX(int value)
{
    return setData(0, value);
}

int OlxAPIGraphicsType2Obj::getY()
{
    return getData(1);
}

int OlxAPIGraphicsType2Obj::setY(int value)
{
    return setData(1, value);
}

int OlxAPIGraphicsType2Obj::getAngle()
{
    return getData(2);
}

int OlxAPIGraphicsType2Obj::setAngle(int value)
{
    return setData(2, value);
}

int OlxAPIGraphicsType2Obj::getTextX()
{
    return getData(3);
}

int OlxAPIGraphicsType2Obj::setTextX(int value)
{
    return setData(3, value);
}

int OlxAPIGraphicsType2Obj::getTextY()
{
    return getData(4);
}

int OlxAPIGraphicsType2Obj::setTextY(int value)
{
    return setData(4, value);
}