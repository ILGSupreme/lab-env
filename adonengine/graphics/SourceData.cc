#include "SourceData.h"


Source::~Source()
{
}


Source2V::~Source2V()
{
	if (this->data._datav2 != nullptr)
	{
		delete[] this->data._datav2;
	}
	delete[] this->data._datav2;
}

void Source2V::SetData(Data _data)
{
	this->data = _data;
}

Data Source2V::GetData()
{
	return this->data;
}


string Source2V::GetName()
{
	return this->name;
}

int Source2V::GetCount()
{
	return this->count;
}


size_t Source2V::SizeOf()
{
	return this->size;
}


Source3V::~Source3V()
{
	if (this->data._datav3 != nullptr)
	{
		delete[] this->data._datav3;
	}
	this->data._datavect3.clear();
}

void Source3V::SetData(Data _data)
{
	this->data = _data;
}

Data Source3V::GetData()
{
	return this->data;
}


string Source3V::GetName()
{
	return this->name;
}

int Source3V::GetCount()
{
	return this->count;
}

size_t Source3V::SizeOf()
{
	return this->size;
}


Source3s::~Source3s()
{
	this->data._dataui.clear();
}

void Source3s::SetData(Data _data)
{
	this->data = _data;
}

Data Source3s::GetData()
{
	return this->data;
}


string Source3s::GetName()
{
	return this->name;
}

int Source3s::GetCount()
{
	return this->count;
}

size_t Source3s::SizeOf()
{
	return this->size;
}

