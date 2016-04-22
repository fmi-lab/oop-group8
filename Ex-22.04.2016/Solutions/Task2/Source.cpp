#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

class Worker
{
public:
	Worker(char* name = "")
	{
		this->name = new char[strlen(name) + 1];
		assert(this->name != NULL);
		strcpy(this->name, name);

	}
	~Worker()
	{
		del();
	}
	Worker(const Worker& other)
	{
		cpy(other);
	}
	Worker& operator = (const Worker& other)
	{
		if (this != &other)
		{
			del();
			cpy(other);
		}
		return *this;
	}
	virtual double getSalary() const
	{
		return 0;
	}
	virtual void print()
	{
		cout << "name " << name  << " ";
	}
protected:
	char* name;
	double salary;
	void del()
	{
		delete[] name;
	}
	void cpy(const Worker& other)
	{
		name = new char[strlen(other.name) + 1];
		assert(name != NULL);
		strcpy(name, other.name);
		salary = other.salary;
	}
};

class Salary : public Worker
{
public:
	Salary(char* name = "", double years = 0) : Worker(name)
	{

		if (years >= 0)
			this->years = years;
		else
			this->years = 0;
	}
	Salary(const Salary& other) : Worker(other)
	{
		years = other.years;
	}
	Salary& operator = (const Salary& other)
	{
		if (this != &other)
		{
			Worker:: operator = (other);			
			years = other.years;
		}
	}
	virtual void print()
	{
		Worker::print();
		cout << "years " << years << " " ;
		cout << "salary " << getSalary() << endl;

	}
	virtual double getSalary() const
	{
		return (years*50);
	}
private:
	double years;
};

class PerHour : public Worker
{
public:
	PerHour(char* name = "", int hours = 0, double payHour = 0) : Worker(name)
	{
		this->hours = hours;
		this->payHour = payHour;
	}
	PerHour(const PerHour& other) : Worker(other)
	{
		hours = other.hours;
		payHour = other.payHour;
	}
	PerHour& operator = (const PerHour& other)
	{
		if (this != &other)
		{
			Worker:: operator = (other);
			hours = other.hours;
			payHour = other.payHour;
		}
		return *this;
	}
	virtual void print()
	{
		Worker::print();
		cout << "hours " << hours << " " << "perHour " << payHour << " ";
		cout << "salary " << getSalary() << endl;

	}
	virtual double getSalary() const
	{
		return hours*payHour;
	}
private:
	int hours;
	double payHour;
};

class Intern : public Worker
{
public:
	Intern(char* name = "", bool isPaid = 0) : Worker(name)
	{
		this->isPaid = isPaid;
	}
	Intern(const Intern& other) : Worker(other)
	{
		isPaid = other.isPaid;
	}
	Intern& operator = (const Intern& other)
	{
		if (this != &other)
		{
			Worker :: operator = (other);
			isPaid = other.isPaid;
		}
		return *this;
	}
	
	virtual void print()
	{
		Worker::print();
		cout << "isPaid " << isPaid << " ";
		cout << "salary " << getSalary() << endl;
	}

	virtual double getSalary() const
	{
		if (isPaid)
			return 800;
		else
			return 0;
	}
private:
	bool isPaid;
};

//int main()
//{
//	Intern a("A", 0);
//	a.print();
//	Intern b("B", 1);
//	b.print();
//	PerHour c("C", 4, 6);
//	c.print();
//	Salary d("ioana", 4);
//	d.print();
//	Worker* work[4];
//	work[0] = &a;
//	work[1] = &b;
//	work[2] = &c;
//	work[3] = &d;
//	double sum = 0;
//	for (int i = 0; i < 4; i++)
//	{
//		sum += work[i]->getSalary();
//	}
//	cout << "sum: " << sum << endl;
//	return 0;
//}
