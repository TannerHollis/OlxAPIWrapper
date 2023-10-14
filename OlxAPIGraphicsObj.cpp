#include "OlxAPIGraphicsObj.h"

OlxAPIGraphicsObj::OlxAPIGraphicsObj(int handle, int objType)
{
    this->handle = handle;
    this->objType = objType;
    this->gfxObjType = getGraphicsObjType(objType);
    int ret = OlxAPIGetObjGraphicData(handle, data);
}

int OlxAPIGraphicsObj::getData(int offset)
{
    return data[offset];
}

int OlxAPIGraphicsObj::setData(int offset, int value)
{
    data[offset] = value;
    int ret = OlxAPISetObjGraphicData(handle, data);
    if (ret != OLXAPI_FAILURE)
        cout << "Success writing graphics obj" << endl;
    return ret;
}

OlxAPIGraphicsObj::GraphicsObjType OlxAPIGraphicsObj::getGraphicsObjType(int objType)
{
    switch (objType)
    {
    case TC_BUS:
        return GFXOBJ_TYPE_0;
    case TC_GEN:
        return GFXOBJ_TYPE_1;
    case TC_GENW3:
        return GFXOBJ_TYPE_1;
    case TC_GENW4:
        return GFXOBJ_TYPE_1;
    case TC_CCGEN:
        return GFXOBJ_TYPE_1;
    case TC_LOAD:
        return GFXOBJ_TYPE_1;
    case TC_SHUNT:
        return GFXOBJ_TYPE_1;
    case TC_SVD:
        return GFXOBJ_TYPE_1;
    case TC_XFMR:
        return GFXOBJ_TYPE_2;
    case TC_PS:
        return GFXOBJ_TYPE_2;
    case TC_SCAP:
        return GFXOBJ_TYPE_2;
    case TC_SWITCH:
        return GFXOBJ_TYPE_2;
    case TC_DCLINE2:
        return GFXOBJ_TYPE_2;
    case TC_XFMR3:
        return GFXOBJ_TYPE_3;
    case TC_LINE:
        return GFXOBJ_TYPE_4;
    case TC_SYS:
        return GFXOBJ_TYPE_5;
    default:
        return GFXOBJ_TYPE_UNKNOWN;
    }
}
