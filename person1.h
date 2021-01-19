#pragma once
/* Person.h
TestGross: Klassen
- Person - konkret
Loose, 18.12.2019
*/

#include <iostream>
#include <string>
#include <vector>
#include "Haus.h" 
#include "PKW.h"
#include "Bike.h"

using namespace std;



class Person : public Haus, public PKW
{
private:
	string Name;
	int Alter;
	//custom
	int anzahlFahrzeuge, anzahlImmobilien;
	Fahrzeug** fahrzeugliste;
	vector <Fahrzeug*> fahrzeugvector;
	Immobilie** immobilienliste;


public:
	Person(string name , int alter, PKW& pkw, Haus& haus);

	PKW& getPKW() const { return (PKW&)(*this); }
	void setPKW(PKW& pkw);

	Haus& getHaus() const { return (Haus&)(*this); }
	void setHaus(Haus& haus);

	void createFahrzeugliste(Fahrzeug** fahrzeuge, int anzahl);
	void createImmobilienListe(Immobilie** immobilien, int anzahl);
	void createFahrzeugVector(vector <Fahrzeug*> fahrzeuge);

	double mieteFahrzeug(Fahrzeug& fahrzeug, int km, int tage)
	{
		return fahrzeug.mieteFahrzeug(km, tage);
	}

	double mieteImmobilie(Immobilie& immobilie, int monate)
	{
		return immobilie.mieteImmobilie(monate);
	}

	Person(string name = string("Loose"), int alter = 100);
	
	Person(const Person& st);

	~Person()
	{
		if (immobilienliste) delete[] immobilienliste;
		if (fahrzeugliste) delete[] fahrzeugliste;
		fahrzeugvector.clear();
	};

	string getName() const { return Name; }
	void setName(string name) { Name = name; }
	int getAlter() const { return Alter; }
	void setAlter(int alter) { Alter = alter; }

	const Person& operator = (const Person& f);
	friend ostream& operator << (ostream& s, const Person& z);
	friend istream& operator >> (istream& s, Person& z);
};
 
