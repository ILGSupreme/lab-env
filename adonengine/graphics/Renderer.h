#ifndef _RENDERER_H_
#define _RENDERER_H_
#include "IBase.h"
#include "counter.h"
#include <stdexcept>
#include <DataStructures.h>

namespace AdonEngine
{
  namespace Graphics
  {
    class Renderer : private Base::Counter<Renderer>
    {
    public:
      using Base::Counter<Renderer>::GetCount;
       Renderer(ScGr,CaCo);
      ~Renderer();
      void Update();
    private:
      ScGr sceneId;
      CaCo contId;
    };
  }
}

#endif // _RENDERER_H_