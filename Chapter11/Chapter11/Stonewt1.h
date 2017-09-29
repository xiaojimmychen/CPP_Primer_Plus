#pragma once
#ifndef STONEWT1_H_
#define STONEWT1_H_

#include <iostream>

class Stonewt1
{
public:
	enum format { STONES, IPOUND, DPOUND };

private:
	enum {Lbs_per_stn = 14};
	format ft;
	double stone;
	int ipounds;
	double dpounds;

	// 有三种格式的数据，成员函数先对total进行操作
	// 然后调用update更新所有的成员变量
	// 免得每个成员函数里面都用if...else if的判断来更新
	double total;
	void update();
	
public:
	Stonewt1();
	Stonewt1(double n, format f = STONES);
	Stonewt1 operator+(double n) const;
	Stonewt1 operator-(double n) const;
	Stonewt1 operator*(double n) const;

	friend Stonewt1 operator+(double n, const Stonewt1 & st);
	friend Stonewt1 operator-(double n, const Stonewt1 & st);
	friend Stonewt1 operator*(double n, const Stonewt1 & st);
	friend std::ostream & operator<<(std::ostream & os, const Stonewt1 & st);
};

#endif // !STONEWT1_H_

