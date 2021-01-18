/* Bike.h 
TestGross 
Klassen
- Bike - abstrakt
- Bike
- Zweirad - abstrakt
- Motorrad, Fahrrad

Loose, 18.12.2019
*/

#pragma once
#include "Fahrzeug.h"
#include <string>

class Bike : public Fahrzeug
{
private:
	string Modell;		// beginnend mit Groﬂbuchstaben 
	int Leistung;		// PS

public:
	Bike(string modell = string("V500"),int leistung = 85,
		string typ = string("BMW"), int rad = 2, int jahr = 2020, bool motor = true);
	Bike(string modell, int leistung, Fahrzeug& f);
	Bike(const Bike& f);
	~Bike() {};
	Fahrzeug& getFahrzeug() const;
	void setFahrzeug(const Fahrzeug& fahrzeug);
	string getModell() const { return Modell; }
	void setModell(string modell);
	int getLeistung() const { return Leistung; }
	void setLeistung(int leistung);

	virtual double mieteFahrzeug(int km, int tage);
	virtual double berechneTax(double psTarif);
	virtual void ausgabe(ostream& s);

	const Bike& operator = (const Bike& f);
	friend ostream& operator << (ostream& s, const Bike& z);
	friend istream& operator >> (istream& s, Bike& z);

};

