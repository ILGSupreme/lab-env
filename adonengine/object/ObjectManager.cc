#include "ObjectManager.h"
#include <ContainerManager.h>
#include <iostream>
#include <stdexcept>
#include <Array.h>
#include <utility>

AdonEngine::Object::ObjectManager* AdonEngine::Object::ObjectManager::_instance = nullptr;

AdonEngine::Object::ObjectManager::ObjectManager(){
  activeScenegraphs = Base::Array<size_t>(CONTSIN()->GetScenegraphs().Count());
}

AdonEngine::Object::ObjectManager::~ObjectManager()
{
  Object::ObjectManager::_instance = nullptr;
}

void AdonEngine::Object::ObjectManager::Create()
{
  Object::ObjectManager::_instance = new ObjectManager();
}

AdonEngine::Object::ObjectManager* AdonEngine::Object::ObjectManager::Instance()
{
  if(!Object::ObjectManager::_instance) Object::ObjectManager::Create();
  return Object::ObjectManager::_instance;
}

Object3D& AdonEngine::Object::ObjectManager::GetObject(const Ob3D& id)
{
  return AdonEngine::Base::ContainerManager::Instance()->GetObject3D(id);
}

AdonEngine::Base::Array< size_t >& AdonEngine::Object::ObjectManager::GetActiveSceneIds()
{
  return this->activeScenegraphs;
}

void AdonEngine::Object::ObjectManager::ActivateSceneGraph(const ScGr& id)
{
  if(id > activeScenegraphs.Count()){
    std::runtime_error("value is bigger than the size of the array");
  }
  activeScenegraphs[id]=1;
}

void AdonEngine::Object::ObjectManager::DeactivateSceneGraph(const ScGr& id)
{
  if(id > activeScenegraphs.Count()){
    std::runtime_error("value is bigger than the size of the array");
  }
  activeScenegraphs[id]=0;
}

void AdonEngine::Object::ObjectManager::Update(){
  for(size_t i; i < activeScenegraphs.Count(); i++){
    if(activeScenegraphs[i]==1){
      CONTSIN()->GetScenegraphs()[i].Update(Mat4::InitIdentityMat4F());
    }
  }
}

void AdonEngine::Object::ObjectManager::Free()
{
  delete this;
}

void AdonEngine::Object::ObjectManager::Init()
{
  
}