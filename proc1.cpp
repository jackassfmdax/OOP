// proc1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "windows.h"
#include "container.h"

using namespace std;

int main(int argc, char* argv[])
{
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
	out << "Filled contienr." << endl;
	c.Output(out);
	c.Clear();
	out << "Empty container." << endl;
	c.Output(out);
	cout << "Stop" << endl;
	in.close();
	out.close();
	system("pause");
    return 0;
}

