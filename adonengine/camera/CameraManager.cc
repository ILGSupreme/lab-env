#include "CameraManager.h"
#include <ContainerManager.h>

AdonEngine::Camera::CameraManager* AdonEngine::Camera::CameraManager::_instance = nullptr;

AdonEngine::Camera::CameraManager::CameraManager(){
}


AdonEngine::Camera::CameraManager::~CameraManager(){
  Camera::CameraManager::_instance = nullptr;
}


void AdonEngine::Camera::CameraManager::Create(){
  Camera::CameraManager::_instance = new CameraManager();
}

void AdonEngine::Camera::CameraManager::Free(){
  delete this;
}

void AdonEngine::Camera::CameraManager::Init(){
}

CameraContainer& AdonEngine::Camera::CameraManager::GetContainer(const CaCo& id){
  return AdonEngine::Base::ContainerManager::Instance()->GetCamCont(id);
}

AdonEngine::Camera::CameraManager* AdonEngine::Camera::CameraManager::Instance(){
  if(!Camera::CameraManager::_instance)Camera::CameraManager::Create();
  return Camera::CameraManager::_instance;
}

void AdonEngine::Camera::CameraManager::Update(){
  for(int i;i<CONTSIN()->GetContainers().Count();i++){
    CONTSIN()->GetContainers()[i].Update();
  }
}

