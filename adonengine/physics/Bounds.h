#ifndef _BOUNDS_H_
#define _BOUNDS_H_
#include "SamMathsMatrices.h"
#include <vector>
using namespace std;

enum BOUNDDEF
{
  BOUNDINGBOX,
  BOUNDINGSPHERE,
};

namespace AdonPhysics
{
  
  class Bounds
  {
  public:
	Bounds()
	{
	}
    	BOUNDDEF def;
	vector<Vector3f> object_positions;
	float radius;
	Vector3f center;
	Vector3f max;
	Vector3f min;
  };
  
  
  class BoundingBox : public Bounds
  {
  public:
    BoundingBox(){}
    
    BoundingBox(vector<Vector3f> positions):Bounds()
    {
      this->object_positions = positions;
      this->def = BOUNDINGBOX;

      Vector3f center = object_positions[0];
      float radius = 0.0001f;
      Vector3f pos, diff;
      float len, alpha, alphaSq;
      
      for (int i = 0; i < 2; i++){
	for (int it = 1; it < object_positions.size(); it++){
	  pos = object_positions[it];
	  diff = pos - center;
	  len = diff.lenght();
	  if (len > radius){
	    alpha = len / radius;
	    alphaSq = alpha * alpha;
	    radius = 0.5f * (alpha + 1 / alpha) * radius;
	    center = 0.5f * ((1 + 1 / alphaSq) * center + (1 - 1 / alphaSq) * pos);
	  }
	}
      }
      
      for (int it = 0; it < object_positions.size(); it++){
	pos = object_positions[it];
	diff = pos - center;
	len = diff.lenght();
	if (len > radius){
	  radius = (radius + len) / 2.0f;
	  center = center + ((len - radius) / len * diff);
	}
      }
      
      this->radius = radius;
      this->center = center;
      
      max = Vector3f(center[0] + radius,center[1] + radius,center[2] + radius);
      min = Vector3f(center[0] - radius,center[1] - radius,center[2] - radius);
    }
  };
  
  
  class BoundingSphere : public Bounds
  {
  public:
	/*
	*	BoundingSphere
	*/
	BoundingSphere() : Bounds()
	{

	}
	/*
	*	BoundingSphere
	*	Constructs the bounding sphere from the meshs vertex positions
	*/
	BoundingSphere(vector<Vector3f> positions) : Bounds()
	{
		this->object_positions = positions;
		this->def = BOUNDINGSPHERE;

		Vector3f center = object_positions[0];
		float radius = 0.0001f;
		Vector3f pos, diff;
		float len, alpha, alphaSq;

		for (int i = 0; i < 2; i++){
			for (int it = 1; it < object_positions.size(); it++){
				pos = object_positions[it];
				diff = pos - center;
				len = diff.lenght();
				if (len > radius){
					alpha = len / radius;
					alphaSq = alpha * alpha;
					radius = 0.5f * (alpha + 1 / alpha) * radius;
					center = 0.5f * ((1 + 1 / alphaSq) * center + (1 - 1 / alphaSq) * pos);
				}
			}
		}

		for (int it = 0; it < object_positions.size(); it++){
			pos = object_positions[it];
			diff = pos - center;
			len = diff.lenght();
			if (len > radius){
				radius = (radius + len) / 2.0f;
				center = center + ((len - radius) / len * diff);
			}
		}

		this->radius = radius;
		this->center = center;

	}
    };
  
}
#endif //_BOUNDS_H_