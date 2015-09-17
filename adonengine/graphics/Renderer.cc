#include "Renderer.h"
#include <ContainerManager.h>
#include <ObjectManager.h>
#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <map>
#include <iostream>

AdonEngine::Graphics::Renderer::Renderer(ScGr scenegraph ,CaCo camcontainer): 
sceneId(scenegraph) , contId(camcontainer){}

AdonEngine::Graphics::Renderer::~Renderer(){}

void AdonEngine::Graphics::Renderer::Update(){
  const float red[] = {0.0f,0.0f,0.0f,1.0f};
  const float one = 1.0f;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearBufferfv(GL_COLOR, 0,red);
  glClearBufferfv(GL_DEPTH,0,&one);
  for(std::map<string,Camera>::iterator it=CONTSIN()->GetCamCont(contId).GetCameras().begin(); it != CONTSIN()->GetCamCont(contId).GetCameras().end();it++)
  {
    if(it->second.isActive())
    {
      glEnable(GL_SCISSOR_TEST);
      glScissor(it->second.GetViewPort().x, it->second.GetViewPort().y, it->second.GetViewPort().width, it->second.GetViewPort().height);
      glClearBufferfv(GL_DEPTH, 0, &one);
      glViewport(it->second.GetViewPort().x, it->second.GetViewPort().y, it->second.GetViewPort().width, it->second.GetViewPort().height);
      glDisable(GL_SCISSOR_TEST);
      for(size_t i=0;i<OBJSIN()->GetActiveSceneIds().Count();i++)
      {
	if(OBJSIN()->GetActiveSceneIds()[i]==1)
	  CONTSIN()->GetScenegraphs()[i].Render(it->second);
      }
    }
  }
}