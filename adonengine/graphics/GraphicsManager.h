#ifndef __GRAPHICS__MANAGER__H__
#define __GRAPHICS__MANAGER__H__

#include "Instance.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "string.h"

struct PackedVertex{
	Vector3f position;
	Vector2f uv;
	Vector3f normal;
	bool operator<(const PackedVertex that) const{
		return memcmp((void*)this, (void*)&that, sizeof(PackedVertex))>0;
	};
};


class GraphicsManager
{
public:
	/**
	*	Deconstructor
	*/
	~GraphicsManager();
	/**
	*	Constructor
	*/
	GraphicsManager();
	/**
	*	AddMesh
	*	@param mesh
	*	@param name
	*/
	void AddMesh(string name);
	/**
	*	AddShaderProgram
	*	@param sh
	*	@param name
	*/
	void AddShaderProgram(string name);
	/**
	*	AddInstance
	*	@param in
	*	@param name
	*/
	void AddInstance(Instance &in, string name);

	/**
	*	AddTextureID
	*	@param id
	*	@param name
	*/
	void AddTextureID(unsigned int id, string name);

	/**
	*	AddShader
	*	@param shader
	*	@param name
	*/
	void AddShader(string name,string filename,ShaderDef definition);
	/**
	*	GetShader
	*	@param name
	*/
	Shader* GetShader(string name);
	/**
	*	GetShaderProgram
	*	@param name
	*/
	ShaderProgram* GetShaderProgram(string name);
	/**
	*	GetInstance
	*	@param name
	*/
	Instance GetInstance(string name);
	/**
	*	CreateInstance
	*	@param meshname
	*	@param shaderprogram
	*	@param InstanceName
	*/
	void CreateInstance(string meshname, string shaderprogram, string InstanceName);
	/**
	*	LoadOBJFile
	*	@param name
	*	@param path
	*/
	void LoadOBJFile(string name, const char* path);
	/**
	*	LoadBMPFile
	*	@param filename
	*	@param texturename
	*/
	unsigned int LoadBMPFile(const char* filename, string texturename);
	/**
	*	GetTextureID
	*	@param name
	*/
	int GetTextureID(string name);

private:
	bool getSimilarVertexIndex_fast(PackedVertex & packed, std::map<PackedVertex, unsigned short> & VertexToOutIndex, unsigned short & result);
	void indexVBO(std::vector<Vector3f> & in_vertices,std::vector<Vector2f> & in_uvs,std::vector<Vector3f> & in_normals,std::vector<unsigned short> & out_indices,std::vector<Vector3f> & out_vertices,std::vector<Vector2f> & out_uvs,std::vector<Vector3f> & out_normals);
	map<string, Mesh> meshlist;
	map<string, ShaderProgram> ShaderProgramlist;
	map<string, Shader> Shaderlist;
	map<string, Instance> instancelist;
	map<string, unsigned int> textures;
	char path[256];
};

#endif // !__GRAPHICS__MANAGER__H__
