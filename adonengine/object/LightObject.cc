#include "LightObject.h"


LightObject::LightObject(Vector3f pos, float color, float power) : pos(pos), color(color),power(power)
{

}


Vector3f LightObject::GetPos()
{
  return this->pos;
}