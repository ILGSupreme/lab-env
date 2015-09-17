#include <PhysicsManager.h>

AdonEngine::Physics::PhysicsManager* AdonEngine::Physics::PhysicsManager::_instance = nullptr;

AdonEngine::Physics::PhysicsManager::PhysicsManager(){
}


AdonEngine::Physics::PhysicsManager::~PhysicsManager(){
  Physics::PhysicsManager::_instance = nullptr;
}


void AdonEngine::Physics::PhysicsManager::Create(){
  Physics::PhysicsManager::_instance = new PhysicsManager();
}

void AdonEngine::Physics::PhysicsManager::Free(){
  delete this;
}

void AdonEngine::Physics::PhysicsManager::Init(){

}

AdonEngine::Physics::PhysicsManager* AdonEngine::Physics::PhysicsManager::Instance()
{
  if(!Physics::PhysicsManager::_instance)Physics::PhysicsManager::Create();
  return Physics::PhysicsManager::_instance;
}

void AdonEngine::Physics::PhysicsManager::Update(){
}