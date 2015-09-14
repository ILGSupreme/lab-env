#ifndef _LIGHTOBJECT_H_
#define _LIGHTOBJECT_H_

#include "SamMathsVectors.h"

class LightObject
{
public:
  LightObject(Vector3f pos,float color,float power);
  Vector3f GetPos();
private:
  Vector3f pos;
  float color;
  float power;
};
#endif //_LIGHTOBJECT_H_