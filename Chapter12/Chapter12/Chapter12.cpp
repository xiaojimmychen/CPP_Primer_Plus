#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cstdlib>

#include "Chapter12.h"
#include "string2.h"
#include "Stock.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;


// practice 1
Cow::Cow()
{

}
Cow::Cow(const char * nm, const char * ho, double wt)
{
	strncpy(name, nm, 20);
	int ho_length = strlen(ho);
	hobby = new char[ho_length + 1];
	strncpy(hobby, ho, ho_length);
	hobby[ho_length] = '\0';
	weight = wt;
}
Cow::Cow(const Cow & c)
{
	strncpy(name, c.name, 20);
	int ho_length = strlen(c.hobby);
	hobby = new char[ho_length + 1];
	strncpy(hobby, c.hobby, ho_length);
	hobby[ho_length] = '\0';
	weight = c.weight;
}
Cow::~Cow()
{
	delete[] hobby;
	hobby = nullptr;
}
Cow & Cow::operator=(const Cow & c)
{
	strncpy(name, c.name, 20);
	int ho_length = strlen(c.hobby);
	hobby = new char[ho_length + 1];
	strncpy(hobby, c.hobby, ho_length);
	hobby[ho_length] = '\0';
	weight = c.weight;

	return *this;
}
void Cow::ShowCow() const
{
	cout << "Cow name: " << name << endl;
	cout << "Cow hobby: " << hobby << endl;
	cout << "Cow weight: " << weight << endl;
}
void p12_1(void)
{
	Cow cow1("hehehe", "eat", 123.4);
	Cow cow2("heihei", "drink", 321.2);
	Cow cow3(cow2);
	Cow cow4 = cow1;

	cow1.ShowCow();
	cow2.ShowCow();
	cow3.ShowCow();
	cow4.ShowCow();
}


// practice 2
void p12_2(void)
{
	String2 s1("and i am a C++ student.");
	String2 s2 = "Please enter your name: ";
	String2 s3;
	cout << s2;
	cin >> s3;
	s2 = "My name is " + s3;
	cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.Stringup();
	cout << "The sting\n" << s2 << "\ncontains " << s2.has('A')
		<< " 'A' characters in it.\n";
	s1 = "red";
	String2 rgb[3] = { String2(s1), String2("green"), String2("blue") };
	cout << "Enter the name of a primary color for mixing light: ";
	String2 ans;
	bool success = false;
	while (cin >> ans)
	{
		ans.Stringlow();
		for (int i = 0; i < 3; i++)
		{
			if (ans == rgb[i])
			{
				cout << "That's right!\n";
				success = true;
				break;
			}
		}
		if (success)
		{
			break;
		}
		else
		{
			cout << "Try again!\n";
		}
	}

	cout << "Bye!\n";
	return ;
}


// practice 3
const int STKS = 4;
void p12_3(void)
{
	Stock stocks[STKS] = {
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};

	std::cout << "Stock holdings:\n";
	int st;
	for (st = 0; st < STKS; st++)
	{
		std::cout << stocks[st];
	}

	const Stock * top = &stocks[0];
	for (st = 0; st < STKS; st++)
	{
		top = &top->topval(stocks[st]);
	}

	std::cout << "\nMost valuable holding:\n";
	cout << *top;
	return;
}


// practice 4
void p12_4(void)
{
	Stack st1(10);
	srand(time(0));
	for (size_t i = 0; i < 10; i++)
	{
		if (!st1.push(rand() % 100))
		{
			cout << "Push error!" << endl;;
		}
		
	}
	if (!st1.push(0))
	{
		cout << "Push 0 error!" << endl;
	}
	Stack st2(st1);
	Stack st3 = st1;
	// ���⵼��pop error
	for (size_t i = 0; i < 11; i++)
	{
		Item item;
		cout << "#" << i+1 << ": " << endl;
		if (!st1.pop(item))
		{
			cout << "st1 pop error!" << endl;
		}
		else
			cout << "st1: " << item << endl;

		if (!st2.pop(item))
		{
			cout << "st2 pop error!" << endl;
		}
		else
			cout << "st2: " << item << endl;

		if (!st3.pop(item))
		{
			cout << "st3 pop error!" << endl;
		}
		else
			cout << "st3: " << item << endl;

		cout << endl;
	}
}


// practice 5
const int MIN_PER_HR = 60;
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}
void p12_5(void)
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	std::srand(std::time(0));

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximun size of queue: ";
	int qs;
	cin >> qs;
	Queue line(qs);

	// ֱ�ӽ�����ʱ������Ϊ100����
	cout << "Simulation hours: 100" << endl;
	int hours = 100;

	long cyclelimit = MIN_PER_HR * hours;

	cItem temp;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;
	double avg_wait_time = 0.0;

	// ÿСʱʹ��������ʼֵΪ15��֮�����+1ö�ٲ���
	double perhour = 15;
	double min_per_cust;

	do {
		min_per_cust = MIN_PER_HR / perhour;
		turnaways = 0;
		customers = 0;
		served = 0;
		sum_line = 0;
		wait_time = 0;
		line_wait = 0;
		avg_wait_time = 0;

		// ��Ҫ��ն���
		while (!line.isempty())
		{
			line.dequeue(temp);
		}

		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust))
			{
				if (line.isfull())
				{
					turnaways++;
				}
				else
				{
					customers++;
					temp.set(cycle);
					line.enqueue(temp);
				}
			}
			if (wait_time <= 0 && !line.isempty())
			{
				line.dequeue(temp);
				wait_time = temp.ptime();
				line_wait += (cycle - temp.when());
				served++;
			}
			if (wait_time > 0)
			{
				wait_time--;
			}
			sum_line += line.queuecount();
		}

		if (customers > 0)
		{
			cout << "customers accepted: " << customers << endl;
			cout << "  customers served: " << served << endl;
			cout << "         turnaways: " << turnaways << endl;
			cout << "average queue size: ";
			cout.precision(2);
			cout.setf(ios_base::fixed, ios_base::floatfield);
			cout << (double)sum_line / cyclelimit << endl;
			avg_wait_time = (double)line_wait / served;
			cout << " average wait time: "
				<< avg_wait_time << " minutes\n" << endl;
		}
		else
			cout << "No customers!\n" << endl;;
		// ƽ���ȴ�ʱ�䲻һ���պ���1��������һ��������
	} while ((perhour++) && (avg_wait_time < 0.9) || (avg_wait_time > 1.1));
	
	cout << "When perhour = " << perhour << " , the average wait time"
		" will be about 1 minute\n" << endl;

	cout << "Done!\n";

	return;
}


// practice 6
void p12_6(void)
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	std::srand(std::time(0));

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximun size of queue: ";
	int qs;
	cin >> qs;
	Queue line1(qs);
	Queue line2(qs);

	// ֱ�ӽ�����ʱ������Ϊ100����
	cout << "Simulation hours: 100" << endl;
	int hours = 100;

	long cyclelimit = MIN_PER_HR * hours;

	cItem temp;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time1 = 0;
	int wait_time2 = 0;
	int line1_size = 0;
	int line2_size = 0;
	long line_wait = 0;
	double avg_wait_time = 0.0;

	// ÿСʱʹ��������ʼֵΪ15��֮�����+1ö�ٲ���
	double perhour = 15;
	double min_per_cust;

	do {
		min_per_cust = MIN_PER_HR / perhour;
		turnaways = 0;
		customers = 0;
		served = 0;
		sum_line = 0;
		wait_time1 = 0;
		wait_time2 = 0;
		line1_size = 0;
		line2_size = 0;
		line_wait = 0;
		avg_wait_time = 0;

		// ��Ҫ��ն���
		while (!line1.isempty())
		{
			line1.dequeue(temp);
		}

		while (!line2.isempty())
		{
			line2.dequeue(temp);
		}

		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust))
			{
				if (line1.isfull() && line2.isfull())
				{
					turnaways++;
				}
				else if (line1_size > line2_size)
				{
					customers++;
					temp.set(cycle);
					line2.enqueue(temp);
					line2_size++;
				} 
				else
				{
					customers++;
					temp.set(cycle);
					line1.enqueue(temp);
					line1_size++;
				}
			}
			if (wait_time1 <= 0 && !line1.isempty())
			{
				line1.dequeue(temp);
				line1_size--;
				wait_time1 = temp.ptime();
				line_wait += (cycle - temp.when());
				served++;
			}
			if (wait_time2 <=0 && !line2.isempty())
			{
				line2.dequeue(temp);
				line2_size--;
				wait_time2 = temp.ptime();
				line_wait += (cycle - temp.when());
				served++;
			}
			if (wait_time1 > 0)
			{
				wait_time1--;
			}
			if (wait_time2 > 0)
			{
				wait_time2--;
			}
			sum_line += line1.queuecount();
			sum_line += line2.queuecount();
		}

		if (customers > 0)
		{
			cout << "customers accepted: " << customers << endl;
			cout << "  customers served: " << served << endl;
			cout << "         turnaways: " << turnaways << endl;
			cout << "average queue size: ";
			cout.precision(2);
			cout.setf(ios_base::fixed, ios_base::floatfield);
			cout << (double)sum_line / cyclelimit << endl;
			avg_wait_time = (double)line_wait / served;
			cout << " average wait time: "
				<< avg_wait_time << " minutes\n" << endl;;
		}
		else
			cout << "No customers!\n" << endl;
		// ƽ���ȴ�ʱ�䲻һ���պ���1��������һ��������
	} while ((perhour++) && (avg_wait_time < 0.9) || (avg_wait_time > 1.1));

	cout << "When perhour = " << perhour << " , the average wait time"
		" will be about 1 minute\n" << endl;

	cout << "Done!\n";

	return;
}






int main(int argc, char **argv)
{
	p12_6();

	while (cin.get());
}

