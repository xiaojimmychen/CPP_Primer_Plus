#include "Wine1.h"

#if 1

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) :
	std::string(l), PairArray(ArrayInt(y), ArrayInt(y))
{
	year = y;
	for (int i = 0; i < year; i++)
	{
		PairArray::first()[i] = yr[i];
		PairArray::second()[i] = bot[i];
	}
}

Wine::Wine(const char * l, int y) :
	std::string(l), PairArray(ArrayInt(y), ArrayInt(y))
{
	year = y;
	for (int i = 0; i < year; i++)
	{
		PairArray::first()[i] = 0;
		PairArray::second()[i] = 0;
	}
}

Wine::~Wine()
{

}

void Wine::GetBottles()
{
	std::cout << "Enter " << (const std::string)*this << " data for " << year
		<< " year(s): " << std::endl;
	for (int i = 0; i < year; i++)
	{
		std::cout << "Enter year: ";
		std::cin >> PairArray::first()[i];
		std::cout << "Enter bootles for that year: ";
		std::cin >> PairArray::second()[i];
	}
}

void Wine::Show()
{
	std::cout << "Wine: " << (const std::string)*this << std::endl;
	std::cout << "	Year	Bootles" << std::endl;
	for (int i = 0; i < year; i++)
	{
		std::cout << "	" << PairArray::first()[i] << "	"
			<< PairArray::second()[i] << std::endl;
	}
}

std::string & Wine::Label()
{
	return (std::string &)*this;
}

int Wine::sum()
{
	int sum = 0;
	for (int i = 0; i < year; i++)
	{
		sum += PairArray::second()[i];
	}

	return sum;
}

#endif

