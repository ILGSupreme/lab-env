#ifndef _INTERVAL_H_
#define _INTERVAL_H_

namespace AdonEngine
{
  namespace Time
  {
    class Interval
    {
    public:
      Interval(float tmax,float tmin);
      float getMax();
      float getMin();
    private:
      float tmax;
      float tmin;
    };
  }
}




#endif // _INTERVAL_H_