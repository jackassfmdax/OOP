#pragma once

#include <fstream>

using namespace std;

class arrays
{
public:
	int count = 0;
	int key = 0;//
public:
	static arrays* ReadArray(ifstream& ifst); 
	static void arrays::WriteArray(arrays *write_ar, ofstream &ofst);
	virtual void Read(ifstream &ifst) = 0;
	virtual void Write(ofstream &ofst) = 0;
	virtual void Outusual(ofstream &ofst);

	arrays() {};
};

class usual_ar:public arrays
{
	int** ar_us;
public:
	void Read(ifstream &ifst);
	void Write(ofstream &ofst);
	void Outusual(ofstream &ofst);
	usual_ar() {};
};

class diagonal_ar : public arrays
{
	int* ar_d;
public:
	void Read(ifstream &ifst);
	void Write(ofstream &ofst);
	diagonal_ar() {};
};