#ifndef __SOURCEDATA__H__
#define __SOURCEDATA__H__

#include <string>
#include <vector>
#include "SamMathsVectors.h"
#include "SamMathsVectors.h"
using namespace std;

//spara buffers till olika data? behålla?
struct StoredBufferData
{
};

struct Data
{
	vector<unsigned short> _dataui;
	vector<Vector2f> _datavect2;
	vector<Vector3f> _datavect3;
	Vector2f* _datav2 = nullptr;
	Vector3f* _datav3 = nullptr;
};

///
/// Abstract Class that hold Vertex data
///
class Source
{
public:
	~Source();
	/**
	*	Constructor
	*/
	Source();
	/**
	*	Constructor
	*	@param name
	*/
	Source(string _name) : name(_name){}
	/**
	*	GetName
	*	returns the name of the specific data
	*/
	virtual string GetName() = 0;
	/**
	*	GetData
	*	returns data
	*/
	virtual Data GetData() = 0;
	/**
	*	GetData
	*	returns count
	*/
	virtual int GetCount() = 0;
	/**
	*	SizeOf
	*	returns the size
	*/
	virtual size_t SizeOf() = 0;
	/**
	*	SetData
	*	Sets Data
	*	@param _dt
	*/
	virtual void SetData(Data _dt) = 0;
protected:
	Data data;
	string name;
	size_t size;
	int count;
};


class Source2V : public Source
{
public:	
	~Source2V();

	Source2V() : Source(){}

	Source2V(string name) :Source(name){}

	Source2V(string name, Vector2f _dat[], size_t _size, int _tri) : Source(name)
	{
		this->data._datav2 = _dat;
		this->size = _size;
		this->count = _tri;
	}

	Source2V(string name, vector<Vector2f> _data, size_t _size, int _tri) : Source(name)
	{
		this->data._datavect2 = _data;
		this->size = _size;
		this->count = _tri;
	}

	string GetName();
	void SetData(Data _data);
	Data GetData();
	int GetCount();
	size_t SizeOf();
};


class Source3V : public Source
{
public:
	~Source3V();

	Source3V() : Source(){}

	Source3V(string name) : Source(name){}

	Source3V(string name, Vector3f _data[], size_t _size,int _tri) : Source(name)
	{
		this->data._datav3 = _data;
		this->size = _size;
		this->count = _tri;
	}

	Source3V(string name, vector<Vector3f> _data, size_t _size, int _tri) : Source(name)
	{
		this->data._datavect3 = _data;
		this->size = _size;
		this->count = _tri;
	}

	string GetName();
	void SetData(Data _data);
	Data GetData();
	int GetCount();
	size_t SizeOf();
};


class Source3s : public Source
{
public:
	~Source3s();

	Source3s() : Source(){}

	Source3s(string name) : Source(name){}

	Source3s(string name, vector<unsigned short> _data, size_t _size, int _tri) : Source(name)
	{
		this->data._dataui = _data;
		this->size = _size;
		this->count = _tri;
	}

	string GetName();
	void SetData(Data _data);
	Data GetData();
	int GetCount();
	size_t SizeOf();
};

#endif // !__SOURCEDATA__H__
