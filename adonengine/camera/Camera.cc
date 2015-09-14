#include "Camera.h"
#include "Object3D.h"

Camera::Camera()
{
}

Camera::Camera(CameraDefinition def,Viewport viewport) : active(false)
{
	this->camdef = def;
	this->viewport = viewport;
}

void Camera::Follow(Matrix4F* obj, Vector3f distance)
{
	this->follow = obj;
	this->distance = distance;
}

void Camera::LookAt(Vector3f look)
{
	//KOD!
}

void Camera::Follow(Matrix4F obj,Vector3f distance)
{
	this->follow = &obj;
	this->distance = distance;
}

void Camera::LookAt(Matrix4F* obj)
{
	this->lookat = obj;
}

void Camera::SetPerspective(Matrix4F perspective)
{
	this->perspectiveMatrix = perspective;
}

Matrix4F& Camera::GetPerspective()
{
	return this->perspectiveMatrix;
}

void Camera::Update()
{
	if (this->camdef == CLASSDEFINED)
	{
		Vector3f eye_pos = Vector3f(this->follow->data[0][3], this->follow->data[1][3], this->follow->data[2][3]) + distance;
		Vector3f center = Vector3f(this->lookat->data[0][3], this->lookat->data[1][3], this->lookat->data[2][3]);
		Vector3f up = Vector3f(0,1,0);

		Matrix4F viewmatrix = Mat4::InitLookAtMat4F(eye_pos, center, up);

		this->viewmatrix = viewmatrix;
	}
	else if (this->camdef == USERDEFINED)
	{
	}
	SetPlanes();
}

void Camera::SetID(int _id)
{
	this->id = _id;
}

void Camera::SetViewMatrix(Matrix4F _matrix)
{
	this->viewmatrix = _matrix;
}
Matrix4F& Camera::GetViewMatrix()
{
	return this->viewmatrix;
}

void Camera::SetToViewPort(Viewport name)
{
	this->viewport = name;
}

Viewport& Camera::GetViewPort()
{
	return this->viewport;
}

void Camera::SetDefinition(CameraDefinition def)
{
	this->camdef = def;
}

vector<Plane> Camera::GetPlanes()
{
	return this->planes;
}


void Camera::SetPlanes()
{
	planes.clear();

	Matrix4F pv = this->perspectiveMatrix * this->viewmatrix;

	auto it = planes.begin();

	planes.insert(it, 6, Plane());

	//left
	planes[0].a = pv[3][0] + pv[0][0];
	planes[0].b = pv[3][1] + pv[0][1];
	planes[0].c = pv[3][2] + pv[0][2];
	planes[0].d = pv[3][3] + pv[0][3];

	//right
	planes[1].a = pv[3][0] - pv[0][0];
	planes[1].b = pv[3][1] - pv[0][1];
	planes[1].c = pv[3][2] - pv[0][2];
	planes[1].d = pv[3][3] - pv[0][3];

	//bottom
	planes[2].a = pv[3][0] + pv[1][0];
	planes[2].b = pv[3][1] + pv[1][1];
	planes[2].c = pv[3][2] + pv[1][2];
	planes[2].d = pv[3][3] + pv[1][3];

	//top
	planes[3].a = pv[3][0] - pv[1][0];
	planes[3].b = pv[3][1] - pv[1][1];
	planes[3].c = pv[3][2] - pv[1][2];
	planes[3].d = pv[3][3] - pv[1][3];

	//near
	planes[4].a = pv[3][0] + pv[2][0];
	planes[4].b = pv[3][1] + pv[2][1];
	planes[4].c = pv[3][2] + pv[2][2];
	planes[4].d = pv[3][3] + pv[2][3];

	//far
	planes[5].a = pv[3][0] - pv[2][0];
	planes[5].b = pv[3][1] - pv[2][1];
	planes[5].c = pv[3][2] - pv[2][2];
	planes[5].d = pv[3][3] - pv[2][3];

	for (int i = 0; i < 6; i++)
	{
		planes[i].Normalize();
	}
}


void Camera::ActivateCamera()
{
  this->active = true;
}

void Camera::UnActivate()
{
  this->active = false;
}
bool& Camera::isActive()
{
  return this->active;
}

bool Camera::PointInFrustrum(const Vector3f& Position,const float& radius)
{
  for (int i = 0; i < this->planes.size(); i++)
  {
    if (this->planes[i].DistanceToPoint(Position) + radius < 0)
    {
      return false;
    }
  }
  return true;
}