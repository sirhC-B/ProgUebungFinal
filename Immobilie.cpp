/* Immobilie.cpp
TestGross: Klassen
Loose, 18.12.2019
*/

#include "Immobilie.h"

//const time_t Immobilie::Zeit = time(nullptr); //chrono::system_clock::now();
//int Immobilie::aktJahr = newtime.tm_year + 1900;

Immobilie::Immobilie(string typ, int flaeche, int jahr)
{
	setTyp(typ);
	setFlaeche(flaeche);
	setJahr(jahr);
}

Immobilie::Immobilie(const Immobilie& st)
{
	if (this != &st) *this = st;
}

inline void Immobilie::setTyp(string typ)
{
	if (typ[0] >= 'A' && typ[0] <= 'Z')
		Typ = typ;
	else
		throw string("Typ muss mit Grossbuchstaben beginnen!");
}

inline void Immobilie::setFlaeche(int flaeche)
{
	if (flaeche > 1 && flaeche <= 2000)
		Flaeche = flaeche;
	else
		throw string("Anzahl der Räder muss zwischen 2 und 2000 liegen!");
}

inline void Immobilie::setJahr(int jahr)
{
	if (jahr >= 1800 && jahr <= 2020)   // aktuelles Jahr 
		Jahr = jahr;
	else
		throw string("Baujahr muss zwischen 1800 und heute liegen!");
}

double Immobilie::berechneTax(double psTarif)
{
	return psTarif * Flaeche;
}

double Immobilie::berechneMiete(double qmPreis)
{
	return qmPreis * Flaeche;
}

double Immobilie::mieteImmobilie(int monate)
{
	return monate * berechneMiete(2.0);
}

const Immobilie& Immobilie::operator = (const Immobilie& f)
{
	Typ = f.Typ;
	Flaeche = f.Flaeche;
	Jahr = f.Jahr;
	return *this;
}

void Immobilie::ausgabe(ostream& s)
{
	s << *this;
}

ostream& operator << (ostream& s, const Immobilie& z)
{
	if (typeid(s) == typeid(cout))
	{
		return s << "Immobilie = {" << z.getTyp() << ", " << z.getFlaeche()
			<< ", " << z.getJahr() << "}";
	}
	else
	{
		s << z.getTyp() << ';' << z.getFlaeche()
			<< ';' << z.getJahr() << ';';
		s << endl;
		return s;
	}
}

istream& operator >> (istream& s, Immobilie& z)
{
	string typ; 
	int jahr, Flaeche;
	if (typeid(s) == typeid(cin))
	{
		cout << "Geben Sie die Immobiliedaten in der Reihenfolge Typ, Fläche und Baujahr ein: " << endl;
		s >> typ >> Flaeche >> jahr;
	}
	else
	{
#define N 2 
		char tmpc[100];
		int w[N];
		s.getline(tmpc,100);
		string tmp(tmpc), tmp1; 
		//cout << tmp << endl;
		int id = tmp.find(";");
		int idb = 0;
		z.Typ = tmp.substr(0, id);
		for (int k = 0; k < N; k++)
		{
			tmp = string(&tmpc[idb+id+1]);
			idb = idb + id + 1;
			//cout << tmp << endl;
			id = tmp.find(";"); 
			w[k] = atoi((tmp.substr(0, id)).c_str());
		}
		z.Flaeche = w[0];
		z.Jahr = w[1];
	}
	return s;
}
