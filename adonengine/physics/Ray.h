#ifndef _RAY_H_
#define _RAY_H_
#include "SamMathsVectors.h"

namespace AdonEngine
{
  namespace Physics
  {
    struct Ray{
      Ray(){
	
      }
      
      Ray(Vector3f origin,Vector3f direction,float distance):t(1){
	this->origin = origin;
	this->direction = direction;
	this->distance = distance;
      }
      Vector3f origin;
      Vector3f direction;
      float t;
      float distance;
      
    };
  }
}
#endif //_RAY_H_