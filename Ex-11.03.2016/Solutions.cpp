# include <iostream>
using namespace std;
/* Task 1
struct Person
{
int age;
char name[30];
};

void input(Person &n)
{
cin >> n.age;
cin >> n.name;
}

void print(Person n)
{
cout << "Name: " << n.name << endl;
cout << "Age: " <<  n.age <<endl;
}

int main()
{
Person ivan;
input(ivan);
print(ivan);
Person people[5];
for (int i = 0; i < 5; i++)
{
input (people[i]);
print(people[i]);
}

for (int i = 0; i < 5; i++)
{
if (!(strcmp((people[i]).name,ivan.name)))
{

cout << "There is a person with that name at index: " << i + 1 << endl;
}
}

int maxAge = 0;
for (int i = 1; i < 5; i++)
{
if ((people[i]).age > (people[maxAge]).age)
{
maxAge = i;
}
}
cout << "The oldest one is " << (people[maxAge]).name << " and his age is  " << (people[maxAge]).age << endl;

system("pause");
return 0;
}*/


//Task 2
/*
class Data
{
private:
int day;
int month;
int year;
public:
int getDay() const
{
return day;
}

void setDay (int d)
{
if (d >= 1 && d <=31)
day = d;
else
day = 1;
}

int getMonth() const
{
return month;
}

void setMonth(int m)
{
if (m >= 1 && m <=12)
month = m;
else
month = 1;
}

int getYear() const
{
return year;
}

void setYear (int y)
{
year = y;
}

Data (int d = 2, int m = 2, int y = 2001)
{
setDay(d);
setMonth(m);
setYear(y);
}

void print () const
{
cout << day << "." << month << "." << year << endl;
}
};

int main ()
{
Data firstData;
firstData.print();

Data secondData(2, 36, 4500);
secondData.print();

system ("pause");
return 0;
}*/

//Task 3
/*
class BankAccount
{
private:
char name [24];
char accountNumber [16];
double balance;
public:
BankAccount(const char* n = "", const char* aNum = "0", double b = 0.0)
{
strcpy (name, n);
strcpy (accountNumber, aNum);
balance = b;
}

void print () const
{
cout << name << " " << accountNumber << " " << balance << endl;
}

void putIn (double cash)
{
if (cash>=0)
balance += cash;
else
cout <<"Invalid!" << endl;
}

void draw (double cash)
{
if (cash < 0)
{
cout << "Invalid!" << endl;
return;
}
if (cash <= balance)
balance -= cash;
else
cout << "Not enough money!" << endl;
}
};

int main ()
{
BankAccount first;
first.print();

BankAccount  second ("Kalina", "Kalina1234", 250.50);
second.print();

BankAccount  third ("Elena", "Elena7896", 150.60);
third.print();

first.putIn(20);
first.print();
first.draw(30);

second.draw(200);
second.print();

third.draw (-30.6);
third.print();

third.putIn(100);
third.print();
system ("pause");
return 0;
}
*/

//Task 4
#include <iostream>
#include <cstring>

using namespace std;

class Employee
{
private:
	int salary;
	int	age;
	char name[41];
	char EGN[11];
public:
	void set_age(int age)
	{
		if (age >= 18 && age <= 65) this->age = age;
	}
	int get_age()
	{
		return age;
	}
	void set_EGN(char *egn)
	{
		strcpy(EGN, egn);
	}
	char* get_egn()
	{
		return EGN;
	}
	int get_salary() const
	{
		return salary;
	}
	void set_name(char *_name)
	{
		strcpy(name, _name);
	}
	char* get_name()
	{
		return name;
	}
	Employee(int salary = 500, int age = 18, char* _egn = "", char* _name = "")
	{
		this->salary = salary;
		this->age = age;
		strcpy(name, _name);
		strcpy(EGN, _egn);
	}
	double salaryPerHour()
	{
		return salary / 20 / 8;
	}
	void print() const
	{
		cout << name << " " << EGN << " " << age << " " << salary << endl;
	}

};


bool isThere(Employee emp[], int size, char* name)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(emp[i].get_name(), name) == 0)
			return true;
	}
	return false;
}

void richestEmployee(Employee emp[], int size)
{
	Employee richest = emp[0];
	for (int i = 0; i<size; i++)
	{
		if (emp[i].get_salary()>richest.get_salary())
			richest = emp[i];
	}
	cout << richest.get_name();
}

void yongestEmployee(Employee emp[], int size)
{
	Employee youngest = emp[0];
	for (int i = 0; i<size; i++)
	{
		if (emp[i].get_age()<youngest.get_age())
			youngest = emp[i];
	}
	cout << youngest.get_name();
}

int main()
{
	Employee first(2000, 20, "123", "kali");
	Employee second(30, 19, "234", "nia");
	Employee third(40, 40, "345", "eli");
	first.print();
	second.print();
	third.print();

	cout << first.salaryPerHour() << endl;

	Employee employees[3];
	employees[0] = first;
	employees[1] = second;
	employees[2] = third;



	richestEmployee(employees, 3);
	cout << endl;
	yongestEmployee(employees, 3);
	cout << endl;
	cout << isThere(employees, 3, "aa");

	return 0;
}