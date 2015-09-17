#include "Bounds.h"

BDEF AdonEngine::Physics::Bounds::Def()
{
  return def;
}

float AdonEngine::Physics::Bounds::Radius()
{
  return radius;
}

Vector3f AdonEngine::Physics::Bounds::Center()
{
  return center;
}

Vector3f AdonEngine::Physics::Bounds::Max()
{
  return max;
}

Vector3f AdonEngine::Physics::Bounds::Min()
{
  return min;
}

void AdonEngine::Physics::Bounds::SetGlobalPos(Vector3f pos)
{
  this->globalpos = pos;
}

Vector3f AdonEngine::Physics::Bounds::GlobalPos()
{
  return this->globalpos;
}

AdonEngine::Physics::BoundingBox::BoundingBox(vector<Vector3f> positions)
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


AdonEngine::Physics::BoundingSphere::BoundingSphere(vector<Vector3f> positions)
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