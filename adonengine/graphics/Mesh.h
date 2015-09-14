#ifndef __MESH__H__
#define __MESH__H__

#include <vector>
#include "SourceData.h"
using namespace std;


class Mesh
{
private:
	vector<Source*> list;
public:
	~Mesh();
	/**
	*	operator[] 
	*/
	Source* operator[](string numb);
	/**
	*	operator[]
	*/
	Source* operator[](int numb);
	/**
	*	Find
	*	@param name
	*/
	bool Find(string name);
	/**
	*	AddData
	*	@param name
	*	@param _data
	*	@param _size
	*	@param tricount
	*/
	void AddData(string name, Vector2f _data[], size_t _size, int tricount);
	/**
	*	AddData
	*	@param name
	*	@param _data
	*	@param _size
	*	@param tricount
	*/
	void AddData(string name, Vector3f _data[], size_t _size,int tricount);
	/**
	*	AddData
	*	@param name
	*	@param _data
	*	@param _size
	*	@param tricount
	*/
	void AddData(string name, vector<Vector3f> _data);
	/**
	*	AddData
	*	@param name
	*	@param _data
	*/
	void AddData(string name, vector<Vector2f> _data);
	/**
	*	AddData
	*	@param name
	*	@param _data
	*/
	void AddData(string name, vector<unsigned short> _data);
};

#endif // !__MESH__H__
