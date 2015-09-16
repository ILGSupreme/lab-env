#include "Shader.h"
#include <unistd.h>
#include <string>
#include <limits.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>

Shader::~Shader()
{
	glDeleteShader(this->shaderbuffer);
}

Shader::Shader()
{
}

Shader::Shader(string filename, ShaderDef _definition)
{
	this->LoadShaderFromFile(filename);
	this->definition = _definition;
}

Shader::operator GLuint()
{
	return this->shaderbuffer;
}

void Shader::LoadShaderFromFile(string name)
{
	std::cout<<name;
	string line;
	string wholetext;
	
	char absolutepath[256];
	char* path_p = getcwd(absolutepath,256);
	char path[256];
	path[0]=0;
	strcpy(path,path_p);
	strcat(path,"/res/");
	strcat(path,name.c_str());
	strcat(path,".glsl");
	
	string filename = path;
	ifstream myfile(filename);
	if (myfile.is_open())
	{
		while (getline(myfile,line))
		{
			wholetext = wholetext + line + "\n";
		}
		myfile.close();
	}
	this->shadersource = wholetext;
}

void Shader::Compile()
{
	const char* ssource = this->shadersource.c_str();

	if (this->definition == 0)
	{
		this->shaderbuffer = glCreateShader(GL_VERTEX_SHADER);
	}

	else if (this->definition == 1)
	{
		this->shaderbuffer = glCreateShader(GL_GEOMETRY_SHADER);
	}

	else if (this->definition == 2)
	{
		this->shaderbuffer = glCreateShader(GL_FRAGMENT_SHADER);
	}

	glShaderSource(shaderbuffer, 1, &ssource, NULL);
	glCompileShader(shaderbuffer);

	if (CompileSuccessful(this->shaderbuffer))
	{
		std::cout << "Shader Compiled! \n";
	}
	else
	{
		GLint maxLength = 0;
		glGetShaderiv(this->shaderbuffer, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(this->shaderbuffer, maxLength, &maxLength, &infoLog[0]);
		for (int i = 0; i < infoLog.size(); i++)
		{
			std::cout << infoLog[i];
		}
		//We don't need the shader anymore.
		glDeleteShader(this->shaderbuffer);

		//Use the infoLog as you see fit.

		//In this simple program, we'll just leave
	}
}

bool Shader::CompileSuccessful(int obj) {
	int status;
	glGetShaderiv(obj, GL_COMPILE_STATUS, &status);
	return status == GL_TRUE;
}
