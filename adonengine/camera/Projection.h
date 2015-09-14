#ifndef _PROJECTION_H_
#define _PROJECTION_H_
#include "SamMathsMatrices.h"
#include "Viewport.h"
#include "Ray.h"

namespace Util
{
  
  static Vector3f Project(Vector3f pos,Matrix4F trans,Viewport& view){
    Vector4f pos_modelspace(pos[0],pos[1],pos[2],1);
    Vector4f pos_clipspace = pos_modelspace * trans;
    
    float w= pos_clipspace[3];
    
    pos_clipspace = pos_clipspace * (1/w);
    
    Vector3f pos_viewport(
      ((pos_clipspace[0]+1)/2)*view.width,
      ((pos_clipspace[1]+1)/2)*view.height,
      ((pos_clipspace[2]+1)/2)
	     );
    
    return Vector3f(pos_viewport[0]+view.x,
		    pos_viewport[1]+view.y,
		    pos_viewport[2]
		   );
  }
  
  
  static Vector3f Unproject(Vector3f pos,Matrix4F trans,Viewport& view){
    //screen space->viewport space
    //viewport-> clipspace
    //clipspace -> modelspace
    
    Vector3f pos_viewport;
    pos_viewport[0]=pos[0]-view.x;
    pos_viewport[1]=pos[1]-view.y;
    pos_viewport[2]=pos[2];
    
    
    Vector4f pos_clipspace;
    pos_clipspace[0] = (pos_viewport[0]/view.width) * 2 -1;
    pos_clipspace[1] = (pos_viewport[1]/view.height) * 2 -1;
    pos_clipspace[2] = (pos_viewport[2]*2) -1;
    pos_clipspace[3] = 1;
    
    Vector4f pos_modelspace = pos_clipspace * trans.GetInverse();
    
    float w = pos_modelspace[3];
    
    return Vector3f(pos_modelspace[0]/w,
		    pos_modelspace[1]/w,
		    pos_modelspace[2]/w);
  }
  
  
  static AdonPhysics::Ray CreateRay(Vector2f pos,Matrix4F Perspective,Matrix4F View,float nearPlane,float lenght)
  {
    Vector4f point((pos[0]-0.5)*2,(pos[1]-0.5)*2,1,1);
    Vector4f pv = point * Perspective.GetInverse();
    
    Vector4f pl(pv[0],pv[1]*-1,pv[2]*nearPlane,pv[3]);
    
    Matrix4F ViewInv = View.GetInverse();
    
    Vector4f pw = pl * ViewInv;
    
    Vector4f viewpos(ViewInv[0][3],ViewInv[1][3],ViewInv[2][3],ViewInv[3][3]);
    
    Vector4f dw = pw - viewpos;
    
    Vector3f dir(dw[0],dw[1],dw[2]);
    dir.normalize();
    
    Vector3f raypos(pw[0],pw[1],pw[2]);
    //raypos.normalize();
    
    return AdonPhysics::Ray(raypos,dir,lenght);
    
  }
  
}

#endif