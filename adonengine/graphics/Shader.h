#ifndef __SHADER__H__
#define __SHADER__H__

#include "GL/glew.h"
#include <string>
#include <map>
using namespace std;

enum ShaderDef
{
	VERTEX_SHADER,
	GEOMETRY_SHADER,
	FRAGMENT_SHADER,
};

class Shader
{
public:
	~Shader();
	Shader();
	/**
	*	Constructor
	*	@param filename
	*	@param def
	*/
	Shader(string filename, ShaderDef def);
	/**
	*	LoadShaderFromFile
	*	@param filename
	*/
	void LoadShaderFromFile(string filename);
	/**
	*	Compile
	*/
	void Compile();
	/**
	*	Cast Operator
	*/
	operator GLuint();
private:
	string shadersource;
	GLuint shaderbuffer;
	int definition;
	bool CompileSuccessful(int obj);
};




#endif // !__SHADER__H__
