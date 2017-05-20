#include "stdafx.h";
#include "container.h"
#include <fstream>

using namespace std;

void container::Init()
{
	data = NULL;
}

void container::Input(ifstream& ifst)
{
	while (!ifst.eof())
	{
		element *temp = new element;
		temp->ar = arrays::ReadArray(ifst);
		temp->next = data;
		data = temp;
		lenght++;
	}
}

void container::Output(ofstream &ofst)
{
	ofst << "Containrt contents " << lenght << " elements." << endl;
	element *temp = data;
	int num = lenght;
	while (temp != NULL)
	{
			temp->ar->Outusual(ofst);
			temp = temp->next;
	}
}

void container::Clear()
{
	while (data != NULL)
	{
		element *temp = data->next;
		delete data;
		data = temp;
	}
	lenght = 0;
}