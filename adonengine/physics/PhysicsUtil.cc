#include "PhysicsUtil.h"
#include "IntersectionTest.h"
#include "Object3D.h"
#include <map>
#include <iterator>
#include <list>
AdonEngine::Physics::Ray AdonEngine::Physics::PhysicsUtil::CreateRay(Vector2f pos, Matrix4F Perspective, Matrix4F View, float nearPlane, float lenght)
{
    Vector4f point((pos[0]-0.5)*2,(pos[1]-0.5)*2,-1,1);
    Vector4f pv = point * Perspective.GetInverse()*nearPlane*1.1f;
    
    Vector4f pl(pv[0],pv[1]*-1,pv[2],1);
    
    Matrix4F ViewInv = View.GetInverse();
    
    Vector4f pw = pl*ViewInv;
    
    Vector4f viewpos(ViewInv[0][3],ViewInv[1][3],ViewInv[2][3],ViewInv[3][3]);
    
    Vector4f dw = pw - viewpos;
    
    Vector3f dir(dw[0],dw[1],dw[2]);
    dir.normalize();
     
    Vector3f raypos(pw[0],pw[1],pw[2]);
    //raypos.normalize();
    
    return AdonEngine::Physics::Ray(raypos,dir,lenght);
}

Object3D* AdonEngine::Physics::PhysicsUtil::RaycastDummyFunc(AdonEngine::Physics::Ray ray, std::map<int,Object3D>* scenegraph)
{
  float min = 999999;
  Object3D* target = nullptr;
  for(std::map<int,Object3D>::iterator it = scenegraph->begin();it != scenegraph->end();it++)
  {
    if(it->second.GetInstance().GetBounds()->Def()==BOUNDINGBOX)
    {
      Matrix4F globalmatrix = *it->second.GetGlobalAddress();
      Vector3f gm(globalmatrix[0][3],globalmatrix[1][3],globalmatrix[2][3]);
      std::tuple<bool,AdonEngine::Time::Interval> hit = AdonEngine::Physics::IntersectionTest::RayAABB(ray,it->second.GetInstance().GetBounds(),gm);
      if(get<0>(hit))
      {
	if(get<1>(hit).getMin() < min)
	{
	  min = get<1>(hit).getMin();
	  target = &it->second;
	}
	std::cout<<"hit"<<endl;
      }
    }
  }
  return target;
}