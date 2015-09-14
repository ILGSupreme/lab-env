//------------------------------------------------------------------------------
// main.cc
// (C) 2015 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "App.h"

int
main(int argc, const char** argv)
{
  	GraphicsLabb::GraphicsApp app;
	if (app.Open())
	{
		app.Run();
		app.Close();
	}
	app.Exit();
}