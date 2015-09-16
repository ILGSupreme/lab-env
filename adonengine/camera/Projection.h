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
}

#endif //_PROJECTION_H_