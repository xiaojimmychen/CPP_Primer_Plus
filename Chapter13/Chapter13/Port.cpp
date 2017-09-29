#include "Port.h"



Port::Port(const char * br, const char * st, int b)
{
	int brand_length = std::strlen(br);
	brand = new char[brand_length + 1];
	std::strcpy(brand, br);
	std::strcpy(style, st);
	bottles = b;
}

Port::Port(const Port & p)
{
	int brand_length = std::strlen(p.brand);
	brand = new char[brand_length + 1];
	std::strcpy(brand, p.brand);
	std::strcpy(style, p.style);
	bottles = p.bottles;
}

Port & Port::operator=(const Port & p)
{
	delete[] brand;

	int brand_length = std::strlen(p.brand);
	brand = new char[brand_length + 1];
	std::strcpy(brand, p.brand);
	std::strcpy(style, p.style);
	bottles = p.bottles;

	return *this;
}

Port & Port::operator+=(int b)
{
	bottles += b;

	return *this;
}

Port & Port::operator-=(int b)
{
	bottles -= b;
	return *this;
}

void Port::Show() const
{
	std::cout << "Brand: " << brand << std::endl;
	std::cout << "Style: " << style << std::endl;
	std::cout << "Bottles: " << bottles << std::endl;
}

ostream & operator<<(ostream & os, const Port & s)
{
	os << s.brand << ", " << s.style << ", " << s.bottles;

	return os;
}

VintagePort::VintagePort() : Port()
{
	int null_length = std::strlen("null");
	nickname = new char[null_length + 1];
	std::strcpy(nickname, "null");
	year = 0;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y) :
	Port(br, "Vintage", b)
{
	int nn_length = std::strlen(nn);
	nickname = new char[nn_length + 1];
	std::strcpy(nickname, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp)
{
	int nn_length = std::strlen(vp.nickname);
	nickname = new char[nn_length + 1];
	std::strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
	delete nickname;
	Port::operator=(vp);

	int nn_length = std::strlen(vp.nickname);
	nickname = new char[nn_length + 1];
	std::strcpy(nickname, vp.nickname);
	year = vp.year;

	return *this;
}

void VintagePort::Show() const
{ 
	Port::Show();
	cout << "Nickname: " << nickname << endl;
	cout << "Year: " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp)
{
	os << Port(vp);
	os << ", " << vp.nickname << ", " << vp.year;

	return os;
}
