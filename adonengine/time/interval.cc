#include "interval.h"


AdonEngine::Time::Interval::Interval(float max,float min):tmax(max),tmin(min){
}


float AdonEngine::Time::Interval::getMax()
{
  return tmax;
}

float AdonEngine::Time::Interval::getMin()
{
  return tmin;
}