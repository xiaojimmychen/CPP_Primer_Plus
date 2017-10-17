#pragma once
#include <iostream>
#include <array>
#include <string>
#include <valarray>
#include "Pairs.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
private:
	int year;
	std::string label;
	PairArray pArray;

public:
	Wine(const char * l, int y, const int yr[], const int bot[]);
	Wine(const char * l, int y);
	~Wine();
	void GetBottles();
	void Show();
	std::string & Label();
	int sum();
};

