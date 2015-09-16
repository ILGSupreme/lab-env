#ifndef _PHYSICS_H_
#define _PHYSICS_H_
#include "Bounds.h"
#include "Ray.h"
#include "interval.h"
#include <tuple>
namespace AdonEngine
{
  namespace Physics
  {
    namespace IntersectionTest
    {
      std::tuple<bool,float> RaySphere(AdonEngine::Physics::Ray ray,Bounds* bounds);
      std::tuple<bool,AdonEngine::Time::Interval> RayAABB(AdonEngine::Physics::Ray ray,Bounds* bounds,Vector3f globalpos);
    }
  }
}

#endif // _PHYSICS_H_