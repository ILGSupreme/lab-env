#ifndef __CAMERA__H__
#define __CAMERA__H__
#include "SamMathsMatrices.h"
#include "Viewport.h"
#include "Plane.h"
#include <vector>

enum CameraDefinition
{
	USERDEFINED,
	CLASSDEFINED
};

class Camera
{
public:
	Camera();
	/**
	*	Camera
	*	@param CameraDefinition
	*	@param viewport
	*/
	Camera(CameraDefinition def,Viewport viewport);
	/**
	*	Follow
	*	@param obj
	*	@param distance
	*/
	void Follow(Matrix4F* obj, Vector3f distance);
	/**
	*	Follow
	*	@param obj
	*	@param distance
	*/
	void Follow(Matrix4F obj,Vector3f distance);
	/**
	*	Follow
	*	@param obj
	*	@param distance
	*/
	void LookAt(Matrix4F* obj);
	/**
	*	LookAt
	*	@param lookat
	*/
	void LookAt(Vector3f look);
	/**
	*	SetPerspective
	*	@param _perspective
	*/
	void SetPerspective(Matrix4F _perspective);

	Matrix4F& GetPerspective();
	/**
	*	SetCameraMatrix
	*	@param _matrix
	*/
	void SetViewMatrix(Matrix4F _matrix);
	/**
	*	GetCameraMatrix
	*/
	Matrix4F& GetViewMatrix();
	/**
	*	SetToViewPort
	*/
	void SetToViewPort(Viewport name);
	/**
	*	GetViewPort
	*/
	Viewport& GetViewPort();
	/**
	*	Update
	*/
	void Update();
	/**
	*	SetID
	*	@param id
	*/
	void SetID(int id);
	/**
	*	SetDefinition
	*	@param def
	*/
	void SetDefinition(CameraDefinition def);

	void SetPlanes();

	std::vector<Plane> GetPlanes();
	
	void ActivateCamera();
	
	void UnActivate();
	
	bool& isActive();
	
	bool PointInFrustrum(const Vector3f& Position,const float& radius);
private:
	Matrix4F viewmatrix;
	Matrix4F* follow;
	Matrix4F* lookat;
	Matrix4F perspectiveMatrix;
	
	std::vector<Plane> planes;
	Vector3f distance;
	
	Viewport viewport;
	int camdef;
	int id;
	bool active;
};

#endif // !__CAMERA__H__
