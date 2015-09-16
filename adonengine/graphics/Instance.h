#ifndef __INSTANCE__H__
#define __INSTANCE__H__
#include <map>
#include "SamMathsMatrices.h"
#include <vector>
#include "DataStructures.h"
#include "Bounds.h"
using namespace std;


enum TEXTURE_INFO
{
	TEXTURE_OFF,
	TEXTURE_ON
};
enum DRAWCALL
{
	DRAWARRAYS,
	DRAWELEMENTS
};

enum CULLING
{
	ENABLE_CULL_FACE,
	DISABLE_CULL_FACE
};

struct Material
{
	Material()
	{

	}
	Material(string name, Vector3f data) : uniformname(name), material(data) {}
	Vector3f material;
	string uniformname;
};

struct RenderInformation
{
	int textinfo;
	int drawinfo;
	int CULL_FACE;
};


class Instance
{
public:
	Instance();
	/**
	*	Instance
	*	@param vao
	*	@param program
	*	@param tricount
	*	@param textureid
	*	@param uniform
	*	@param rd
	*	@param pos
	*/
	Instance(unsigned int vao, unsigned int program, int tricount,map<string,int> uniforms,RenderInformation rd,AdonEngine::Physics::Bounds* bsphere);
	/**
	*	Instance
	*	@param vao
	*	@param program
	*	@param tricount
	*	@param textureid
	*	@param uniform
	*	@param rd
	*	@param uniformbuffer
	*/
	Instance(unsigned int vao, unsigned int program, int tricount, map<string, int> uniforms, RenderInformation rd, int uniformbuffer);
	/**
	*	SetVAO
	*	@param vao
	*/
	void SetVAO(unsigned int vao);
	/**
	*	SetShaderProgram
	*	@param program
	*/
	void SetShaderProgram(unsigned int program);
	/**
	*	GetVAO
	*/
	unsigned int GetVAO();
	/**
	*	GetProgram
	*/
	unsigned int GetProgram();
	/**
	*	GetCount
	*/
	int GetCount();
	/**
	*	GetUniform
	*/
	int GetUniform(string name);
	/**
	*	GetRenderInfo
	*/
	RenderInformation& GetRenderInfo();

	Material& GetMaterial(string name);

	void AddMaterial(string name, Vector3f);

	Material GetMaterial(int i);

	int MaterialCount();

	AdonEngine::Physics::Bounds* GetBounds();
	
	bool isInitilized();
	
	//TEST CODE
	unsigned int uniformbuffer;
private:
	AdonEngine::Physics::Bounds* bounds;
	unsigned int VAO;
	unsigned int program;
	int triangles; //ändra namn!
	map<string, int> uniforms;
	RenderInformation rd;
	vector<Material> materials;
	BYTE init = 0;
	//change!!!
};

#endif // !__INSTANCE__H__
