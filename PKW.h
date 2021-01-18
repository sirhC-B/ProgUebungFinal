/* PKW.h 
TestGross 
Klassen
- PKW - abstrakt
- PKW
- Zweirad - abstrakt
- Motorrad, Fahrrad

Loose, 18.12.2019
*/

#pragma once
#include "Fahrzeug.h"
#include <string>

class PKW : public Fahrzeug
{
private:
	string Modell;		// beginnend mit Groﬂbuchstaben 
	int Leistung;		// PS
	string Treibstoff;

public:

public:
	PKW(string modell = string("X3"),int leistung = 185, string treibstoff = string("Diesel"),
		string typ = string("BMW"), int rad = 4, int jahr = 2020, bool motor = true);
	PKW(string modell, int leistung, string treibstoff,
		Fahrzeug& f);
	PKW(const PKW& f);
	~PKW() {};
	Fahrzeug& getFahrzeug() const;
	void setFahrzeug(const Fahrzeug& fahrzeug);
	string getModell() const { return Modell; }
	void setModell(string modell);
	int getLeistung() const { return Leistung; }
	void setLeistung(int leistung);
	string getTreibstoff() const { return Treibstoff; }
	void setTreibstoff(string treibstoff);

	virtual double mieteFahrzeug(int km, int tage);
	virtual double berechneTax(double psTarif);
	virtual void ausgabe(ostream& s);

	const PKW& operator = (const PKW& f);
	friend ostream& operator << (ostream& s, const PKW& z);
	friend istream& operator >> (istream& s, PKW& z);

};

