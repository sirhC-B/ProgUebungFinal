#pragma once
/* Person.h
TestGross: Klassen
- Person - konkret
Loose, 18.12.2019
*/

#include <iostream>
#include <string>
#include "Haus.h" 
#include "PKW.h"
#include "Fahrzeug.h"
#include "Bike.h"

using namespace std;

class ArrayException
{
private:
	string message;
public:
	ArrayException(string message = "")
	{
		this->message = message;
	}
	string getMessage() const { return message; }
};


class Person : public Haus
{
private:
	string Name;
	int Alter;
	//custom
	PKW pkw;
	Bike bike;
	Fahrzeug** imBesitz; //<---- unsicher
	unsigned int count;
	unsigned int size;
	//hilfsfunktionen
	bool isFull() const { return count == size ? true : false; }
	bool isEmpty() const { return count == 0 ? true : false; }

public:
	
	Person(string name = string("Loose"), int alter = 100);
	Person(PKW p, Haus h);
	Person(const Person& st);
	~Person() {};
	string getName() const { return Name; }
	void setName(string name) { Name = name; }
	int getAlter() const { return Alter; }
	void setAlter(int alter) { Alter = alter; }
	
	//custom

	void setPKW(PKW p);
	PKW getPKW() const;
	void setBike(Bike b);
	Bike getBike() const; 
	void setHaus(Haus h);
	Haus getHaus() const;


	void setImBesitz(Fahrzeug& f)
	{	 
		if(!isFull())
			*this->imBesitz[count++] = f;
		else
			throw ArrayException("Array is Full.");
	}

	const Person& operator = (const Person& f);
	friend ostream& operator << (ostream& s, const Person& z);
	friend istream& operator >> (istream& s, Person& z);
};

