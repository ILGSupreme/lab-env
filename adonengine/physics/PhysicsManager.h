#ifndef _PHYSICS_MANAGER_H_
#define _PHYSICS_MANAGER_H_
#include <IBase.h>
#include <counter.h>

namespace AdonEngine
{
  namespace Physics
  {
    class PhysicsManager : public Base::IBase , private Base::Counter<PhysicsManager>
    {
    public:
      using Base::Counter<PhysicsManager>::GetCount;
      static AdonEngine::Physics::PhysicsManager* Instance();
      void Update();
      void Free();
      void Init();
    private:
      PhysicsManager();
      ~PhysicsManager();
      static PhysicsManager* _instance;
      static void Create();
    };
  }
}

#define PHYSIN()(AdonEngine::Physics::PhysicsManager::Instance())

#endif // _PHYSICS_MANAGER_H_