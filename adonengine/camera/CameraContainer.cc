#include "CameraContainer.h"
#include "Camera.h"
#include <map>
//FIXA!

CameraContainer::CameraContainer()
{
}


void CameraContainer::AddCamera(std::string name,CameraDefinition def,Viewport viewport)
{
	Camera cam = Camera(def, viewport);
	if (this->camera_container.find(name)!=this->camera_container.end())
	{
		//throw exception("Camera Already exists!");
		throw std::runtime_error("Camera Already exists!");
	}
	this->camera_container[name] = cam;
	this->camera_container[name].SetID(this->camera_container.size());
}

void CameraContainer::Update()
{
	for (std::map<std::string, Camera>::iterator i = this->camera_container.begin(); i != this->camera_container.end(); i++)
	{
		i->second.Update();
	}
}

Camera* CameraContainer::GetCamera(std::string name)
{
	return &this->camera_container.at(name);
}

void CameraContainer::ActivateCamera(std::string name)
{
	for (std::map<std::string, Camera>::iterator i = this->camera_container.begin(); i != this->camera_container.end(); i++)
	{
		if (i->second.isActive())
		{
			printf("Camera is already activated! err: %s", name.c_str());
			return;
		}
	}
	printf("Camera activated! err: %s", name.c_str());
	this->camera_container[name].ActivateCamera();
}

std::map< std::string, Camera >& CameraContainer::GetCameras()
{
  return this->camera_container;
}


