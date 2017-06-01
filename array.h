#pragma once

#include <fstream>

using namespace std;

class arrays
{
public:
	int count = 0;
	int key = 0;
public:
	static arrays* ReadArray(ifstream& ifst); 
	static void arrays::WriteArray(arrays *write_ar, ofstream &ofst);
	virtual void Read(ifstream &ifst) = 0;
	virtual void Write(ofstream &ofst) = 0;
	virtual void Multimethod(arrays *ar, ofstream &ofst) = 0;
	virtual void DiagonalMultimethod(ofstream &ofst) = 0;
	virtual void UsualMultimethod(ofstream &ofst) = 0;
	arrays() {};
};

class usual_ar:public arrays
{
	int** ar_us;
public:
	void Read(ifstream &ifst);
	void Write(ofstream &ofst);
	void Multimethod(arrays *ar, ofstream &ofst);
	void DiagonalMultimethod(ofstream &ofst);
	void UsualMultimethod(ofstream &ofst);
	usual_ar() {};
};

class diagonal_ar : public arrays
{
	int* ar_d;
public:
	void Read(ifstream &ifst);
	void Write(ofstream &ofst);
	void Multimethod(arrays *ar, ofstream &ofst);
	void DiagonalMultimethod(ofstream &ofst);
	void UsualMultimethod(ofstream &ofst);
	diagonal_ar() {};
};