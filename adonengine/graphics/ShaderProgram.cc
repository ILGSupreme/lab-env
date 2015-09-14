#include "ShaderProgram.h"
#include <iostream>


ShaderProgram::ShaderProgram()
{
	this->program = glCreateProgram();
}

ShaderProgram::operator GLuint()
{
	return this->program;
}

void ShaderProgram::AttachShader(Shader shader)
{
	glAttachShader(this->program,shader);
}

void ShaderProgram::LinkProgram()
{
	glLinkProgram(this->program);
	if (LinkSuccessful(program))
	{
		std::cout << "Link Successful!!"<<endl;
	}
}


bool ShaderProgram::LinkSuccessful(int obj) {
	int status;
	glGetProgramiv(obj, GL_LINK_STATUS, &status);
	return status == GL_TRUE;
}

void ShaderProgram::AddAttribute(string _attrib)
{
	int attrib = glGetAttribLocation(this->program, _attrib.c_str());
	if (attrib == -1)
	{
		std::cout << "Add Attribute: There is no attribute named: " + _attrib;
		throw;
	}
	this->AttribValues[_attrib] = attrib;
}

void ShaderProgram::AddUniform(string _uniform)
{
	int uniform = glGetUniformLocation(this->program, _uniform.c_str());
	if (uniform == -1)
	{
		std::cout << "Add Attribute: There is no uniform named: " + _uniform;
		throw;
	}
	this->UniformValues[_uniform] = uniform;
}

int ShaderProgram::GetAttribute(string attrib)
{
	return this->AttribValues.find(attrib)->second;
}

int ShaderProgram::GetUniform(string uniform)
{
	return this->UniformValues.find(uniform)->second;
}

map<string, int> ShaderProgram::GetUniforms()
{
	return this->UniformValues;
}