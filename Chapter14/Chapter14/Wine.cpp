#include "Wine.h"

#if 0

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
{
	pArray = PairArray(ArrayInt(y), ArrayInt(y));
	label = l;
	year = y;
	for (int  i = 0; i < y; i++)
	{
		pArray.first()[i] = yr[i];
		pArray.second()[i] = bot[i];
	}
}

Wine::Wine(const char * l, int y)
{
	pArray = PairArray(ArrayInt(y), ArrayInt(y));
	label = l;
	year = y;
	for (int i = 0; i < y; i++)
	{
		pArray.first()[i] = 0;
		pArray.second()[i] = 0;
	}
}


Wine::~Wine()
{
}

void Wine::GetBottles()
{
	std::cout << "Enter " << label << " data for " << year << " year(s):" << std::endl;
	for (int i = 0; i < year; i++)
	{
		std::cout << "Enter year: ";
		std::cin >> pArray.first()[i];
		std::cout << "Enter bootles for that year: ";
		std::cin >> pArray.second()[i];
	}
}

void Wine::Show()
{
	std::cout << "Wine: " << label << std::endl;
	std::cout << "	Year	Bottles" << std::endl;
	for (int i = 0; i < year; i++)
	{
		std::cout << "	" << pArray.first()[i] << "	" << pArray.second()[i] << std::endl;
	}
}

std::string & Wine::Label()
{
	return label;
}

int Wine::sum()
{
	int sum = 0;
	for (int i = 0; i < year; i++)
	{
		sum += pArray.second()[i];
	}

	return sum;
}

#endif