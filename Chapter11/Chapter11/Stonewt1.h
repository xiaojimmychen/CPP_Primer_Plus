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

	// �����ָ�ʽ�����ݣ���Ա�����ȶ�total���в���
	// Ȼ�����update�������еĳ�Ա����
	// ���ÿ����Ա�������涼��if...else if���ж�������
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

