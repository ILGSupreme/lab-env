#ifndef __CAMERA__CONTAINER__H__
#define __CAMERA__CONTAINER__H__

#include "Camera.h"
#include <map>

class CameraContainer
{
public:
	/**
	*	CameraContainer
	*/
	CameraContainer();
	/**
	*	AddCamera
	*	@param name
	*	@param def
	*	@param viewport
	*/
	void AddCamera(std::string name,CameraDefinition def,Viewport viewport);
	/**
	*	Update
	*/
	void Update();
	/**
	*	GetCamera
	*	@param name
	*/
	Camera* GetCamera(std::string name);
	/*
	*	GetActiveCamera
	*	@param viewport
	*/
// 	Camera* GetActiveCamera(string viewport);
	/**
	*	ActiveCamera
	*	@param name
	*/
	void ActivateCamera(std::string name);
// 	/**
// 	*	ActiveCamContainer
// 	*/
// 	ActiveCamContainer GetActiveContainer();
	/**
	 * 
	 * */
	std::map<std::string,Camera>& GetCameras();
private:
	std::map<std::string,Camera> camera_container;
};


#endif // !__CAMERA__CONTAINER__H__