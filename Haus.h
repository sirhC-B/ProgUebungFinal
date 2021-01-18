/* Haus.h 
TestGross 
Klassen
- Immobilie - abstrakt
- Haus

Loose, 18.12.2019
*/

#pragma once
#include "Immobilie.h"
#include <string>

class Haus : public Immobilie
{
private:
	int Wohnungen;		

public:
	Haus(int wohnungen = 5, string typ = string("Haus"), int flaeche = 150, int jahr = 2010);
	Haus( int wohnungen, Immobilie f = Immobilie("Bunglow", 4, 2000));
	Haus(const Haus& f);
	~Haus() {};
	Immobilie& getImmobilie() const;
	void setImmobilie(const Immobilie& Immobilie);
	int getWohnungen() const { return Wohnungen; }
	void setWohnungen(int wohnungen);

	double berechneTax(double psTarif);
	virtual double mieteImmobilie(int monate);
	virtual double berechneMiete(double qmPreis);
	virtual void ausgabe(ostream& s);

	const Haus& operator = (const Haus& f);
	friend ostream& operator << (ostream& s, const Haus& z);
	friend istream& operator >> (istream& s, Haus& z);
};

