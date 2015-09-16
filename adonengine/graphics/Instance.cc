#include "Instance.h"


Instance::Instance()
{

}

Instance::Instance(unsigned int vao, unsigned int program, int tricount, map<string, int> uniforms, RenderInformation rd,AdonEngine::Physics::Bounds* bsphere)
{
	this->VAO = vao;
	this->program = program;
	this->triangles = tricount;
	this->uniforms = uniforms;
	this->rd = rd;
	this->rd.CULL_FACE = ENABLE_CULL_FACE;
	this->bounds = bsphere;
	init = 1;
}

Instance::Instance(unsigned int vao, unsigned int program, int tricount, map<string, int> uniforms, RenderInformation rd,int uniformbuffer)
{
	this->VAO = vao;
	this->program = program;
	this->triangles = tricount;
	this->uniforms = uniforms;
	this->rd = rd;
	this->rd.CULL_FACE = ENABLE_CULL_FACE;
	this->uniformbuffer = uniformbuffer;
	init = 1;
}


void Instance::SetVAO(unsigned int vao)
{
	this->VAO = vao;
}

unsigned int Instance::GetVAO()
{
	return this->VAO;
}
unsigned int Instance::GetProgram()
{
	return this->program;
}
int Instance::GetCount()
{
	return this->triangles;
}

int Instance::GetUniform(string name)
{
	return this->uniforms[name];
}

Material& Instance::GetMaterial(string name)
{
	for (int i = 0; i < materials.size(); i++)
	{
		if (materials[i].uniformname == name)
		{
			return materials[i];
		}
	}

	printf("There is no Material by that name! : %s", name.c_str());
	throw;
}


Material Instance::GetMaterial(int i)
{
	return this->materials[i];
}

int Instance::MaterialCount()
{
	return this->materials.size();
}

void Instance::AddMaterial(string name, Vector3f materialdata)
{
	for (vector<Material>::iterator i = this->materials.begin(); i != this->materials.end(); i++)
	{
		if (i->uniformname == name)
		{
			printf("There is already a material with name : %s",name.c_str());
			throw;
		}
	}
	this->materials.push_back(Material(name, materialdata));
}

RenderInformation& Instance::GetRenderInfo()
{
	return this->rd;
}

AdonEngine::Physics::Bounds* Instance::GetBounds()
{
	return this->bounds;
}

bool Instance::isInitilized()
{
  return init == 1;
}
