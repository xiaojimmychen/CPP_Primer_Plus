#include "dma.h"

#include <cstring>


DMA::DMA()
{
	
}


DMA::~DMA()
{
}

baseDMA::baseDMA(const char * l, int r)
{
	int label_length = std::strlen(l);
	label = new char[label_length + 1];

	std::strcpy(label, l);
	rating = r;
}

baseDMA::baseDMA(const baseDMA & rs)
{
	int label_length = std::strlen(rs.label);
	label = new char[label_length + 1];

	std::strcpy(label, rs.label);
	rating = rs.rating;
}

baseDMA::~baseDMA()
{
	delete[] label;
	label = nullptr;
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
	delete[] label;

	int label_length = std::strlen(rs.label);
	label = new char[label_length + 1];

	std::strcpy(label, rs.label);
	rating = rs.rating;

	return *this;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
	os << "Label: " << rs.label << std::endl;
	os << "Rating: " << rs.rating;

	return os;
}

void baseDMA::View()
{
	std::cout << "Label: " << label << std::endl;
	std::cout << "Rating: " << rating << std::endl;
}

lacksDMA::lacksDMA(const char * c, const char * l, int t) :
	baseDMA(l, t)
{
	std::strcpy(color, c);
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs) :
	baseDMA(rs)
{
	std::strcpy(color, c);
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & rs)
{
	operator<<(os, (baseDMA)rs) << std::endl;
	os << "Color: " << rs.color;

	return os;
}

void lacksDMA::View()
{
	baseDMA::View();
	std::cout << "Color: " << color << std::endl;
}

hasDMA::hasDMA(const char * s, const char * l, int r) :
	baseDMA(l, r)
{
	int style_length = std::strlen(s);
	style = new char[style_length + 1];

	std::strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const baseDMA & rs) :
	baseDMA(rs)
{
	int style_length = std::strlen(s);
	style = new char[style_length + 1];

	std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs) :
	baseDMA(hs)
{
	int style_length = std::strlen(hs.style);
	style = new char[style_length + 1];

	std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
	delete[] style;
	style = nullptr;
}

hasDMA & hasDMA::operator=(const hasDMA & rs)
{
	baseDMA::operator=(rs);
	delete[] style;

	int style_length = std::strlen(rs.style);
	style = new char[style_length + 1];

	std::strcpy(style, rs.style);

	return *this;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & rs)
{
	operator<<(os, baseDMA(rs)) << std::endl;
	os << "Style: " << rs.style;

	return os;
}

void hasDMA::View()
{
	baseDMA::View();
	std::cout << "Style: " << style << std::endl;
}


