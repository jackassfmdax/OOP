// proc1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "windows.h"
#include "container.h"

using namespace std;

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (argc != 3) 
	{
		cout << "Incorrect command line! Waited: command in_file out_file" << endl;
		exit(1);
	}
	ifstream in(argv[1]);
	ofstream out("out.txt");

	cout << "Start" << endl;
	container c;
	c.Input(in);
	c.Sorting();
	c.Output(out);
	c.Multimethod(out);
	c.Clear();
	out << "Empty container." << endl;
	c.Output(out);
	cout << "Stop" << endl;
	in.close();
	out.close();
	system("pause");
    return 0;
}

