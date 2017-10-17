#pragma once
#include <iostream>
#include <string>
#include <valarray>
#include "Pairs.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : public PairArray, public std::string
{
private:
	int year;

public:
	Wine(const char * l, int y, const int yr[], const int bot[]);
	Wine(const char * l, int y);
	~Wine();
	void GetBottles();
	void Show();
	std::string & Label();
	int sum();
};

