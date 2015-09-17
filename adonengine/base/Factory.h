#ifndef _SINGLETON_H_
#define _SINGLETON_H_
#include <map>
#include "IBase.h"
#include <Object3D.h>
#include <CameraContainer.h>

//will change!
typedef AdonEngine::Base::IBase* (*CreateBase)(void);
typedef std::map<std::string,CreateBase> FactoryMap;

namespace AdonEngine
{
  namespace Base
  {
    class Factory
    {
    private:
      Factory();
      Factory(const Factory& rs);
      Factory &operator=(const Factory& rs);
      FactoryMap m_Factorymap;
    public:
     ~Factory();
      static Factory* getInstance();
      void Register(const std::string& name, CreateBase pfnCreate);
      IBase *CreateIBase(const std::string &name);
    };
  }
}

#endif // _SINGLETON_H_