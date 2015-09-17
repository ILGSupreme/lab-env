#ifndef _SINGLETON_INTERFACE_H_
#define _SINGLETON_INTERFACE_H_
#include "counter.h"
namespace AdonEngine
{
  namespace Base
  {
    class IBase
    {
    public:
	virtual void Free() = 0;
	virtual void Update(){};
	virtual void Init() = 0;
    };
  }
}

#endif //_SINGLETON_INTERFACE_H_