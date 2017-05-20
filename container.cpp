#include "stdafx.h";
#include "container.h"
#include <fstream>

using namespace std;

void container::Init()
{
	data = NULL;
	lenght = 0;
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

void container::Sorting()//
{
	element *current = data, *temp = NULL, *prev = NULL;
	bool flag;
	do
	{
		flag = false;
		current = data;
		while (current->next)
		{
			if (current->ar->Compare(current->next->ar))
			{
				if (current == data)
				{
					temp = current;
					current = temp->next;
					temp->next = current->next;
					current->next = temp;
					data = current;
					flag = true;
				}
				else
				{
					temp = current;
					current = temp->next;
					temp->next = current->next;
					current->next = temp;
					prev->next = current;
					flag = true;
				}
			}
			prev = current;
			current = current->next;
		}
	} while (flag);
}