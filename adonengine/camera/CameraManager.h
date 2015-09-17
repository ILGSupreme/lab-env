#ifndef _CAMERA_MANAGER_H_
#define _CAMERA_MANAGER_H_
#include <IBase.h>
#include "DataStructures.h"
#include "CameraContainer.h"

namespace AdonEngine
{
  namespace Camera
  {
    class CameraManager : public Base::IBase , private Base::Counter<CameraManager>
    {
    public:
      ~CameraManager();
      using Base::Counter<CameraManager>::GetCount;
      static AdonEngine::Camera::CameraManager* Instance();
      void Update();
      void Free();
      void Init();
    private:
      CameraManager();
      static CameraManager* _instance;
      static void Create();
    public:
      CameraContainer& GetContainer(const CaCo& id);
    };
  }
}

#define CAMSIN()(AdonEngine::Camera::CameraManager::Instance())
#endif // _CAMERA_MANAGER_H_