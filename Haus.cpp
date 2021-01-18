/* Haus.cpp
TestGross: Klassen
Loose, 18.12.2019
*/

#include "Haus.h"

Haus::Haus(int wohnungen, string typ, int flaeche, int jahr) : Immobilie(typ, flaeche, jahr)
{
	setWohnungen(wohnungen);
}

Haus::Haus(int wohnungen, Immobilie f) : Immobilie(f),Wohnungen(wohnungen)
{
}

Haus::Haus(const Haus& st)
{
	if (this != &st) *this = st;
}

inline Immobilie& Haus::getImmobilie() const
{
	return (Immobilie&) *this;
}

inline void Haus::setImmobilie(const Immobilie& immobilie)
{
	*((Immobilie *) this) = immobilie;
}



inline void Haus::setWohnungen(int wohnungen)
{
	if (wohnungen >= 1 && wohnungen <= 10)
		Wohnungen = wohnungen;
	else
		throw string("Lesitung muss zwischen 1 und 10 Wohnungen liegen!");
}

double Haus::berechneTax(double psTarif)
{
	return psTarif * Wohnungen;
}

double Haus::berechneMiete(double qmPreis)
{
	return Immobilie::berechneMiete(qmPreis) + 100. * Wohnungen;
}

double Haus::mieteImmobilie(int monate)
{
	return monate * berechneMiete(10.0);
}

const Haus& Haus::operator = (const Haus& f)
{
	setImmobilie((Immobilie) f);
	Wohnungen = f.Wohnungen;
	return *this;
}

void Haus::ausgabe(ostream& s)
{
	s << *this;
}

ostream& operator << (ostream& s, const Haus& z)
{
	if (typeid(s) == typeid(cout))
	{
		return s << "Haus = {" << z.getImmobilie() << ", " << z.getWohnungen() << "}";
	}
	else
	{
		s << z.getImmobilie() << z.getWohnungen() << ';';
		s << endl;
		return s;
	}
}

istream& operator >> (istream& s, Haus& z)
{
	int wohnungen;
	s >> *((Immobilie*)& z);
	if (typeid(s) == typeid(cin))
	{ 
		cout << "Geben Sie die Hausdaten in der Reihenfolge Anzahl der Wohnungen ein: " << endl;
		s >> wohnungen;
	}
	else
	{
#define N 1 
		char tmpc[100];
		int w[N];
		s.getline(tmpc,100);
		string tmp(tmpc), tmp1; 
		//cout << tmp << endl;
		int id = tmp.find(";");
		int idb = 0;
		z.Wohnungen = atoi((tmp.substr(0, id).c_str()));
	}
	return s;
}
