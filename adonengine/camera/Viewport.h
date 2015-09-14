#ifndef _VIEWPORT_H_
#define _VIEWPORT_H_
#include <string>
class Viewport
{
public:
	Viewport(){}
	Viewport(int xpos, int ypos,int width, int height) : width(width), height(height), x(xpos),y(ypos){}
	int width;
	int height;
	int x, y;
};
#endif