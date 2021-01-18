/* Bike.cpp
TestGross: Klassen
Loose, 18.12.2019
*/

#include "Bike.h"

Bike::Bike(string modell, int leistung, string typ, int rad, int jahr, bool motor) : Fahrzeug(typ, rad, jahr, motor)
{
	setModell(modell);
	setLeistung(leistung);
}

Bike::Bike(string modell, int leistung, Fahrzeug& f)
	: Fahrzeug(f),Modell(modell),Leistung(leistung)
{
}

Bike::Bike(const Bike& st)
{
	if (this != &st) *this = st;
}

inline Fahrzeug& Bike::getFahrzeug() const
{
	return (Fahrzeug&) *this;
}

inline void Bike::setFahrzeug(const Fahrzeug& fahrzeug)
{
	*((Fahrzeug *) this) = fahrzeug;
}

inline void Bike::setModell(string modell)
{
	if (modell[0] >= 'A' && modell[0] <= 'Z')
		Modell = modell;
	else
		throw string("Typ muss mit Grossbuchstaben beginnen!");
}

inline void Bike::setLeistung(int leistung)
{
	if (leistung >= 1 && leistung <= 100)
		Leistung = leistung;
	else
		throw string("Lesitung muss zwischen 1 und 100 PS liegen!");
}

double Bike::berechneTax(double psTarif)
{
	return psTarif * Leistung;
}

double Bike::mieteFahrzeug(int km, int tage)
{
	return 20. * tage + 0.20 * km;
}

const Bike& Bike::operator = (const Bike& f)
{
	setFahrzeug((Fahrzeug&) f);
	Modell = f.Modell;
	Leistung = f.Leistung;
	return *this;
}

void Bike::ausgabe(ostream& s)
{
	s << *this;
}

ostream& operator << (ostream& s, const Bike& z)
{
	if (typeid(s) == typeid(cout))
	{
		return s << "Bike = {" << z.getFahrzeug() << ", " << z.getModell()
			<< ", " << z.getLeistung() <<  "}";
	}
	else
	{
		s << z.getFahrzeug() << z.getModell()
			<< ';' << z.getLeistung() << ';' ;
		s << endl;
		return s;
	}
}

istream& operator >> (istream& s, Bike& z)
{
	string modell, treibstoff; 
	int leistung;
	s >> *((Fahrzeug*)& z);
	if (typeid(s) == typeid(cin))
	{ 
		cout << "Geben Sie die Bikedaten in der Reihenfolge Modell und Leistung ein: " << endl;
		s >> modell >> leistung >> treibstoff;
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
		z.Modell = tmp.substr(0, id);
		for (int k = 0; k < N; k++)
		{
			tmp = string(&tmpc[idb+id+1]);
			idb = idb + id + 1;
			//cout << tmp << endl;
			id = tmp.find(";"); 
			w[k] = atoi((tmp.substr(0, id)).c_str());
		}
		z.Leistung = w[0];
		tmp = string(&tmpc[idb + id + 1]);
		idb = idb + id + 1;
		//cout << tmp << endl;
		id = tmp.find(";");
	}
	return s;
}
