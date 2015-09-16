#ifndef __ADON__ENGINE__H__
#define __ADON__ENGINE__H__

#include "GraphicsManager.h"
#include "CameraContainer.h"
#include "Object3D.h"
#include "GLFW/glfw3.h"

using namespace Mat4;
using namespace SMUtility;

class Adon
{
public:

	Adon();
	/**
	*	CreateShader
	*	Creates a Shader object with the shader text data
	*	@param name
	*	@param filename
	*	@param definition
	*/
	void CreateShader(string name , string filename, ShaderDef definition);
	/**
	*	GetShader
	*	Creates a Shader object with the shader text data
	*	@param name
	*/
	Shader* GetShader(string name);
	/**
	*	CreateShaderProgram
	*	Creates a Shader program with the shader text data
	*	@param shaderprogram
	*/
	void CreateShaderProgram(string shaderprogram);
	/**
	*	AttachShaderToProgram
	*	Attaches a Shader to a Shader program
	*	@param shadername
	*	@param shaderprogram
	*/
	void AttachShaderToProgram(string shadername, string shaderprogram);
	/**
	*	AddAttributeToShaderProgram
	*	Add Attribute
	*	@param name
	*	@param attribute
	*/
	void AddAttributeToShaderProgram(string name,string attribute);
	/**
	*	AddUniformToShaderProgram
	*	Add Uniform
	*	@param name
	*	@param uniform
	*/
	void AddUniformToShaderProgram(string name,string uniform);
	/**
	*	LinkProgram
	*	Add Uniform
	*	@param name
	*	@param uniform
	*/
	void LinkProgram(string name);
	/**
	*	LoadOBJFile
	*	Loads a OBJ File and adds it as a Mesh
	*	@param meshname
	*	@param path
	*/
	void LoadOBJFile(string meshname, const char* path);
	/**
	*	LoadBMPFile
	*	Loads a OBJ File and adds it as a Mesh
	*	@param texturename
	*	@param filename
	*/
	void LoadBMPFile(string texturename, const char* filename);
	/**
	*	LoadBMPFile
	*	Creates an instance
	*	@param meshname
	*	@param Shaderprogram
	*	@param texture
	*	@param InstanceName
	*/
	void CreateInstance(string meshname, string Shaderprogram,string InstanceName);
	/**
	*	Create3DObject
	*	@param id
	*	@param instance
	*	@param rood_id
	*/
	void Create3DObject(int id,string instance,int root_id);
	/**
	*	Create3DObject
	*	@param id
	*	@param instance
	*	@param Object3D this makes the current object child to this one
	*/
	void Create3DObject(int id, string instance,Object3D& object);
	/**
	*	Create3DObject
	*	@param id
	*	@param instance
	*/
	void Create3DObject(int id, string instance);
	/**
	*	GetObject3D
	*	@param id
	*/
	Object3D* GetObject3D(int id);
	/**
	*	AddCamera
	*	@param name
	*	@param def
	*	@param viewport
	*/
	void AddCamera(string name,CameraDefinition def,Viewport viewport);
	/**
	*	GetCamera
	*	@param name
	*/
	Camera* GetCamera(string name);
	/**
	*	ActivateCamera
	*	@param name
	*/
	void ActivateCamera(string name);
	/**
	*	Update
	*	Updates the Scenegraph and cameras
	*/
	void Update();
	/**
	*	Render
	*	Renders the Scenegraph and cameras
	*/
	void Render(GLFWwindow* window);
	/**
	*	GetTextureID
	*	Gets the specified textures ID
	*/
	int GetTextureID(string name);
	
	//DUMMY FUNC
	map<int,Object3D>* getObjects();
	
private:
	void FrustrumCulling();
	GraphicsManager graphics;
	CameraContainer camera_container;
	map<int,Object3D> AllObjects;
	vector<Object3D> Scenegraph;
};


#endif // !__HEAVEN__ENGINE__
