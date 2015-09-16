#include "IntersectionTest.h"
#include <limits>
#include "interval.h"

std::tuple< bool, float > AdonEngine::Physics::IntersectionTest::RaySphere(AdonEngine::Physics::Ray ray, AdonEngine::Physics::Bounds* bounds)
{
  return std::tuple<bool,float>(true,0);
}


std::tuple<bool,AdonEngine::Time::Interval> AdonEngine::Physics::IntersectionTest::RayAABB(AdonEngine::Physics::Ray ray, AdonEngine::Physics::Bounds* bounds, Vector3f globpos)
{
      float tmin = 0;
      float tmax = std::numeric_limits<float>::infinity();

      Vector3f max = bounds->Max()+globpos;
      Vector3f min = bounds->Min()+globpos;
      
      for(int i=0;i<3;i++)
      {
	if(ray.origin[i] < min[i] && ray.direction[i] <= 0){
	  //no hit;
	  return std::tuple<bool,AdonEngine::Time::Interval>(false,AdonEngine::Time::Interval(0,0));
	}
	
	if(ray.origin[i] > max[i] && ray.direction[i] >= 0){
	  //no hit
	  return std::tuple<bool,AdonEngine::Time::Interval>(false,AdonEngine::Time::Interval(0,0));
	}
	
	float t1 = (min[i]-ray.origin[i]) / ray.direction[i];
	float t2 = (max[i]-ray.origin[i]) / ray.direction[i];
	
	float ltmin = t1 < t2 ? t1 : t2;
	float ltmax = t1 > t2 ? t1 : t2;
	
	
	tmin = tmin > ltmin ? tmin : ltmin;
	tmax = tmax < ltmax ? tmax : ltmax;
	
	if(tmin > tmax){
	  return std::tuple<bool,AdonEngine::Time::Interval>(false,AdonEngine::Time::Interval(0,0));
	}
      }
      return std::tuple<bool,AdonEngine::Time::Interval>(true,AdonEngine::Time::Interval(tmax,tmin));
}