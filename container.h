#pragma once

#include "stdafx.h"
#include "array.h"

struct element
{
	arrays* ar;
	element* next;
};

class container
{
	element *data;
	int lenght = 0;
public:
	void Sorting();//
	void Init();
	void Input(ifstream& ifst);
	void Output(ofstream& ofst);
	void Clear();
	void Multimethod(ofstream &ofst);
	container() { Init(); }
	~container() { Clear(); };
};