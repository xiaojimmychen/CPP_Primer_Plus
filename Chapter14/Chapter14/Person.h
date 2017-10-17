#pragma once
#include <string>

class Person
{
private:
	std::string firstName;
	std::string lastName;

public:
	Person() : firstName("None"), lastName("None") {}
	Person(const std::string fname, const std::string lname) :
		firstName(fname), lastName(lname) {}
	Person(const Person & p);
	virtual ~Person() = 0;
	virtual void Show() const = 0;
};

class Gunslinger : public virtual Person
{
private:
	int nicks;

public:
	Gunslinger(int d = 0) : Person(), nicks(d) {}
	Gunslinger(const std::string fname, const std::string lname, int d) :
		Person(fname, lname), nicks(d) {}
	Gunslinger(const Person & p, int d) : Person(p), nicks(d) {}
	Gunslinger(const Gunslinger & g);
	~Gunslinger();
	void Show() const;
	double Draw() const;
};

class PokerPlayer : public virtual Person
{
public:
	int Draw() const;
	void Show() const;
	PokerPlayer() : Person() {}
	PokerPlayer(const Person & p) : Person(p) {}
	PokerPlayer(const std::string fname, const std::string lname) :
		Person(fname, lname) {}
	PokerPlayer(const PokerPlayer & p) : Person(p) {}
	~PokerPlayer();
};

class BadDude : public Gunslinger, public PokerPlayer
{
public:
	BadDude() {}
	BadDude(const std::string fname, const std::string lname, int d) :
		Person(fname, lname), Gunslinger(fname, lname, d), PokerPlayer(fname, lname) {}
	BadDude(const Person & p, int d) :
		Person(p), Gunslinger(p, d), PokerPlayer(p) {}
	BadDude(const Gunslinger & g) :
		Person(g), Gunslinger(g), PokerPlayer(g) {}
	BadDude(const PokerPlayer & p, int d) :
		Person(p), Gunslinger(p, d), PokerPlayer(p) {}
	~BadDude();

	void Show() const;
	double Gdraw();
	int Cdraw();
};

