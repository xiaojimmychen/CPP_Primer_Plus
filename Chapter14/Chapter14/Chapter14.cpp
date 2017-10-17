#include <iostream>
#include <array>
#include <string>
#include <ctime>
#include "Pairs.h"
#include "QueueTp.h"
#include "Worker.h"
#include "Person.h"
#include "emp.h"

// practice 1的时候include Wine.h
// 还要将Wine.cpp中的 #if 0 改成 #if 1
// 还要将Wine1.cpp中的 #if 1 改成 #if 0
//#include "Wine.h"

// practice 2的时候include Wine1.h
#include "Wine1.h"

using namespace std;

// practice 1 && practice 2
void p14_1(void)
{
	cout << "Enter name of wine: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter number of years: ";
	int yrs;
	cin >> yrs;

	Wine holding(lab, yrs);
	holding.GetBottles();
	holding.Show();

	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };
	
	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();

	cout << "Total bottles for " << more.Label()
		<< ": " << more.sum() << endl;

	cout << "Bye\n";
	return;
}


// practice 3
void p14_3(void)
{
	QueueTp<Worker> * Qworker = new QueueTp<Worker>(20);

	// 放在大括号里面是想看看Queue里面的item是否受原数据生命周期的影响的
	// 看来是不会受到影响
	{
		Worker w1("jimmy", 0);
		Worker w2("jimmy2", 1);
		if (Qworker->isempty())
		{
			cout << "Qworker is empty!\n";
		}
		Qworker->enqueue(w1);
		Qworker->enqueue(w2);
		cout << "Qworker count: " << Qworker->queuecount() << endl;

		Worker w3("hello", 2);
		Qworker->enqueue(w3);
		Qworker->enqueue(w2);
		cout << "Qworker count: " << Qworker->queuecount() << endl;
	}

	Worker temp;
	Qworker->dequeue(temp);
	cout << "Dequeue: " << endl;
	temp.Show();

	Qworker->dequeue(temp);
	cout << "Dequeue: " << endl;
	temp.Show();

	cout << "Qworker count: " << Qworker->queuecount() << endl;
}


// practice 4
// 勉勉强强用吧，感觉写得我自己都有点晕了
void p14_4(void)
{
	const int SIZE = 5;
	srand(time(0));

	Person * person[SIZE];
	int ct = 0;
	for ( ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the choice:\n"
			<< "g: Gunslinger  t: BadDude  "
			<< "a: PokerPlayer  q: quit\n";
		cin >> choice;

		while (strchr("pgatq", choice) == NULL)
		{
			cout << "Please enter a p, g, a, t, q: ";
			cin >> choice;
		}
		while (cin.get() != '\n')
		{
			continue;
		}

		if (choice == 'q')
		{
			break;
		}

		string fname;
		string lname;
		int nicks = 0;

		cout << "Enter first name: " << endl;
		getline(cin, fname);
		cout << "Enter last name: " << endl;
		getline(cin, lname);

		switch (choice)
		{
		case 'g':
			cout << "Enter nicks: " << endl;
			cin >> nicks;
			person[ct] = new Gunslinger(fname, lname, nicks);
			break;

		case 'a':
			person[ct] = new PokerPlayer(fname, lname);
			break;

		case 't':
			cout << "Enter nicks: " << endl;
			cin >> nicks;
			person[ct] = new BadDude(fname, lname, nicks);
			break;

		default:
			break;
		}
	}

	cout << "\nHere is your input:\n";
	int i = 0;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		person[i]->Show();
	}

	for (i = 0; i < ct; i++)
	{
		delete person[i];
	}

	cout << "Bye!\n";
	return;
}


// practice 5
void p14_5(void)
{
	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.ShowAll();
	manager ma("Amorphias", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.ShowAll();

	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.ShowAll();
	highfink hf(ma, "Curly Kew");
	hf.ShowAll();
	cout << "Press a key for next phase:\n";
	cin.get();
	highfink hf2;
	hf2.SetAll();

	cout << "Using an abstr_emp * pointer:\n";
	abstr_emp * tri[4] = { &em, &fi, &hf, &hf2 };
	for (int i = 0; i < 4; i++)
	{
		tri[i]->ShowAll();
	}

	return;
}



int main(int argc, char **argv)
{
	p14_5();

	while (cin.get());

	return 0;
}