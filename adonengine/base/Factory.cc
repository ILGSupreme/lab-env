#include "Factory.h"
#include "Renderer.h"

AdonEngine::Base::Factory::Factory(){
}

AdonEngine::Base::Factory::Factory(const AdonEngine::Base::Factory& rs)
{
}

AdonEngine::Base::Factory& AdonEngine::Base::Factory::operator=(const AdonEngine::Base::Factory& rs){
  return *this;
}

AdonEngine::Base::Factory::~Factory(){
  m_Factorymap.clear();
}

AdonEngine::Base::Factory* AdonEngine::Base::Factory::getInstance()
{
  static Factory pInstance;
  return &pInstance;
}

void AdonEngine::Base::Factory::Register(const std::string& name, CreateBase pfnCreate){
  m_Factorymap[name] = pfnCreate;
}


AdonEngine::Base::IBase* AdonEngine::Base::Factory::CreateIBase(const std::string& name)
{
  FactoryMap::iterator it = m_Factorymap.find(name);
  if(it != m_Factorymap.end())
    return it->second();
  return NULL;
}