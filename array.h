#pragma once

#include <fstream>

using namespace std;

class arrays
{
public:
	int count = 0;	
	enum way { Line, Column, Vector };
	way w;
	int key = 0;//
	int sum = 0;//
public:
	bool Compare(arrays *next);//
	static arrays* ReadArray(ifstream& ifst); 
	static void arrays::WriteArray(arrays *write_ar, ofstream &ofst);
	virtual void Read(ifstream &ifst) = 0;
	virtual void Write(ofstream &ofst) = 0;
	virtual void Outusual(ofstream &ofst);
	virtual int Sum() = 0;//
	virtual void Multimethod(arrays *ar, ofstream &ofst) = 0;
	virtual void DiagonalMultimethod(ofstream &ofst) = 0;
	virtual void UsualMultimethod(ofstream &ofst) = 0;
	virtual void TrianglMultimethod(ofstream &ofst) = 0;
	arrays() {};
};

class usualArray:public arrays
{
	int** arUs;
public:
	void Read(ifstream &ifst);
	void Write(ofstream &ofst);
	void Outusual(ofstream &ofst);
	//int UsualSum();
	int Sum();//
	void Multimethod(arrays *ar, ofstream &ofst);
	void DiagonalMultimethod(ofstream &ofst);
	void UsualMultimethod(ofstream &ofst);
	void TrianglMultimethod(ofstream &ofst);
	usualArray() {};
};

class diagonalArray : public arrays
{
	int* arD;
public:
	void Read(ifstream &ifst);
	void Write(ofstream &ofst);
	//int DiagonalSum();
	int Sum();//
	void Multimethod(arrays *ar, ofstream &ofst);
	void DiagonalMultimethod(ofstream &ofst);
	void UsualMultimethod(ofstream &ofst);
	void TrianglMultimethod(ofstream &ofst);
	diagonalArray() {};
};

class triangleArray : public arrays
{
public:
	int** arTr;
public:
	void Read(ifstream &ifst);
	void Write(ofstream &ofst);
	//int TrianglSum();
	int Sum();//
	void Multimethod(arrays *ar, ofstream &ofst);
	void DiagonalMultimethod(ofstream &ofst);
	void UsualMultimethod(ofstream &ofst);
	void TrianglMultimethod(ofstream &ofst);
	triangleArray() {};
};
