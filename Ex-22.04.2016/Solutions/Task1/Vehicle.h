#ifndef VEH_H
#define VEH_H
#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std;

class Vehicle {
private:
	char* number;
	char* producer;
	void cpy(const Vehicle& a)
	{
		this->number = new char[strlen(a.number) + 1];
		assert(this->number);
		strcpy_s(this->number, strlen(a.number) + 1, a.number);

		this->producer = new char[strlen(a.producer) + 1];
		assert(this->producer);
		strcpy_s(this->producer, strlen(a.producer) + 1, a.producer);
	}
	void del()
	{
		delete[] number;
		delete[]producer;
	}
public:
	void setNumber(char*);
	void setProducer(char*);
	char* getNumber()const;
	char* getProducer()const;
	virtual void print()const;

	Vehicle();
	Vehicle(char*, char*);
	~Vehicle();
	Vehicle(const Vehicle&);
	Vehicle& operator=(const Vehicle&);
};

class Car : public Vehicle {
private:
	char* model;
	int maxSpeed;
	void cpy(const Car& other)
	{
		this->maxSpeed = other.maxSpeed;
		this->model = new char[strlen(other.model) + 1];
		strcpy_s(this->model, strlen(other.model) + 1, other.model);
	}
	void del()
	{
		delete[]model;
	}
public:
	void setModel(char*);
	void setSpeed(int);
	int getSpeed();
	char* getModel();
	virtual void print()const;

	Car();
	Car(char*, int, char*, char*);
	~Car();
	Car(const Car&);
	Car& operator=(const Car&);
};

class Bicycle : public Vehicle {
private:
	char* model;
	int maxSpeed;
	int numberOfSpeed;
	void cpy(const Bicycle& other)
	{
		this->maxSpeed = other.maxSpeed;
		this->numberOfSpeed = other.numberOfSpeed;
		this->model = new char[strlen(other.model) + 1];
		strcpy_s(this->model, strlen(other.model) + 1, other.model);
	}
	void del()
	{
		delete[]model;
	}
public:
	void setModel(char*);
	void setSpeed(int);
	void setNumberOfSpeed(int);
	int getNumberOfSpeed();
	int getSpeed();
	char* getModel();
	virtual void print()const;

	Bicycle();
	Bicycle(char*, int, int, char*, char*);
	~Bicycle();
	Bicycle(const Bicycle&);
	Bicycle& operator=(const Bicycle&);
};

#endif
