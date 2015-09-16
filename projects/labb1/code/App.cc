//------------------------------------------------------------------------------
// exampleapp.cc
// (C) 2015 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "App.h"
#include "AdonEngine.h"
#include "Projection.h"
#include "Ray.h"
#include "IntersectionTest.h"
#include "Bounds.h"
#include <PhysicsUtil.h>
#include "Factory.h"
#include "Renderer.h"
#include <ObjectManager.h>
#include <cstring>
#include <stdio.h>

using namespace Display;
namespace GraphicsLabb
{

//------------------------------------------------------------------------------
/**
*/
GraphicsApp::GraphicsApp()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
GraphicsApp::~GraphicsApp()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
bool
GraphicsApp::Open()
{
	App::Open();
	this->window = new Display::Window;
	window->SetSize(1920,1200);
	window->SetKeyPressFunction([this](int32 key, int32 scancode, int32 action, int32 mods)
	{
	  if (key == 256)
	  {
	    window->Close();
	  }
	});
	
	window->SetMouseMoveFunction([this](float64 x ,float64 y)
	{
		xmouse = (float)x;
		ymouse = (float)y;
	  
		//KAMERA!
 		horizontalAngle += mousespeed*deltatime*((width /2)-xmouse);
 		verticalAngle += mousespeed*deltatime*((height /2)-ymouse);
 
 		direction = Vector3f(
			cos(verticalAngle)*sin(horizontalAngle),
 			sin(verticalAngle),
 			cos(verticalAngle)*cos(horizontalAngle)
 			);
 
 		right = Vector3f(sin(horizontalAngle - 3.14f / 2.0), 0, cos(horizontalAngle - 3.14f / 2.0));
 		left = Vector3f(sin(horizontalAngle + 3.14 / 2.0), 0, cos(horizontalAngle + 3.14 / 2.0));
 		up = right.crossProduct(direction);
		
		Matrix4F cameraView = InitLookAtMat4F(position,position+direction, up);
		Matrix4F PV = proj_matrix1 * cameraView;
		Viewport view = eng.GetCamera("FirstPerson")->GetViewPort();
		p1 = Vector3f(xmouse,height-ymouse,0);
		p3 = Vector3f(xmouse,height-ymouse,1);
		Vector2f mousecoord(xmouse/view.width,ymouse/view.height);
		
		//ray_2= AdonEngine::Physics::PhysicsUtil::CreateRay(mousecoord,proj_matrix1,cameraView,0.1f,30);
		
		p2 = Util::Unproject(p1,PV,view);
		p4 =Util::Unproject(p3,PV,view);
		
		p5 = p4-p2;
		
		ray_1 = AdonEngine::Physics::Ray(p2,p5.getnormalize(),10);
		
		std::cout<<"";
	});
	
	window->SetMousePressFunction([this](int32 button, int32 action, int32 mods){
	  double mousexpick = 0;
	  double mouseypick = 1;
	  
	  glfwGetCursorPos(this->window->GetWindow(),&mousexpick,&mouseypick);
	  
	  std::cout<<"xpos:"<<mousexpick<<" "<<"ypos:"<<mouseypick<<"\n"<<std::endl;
	  std::map<int,Object3D>* mapingstuff = eng.getObjects();
	  newtarget = AdonEngine::Physics::PhysicsUtil::RaycastDummyFunc(ray_1, eng.getObjects());
	  //std::cout<<std::get<0>(trg)<<"\n";
 	  if(newtarget!=nullptr)
 	  {
	    Vector3f newvec(1,1,1);
	    if(target!=nullptr)
	    {
	      Vector3f resetvec(0,0,0);
	      target->GetMaterial("target_color").material = resetvec;
	    }
	    target = newtarget;
	    target->GetMaterial("target_color").material = newvec;
 	  }
 	  else
	  {
	    Vector3f resetvec(0,0,0);
	    if(target != nullptr)
	      target->GetMaterial("target_color").material = resetvec;
	  }
	});
	
	if (this->window->Open())
	{
		eng = Adon();
		this->target = nullptr;
		this->newtarget = nullptr;
		eng.CreateShader("VertexSH1", "VertexSphere", VERTEX_SHADER);
		eng.CreateShader("FragmentSH1", "FragmentSphere", FRAGMENT_SHADER);
		eng.GetShader("VertexSH1")->Compile();
		eng.GetShader("FragmentSH1")->Compile();

		eng.CreateShaderProgram("ShaderProgram");
		
		eng.AttachShaderToProgram("VertexSH1", "ShaderProgram");

		eng.AttachShaderToProgram("FragmentSH1", "ShaderProgram");

		eng.LinkProgram("ShaderProgram");

		eng.AddAttributeToShaderProgram("ShaderProgram", "position");

		eng.AddAttributeToShaderProgram("ShaderProgram", "UV");

		eng.AddAttributeToShaderProgram("ShaderProgram", "normal");

		eng.AddUniformToShaderProgram("ShaderProgram", "MVP");

		eng.AddUniformToShaderProgram("ShaderProgram", "v");

		eng.AddUniformToShaderProgram("ShaderProgram", "m");

		eng.AddUniformToShaderProgram("ShaderProgram", "LightPosition_worldspace");

		eng.AddUniformToShaderProgram("ShaderProgram", "ambient_light");

		eng.AddUniformToShaderProgram("ShaderProgram", "diffuse_light");

		eng.AddUniformToShaderProgram("ShaderProgram", "specular_light");
		
		eng.AddUniformToShaderProgram("ShaderProgram", "target_color");

		eng.LoadOBJFile("SphereOBJ", "sphere.obj");

		eng.LoadOBJFile("RymdSkeppOBJ", "CubeNormal.obj");

		eng.LoadBMPFile("Earth", "melted-ice-surface-darker-texture-8192x4096.bmp");

		eng.LoadBMPFile("Stars", "PIA15482_hiresre.bmp");

		eng.LoadBMPFile("Moon", "moon_8k_color_brim16.bmp");

		eng.LoadBMPFile("BORG", "5210.bmp");

		eng.LoadBMPFile("Mars", "mars-src.bmp");

		eng.LoadBMPFile("Sun", "Map_of_the_full_sun.bmp");

		eng.LoadBMPFile("Venus", "venus4_rgb_cyl_www.bmp");

		eng.CreateInstance("SphereOBJ", "ShaderProgram", "SphereSpaceINS");

		eng.CreateInstance("SphereOBJ", "ShaderProgram", "SunINS");

		eng.CreateInstance("RymdSkeppOBJ", "ShaderProgram", "BORGINS");

		eng.Create3DObject(1, "SphereSpaceINS",0);

		eng.Create3DObject(3, "SunINS", 0);
		
		eng.Create3DObject(4,"SunINS",0);
		
		eng.GetObject3D(4)->SetTextureID(eng.GetTextureID("Earth"));
		eng.GetObject3D(4)->AddMaterial("ambient_light", Vector3f(1, 1, 1));
 		eng.GetObject3D(4)->AddMaterial("diffuse_light", Vector3f(1, 1, 1));
		eng.GetObject3D(4)->AddMaterial("specular_light", Vector3f(0, 0, 0));
		eng.GetObject3D(4)->AddMaterial("target_color", Vector3f(0, 0, 0));

		eng.GetObject3D(1)->SetTextureID(eng.GetTextureID("Stars"));
		eng.GetObject3D(1)->GetInstance().GetRenderInfo().CULL_FACE = DISABLE_CULL_FACE;;
		eng.GetObject3D(3)->SetTextureID(eng.GetTextureID("Earth"));

 		eng.GetObject3D(1)->AddMaterial("ambient_light", Vector3f(1, 1, 1));
 		eng.GetObject3D(1)->AddMaterial("diffuse_light", Vector3f(1, 1, 1));
		eng.GetObject3D(1)->AddMaterial("specular_light", Vector3f(0, 0, 0));
		eng.GetObject3D(1)->AddMaterial("target_color", Vector3f(0, 0, 0));

		eng.GetObject3D(3)->AddMaterial("ambient_light", Vector3f(2.0, 2.0, 2.0));
		eng.GetObject3D(3)->AddMaterial("diffuse_light", Vector3f(2, 2, 2));
		eng.GetObject3D(3)->AddMaterial("specular_light", Vector3f(1.0, 1.0, 1.0));
		eng.GetObject3D(3)->AddMaterial("target_color", Vector3f(0, 0, 0));
		
		eng.AddCamera("FirstPerson",USERDEFINED,Viewport(0,0,1920,1200));
		eng.ActivateCamera("FirstPerson");
		
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		eng.GetObject3D(1)->SetLocalMatrix(InitTranslationMat4F(Vector3f(10, 1, 1)));
		eng.GetObject3D(4)->SetLocalMatrix(InitTranslationMat4F(Vector3f(0,0,0)));
		eng.GetObject3D(3)->SetLocalMatrix(InitTranslationMat4F(Vector3f(1,0,2)));
		
		return true;
	}
	return false;
}

//------------------------------------------------------------------------------
/**
*/
void
GraphicsApp::Run()
{
	glfwGetFramebufferSize(window->GetWindow(), &width, &height);
	
	aspect = (float)width / (float)height;
	proj_matrix1 = Mat4::InitPerspectiveMat4F(50.0f, aspect, 0.1f, 1000000.0f);
	eng.GetCamera("FirstPerson")->SetPerspective(proj_matrix1);
	while (this->window->IsOpen())
	{	
		this->window->Update();
		glClear(GL_COLOR_BUFFER_BIT);
		time = glfwGetTime();
		
		if (oldTime == 0)
		{
			oldTime = time;
		}

		deltatime = time - oldTime;

		oldTime = time;
		
		
		if (glfwGetKey(window->GetWindow(),87) ==GLFW_PRESS)
 		{
 			position = position + direction * (deltatime * speed);
 		}

 		if (glfwGetKey(window->GetWindow(),83)==GLFW_PRESS)
		{
 			position = position - direction *(deltatime * speed);
		}

 		if (glfwGetKey(window->GetWindow(), 65) == GLFW_PRESS)
 		{
 			position = position + left *(deltatime * speed);
 		}

 		if (glfwGetKey(window->GetWindow(),68) == GLFW_PRESS)
 		{
			position = position + right *(deltatime * speed);
		}

		Matrix4F cameraView = InitLookAtMat4F(position,position+direction, up);
		
		eng.Update();
		eng.GetCamera("FirstPerson")->SetViewMatrix(cameraView);
		eng.Render(window->GetWindow());
		this->window->SwapBuffers();
		glfwSetCursorPos(window->GetWindow(),width / 2, height / 2);
	}
}

} // namespace Example