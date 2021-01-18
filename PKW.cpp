/* PKW.cpp
TestGross: Klassen
Loose, 18.12.2019
*/

#include "PKW.h"

PKW::PKW(string modell, int leistung, string treibstoff,string typ, int rad, int jahr, bool motor) : Fahrzeug(typ, rad, jahr, motor)
{
	setModell(modell);
	setLeistung(leistung);
	setTreibstoff(treibstoff);
}

PKW::PKW(string modell, int leistung, string treibstoff, Fahrzeug& f)
	: Fahrzeug(f),Modell(modell),Leistung(leistung),Treibstoff(treibstoff)
{
}

PKW::PKW(const PKW& st)
{
	if (this != &st) *this = st;
}

inline Fahrzeug& PKW::getFahrzeug() const
{
	return (Fahrzeug&) *this;
}

inline void PKW::setFahrzeug(const Fahrzeug& fahrzeug)
{
	*((Fahrzeug *) this) = fahrzeug;
}

inline void PKW::setModell(string modell)
{
	if (modell[0] >= 'A' && modell[0] <= 'Z')
		Modell = modell;
	else
		throw string("Typ muss mit Grossbuchstaben beginnen!");
}

inline void PKW::setLeistung(int leistung)
{
	if (leistung >= 1 && leistung <= 1000)
		Leistung = leistung;
	else
		throw string("Lesitung muss zwischen 1 und 1000 PS liegen!");
}

inline void PKW::setTreibstoff(string treibstoff)
{
	Treibstoff = treibstoff;
}

double PKW::berechneTax(double psTarif)
{
	return psTarif * Leistung;
}

double PKW::mieteFahrzeug(int km, int tage)
{
	return 30. * tage + 0.30 * km;
}

const PKW& PKW::operator = (const PKW& f)
{
	setFahrzeug((Fahrzeug&) f);
	Modell = f.Modell;
	Leistung = f.Leistung;
	Treibstoff = f.Treibstoff;
	return *this;
}

void PKW::ausgabe(ostream& s)
{
	s << *this;
}

ostream& operator << (ostream& s, const PKW& z)
{
	if (typeid(s) == typeid(cout))
	{
		return s << "PKW = {" << z.getFahrzeug() << ", " << z.getModell()
			<< ", " << z.getLeistung() << ", " << z.getTreibstoff() << "}";
	}
	else
	{
		s << z.getFahrzeug() << z.getModell()
			<< ';' << z.getLeistung() << ';' << z.getTreibstoff() << ';';
		s << endl;
		return s;
	}
}

istream& operator >> (istream& s, PKW& z)
{
	string modell, treibstoff; 
	int leistung;
	s >> *((Fahrzeug*)& z);
	if (typeid(s) == typeid(cin))
	{ 
		cout << "Geben Sie die PKWdaten in der Reihenfolge Modell, Leistung und Treibstoff ein: " << endl;
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
		z.Treibstoff = tmp.substr(0, id);
	}
	return s;
}
