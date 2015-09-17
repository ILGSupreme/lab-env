#ifndef _CONTAINER_MANAGER_H_
#define _CONTAINER_MANAGER_H_
#include "counter.h"
#include "IBase.h"
#include "Object3D.h"
#include "CameraContainer.h"
#include "DataStructures.h"
#include "Array.h"

namespace AdonEngine
{
  namespace Base
  {
    class ContainerManager : public Base::IBase, private Base::Counter<ContainerManager>
    {
    public:
      using Base::Counter<ContainerManager>::GetCount;
      static AdonEngine::Base::ContainerManager* Instance();
      void Init();
      void Free();
    private:
      ContainerManager();
      ~ContainerManager();
      static ContainerManager* _instance;
      static void Create();
    public:
      CameraContainer& GetCamCont(const CaCo& id);
      Object3D& GetObject3D(const Ob3D& id);
      Object3D& GetScenegraph(const ScGr& id);
      Array<Object3D>& GetScenegraphs();
      Array<CameraContainer>& GetContainers();
    private:
      Array<Object3D> objects;
      Array<Object3D> scenegraphs;
      Array<CameraContainer> camcontainers;
    };
  }
}

#define CONTSIN()(AdonEngine::Base::ContainerManager::Instance())
#endif // _CONTAINER_MANAGER_H_