#pragma once
#ifndef MYTIME2_H_
#define MYTIME2_H_

class Stonewt2
{
private:
	enum { Lbs_per_stn = 14 };
	int stone;
	double pds_left;
	double pounds;

public:
	Stonewt2(double lbs);
	Stonewt2(int stn, double lbs);
	Stonewt2();
	~Stonewt2();
	void show_lbs() const;
	void show_stn() const;

	bool operator==(const Stonewt2 & st) const;
	bool operator!=(const Stonewt2 & st) const;
	bool operator<(const Stonewt2 & st) const;
	bool operator>(const Stonewt2 & st) const;
	bool operator<=(const Stonewt2 & st) const;
	bool operator>=(const Stonewt2 & st) const;
};

#endif // !MYTIME2_H_

