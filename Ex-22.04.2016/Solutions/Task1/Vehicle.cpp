#include <iostream>
#include <string.h>
#include "Vehicle.h"
using namespace std;

void Vehicle::setNumber(char* number)
{
	delete[]this->number;
	if (((number[0] > 'a' && number[0] <'z') || (number[0]>'A' && number[0]<'Z'))
		&& ((number[1]>'a' && number[1] <'z') || (number[1]>'A' && number[1] < 'Z'))
		&& (number[2]>0 && number[2] < 9) && (number[3]>0 && number[3] < 9)
		&& (number[4]>0 && number[4] < 9) && (number[5]>0 && number[5]<9)
		&& ((number[6]>'a' && number[6] <'z') || (number[6]>'A' && number[6]<'Z'))
		&& ((number[7]>'a' && number[7] <'z') || (number[7]>'A' && number[7] < 'Z')))
	{
		this->number = new char[strlen(number) + 1];
		assert(this->number);
		strcpy_s(this->number, strlen(number) + 1, number);
	}
	else {
		this->number = new char[1];
		number[0] = '\0';
	}
}
void Vehicle::setProducer(char* producer)
{
	delete[]this->producer;
	this->producer = new char[strlen(producer) + 1];
	assert(this->producer);
	strcpy_s(this->producer, strlen(producer) + 1, producer);
}
char* Vehicle::getNumber()const
{
	return number;
}
char* Vehicle::getProducer()const
{
	return producer;
}
Vehicle::Vehicle(char* number, char* producer)
{
	if (strlen(number) == 8)
	{
		if (((number[0] >= 'a' && number[0] <= 'z') || (number[0] >= 'A' && number[0] <= 'Z'))
			&& ((number[1] >= 'a' && number[1] <= 'z') || (number[1] >= 'A' && number[1] <= 'Z'))
			&& (number[2] >= '0' && number[2] <= '9') && (number[3] >= '0' && number[3] <= '9')
			&& (number[4] >= '0' && number[4] <= '9') && (number[5] >= '0' && number[5] <= '9')
			&& ((number[6] >= 'a' && number[6] <'z') || (number[6] >= 'A' && number[6] <= 'Z'))
			&& ((number[7] >= 'a' && number[7] <'z') || (number[7] >= 'A' && number[7] <= 'Z')))
		{
			this->number = new char[strlen(number) + 1];
			assert(this->number);
			strcpy_s(this->number, strlen(number) + 1, number);
		}
		else {
			this->number = new char[1];
			number[0] = '\0';
		}
	}
	this->producer = new char[strlen(producer) + 1];
	assert(this->producer);
	strcpy_s(this->producer, strlen(producer) + 1, producer);
}
void Vehicle::print()const
{
	cout << "Vehicle number:" << number << endl
		<< "Vehicle producer:" << producer << endl;
}

Vehicle::Vehicle()
{
	this->number = new char[1];
	number[0] = '\0';
	this->producer = new char[1];
	producer[0] = '\0';
}
Vehicle::~Vehicle()
{
	del();
}
Vehicle::Vehicle(const Vehicle& other)
{
	cpy(other);
}
Vehicle& Vehicle::operator=(const Vehicle& other)
{
	if (this != &other)
	{
		del();
		cpy(other);
	}
	return *this;
}
void Car::setModel(char* model)
{
	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
}
void Car::setSpeed(int maxSpeed)
{
	this->maxSpeed = maxSpeed;
}
int Car::getSpeed()
{
	return maxSpeed;
}
char* Car::getModel()
{
	return model;
}
void Car::print()const
{
	Vehicle::print();
	cout << "Model:" << model << endl
		<< "Max speed:" << maxSpeed << endl;
}

Car::Car() :Vehicle()
{
	this->model = new char[1];
	model[0] = '\0';
	this->maxSpeed = 0;
}
Car::Car(char* model, int maxSpeed, char* number, char* producer) :Vehicle(number, producer)
{
	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
	this->maxSpeed = maxSpeed;
}
Car::~Car()
{
	del();
}
Car::Car(const Car& other) :Vehicle(other)
{
	cpy(other);
}
Car& Car::operator=(const Car& other)
{
	if (this != &other)
	{
		Vehicle::operator=(other);
		del();
		cpy(other);
	}
	return *this;
}
void Bicycle::setModel(char* model)
{
	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
}
void Bicycle::setSpeed(int maxSpeed)
{
	this->maxSpeed = maxSpeed;
}
int Bicycle::getSpeed()
{
	return maxSpeed;
}
void Bicycle::setNumberOfSpeed(int numberOfSpeed)
{
	this->numberOfSpeed = numberOfSpeed;
}
int Bicycle::getNumberOfSpeed()
{
	return numberOfSpeed;
}
char* Bicycle::getModel()
{
	return model;
}
void Bicycle::print()const
{
	Vehicle::print();
	cout << "Model:" << model << endl
		<< "Max speed:" << maxSpeed << endl
		<< "Number of speeds:" << numberOfSpeed << endl;
}

Bicycle::Bicycle() :Vehicle()
{
	this->model = new char[1];
	model[0] = '\0';
	this->maxSpeed = 0;
}
Bicycle::Bicycle(char* model, int maxSpeed, int numberOfSpeed, char* number, char* producer) :Vehicle(number, producer)
{
	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
	this->maxSpeed = maxSpeed;
	this->numberOfSpeed = numberOfSpeed;
}
Bicycle::~Bicycle()
{
	del();
}
Bicycle::Bicycle(const Bicycle& other) :Vehicle(other)
{
	cpy(other);
}
Bicycle& Bicycle::operator=(const Bicycle& other)
{
	if (this != &other)
	{
		Vehicle::operator=(other);
		del();
		cpy(other);
	}
	return *this;
}
