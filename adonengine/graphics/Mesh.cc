#include "Mesh.h"
#include "stdexcept"

Mesh::~Mesh()
{
	for (Source* in : list)
	{
		delete[] in;
	}
}

Source* Mesh::operator[] (string n)
{
	for (int i = 0; i < this->list.size(); i++)
	{
		if (n == list[i]->GetName())
		{
			return list[i];
		}
	}
	//throw exception("cant find the specified item");
	throw std::runtime_error("cant find the specified item");
}

Source* Mesh::operator[](int n)
{
	return this->list[n];
}


bool Mesh::Find(string name)
{
	for (int i = 0; i < this->list.size(); i++)
	{
		if (name == list[i]->GetName())
		{
			return true;
		}
	}
	return false;
}

void Mesh::AddData(string name, Vector2f _data[],size_t size, int tricount)
{
	list.push_back(new Source2V(name, _data, size, tricount));
}

void Mesh::AddData(string name, Vector3f _data[], size_t size, int tricount)
{
	list.push_back(new Source3V(name, _data, size, tricount));
}

void Mesh::AddData(string name, vector<Vector3f> _data)
{
	size_t st = _data.size() * sizeof(Vector3f);
	int count = _data.size();
	list.push_back(new Source3V(name, _data, st, count));
}

void Mesh::AddData(string name, vector<Vector2f> _data)
{
	size_t st = _data.size() * sizeof(Vector2f);
	int count = _data.size();
	list.push_back(new Source2V(name, _data, st, count));
}


void Mesh::AddData(string name, vector<unsigned short> _data)
{
	size_t st = _data.size() * sizeof(unsigned short);
	int count = _data.size();
	list.push_back(new Source3s(name, _data, st, count));
}