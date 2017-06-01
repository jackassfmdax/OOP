#include "stdafx.h"
#include <fstream>
#include "array.h"
#include "protect.h"

using namespace std;

void diagonalArray::Read(ifstream &ifst)
{
	int w;//
	ifst >> w;
	CheckWrongInput(ifst);//
	CheckWay(w);
	w--;
	this->w = (diagonalArray::way)w;
	ifst >> count;//
	CheckCount(count);
	arD = new int[count];
	for (int i = 0; i < count; i++)
		ifst >> arD[i];
}

int diagonalArray::Sum()//
{
	int sum = 0;
	for (int i = 0; i < count; i++)
		sum += arD[i];
	return sum;
}

void diagonalArray::Write(ofstream &ofst)
{
	string way[3] = { "Line", "Column", "Vector" };//
	ofst << way[w].c_str() << endl;//
	ofst << "It is Diagonal Matrix: count of elements = " << count << endl << "Matrix:" << endl;
	ofst << "Sum of elements = " << Sum() << endl;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
			if (i == j)
				ofst << arD[i] << '\t';
			else
				ofst << "0\t";
		ofst << endl;
	}
}

void diagonalArray::Multimethod(arrays *ar, ofstream &ofst)
{
	ar->DiagonalMultimethod(ofst);
}

void diagonalArray::DiagonalMultimethod(ofstream &ofst)
{
	ofst << "Diagonal & Diagonal Matrix" << endl;
}

void diagonalArray::UsualMultimethod(ofstream &ofst)
{
	ofst << "Usual & Diagonal Matrix" << endl;
}

void diagonalArray::TrianglMultimethod(ofstream &ofst)
{
	ofst << "Triangle & Diagonal Matrix" << endl;
}

void usualArray::Read(ifstream &ifst)
{
	int w;//
	ifst >> w;
	CheckWrongInput(ifst);//
	CheckWay(w);//
	w--;
	this->w = (usualArray::way)w;
	ifst >> count;//
	CheckCount(count);
	arUs = new int*[count];
	for (int i = 0; i < count; i++)
		arUs[i] = new int[count];
	for (int i = 0; i < count; i++)
		for (int j = 0; j < count; j++)
			ifst >> arUs[i][j];
}

int usualArray::Sum()//
{
	int sum = 0;
	for (int i = 0; i < count; i++)
		for (int j = 0; j < count; j++)
			sum += arUs[i][j];
	return sum;
}

void usualArray::Write(ofstream &ofst)
{

	string way[3] = { "Line", "Column", "Vector" };//
	ofst << way[w].c_str() << endl;//
	ofst << "It is Usual Matrix: count of elements = " << count << endl << "Matrix:" << endl;
	ofst << "Sum of elements = " << Sum() << endl;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
			ofst << arUs[i][j] << '\t';
		ofst << endl;
	}
}

void usualArray::Multimethod(arrays *ar, ofstream &ofst)
{
	ar->UsualMultimethod(ofst);
}

void usualArray::UsualMultimethod(ofstream &ofst)
{
	ofst << "Usual & Usual Matrix" << endl;
}

void usualArray::DiagonalMultimethod(ofstream &ofst)
{
	ofst << "Diagonal & Usual Matrix" << endl;
}

void usualArray::TrianglMultimethod(ofstream &ofst)
{
	ofst << "Triangle & Usual Matrix" << endl;
}

void arrays::Outusual(ofstream &ofst) 
{
	ofst << endl;  // пустая строка
}

void usualArray::Outusual(ofstream &ofst) 
{
	Write(ofst);
}

void triangleArray::Read(ifstream &ifst)
{
	int w;//
	ifst >> w;
	CheckWrongInput(ifst);//
	CheckWay(w);//
	w--;
	this->w = (triangleArray::way)w;
	ifst >> count;
	CheckCount(count);
	arTr = new int*[count];
	for (int i = 0; i < count; i++)
		arTr[i] = new int[count];
	for (int i = 0; i < count; i++)
		for (int j = 0; j < count; j++)
			if (i >= j)
				ifst >> arTr[i][j];
			else
				arTr[i][j] = 0;
}

int triangleArray::Sum()//
{
	int sum = 0;
	for (int i = 0; i < count; i++)
		for (int j = 0; j < count; j++)
			sum += arTr[i][j];
	return sum;
}

void triangleArray::Write(ofstream &ofst)
{
	ofst << "It is Triangle Matrix: count of elements = " << count << endl << "Matrix:" << endl;
	ofst << "Sum of elements = " << Sum() << endl;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
			if (i >= j)
				ofst << arTr[i][j] << '\t';
			else
				ofst << "0\t";
		ofst << endl;
	}
}

void triangleArray::Multimethod(arrays *ar, ofstream &ofst)
{
	ar->UsualMultimethod(ofst);
}

void triangleArray::UsualMultimethod(ofstream &ofst)
{
	ofst << "Usual & Triangle Matrix" << endl;
}

void triangleArray::DiagonalMultimethod(ofstream &ofst)
{
	ofst << "Diagonal & Triangle Matrix" << endl;
}

void triangleArray::TrianglMultimethod(ofstream &ofst)
{
	ofst << "Triangle & Triangle Matrix" << endl;
}

arrays* arrays::ReadArray(ifstream& ifst)
{
	arrays* ar;
	int key;
	CheckInputFile(ifst);//
	ifst >> key;
	CheckWrongInput(ifst);//
	CheckKey(key);//
	switch (key)
	{
	case 1:
		ar = new diagonalArray;
		break;
	case 2:
		ar = new usualArray;
		break;
	case 3:
		ar = new triangleArray;
		break;
	default:
		return NULL;
	}
	ar->key = key;
	ar->Read(ifst);
	return ar;
}

void arrays::WriteArray(arrays *write_ar, ofstream &ofst)
{
	CheckOutputFile(ofst);//
	write_ar->Write(ofst);
}

bool arrays::Compare(arrays *next)//
{
	return (Sum() > next->Sum());
}