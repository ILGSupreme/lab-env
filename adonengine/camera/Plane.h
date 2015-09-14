#ifndef _PLANE_H_
#define _PLANE_H_

#include <math.h>

struct Plane
{
	float a, b, c, d;
	void Normalize()
	{
		float mag = sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2) + pow(d, 2));
		a = a / mag;
		b = b / mag;
		c = c / mag;
		d = d / mag;
	}
	float DistanceToPoint(const Vector3f & point)
	{
		return a*point[0] + b*point[1] + c*point[2] + d;
	}
};

#endif