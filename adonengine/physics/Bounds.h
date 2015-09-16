#ifndef _BOUNDS_H_
#define _BOUNDS_H_
#include "SamMathsMatrices.h"
#include <vector>
using namespace std;

enum BDEF
{
  BOUNDINGBOX,
  BOUNDINGSPHERE,
};

namespace AdonEngine
{
  namespace Physics
  {
    class Bounds
    {
    public:
      virtual BDEF Def();
      virtual float Radius();
      virtual Vector3f Center();
      virtual Vector3f Max();
      virtual Vector3f Min();
      virtual void SetGlobalPos(Vector3f);
      virtual Vector3f GlobalPos();
    protected:
      BDEF def;
      vector<Vector3f> object_positions;
      float radius;
      Vector3f center;
      Vector3f max;
      Vector3f min;
      Vector3f globalpos;
    };
    
    
    class BoundingBox : public Bounds
    {
    public:
       /*
       *	BoundingBox
       *	Constructs the bounding sphere from the meshs vertex positions
       */
      BoundingBox(vector<Vector3f> positions);
    };
    
    
    class BoundingSphere : public Bounds
    {
    public:
      /*
       *	BoundingSphere
       *	Constructs the bounding sphere from the meshs vertex positions
       */
      BoundingSphere(vector<Vector3f> positions);
    };
  }
}
#endif //_BOUNDS_H_