#include "Person.h"
#include <iostream>
#include <ctime>
#include <cmath>

using std::cout;
using std::endl;

Person::Person(const Person & p)
{
	firstName = p.firstName;
	lastName = p.lastName;
}

Person::~Person()
{
}

void Person::Show() const
{
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
}

Gunslinger::Gunslinger(const Gunslinger & g) : Person(g)
{
	nicks = g.nicks;
}

double Gunslinger::Draw() const
{
	return (double)(rand() % 10) / 10;
}

void Gunslinger::Show() const
{
	Person::Show();
	cout << "Nicks: " << nicks << endl;
	cout << "Pull the gun time: " << Draw() << endl;
}

Gunslinger::~Gunslinger()
{

}

int PokerPlayer::Draw() const
{
	return (rand() % 52);
}

void PokerPlayer::Show() const
{
	Person::Show();
}

PokerPlayer::~PokerPlayer()
{

}


void BadDude::Show() const
{
	Gunslinger::Show();
	cout << "Next Card: " << PokerPlayer::Draw() << endl;
}

double BadDude::Gdraw()
{
	return Gunslinger::Draw();
}

int BadDude::Cdraw()
{
	return PokerPlayer::Draw();
}

BadDude::~BadDude()
{

}



