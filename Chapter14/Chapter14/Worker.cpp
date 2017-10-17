#include "Worker.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;


void Worker::Set()
{
	cout << "Enter worker's name: ";
	std::getline(cin, fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while (cin.get() != '\n')
	{
		continue;
	}
}

void Worker::Show() const
{
	cout << "Name: " << fullname << "\n";
	cout << "Employee ID: " << id << "\n";
}


Worker::~Worker()
{
}
