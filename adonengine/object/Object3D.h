#ifndef __OBJECT3D__H__
#define __OBJECT3D__H__
#include "Instance.h"
#include "SamMathsMatrices.h"
#include <iostream>
#include <vector>
#include "Camera.h"

using namespace SMUtility;
using namespace std;


class Object3D
{
public:
	/**
	* Constructor
	*/
	Object3D();
	/**
	* Constructor
	* @param Instance
	*/
	Object3D(Instance ins);
	/**
	* Constructor
	* @param Instance
	* @param _transform
	*/
	Object3D(Instance ins,Matrix4F _transform);
	/**
	* Constructor
	* @param Instance
	* @param _transform
	*/
	void ChildOf(Object3D &other);
	/**
	* createConnection
	* @param other
	*/
	void createConnection(Object3D* other);
	/**
	* hasChildren
	*/
	bool hasChildren();
	/**
	* hasChildren
	* @param _transform
	*/
	void Update(Matrix4F _transform);
	/**
	* GetTransform
	*/
	Matrix4F GetTransform();
	/**
	* GetGlobalAddress
	*/
	Matrix4F* GetGlobalAddress();
	/**
	* SetLocalMatrix
	* @param _matrix
	*/
	void SetLocalMatrix(Matrix4F _matrix);
	/**
	* Render
	* @param ActiveCamContainer
	*/
	void Render(Camera& cam);
	/**
	*	SetTextureID
	*	param textureid the id of the texture
	*/
	void SetTextureID(int textureid);
	/**
	*	GetTextureID
	*/
	int GetTextureID();
	void Initilize(int instance_id);
	void AddMaterial(string name , Vector3f);
	Material& GetMaterial(string name);
	Instance& GetInstance();
	int init = 0;
private:
	int instance_id;
	Instance graphicdata;
	Matrix4F transform;
	Matrix4F globaltransform;
	vector<Object3D*> children;
	int textureid;
	//temp code
};


#endif // !__3DOBJECT__H__
