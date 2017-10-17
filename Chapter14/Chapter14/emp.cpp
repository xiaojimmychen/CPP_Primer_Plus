#include "emp.h"

using namespace std;

abstr_emp::abstr_emp() : fname("None"), lname("None"), job("None")
{

}

abstr_emp::abstr_emp(const string & fn, const string & ln,
	const string & j)
{
	lname = ln;
	fname = fn;
	job = j;
}

void abstr_emp::ShowAll() const
{
	cout << "abstr_emp: " << endl;
	cout << "First Name: " << fname << endl;
	cout << "Last Name: " << lname << endl;
	cout << "job: " << job << endl;
}

void abstr_emp::SetAll()
{
	cout << "Enter First name: ";
	getline(cin, fname);
	cout << "Enter Last name: ";
	getline(cin, lname);
	cout << "Enter job: ";
	getline(cin, job);
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
	cout << e.fname << ", " << e.lname ;
	return os;
}

abstr_emp::~abstr_emp()
{

}

employee::employee() : abstr_emp()
{

}

employee::employee(const string & fn, const string & ln,
	const string & j) : abstr_emp(fn, ln, j)
{

}

void employee::ShowAll() const
{
	cout << "employee: " << endl;
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

manager::manager() : abstr_emp(), inchargeof(-1)
{

}

manager::manager(const string & fn, const string & ln,
	const string & j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico)
{

}

manager::manager(const abstr_emp & e, int ico) :
	abstr_emp(e), inchargeof(ico)
{

}

manager::manager(const manager & m) : abstr_emp(m)
{
	inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
	cout << "manager: " << endl;
	abstr_emp::ShowAll();
	cout << "inchargeof: " << inchargeof << endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter inchargeof: ";
	cin >> inchargeof;
	while (cin.get() != '\n')
	{
		continue;
	}
}

fink::fink() : abstr_emp(), reportsto("None")
{

}

fink::fink(const string & fn, const string & ln,
	const string & j, const string & rpo) : abstr_emp(fn, ln, j), reportsto(rpo)
{

}

fink::fink(const abstr_emp & e, const string & rpo) : abstr_emp(e), reportsto(rpo)
{

}

fink::fink(const fink & e) : abstr_emp(e)
{
	reportsto = e.reportsto;
}

void fink::ShowAll() const
{
	cout << "fink: " << endl;
	abstr_emp::ShowAll();
	cout << "reportsTo: " << reportsto << endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter reportsTo: ";
	getline(cin, reportsto);
}

highfink::highfink() : abstr_emp(), manager(), fink()
{

}

highfink::highfink(const string & fn, const string & ln,
	const string & j, const string & rpo, int ico) :
	abstr_emp(fn, ln, j), manager(fn, ln, j, ico),
	fink(fn, ln, j, rpo)
{

}

highfink::highfink(const abstr_emp & e, const string & rpo, int ico) :
	abstr_emp(e), manager(e, ico), fink(e, rpo)
{

}

highfink::highfink(const fink & f, int ico) :
	abstr_emp(f), manager(f, ico), fink(f)
{

}

highfink::highfink(const manager & m, const string & rpo) :
	abstr_emp(m), manager(m), fink(m, rpo)
{

}

highfink::highfink(const highfink & h) :
	abstr_emp(h), manager(h), fink(h)
{

}

void highfink::ShowAll() const
{
	cout << "highfink: " << endl;
	abstr_emp::ShowAll();
	cout << "inchargeof: " << manager::InChargeOf() << endl;
	cout << "reportsTo: " << fink::ReportsTo() << endl;
}

void highfink::SetAll()
{
	manager::SetAll();
	cout << "Enter reportsTo: ";
	getline(cin, fink::ReportsTo());
}