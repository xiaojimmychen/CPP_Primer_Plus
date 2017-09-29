#include "Cd.h"

#include <cstring>

Cd::Cd(char * s1, char * s2, int n, double x)
{
	std::strcpy(performers, s1);
	std::strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd & d)
{
	std::strcpy(performers, d.performers);
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	std::strcpy(performers, "null");
	std::strcpy(label, "null");
	selections = 0;
	playtime = 0;
}


Cd::~Cd()
{
}

void Cd::Report() const
{
	std::cout << "Performers: " << performers << std::endl;
	std::cout << "Label: " << label << std::endl;
	std::cout << "Selections: " << selections << std::endl;
	std::cout << "Playtime: " << playtime << std::endl;
}

Cd & Cd::operator=(const Cd & d)
{
	std::strcpy(performers, d.performers);
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;

	return *this;
}



// Classic
Classic::Classic(char * s1, char * s2, char * s3, int n, double x) :
	Cd(s1, s2, n, x)
{
	std::strcpy(mainfile, s3);
}

Classic::Classic(const Cd & d, char * s3) : Cd(d)
{
	std::strcpy(mainfile, s3);
}

Classic::Classic(const Classic & d) : Cd(d)
{
	std::strcpy(mainfile, d.mainfile);
}

Classic::Classic() : Cd()
{
	std::strcpy(mainfile, "null");
}

Classic::~Classic()
{

}

void Classic::Report() const
{
	Cd::Report();
	std::cout << "Mainfile: " << mainfile << std::endl;
}

Classic & Classic::operator=(const Classic & d)
{
	Cd::operator=(d);
	std::strcpy(mainfile, d.mainfile);
	return *this;
}
