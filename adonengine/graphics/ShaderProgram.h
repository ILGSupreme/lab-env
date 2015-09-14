#ifndef __SHADER__PROGRAM__H__
#define __SHADER__PROGRAM__H__

#include "Shader.h"

class ShaderProgram
{
public:
	ShaderProgram();
	/**
	*	AttachShader
	*	Attaches Shader to program
	*	@param shader
	*/
	void AttachShader(Shader shader);
	/**
	*	LinkProgram
	*	Links the program
	*/
	void LinkProgram();
	/**
	*	AddAttribute
	*	@param attrib
	*/
	void AddAttribute(string attrib);
	/**
	*	AddUniform
	*	@param uniform
	*/
	void AddUniform(string uniform);
	/**
	*	GetAttribute
	*	@param attrib
	*/
	int GetAttribute(string attrib);
	/**
	*	GetUniform
	*	@param uniform
	*/
	int GetUniform(string uniform);
	/**
	*	GetUniforms
	*/
	map<string, int> GetUniforms();
	/**
	*	Cast Operator
	*/
	operator GLuint();
private:
	bool LinkSuccessful(int obj);
	map<string, int> AttribValues;
	map<string, int> UniformValues;
	unsigned int program;
};

#endif // !__SHADER__PROGRAM__H__
