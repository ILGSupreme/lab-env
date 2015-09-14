//------------------------------------------------------------------------------
/**
	Application class used for example application.
	
	(C) 2015 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "core/app.h"
#include "render/window.h"
#include "../../adonengine/AdonEngine.h"
#include "Ray.h"

namespace GraphicsLabb
{
class GraphicsApp : public Core::App
{
public:
	/// constructor
	GraphicsApp();
	/// destructor
	~GraphicsApp();

	/// open app
	bool Open();
	/// run app
	void Run();
private:
	Display::Window* window;
	AdonEngine eng;
	double deltatime = 0;
	double time = 0;
	float horizontalAngle = 3.14f;
	float verticalAngle = 0;
	Vector3f position = Vector3f(0,0,-10);
	Vector3f direction = Vector3f(1,0,0);
	Vector3f up = Vector3f(0,1,0);
	Vector3f right = Vector3f(-1,0,0);
	Vector3f left = Vector3f(1,0,0);
	AdonPhysics::Ray raytest;
	
	float xmouse;
 	float ymouse;
	
	Matrix4F proj_matrix1;
	Matrix4F viewmatrix;
	Vector3f p1;
	Vector3f p2;
	Vector3f p3;
	Vector3f p4;
	Vector3f p5;
	
	double oldTime = 0;
	double speed = 100;
	float aspect = 3.16f;
	int width = 0;
	int height = 0;
	double mousespeed = 0.005;
};
} // namespace Example