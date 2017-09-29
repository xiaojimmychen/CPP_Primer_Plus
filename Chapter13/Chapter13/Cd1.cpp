#include "Cd1.h"

#include <cstring>

Cd1::Cd1(char * s1, char * s2, int n, double x)
{
	int performers_length = std::strlen(s1);
	performers = new char[performers_length + 1];

	int label_length = std::strlen(s2);
	label = new char[label_length + 1];

	std::strcpy(performers, s1);
	std::strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd1::Cd1(const Cd1 & d)
{
	int performers_length = std::strlen(d.performers);
	performers = new char[performers_length + 1];

	int label_length = std::strlen(d.label);
	label = new char[label_length + 1];

	std::strcpy(performers, d.performers);
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd1::Cd1()
{
	int null_length = std::strlen("null");
	performers = new char[null_length + 1];
	label = new char[null_length + 1];

	std::strcpy(performers, "null");
	std::strcpy(label, "null");
	selections = 0;
	playtime = 0;
}


Cd1::~Cd1()
{
	delete[] performers;
	delete[] label;
	performers = nullptr;
	label = nullptr;
}

void Cd1::Report() const
{
	std::cout << "Performers: " << performers << std::endl;
	std::cout << "Label: " << label << std::endl;
	std::cout << "Selections: " << selections << std::endl;
	std::cout << "Playtime: " << playtime << std::endl;
}

Cd1 & Cd1::operator=(const Cd1 & d)
{
	delete[] performers;
	delete[] label;
	performers = nullptr;
	label = nullptr;

	int performers_length = std::strlen(d.performers);
	performers = new char[performers_length + 1];

	int label_length = std::strlen(d.label);
	label = new char[label_length + 1];

	std::strcpy(performers, d.performers);
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;

	return *this;
}



// Classic1
Classic1::Classic1(char * s1, char * s2, char * s3, int n, double x) :
	Cd1(s1, s2, n, x)
{
	int mainfile_length = std::strlen(s3);
	mainfile = new char[mainfile_length + 1];

	std::strcpy(mainfile, s3);
}

Classic1::Classic1(const Cd1 & d, char * s3) : Cd1(d)
{
	int mainfile_length = std::strlen(s3);
	mainfile = new char[mainfile_length + 1];

	std::strcpy(mainfile, s3);
}

Classic1::Classic1(const Classic1 & d) : Cd1(d)
{
	int mainfile_length = std::strlen(d.mainfile);
	mainfile = new char[mainfile_length + 1];

	std::strcpy(mainfile, d.mainfile);
}

Classic1::Classic1() : Cd1()
{
	int null_length = std::strlen("null");
	mainfile = new char[null_length + 1];

	std::strcpy(mainfile, "null");
}

Classic1::~Classic1()
{
	delete[] mainfile;
	mainfile = nullptr;
}

void Classic1::Report() const
{
	Cd1::Report();
	std::cout << "Mainfile: " << mainfile << std::endl;
}

Classic1 & Classic1::operator=(const Classic1 & d)
{
	Cd1::operator=(d);
	delete[] mainfile;
	mainfile = nullptr;

	int mainfile_length = std::strlen(d.mainfile);
	mainfile = new char[mainfile_length + 1];

	std::strcpy(mainfile, d.mainfile);
	return *this;
}
