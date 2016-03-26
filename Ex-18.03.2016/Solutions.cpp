#include <iostream>
#include <cstring>
#include<assert.h>
using namespace std;


class Car
{
	int year;
	double price;
	char* model;
	void cpy(const Car& other)
	{
		this->year = other.year;
		this->price = other.price;
		this->model = new char[strlen(other.model) + 1];
		assert(this->model != NULL);
		strcpy(this->model, other.model);
	}
	void del()
	{
		delete[] model;
	}
	public:
	Car(int year = 1980, double price = 1234.5, char* model = "audi")
	{
		this->year = year;
		this->price = price;
		this->model = new char[strlen(model) + 1];
		assert(model != NULL);
		strcpy(this->model, model);
	}
	~Car()
	{
		del();
	}
	Car(const Car& other)
	{
		cpy(other);
	}
	Car& operator=(const Car& other)
	{
		if (this != &other)
		{
			del();
			cpy(other);
		}
		return *this;
	}
	void setYear(int year)
	{
		if (year >= 1975)
			this->year = year;
		else
			this->year = 1980;
	}
	int getYear() const
	{
		return year;
	}
	void setPrice(double price)
	{
		if (price > 0)
			this->price = price;
		else
			this->price = 1000;
	}
	double getPrice() const
	{
		return price;
	}
	void setModel(char* model)
	{
		delete[] this->model;
		this->model = new char[strlen(model) + 1];
		assert(model != NULL);
		strcpy(this->model, model);
	}
	char* getModel()
	{
		return model;
	}
	void print() const
	{
		cout << "Year: " << year << " Price: " << price << " Model: " << model << endl;
	}
};
Car& carWithHighestPrice(Car* cars, int size)
{
	int highestPriceIndex = 0;
	for (int i = 1; i < size; i++)
	{
		if (cars[i].getPrice() > cars[highestPriceIndex].getPrice())
		{
			highestPriceIndex = i;
		}
	}
	return cars[highestPriceIndex];
}
int main()
{

}



class Phone
{
	private:
	char* model;
	double price;
	char* os;
	void cpy(const Phone& other)
	{
		this->model = new char[strlen(other.model) + 1];
		assert(this->model != NULL);
		strcpy(this->model, other.model);
		price = other.price;
		this->os = new char[strlen(other.os) + 1];
		assert(this->os != NULL);
		strcpy(this->os, other.os);
	}
	void del()
	{
		delete[] model;
		delete[] os;
	}
	public:
	Phone(char* model = "audi", double price = 1234.5, char* os = "android")
	{
		this->model = new char[strlen(model) + 1];
		assert(this->model != NULL);
		strcpy(this->model, model);
		this->price = price;
		this->os = new char[strlen(os) + 1];
		assert(this->os != NULL);
		strcpy(this->os, os);
	}
	~Phone()
	{
		del();
	}
	Phone(const Phone& other)
	{
		cpy(other);
	}
	Phone& operator=(const Phone& other)
	{
		if (this != &other)
		{
			del();
			cpy(other);
		}
		return *this;
	}

	void setModel(char* model)
	{
		delete[] this->model;
		this->model = new char[strlen(model) + 1];
		assert(this->model != NULL);
		strcpy(this->model, model);
	}

	char* getModel() const
	{
		return model;
	}

	void setPrice(double price)
	{
		if (price > 0)
			this->price = price;
		else
			this->price = 1234.5;
	}

	double getPrice()const
	{
		return price;
	}

	void setOS(char* os)
	{
		delete[] this->os;
		this->os = new char[strlen(os) + 1];
		assert(this->os != NULL);
		strcpy(this->os, os);
	}

	char* getOS() const
	{
		return this->os;
	}

	void print()
	{
		cout << model << " " << price << " " << os << " " << endl;
	}

};

void sortPhones(Phone* phones, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int pos = i;
		for (int j = i + 1; j < size; j++)
		{
			if (phones[j].getPrice() < phones[pos].getPrice())
			pos = j;
		}
		if (pos != i)
		{
			Phone tmp = phones[i];
			phones[i] = phones[pos];
			phones[pos] = tmp;
		}
	}
}

int main()
{

}


class Date
{
private:
	int month,
		day,
		year;
public:
	Date(int m = 1, int d = 1, int y = 2000)
	{
		month = m;
		day = d;
		year = y;
	}
	Date(const Date& other)
	{
		month = other.month;
		day = other.day;
		year = other.year;
	}
	Date& operator=(const Date& other)
	{
		month = other.month;
		day = other.day;
		year = other.year;
		return *this;
	}
	void print()
	{
		cout << day << "." << month << "." << year;
	}
	void setMonth(int m)
	{
		if (m >= 1 && m <= 12)
		{
			month = m;
		}
	}
	void setDay(int d)
	{
		if (d >= 1 && d <= 31)
		{
			day = d;
		}
	}
	void setYear(int y)
	{
		year = y;
	}
	int getMonth() const
	{
		return month;
	}
	int getDay() const
	{
		return day;
	}
	int getYear() const
	{
		return year;
	}
	void read()
	{
		cout << "Input month, day and a year" << endl;
		cin >> month >> day >> year;
	}
};

class Patient
{
private:
	char* name;
	Date data;
	int visits;
public:
	Patient(char* n = "a", int d = 1, int m = 1, int y = 2000, int v = 1) 
	{
		name = new char[strlen(n) + 1];
		assert(name != NULL);
		strcpy(name, n);
		Date tmp (d, m, y);
		data = tmp;
		this->data = data;
		visits = v;
	}
	Patient(const Patient& other)
	{
		name = new char[strlen(other.name) + 1];
		assert(name != NULL);
		strcpy(name, other.name);
		data = other.data;
		visits = other.visits;
	}
	~Patient()
	{
		delete[] name;
	}
	Patient& operator= (const Patient& other)
	{
		if (this != &other)
		{
			delete[] name;
			name = new char[strlen(other.name) + 1];
			assert(name != NULL);
			strcpy(name, other.name);
			data = other.data;
			visits = other.visits;
		}
		return *this;
	}
	void setName(char* n)
	{
		delete[] name;
		name = new char[strlen(n) + 1];
		assert(name != NULL);
		strcpy(name, n);
	}
	char* getName() const
	{
		return name;
	}
	void setDate(Date d)
	{
		data = d;
	}
	Date getDate() const
	{
		return data;
	}
	void setVisits(int v)
	{
		visits = v;
	}
	int getVisits() const
	{
		return visits;
	}
	void print()
	{
		cout << name;
		cout << " ";
		data.print();
		cout << " ";
		cout << visits << endl;
	}
};

int main()
{
}

