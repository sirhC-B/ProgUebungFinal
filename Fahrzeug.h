/* Fahrzeug.h 
TestGross 
Klassen
- Fahrzeug - abstrakt
- PKW
- Zweirad - abstrakt
- Motorrad, Fahrrad

Loose, 18.12.2019
*/

#pragma once
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
using namespace std;

extern struct tm newtime;

class Fahrzeug
{
private:
	string Typ;			// beginnend mit Groﬂbuchstaben 
	int Rad, Jahr;		// Rad  [2 ... 6], Jahr [1920 ... aktuelles Jahr]
	bool Motor;

public:
	//static const time_t Zeit;
	static int aktJahr;

public:
	Fahrzeug(string typ = string("Fahrzeug"), int rad = 4, int jahr = 2018, bool motor = true);
	Fahrzeug(const Fahrzeug& f);
	~Fahrzeug() {};
	string getTyp() const { return Typ; }
	void setTyp(string typ);
	int getRad() const { return Rad; }
	void setRad(int rad);
	int getJahr() const { return Jahr; }
	void setJahr(int jahr);
	bool getMotor() const { return Motor; }
	void setMotor(bool motor) { Motor = motor; }

	virtual double mieteFahrzeug(int km, int tage) = 0;
	virtual double berechneTax(double psTarif) = 0;
	virtual void ausgabe(ostream& s);

	const Fahrzeug& operator = (const Fahrzeug& f);
	friend ostream& operator << (ostream& s, const Fahrzeug& z);
	friend istream& operator >> (istream& s, Fahrzeug& z);

};

