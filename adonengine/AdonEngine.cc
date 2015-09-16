#include "AdonEngine.h"
#include "Object3D.h"
#include "GL/gl.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

Adon::Adon()
{
	this->Scenegraph.push_back(Object3D());
	this->Scenegraph[0].SetLocalMatrix(Mat4::InitIdentityMat4F());
	glEnable(GL_CULL_FACE);
}

void Adon::CreateShader(string name, string filename, ShaderDef definition)
{
	this->graphics.AddShader(name, filename, definition);
}

Shader* Adon::GetShader(string name)
{
	return this->graphics.GetShader(name);
}

int Adon::GetTextureID(string name)
{
	return this->graphics.GetTextureID(name);
}

void Adon::CreateShaderProgram(string name)
{
	this->graphics.AddShaderProgram(name);
}

void Adon::AttachShaderToProgram(string shader, string shaderprogram)
{
	this->graphics.GetShaderProgram(shaderprogram)->AttachShader(*this->GetShader(shader));
}

void Adon::LinkProgram(string shaderprogram)
{
	this->graphics.GetShaderProgram(shaderprogram)->LinkProgram();
}

void Adon::AddAttributeToShaderProgram(string name,string Attribute)
{
	this->graphics.GetShaderProgram(name)->AddAttribute(Attribute);
}

void Adon::AddUniformToShaderProgram(string name, string Uniform)
{
	this->graphics.GetShaderProgram(name)->AddUniform(Uniform);
}

void Adon::LoadOBJFile(string meshname, const char* path)
{
	this->graphics.LoadOBJFile(meshname, path);
}

void Adon::LoadBMPFile(string texturename, const char* filename)
{
	this->graphics.LoadBMPFile(filename, texturename);
}

void Adon::CreateInstance(string meshname, string Shaderprogram, string InstanceName)
{
	this->graphics.CreateInstance(meshname, Shaderprogram, InstanceName);
}

void Adon::Create3DObject(int id, string instance,int root_id)
{
	//MAKE CHECKS
	this->AllObjects[id]=Object3D(this->graphics.GetInstance(instance), Mat4::InitIdentityMat4F());
	this->AllObjects[id].ChildOf(this->Scenegraph[root_id]);
}

void Adon::Create3DObject(int id, string instance, Object3D& object)
{
	this->AllObjects[id] = Object3D(this->graphics.GetInstance(instance), Mat4::InitIdentityMat4F());
	this->AllObjects[id].ChildOf(object);
}

void Adon::Create3DObject(int id, string instance)
{
	this->AllObjects[id] = Object3D(this->graphics.GetInstance(instance), Mat4::InitIdentityMat4F());
}

Object3D* Adon::GetObject3D(int id)
{
	return &this->AllObjects[id];
}

void Adon::AddCamera(string name,CameraDefinition def,Viewport viewport)
{
	this->camera_container.AddCamera(name,def,viewport);
}

Camera* Adon::GetCamera(string name)
{
	return this->camera_container.GetCamera(name);
}

void Adon::ActivateCamera(string name)
{
	this->camera_container.ActivateCamera(name);
}


void Adon::Update()
{
	for (int i = 0; i < this->Scenegraph.size(); i++)
	{
		this->Scenegraph[i].Update(Mat4::InitIdentityMat4F());
	}
	this->camera_container.Update();

}

map<int,Object3D >* Adon::getObjects()
{
  return &this->AllObjects;
}

void Adon::Render(GLFWwindow* window)
{
	double time = glfwGetTime();
	static const GLfloat red[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	static const GLfloat one = 1.0f;
	glClearBufferfv(GL_COLOR, 0, red);
	glClearBufferfv(GL_DEPTH, 0, &one);
	
	for(map<string,Camera>::iterator it=this->camera_container.GetCameras().begin(); it != this->camera_container.GetCameras().end();it++)
	{
	  if(it->second.isActive())
	  {
	    glEnable(GL_SCISSOR_TEST);
	    glScissor(it->second.GetViewPort().x, it->second.GetViewPort().y, it->second.GetViewPort().width, it->second.GetViewPort().height);
	    glClearBufferfv(GL_DEPTH, 0, &one);
	    glViewport(it->second.GetViewPort().x, it->second.GetViewPort().y, it->second.GetViewPort().width, it->second.GetViewPort().height);
	    glDisable(GL_SCISSOR_TEST);
	    for (int i = 0; i < this->Scenegraph.size(); i++)
	    {
	      this->Scenegraph[i].Render(it->second);
	    }
	  }
	}
}