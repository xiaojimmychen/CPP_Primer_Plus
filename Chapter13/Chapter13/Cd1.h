#pragma once
#ifndef CD1_H_
#define CD1_H_

#include <iostream>

class Cd1
{
private:
	char * performers;
	char * label;
	int selections;
	double playtime;

public:
	Cd1(char * s1, char * s2, int n, double x);
	Cd1(const Cd1 & d);
	Cd1();
	virtual ~Cd1();
	virtual void Report() const;
	virtual Cd1 & operator=(const Cd1 & d);
};

class Classic1 : public Cd1
{
private:
	char * mainfile;

public:
	Classic1(char * s1, char * s2, char * s3, int n, double x);
	Classic1(const Cd1 & d, char * s3);
	Classic1(const Classic1 & d);
	Classic1();
	virtual ~Classic1();
	virtual void Report() const;
	virtual Classic1 & operator=(const Classic1 & d);
};

#endif // !CD1_H_
