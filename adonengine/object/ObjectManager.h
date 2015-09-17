#ifndef _OBJECT_MANAGER_H_
#define _OBJECT_MANAGER_H_
#include <IBase.h>
#include <Array.h>
#include "Object3D.h"

namespace AdonEngine
{
  namespace Object
  {
    class ObjectManager : public Base::IBase , private Base::Counter<ObjectManager>
    {
    public:
      using Base::Counter<ObjectManager>::GetCount;
      static AdonEngine::Object::ObjectManager* Instance();
      void Update();
      void Free();
      void Init();
    private:
      ObjectManager();
     ~ObjectManager();
      static ObjectManager* _instance;
      static void Create();
    public:
      Object3D& GetObject(const Ob3D& id);
      AdonEngine::Base::Array<size_t>& GetActiveSceneIds();
      void ActivateSceneGraph(const ScGr& id);
      void DeactivateSceneGraph(const ScGr& id);
    private:
      AdonEngine::Base::Array<size_t> activeScenegraphs;
    };
  }
}

#define OBJSIN()(AdonEngine::Object::ObjectManager::Instance())

#endif //_OBJECT_MANAGER_H_