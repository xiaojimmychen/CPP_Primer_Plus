#pragma once
#ifndef CD_H_
#define CD_H_

#include <iostream>

class Cd
{
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;

public:
	Cd(char * s1, char * s2, int n, double x);
	Cd(const Cd & d);
	Cd();
	virtual ~Cd();
	virtual void Report() const;
	virtual Cd & operator=(const Cd & d);
};

class Classic : public Cd
{
private:
	char mainfile[20];

public:
	Classic(char * s1, char * s2, char * s3, int n, double x);
	Classic(const Cd & d, char * s3);
	Classic(const Classic & d);
	Classic();
	virtual ~Classic();
	virtual void Report() const;
	virtual Classic & operator=(const Classic & d);
};

#endif // !CD_H_



