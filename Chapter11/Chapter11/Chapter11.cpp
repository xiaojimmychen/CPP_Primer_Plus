#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "vector.h"
#include "mytime1.h"
#include "Stonewt1.h"
#include "Stonewt2.h"
#include "complex0.h"

using namespace std;


// practice 1
// �������У����������е��������Ӧ���ǳ����嵥11.15�Ŷ�
// ��Ӧ��vector.h��vector.cpp�������鱾��ԭ�еģ�Ҳ������practice 2���޸Ĺ���
void p11_1(void)
{
	using VECTOR::Vector;
	string filename = "randwalk.txt";
	ofstream outFile;
	outFile.open(filename.c_str(), ios_base::out);
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;

		outFile << "Target Distance: " << target << ", " << "Step Size: " << dstep << endl;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
			step.rect_mode();
			outFile << result << endl;
		}
		outFile << "After " << steps << " steps, the subject "
			"has the following locations:\n";
		outFile << result << endl;
		result.polar_mode();
		outFile << " or\n" << result << endl;
		outFile << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;

	return ;
}


// practice 2
void p11_2(void)
{
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;

		cout << "Target Distance: " << target << ", " << "Step Size: " << dstep << endl;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
			step.rect_mode();
			cout << result << endl;
		}
		cout << "After " << steps << " steps, the subject "
			"has the following locations:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;

	return;
}


// practice 3
void p11_3(void)
{
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	unsigned long max_steps = 0;
	unsigned long min_steps = 0 - 1;
	unsigned long total_steps = 0;
	double average_steps = 0.0;
	int test_times = 0;
	cout << "Enter target distance (q to quit): ";
	cin >> target;
	cout << "Enter step length: ";
	cin >> dstep;
	cout << "Enter test times: ";
	cin >> test_times;
	cin.get();
	for (int i = 0; i < test_times; i++)
	{
		cout << "Target Distance: " << target << ", " << "Step Size: " << dstep << endl;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
			step.rect_mode();
			cout << result << endl;
		}
		cout << "After " << steps << " steps, the subject "
			"has the following locations:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;

		total_steps += steps;
		if (steps > max_steps)
		{
			max_steps = steps;
		}
		else if (steps < min_steps)
		{
			min_steps = steps;
		}
		steps = 0;
		result.reset(0.0, 0.0);
		cout << endl;
	}

	average_steps = (double)total_steps / test_times;
	cout << endl;
	cout << "Test " << test_times << " times, max steps is " << max_steps << ", min steps is " << min_steps << ", average steps is " << average_steps << endl;
		
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;

	return;
}


// practice 4
void p11_4(void)
{
	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;

	cout << "Aida and Tosca:\n";
	cout << aida << "; " << tosca << endl;
	temp = aida + tosca;
	cout << "Aida + Tosca: " << temp << endl;

	temp = aida * 1.17;
	cout << "Aida * 1.17: " << temp << endl;

	cout << "10 * Tosca: " << 10 * tosca << endl;

	return;
}


// practice 5
void p11_5(void)
{
	Stonewt1 st1(120);
	Stonewt1 st2(12.3, Stonewt1::IPOUND);
	Stonewt1 st3(123.3, Stonewt1::DPOUND);

	Stonewt1 st4 = 13 + st1;
	Stonewt1 st5 = 13 * st2;
	Stonewt1 st6 = 13 - st2;

	Stonewt1 st7 = st1 + 10;
	Stonewt1 st8 = st1 - 10;
	Stonewt1 st9 = st1 * 10;

	cout << st1 << endl;
	cout << st2 << endl;
	cout << st3 << endl;
	cout << st4 << endl;
	cout << st5 << endl;
	cout << st6 << endl;
	cout << st7 << endl;
	cout << st8 << endl;
	cout << st9 << endl;
}


// practice 6
void p11_6(void)
{
	Stonewt2 st[6] = {
		Stonewt2(10.0, 0),
		Stonewt2(11.1, 0),
		Stonewt2(22.2, 0)
	};
	Stonewt2 max = st[0];
	Stonewt2 min = st[0];
	Stonewt2 ele(11, 0);
	int num = 0;

	for (int i = 0; i < 3; i++)
	{
		double pounds = 0;
		cout << "Enter the pounds: ";
		cin >> pounds;
		Stonewt2 tmp(pounds);
		st[3 + i] = tmp;
	}

	for (int i = 0; i < 6; i++)
	{
		if (max < st[i])
		{
			max = st[i];
		}
		else if (min > st[i])
		{
			min = st[i];
		}

		if (st[i] >= ele)
		{
			num++;
		}
	}

	cout << "Max element: ";
	max.show_stn();

	cout << "Min element: ";
	min.show_stn();

	cout << "There are " << num << " element large than 11 stones." << endl;

	return;
}


// practice 7
void p11_7(void)
{
	complex a(3.0, 4.0);
	complex c;

	cout << "Enter a complex number (q to quit):\n";
	while (cin >> c)
	{
		cout << "c is " << c << '\n';
		cout << "complex conjugate is " << ~c << '\n';
		cout << "a is " << a << '\n';
		cout << "a + c is " << a + c << '\n';
		cout << "a - c is " << a - c << '\n';
		cout << "a * c is " << a * c << '\n';
		cout << "2 * c is " << 2 * c << '\n';
		cout << "Enter a complex number (q to quit):\n";
	}

	cout << "Done!\n";
	return;
}






int main(int argc, char ** argv)
{
	p11_7();

	while (cin.get());
}