#include "GraphicsManager.h"
#include "GL/gl.h"
#include "GL/glew.h"
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <limits.h>
#include <map>
#include "Bounds.h"

using namespace std;

GraphicsManager::~GraphicsManager()
{

}

GraphicsManager::GraphicsManager()
{
	this->meshlist = map<string, Mesh>();
	this->Shaderlist = map<string, Shader>();
	this->ShaderProgramlist = map<string, ShaderProgram>();
	this->instancelist = map<string, Instance>();
	
	this->path[0]=0;
	
	char absolutepath[256];
	char* path_p = getcwd(absolutepath,256);
		
	strcpy(this->path,path_p);
	strcat(this->path,"/res/");
}

void GraphicsManager::AddMesh(string name)
{
	for (map<string, Mesh>::iterator i = this->meshlist.begin(); i != this->meshlist.end(); ++i)
	{
		if (i->first == name)
		{
			throw;
		}
	}
	this->meshlist[name]=Mesh();
}


void GraphicsManager::AddShaderProgram(string name)
{
	for (map<string, ShaderProgram>::iterator i = this->ShaderProgramlist.begin(); i != this->ShaderProgramlist.end(); ++i)
	{
		if (i->first == name)
		{
			throw;
		}
	}
	this->ShaderProgramlist[name] = ShaderProgram();
}

void GraphicsManager::AddInstance(Instance &ins, string name)
{
	for (map<string, Instance>::iterator i = this->instancelist.begin(); i != this->instancelist.end(); ++i)
	{
		if (i->first == name)
		{
			throw;
		}
	}
	this->instancelist[name] = ins;
}

void GraphicsManager::AddTextureID(unsigned int textureid, string name)
{
	for (map<string, unsigned int>::iterator i = this->textures.begin(); i != this->textures.end(); ++i)
	{
		if (i->first == name)
		{
			throw;
		}
	}
	this->textures[name] = textureid;
}


void GraphicsManager::AddShader(string name,string filename, ShaderDef definition)
{
	for (map<string, Shader>::iterator i = this->Shaderlist.begin(); i != this->Shaderlist.end(); ++i)
	{
		if (i->first == name)
		{
			throw;
		}
	}
	this->Shaderlist[name] = Shader(filename,definition);
}

void GraphicsManager::CreateInstance(string meshname, string shaderprogram, string InstanceName)
{
	//FIXA! //RENDER INFO
	RenderInformation rd;
	rd.drawinfo = DRAWARRAYS;
	rd.textinfo = TEXTURE_ON;
	//
	unsigned int vao;
	
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//POSITIONS!

	if (this->meshlist[meshname].Find("in_position"))
	{
		unsigned int vertexbuffer;
		glGenBuffers(1, &vertexbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

		if (this->meshlist[meshname]["in_position"]->GetData()._datavect3.size() != 0)
		{
			glBufferData(GL_ARRAY_BUFFER, this->meshlist[meshname]["in_position"]->SizeOf(), &this->meshlist.find(meshname)->second["in_position"]->GetData()._datavect3.front(), GL_STATIC_DRAW);
			glVertexAttribPointer(this->ShaderProgramlist.find(shaderprogram)->second.GetAttribute("position"), 3, GL_FLOAT, GL_FALSE, 0, NULL);
			glEnableVertexAttribArray(this->ShaderProgramlist.find(shaderprogram)->second.GetAttribute("position"));
			glBindAttribLocation(this->ShaderProgramlist.find(shaderprogram)->second, 0, "position");
		}
		if (this->meshlist[meshname]["in_position"]->GetData()._datavect2.size() != 0)
		{
			glBufferData(GL_ARRAY_BUFFER, this->meshlist[meshname]["in_position"]->SizeOf(), (const Vector3f*)this->meshlist.find(meshname)->second["in_position"]->GetData()._datavect3.data(), GL_STATIC_DRAW);
			glVertexAttribPointer(this->ShaderProgramlist.find(shaderprogram)->second.GetAttribute("position"), 2, GL_FLOAT, GL_FALSE, 0, NULL);
			glEnableVertexAttribArray(this->ShaderProgramlist.find(shaderprogram)->second.GetAttribute("position"));
			//ganska överflödig?
			glBindAttribLocation(this->ShaderProgramlist.find(shaderprogram)->second, 0, "position");
		}
		if (this->meshlist[meshname]["in_position"]->GetData()._datav3 != nullptr)
		{
			glBufferData(GL_ARRAY_BUFFER, this->meshlist[meshname]["in_position"]->SizeOf(), (const Vector3f*)this->meshlist.find(meshname)->second["in_position"]->GetData()._datav3, GL_STATIC_DRAW);
			glVertexAttribPointer(this->ShaderProgramlist.find(shaderprogram)->second.GetAttribute("position"), 3, GL_FLOAT, GL_FALSE, 0, NULL);
			glEnableVertexAttribArray(this->ShaderProgramlist.find(shaderprogram)->second.GetAttribute("position"));
			//ganska överflödig?
			glBindAttribLocation(this->ShaderProgramlist.find(shaderprogram)->second, 0, "position");
		}
		if (this->meshlist[meshname]["in_position"]->GetData()._datav2 != nullptr)
		{
			glBufferData(GL_ARRAY_BUFFER, this->meshlist[meshname]["in_position"]->SizeOf(), (const Vector3f*)this->meshlist.find(meshname)->second["in_position"]->GetData()._datav2, GL_STATIC_DRAW);
			glVertexAttribPointer(this->ShaderProgramlist.find(shaderprogram)->second.GetAttribute("position"), 2, GL_FLOAT, GL_FALSE, 0, NULL);
			glEnableVertexAttribArray(this->ShaderProgramlist.find(shaderprogram)->second.GetAttribute("position"));
			//ganska överflödig?
			glBindAttribLocation(this->ShaderProgramlist.find(shaderprogram)->second, 0, "position");
		}
	}

	//FÖRBÄTTRING KRÄVS!!
	//TEXTURE COORDINATES!

	if (this->meshlist[meshname].Find("in_texcoords"))
	{
		unsigned int texturebuffer;
		glGenBuffers(1, &texturebuffer);
		glBindBuffer(GL_ARRAY_BUFFER, texturebuffer);

		if (this->meshlist[meshname]["in_texcoords"]->GetData()._datavect2.size() != 0)
		{
			glBufferData(GL_ARRAY_BUFFER, this->meshlist[meshname]["in_texcoords"]->SizeOf(), &this->meshlist.find(meshname)->second["in_texcoords"]->GetData()._datavect2.front(), GL_STATIC_DRAW);
			glVertexAttribPointer(this->ShaderProgramlist.find(shaderprogram)->second.GetAttribute("UV"), 2, GL_FLOAT, GL_FALSE, 0, NULL);
			glEnableVertexAttribArray(this->ShaderProgramlist.find(shaderprogram)->second.GetAttribute("UV"));
			glBindAttribLocation(this->ShaderProgramlist.find(shaderprogram)->second, 0, "UV");
		}

		if (this->meshlist[meshname]["in_texcoords"]->GetData()._datav2 != nullptr)
		{
			glBufferData(GL_ARRAY_BUFFER, this->meshlist[meshname]["in_texcoords"]->SizeOf(), (const Vector3f*)this->meshlist.find(meshname)->second["in_texcoords"]->GetData()._datav2, GL_STATIC_DRAW);
			glVertexAttribPointer(this->ShaderProgramlist.find(shaderprogram)->second.GetAttribute("UV"), 2, GL_FLOAT, GL_FALSE, 0, NULL);
			glEnableVertexAttribArray(this->ShaderProgramlist.find(shaderprogram)->second.GetAttribute("UV"));
			glBindAttribLocation(this->ShaderProgramlist.find(shaderprogram)->second, 0, "UV");
		}
	}


	//NORMALS

	if (this->meshlist[meshname].Find("in_normal"))
	{
		unsigned int normalbuffer;
		glGenBuffers(1, &normalbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);

		if (this->meshlist[meshname]["in_normal"]->GetData()._datavect3.size() != 0)
		{
			glBufferData(GL_ARRAY_BUFFER, this->meshlist[meshname]["in_normal"]->SizeOf(), &this->meshlist.find(meshname)->second["in_normal"]->GetData()._datavect3.front(), GL_STATIC_DRAW);
			glVertexAttribPointer(this->ShaderProgramlist.find(shaderprogram)->second.GetAttribute("normal"), 3, GL_FLOAT, GL_FALSE, 0, NULL);
			glEnableVertexAttribArray(this->ShaderProgramlist.find(shaderprogram)->second.GetAttribute("normal"));
			glBindAttribLocation(this->ShaderProgramlist.find(shaderprogram)->second, 0, "normal");
		}
		if (this->meshlist[meshname]["in_normal"]->GetData()._datav3 != nullptr)
		{
			glBufferData(GL_ARRAY_BUFFER, this->meshlist[meshname]["in_normal"]->SizeOf(), (const Vector3f*) this->meshlist.find(meshname)->second["in_normal"]->GetData()._datav3, GL_STATIC_DRAW);
			glVertexAttribPointer(this->ShaderProgramlist.find(shaderprogram)->second.GetAttribute("normal"), 3, GL_FLOAT, GL_FALSE, 0, NULL);
			glEnableVertexAttribArray(this->ShaderProgramlist.find(shaderprogram)->second.GetAttribute("normal"));
			glBindAttribLocation(this->ShaderProgramlist.find(shaderprogram)->second, 0, "normal");
		}

	}




	//INDEX POSITIONS!

	if (this->meshlist[meshname].Find("in_index"))
	{
		unsigned int index_buffer;
		glGenBuffers(1, &index_buffer);
		if (this->meshlist[meshname]["in_index"]->GetData()._dataui.size() != 0)
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->meshlist.find(meshname)->second["in_index"]->SizeOf(), &this->meshlist.find(meshname)->second["in_index"]->GetData()._dataui.front(), GL_STATIC_DRAW);
			//RENDER INFO
			rd.drawinfo = DRAWELEMENTS;
		}

		if (this->meshlist[meshname]["in_index"]->GetData()._datav3 != nullptr)
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->meshlist.find(meshname)->second["in_index"]->SizeOf(), (const Vector3f*)this->meshlist.find(meshname)->second["in_index"]->GetData()._datav3, GL_STATIC_DRAW);
			//RENDER INFO
			rd.drawinfo = DRAWELEMENTS;
		}
	}

	glBindVertexArray(0);

	//KOD FÖR FLERA OLIKA
	//GLuint uniformbuffer;
	//glGenBuffers(1, &uniformbuffer);
	//glBindBuffer(GL_UNIFORM_BUFFER, uniformbuffer);
	//glBufferData(GL_UNIFORM_BUFFER, 3 * sizeof(Matrix4F), NULL, GL_DYNAMIC_DRAW);

	//fixa!
	
	AdonEngine::Physics::BoundingBox* tes;

	if (rd.drawinfo == DRAWELEMENTS)
	{
		Instance args = Instance(vao, 
		this->ShaderProgramlist.find(shaderprogram)->second, 
		this->meshlist[meshname]["in_index"]->GetCount(),
		this->ShaderProgramlist.find(shaderprogram)->second.GetUniforms(),rd,new AdonEngine::Physics::BoundingBox(this->meshlist[meshname]["in_position"]->GetData()._datavect3));

		this->AddInstance(args, InstanceName);
	}
	else
	{
		Instance args = Instance(vao,
		this->ShaderProgramlist.find(shaderprogram)->second,
		this->meshlist[meshname]["in_position"]->GetCount(),
		this->ShaderProgramlist.find(shaderprogram)->second.GetUniforms(),
		rd,new AdonEngine::Physics::BoundingBox(this->meshlist[meshname]["in_position"]->GetData()._datavect3));

		this->AddInstance(args, InstanceName);
	}

}

int GraphicsManager::GetTextureID(string name)
{
	return this->textures[name];
}

Instance GraphicsManager::GetInstance(string name)
{
	return this->instancelist.find(name)->second;
}

bool GraphicsManager::getSimilarVertexIndex_fast(PackedVertex & packed, std::map<PackedVertex, unsigned short> & VertexToOutIndex, unsigned short & result)
{
	std::map<PackedVertex, unsigned short>::iterator it = VertexToOutIndex.find(packed);
	if (it == VertexToOutIndex.end()){
		return false;
	}
	else{
		result = it->second;
		return true;
	}
}

void GraphicsManager::indexVBO(std::vector<Vector3f> & in_vertices, std::vector<Vector2f> & in_uvs, std::vector<Vector3f> & in_normals, std::vector<unsigned short> & out_indices, std::vector<Vector3f> & out_vertices, std::vector<Vector2f> & out_uvs, std::vector<Vector3f> & out_normals)
{
	std::map<PackedVertex, unsigned short> VertexToOutIndex;

	// For each input vertex
	for (unsigned int i = 0; i<in_vertices.size(); i++){

		PackedVertex packed = { in_vertices[i], in_uvs[i], in_normals[i] };


		// Try to find a similar vertex in out_XXXX
		unsigned short index;
		bool found = getSimilarVertexIndex_fast(packed, VertexToOutIndex, index);

		if (found){ // A similar vertex is already in the VBO, use it instead !
			out_indices.push_back(index);
		}
		else{ // If not, it needs to be added in the output data.
			out_vertices.push_back(in_vertices[i]);
			out_uvs.push_back(in_uvs[i]);
			out_normals.push_back(in_normals[i]);
			unsigned short newindex = (unsigned short)out_vertices.size() - 1;
			out_indices.push_back(newindex);
			VertexToOutIndex[packed] = newindex;
		}
	}
}

void GraphicsManager::LoadOBJFile(string name, const char* path)
{
		printf("Loading OBJ file %s...\n", path);

		std::vector<unsigned short>  s_indices;
		std::vector<Vector3f>  s_vertices;
		std::vector<Vector2f>  s_uvs;
		std::vector<Vector3f>  s_normals;

		std::vector<unsigned short>  out_indices;
		std::vector<Vector3f>  out_vertices;
		std::vector<Vector2f>  out_uvs;
		std::vector<Vector3f>  out_normals;

		std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
		std::vector<Vector3f> temp_vertices;
		std::vector<Vector2f> temp_uvs;
		std::vector<Vector3f> temp_normals;
		
		char pathobj[256];
		
		strcpy(pathobj,this->path);
		strcat(pathobj,path);

		FILE * file = fopen(pathobj, "r");
		if (file == NULL){
			printf("Impossible to open the file ! Are you in the right path ? See Tutorial 1 for details\n");
			getchar();
			return;
		}

		while (1){

			char lineHeader[128];
			// read the first word of the line
			int res = fscanf(file, "%s", lineHeader);
			if (res == EOF)
				break; // EOF = End Of File. Quit the loop.

			// else : parse lineHeader

			if (strcmp(lineHeader, "v") == 0){
				Vector3f vertex;
				fscanf(file, "%f %f %f\n", &vertex.data[0], &vertex.data[1], &vertex.data[2]);
				temp_vertices.push_back(vertex);
			}
			else if (strcmp(lineHeader, "vt") == 0){
				Vector2f uv;
				fscanf(file, "%f %f\n", &uv.data[0], &uv.data[1]);
				uv.data[1] = -uv[1]; // Invert V coordinate since we will only use DDS texture, which are inverted. Remove if you want to use TGA or BMP loaders.
				temp_uvs.push_back(uv);
			}
			else if (strcmp(lineHeader, "vn") == 0){
				Vector3f normal;
				fscanf(file, "%f %f %f\n", &normal.data[0], &normal.data[1], &normal.data[2]);
				temp_normals.push_back(normal);
			}
			else if (strcmp(lineHeader, "f") == 0){
				std::string vertex1, vertex2, vertex3;
				unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
				int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
				if (matches != 9){
					printf("File can't be read by our simple parser :-( Try exporting with other options\n");
					return;
				}
				vertexIndices.push_back(vertexIndex[0]);
				vertexIndices.push_back(vertexIndex[1]);
				vertexIndices.push_back(vertexIndex[2]);
				uvIndices.push_back(uvIndex[0]);
				uvIndices.push_back(uvIndex[1]);
				uvIndices.push_back(uvIndex[2]);
				normalIndices.push_back(normalIndex[0]);
				normalIndices.push_back(normalIndex[1]);
				normalIndices.push_back(normalIndex[2]);
			}
			else{
				// Probably a comment, eat up the rest of the line
				char stupidBuffer[1000];
				fgets(stupidBuffer, 1000, file);
			}

		}

		for (unsigned int i = 0; i<vertexIndices.size(); i++){

			// Get the indices of its attributes
			unsigned int vertexIndex = vertexIndices[i];
			unsigned int uvIndex = uvIndices[i];
			unsigned int normalIndex = normalIndices[i];

			 //Get the attributes thanks to the index
			Vector3f vertex = temp_vertices[vertexIndex-1];
			Vector2f uv = temp_uvs[uvIndex-1];
			Vector3f normal = temp_normals[normalIndex-1];

			 //Put the attributes in buffers
			out_vertices.push_back(vertex);
			out_uvs.push_back(uv);
			out_normals.push_back(normal);

		}

		indexVBO(out_vertices, out_uvs, out_normals, s_indices, s_vertices, s_uvs, s_normals);

		this->AddMesh(name);
		this->meshlist[name].AddData("in_position", s_vertices);
		this->meshlist[name].AddData("in_normal", s_normals);
		this->meshlist[name].AddData("in_index", s_indices);
		if (s_uvs.size() != 0)
		{
			this->meshlist[name].AddData("in_texcoords", s_uvs);
		}

		cout << "Done Loading OBJ File" << endl;


		return;
}


unsigned int GraphicsManager::LoadBMPFile(const char* filename,string texturename)
{
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	unsigned char * data;
	
	char pathbmp[256];
		
	strcpy(pathbmp,this->path);
	strcat(pathbmp,filename);

	// Open the file
	FILE * file = fopen(pathbmp, "rb");
	if (!file) 
	{ printf("Image could not be opened\n"); return 0; }

	if (fread(header,1,54,file)!=54)
	{
		printf("Not a correct BMP file\n");
		return false;
	}

	if (header[0] != 'B' || header[1] != 'M'){
		printf("Not a correct BMP file\n");
		return 0;
	}

	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);

	// Some BMP files are misformatted, guess missing information
	if (imageSize == 0)    imageSize = width*height * 3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos == 0)      dataPos = 54; // The BMP header is done that way

	// Create a buffer
	data = new unsigned char[imageSize];

	// Read the actual data from the file into the buffer
	fread(data, 1, imageSize, file);

	//Everything is in memory now, the file can be closed
	fclose(file);

	unsigned int textureID;
	glGenTextures(1, &textureID);

	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	AddTextureID(textureID, texturename);
	//FIXA!!
	glBindTexture(GL_TEXTURE_2D, textureID);
}


Shader* GraphicsManager::GetShader(string name)
{
	return &this->Shaderlist[name];
}

ShaderProgram* GraphicsManager::GetShaderProgram(string name)
{
	return &this->ShaderProgramlist[name];
}