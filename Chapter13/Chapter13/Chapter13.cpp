#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

#include "Cd.h"
#include "Cd1.h"
#include "dma.h"
#include "Port.h"


// practice 1
void Bravo(const Cd & disk);
void p13_1(void)
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);
	Cd *pcd = &c1;

	cout << "Using object directly:\n";
	c1.Report();
	c2.Report();

	cout << "Using type cd * pointer to objects:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	cout << "Calling a function whit a cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment: ";
	Classic copy;
	copy = c2;
	copy.Report();

	return;
}
void Bravo(const Cd & disk)
{
	disk.Report();
}


// practice 2
void Bravo(const Cd1 & disk)
{
	disk.Report();
}
void p13_2(void)
{
	Cd1 c1("Beatles", "Capitol", 14, 35.5);
	Classic1 c2 = Classic1("Piano Sonata in B flat, Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);
	Cd1 *pcd = &c1;

	cout << "Using object directly:\n";
	c1.Report();
	c2.Report();

	cout << "Using type cd * pointer to objects:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	cout << "Calling a function whit a cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment: ";
	Classic1 copy;
	copy = c2;
	copy.Report();

	return;
}


// practice 3
const int CLIMENTS = 5;
void p13_3(void)
{
	baseDMA * dma[CLIMENTS];
	string label;
	int rating;
	char choice;
	string color;
	string style;

	for (int i = 0; i < CLIMENTS; i++)
	{
		cout << "Enter lable: ";
		getline(cin, label);
		cout << "Enter rating: ";
		cin >> rating;
		cout << "Enter 1 for baseDMA or 2"
			" for lacksDMA or 3 for hasDMA: ";
		while (cin >> choice && (choice != '1' && choice != '2' && choice != '3'))
		{
			cout << "Enter 1 or 2 or 3: ";
		}
		while (cin.get() != '\n');
		if (choice == '1')
		{
			dma[i] = new baseDMA(label.c_str(), rating);
		}
		else if (choice == '2')
		{
			cout << "Enter color: ";
			getline(cin, color);
			dma[i] = new lacksDMA(color.c_str(), label.c_str(), rating);
		}
		else
		{
			cout << "Enter style: ";
			getline(cin, style);
			dma[i] = new hasDMA(style.c_str(), label.c_str(), rating);
		}

	}
	cout << endl;
	for (int i = 0; i < CLIMENTS; i++)
	{
		dma[i]->View();
		cout << endl;
	}

	for (int i = 0; i < CLIMENTS; i++)
	{
		delete dma[i];
	}

	cout << "Done.\n";
	return;

}


// practice 4
void p13_4(void)
{
	Port port1("Gallo", "tawny", 20);
	VintagePort vp("None", 20, "The Noble", 1997);

	port1.Show();
	vp.Show();

	VintagePort vp2 = vp;
	Port port2 = port1;

	cout << vp2 << endl;
	cout << port2 << endl;
}



int main(int argc, char ** argv)
{
	p13_4();

	while (cin.get());
}


