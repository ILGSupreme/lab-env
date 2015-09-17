#include "ContainerManager.h"

AdonEngine::Base::ContainerManager* AdonEngine::Base::ContainerManager::_instance = nullptr;


AdonEngine::Base::ContainerManager::ContainerManager(){
  objects = Array<Object3D>(100);
  camcontainers = Array<CameraContainer>(10);
  scenegraphs = Array<Object3D>(10);
}

void AdonEngine::Base::ContainerManager::Create(){
  Base::ContainerManager::_instance = new ContainerManager();
}

AdonEngine::Base::ContainerManager* AdonEngine::Base::ContainerManager::Instance(){
  if(!Base::ContainerManager::_instance)Base::ContainerManager::Create();
  return Base::ContainerManager::_instance;
}

AdonEngine::Base::ContainerManager::~ContainerManager(){
}

void AdonEngine::Base::ContainerManager::Init(){
}

void AdonEngine::Base::ContainerManager::Free(){
  delete this;
}

CameraContainer& AdonEngine::Base::ContainerManager::GetCamCont(const CaCo& id){
  return camcontainers[id];
}

Object3D& AdonEngine::Base::ContainerManager::GetObject3D(const Ob3D& id){
  return objects[id];
}

Object3D& AdonEngine::Base::ContainerManager::GetScenegraph(const ScGr& id){
  return scenegraphs[id];
}

AdonEngine::Base::Array< Object3D >& AdonEngine::Base::ContainerManager::GetScenegraphs(){
  return scenegraphs;
}

AdonEngine::Base::Array< CameraContainer >& AdonEngine::Base::ContainerManager::GetContainers()
{
  return camcontainers;
}