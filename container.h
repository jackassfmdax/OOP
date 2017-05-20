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
	void Init();
	void Input(ifstream& ifst);
	void Output(ofstream& ofst);
	void Clear();
	container() { Init(); }
	~container() { Clear(); };
};