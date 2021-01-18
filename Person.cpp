/* Person.cpp
TestGross: Klassen
Loose, 18.12.2019
*/

#include <iostream>
#include <string>
#include "Person.h"
using namespace std; 

Person::Person(string name, int alter)
{
	this->size = 3;
	this->count = 0;
	imBesitz = new Fahrzeug*[size];
	setName(name);
	setAlter(alter);
}
Person::Person(PKW p, Haus h)
{
	Person();
	setPKW(p);
	setHaus(h);

}
Person::Person(const Person& st)
{
	if (this != &st) *this = st;
}

const Person& Person::operator = (const Person& f)
{
	Name = f.Name;
	Alter = f.Alter;
	return *this;
}

ostream& operator << (ostream& s, const Person& z)
{
	if (typeid(s) == typeid(cout))
	{
		s << "Person = {" << z.getName() << ", " << z.getAlter() << "}" << endl;
	}
	else
	{
		s << z.getName() << ";" << z.getAlter() << ";";
		s << endl;
	}
	return s;
}

istream& operator >> (istream& s, Person& z)
{
	//string pname, name;
	//int alter, ez;
	if (typeid(s) == typeid(cin))
	{
		cout << "Geben Sie Namen und Alter der Person ein:" << endl;
		s >> z.Name >> z.Alter;
	}
	else
	{
#define N 1 
		char tmpc[100];
		int w[N];
		s.getline(tmpc, 100);
		string tmp(tmpc), tmp1;
		//cout << tmp << endl;
		int id = tmp.find(";");
		int idb = 0;
		z.Name = tmp.substr(0, id);
		for (int k = 0; k < N; k++)
		{
			tmp = string(&tmpc[idb + id + 1]);
			idb = idb + id + 1;
			//cout << tmp << endl;
			id = tmp.find(";");
			w[k] = atoi((tmp.substr(0, id)).c_str());
		}
		z.Alter = w[0];
		tmp = string(&tmpc[idb + id + 1]);
		idb = idb + id + 1;
		//cout << tmp << endl;
		id = tmp.find(";");
	}
	//z = Person(pname, alter, name, ez, str, plz);
	return s;
}

void Person::setPKW(PKW p)
{
	this->pkw.setModell(p.getModell());
	this->pkw.setJahr(p.getJahr());
	this->pkw.setLeistung(p.getLeistung());
	this->pkw.setMotor(p.getMotor());
	this->pkw.setTreibstoff(p.getTreibstoff());
	this->pkw.setTyp(p.getTyp());
	this->pkw.setRad(p.getRad());
}

PKW Person::getPKW() const
{

	return PKW(pkw.getModell(),pkw.getLeistung(),pkw.getTreibstoff(),pkw.getTyp(),pkw.getRad(),pkw.getJahr(),pkw.getMotor());
}

void Person::setBike(Bike b)
{
	this->bike.setModell(b.getModell());
	this->bike.setLeistung(b.getLeistung());
	this->bike.setTyp(b.getTyp());
	this->bike.setRad(b.getRad());
	this->bike.setJahr(b.getJahr());
	this->bike.setMotor(b.getMotor());
}

Bike Person::getBike() const
{
	return Bike(bike.getModell(), bike.getLeistung(), bike.getTyp(), bike.getRad(), bike.getJahr(), bike.getMotor());
}


void Person::setHaus(Haus h)
{
	this->Haus::setFlaeche(h.getFlaeche());
	this->Haus::setImmobilie(h.getImmobilie());
	this->Haus::setJahr(h.getJahr());
	this->Haus::setTyp(h.getTyp());
	this->Haus::setWohnungen(h.getWohnungen());

}
Haus Person::getHaus() const
{
	return(Haus)(*this);
}

