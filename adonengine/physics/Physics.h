#ifndef _PHYSICS_H_
#define _PHYSICS_H_
#include "Bounds.h"
#include "Ray.h"
#include <limits>
namespace AdonPhysics
{
  class Physics
  {
    Physics(){};
    static Physics* _pinstance;
  public:
    ~Physics(){};
    static Physics* getInstance(){
      if(!_pinstance){
	_pinstance = new Physics();
      }
      return _pinstance;
    }
    
    std::tuple<bool,float> RayCast(AdonPhysics::Ray ray,Bounds* bounds)
    {
      float tmin = 0;
      float tmax = std::numeric_limits<float>::infinity();
      
      for(int i=0;i<3;i++){
	if(ray.origin[i] < bounds->min[i] && ray.direction[i] <= 0){
	  //no hit;
	  return std::tuple<bool,float>(false,0);
	}
	if(ray.origin[i] > bounds->max[i] && ray.direction[i] >= 0){
	  //no hit
	  return std::tuple<bool,float>(false,0);
	}
	
	float t1 = (bounds->min[i]-ray.origin[i]) / ray.direction[i];
	float t2 = (bounds->max[i]-ray.origin[i]) / ray.direction[i];
	
	float ltmin = t1 < t2 ? t1 : t2;
	float ltmax = t1 > t2 ? t1 : t2;
	
	
	tmin = tmin > ltmin ? tmin : ltmin;
	tmax = tmax < ltmax ? tmax : ltmax;
	
	if(tmin > tmax){
	  return std::tuple<bool,float>(false,0);
	}
      }
      return std::tuple<bool,float>(true,tmin);
    }
  };
}

AdonPhysics::Physics* AdonPhysics::Physics::_pinstance = nullptr;

#endif // _PHYSICS_H_