#ifndef _PHYSICS_UTIL_H_
#define _PHYSICS_UTIL_H_

#include "SamMathsMatrices.h"
#include "Ray.h"
#include "Object3D.h"
#include <map>

namespace AdonEngine
{
  namespace Physics
  {
    namespace PhysicsUtil
    {
      AdonEngine::Physics::Ray CreateRay(Vector2f pos,Matrix4F Perspective,Matrix4F View,float nearPlane,float lenght);
      Object3D* RaycastDummyFunc(AdonEngine::Physics::Ray, std::map<int,Object3D>* scenegraph);
    }
  }
}


#endif //_PHYSICS_UTIL_H_