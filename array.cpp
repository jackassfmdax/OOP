#include "stdafx.h"
#include <fstream>
#include "array.h"

using namespace std;

void diagonal_ar::Read(ifstream &ifst)
{
	ifst >> count;
	ar_d = new int[count];
	for (int i = 0; i < count; i++)
		ifst >> ar_d[i];
}

int diagonal_ar::DiagonalSum()
{
	int sum = 0;
	for (int i = 0; i < count; i++)
		sum += ar_d[i];
	return sum;
}

void diagonal_ar::Write(ofstream &ofst)
{
	ofst << "It is Diagonal Matrix: count of elements = " << count << endl << "Matrix:" << endl;
	ofst << "Sum of elements = " << DiagonalSum() << endl;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
			if (i == j)
				ofst << ar_d[i] << '\t';
			else
				ofst << "0\t";
		ofst << endl;
	}
}

void usual_ar::Read(ifstream &ifst)
{
	ifst >> count;
	ar_us = new int*[count];
	for (int i = 0; i < count; i++)
		ar_us[i] = new int[count];
	for (int i = 0; i < count; i++)
		for (int j = 0; j < count; j++)
			ifst >> ar_us[i][j];
}

int usual_ar::UsualSum()
{
	int sum = 0;
	for (int i = 0; i < count; i++)
		for (int j = 0; j < count; j++)
			sum += ar_us[i][j];
	return sum;
}

void usual_ar::Write(ofstream &ofst)
{
	ofst << "It is Usual Matrix: count of elements = " << count << endl << "Matrix:" << endl;
	ofst << "Sum of elements = " << UsualSum() << endl;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
			ofst << ar_us[i][j] << '\t';
		ofst << endl;
	}
}

arrays* arrays::ReadArray(ifstream& ifst)
{
	arrays* ar;
	int key;
	ifst >> key;
	switch (key)
	{
	case 1:
		ar = new diagonal_ar;
		break;
	case 2:
		ar = new usual_ar;
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
	write_ar->Write(ofst);
}