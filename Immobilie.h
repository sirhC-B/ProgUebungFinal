/* Immobilie.h 
TestGross 
Klassen
- Immobilie - abstrakt
- Haus

Loose, 18.12.2019
*/

#pragma once
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
using namespace std;

extern struct tm newtime;

class Immobilie
{
private:
	string Typ;			// beginnend mit Groﬂbuchstaben 
	int Flaeche, Jahr;		// Flaeche  [2 ... 6], Jahr [1920 ... aktuelles Jahr]

public:
	//static const time_t Zeit;
	static int aktJahr;

public:
	Immobilie(string typ = string("Immobilie"), int flaeche = 400, int jahr = 1918);
	Immobilie(const Immobilie& f);
	~Immobilie() {};
	string getTyp() const { return Typ; }
	void setTyp(string typ);
	int getFlaeche() const { return Flaeche; }
	void setFlaeche(int Flaeche);
	int getJahr() const { return Jahr; }
	void setJahr(int jahr);

	double berechneTax(double psTarif);
	virtual double mieteImmobilie(int monate);
	virtual double berechneMiete(double qmPreis);
	virtual void ausgabe(ostream& s);

	const Immobilie& operator = (const Immobilie& f);
	friend ostream& operator << (ostream& s, const Immobilie& z);
	friend istream& operator >> (istream& s, Immobilie& z);
};

