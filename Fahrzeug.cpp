/* Fahrzeug.cpp
TestGross: Klassen
Loose, 18.12.2019
*/

#include "Fahrzeug.h"

//const time_t Fahrzeug::Zeit = time(nullptr); //chrono::system_clock::now();
//int Fahrzeug::aktJahr = newtime.tm_year + 1900;

Fahrzeug::Fahrzeug(string typ, int rad, int jahr, bool motor)
{
	setTyp(typ);
	setRad(rad);
	setJahr(jahr);
	setMotor(motor);
}

Fahrzeug::Fahrzeug(const Fahrzeug& st)
{
	if (this != &st) *this = st;
}

inline void Fahrzeug::setTyp(string typ)
{
	if (typ[0] >= 'A' && typ[0] <= 'Z')
		Typ = typ;
	else
		throw string("Typ muss mit Grossbuchstaben beginnen!");
}

inline void Fahrzeug::setRad(int rad)
{
	if (rad > 1 && rad <= 8)
		Rad = rad;
	else
		throw string("Anzahl der Räder muss zwischen 2 und 8 liegen!");
}

inline void Fahrzeug::setJahr(int jahr)
{
	if (jahr >= 1920 && jahr <= 2020)   // aktuelles Jahr 
		Jahr = jahr;
	else
		throw string("Baujahr muss zwischen 1920 und heute liegen!");
}

const Fahrzeug& Fahrzeug::operator = (const Fahrzeug& f)
{
	Typ = f.Typ;
	Rad = f.Rad;
	Jahr = f.Jahr;
	Motor = f.Motor;
	return *this;
}

void Fahrzeug ::ausgabe(ostream& s)
{
	s << *this;
}


ostream& operator << (ostream& s, const Fahrzeug& z)
{
	if (typeid(s) == typeid(cout))
	{
		return s << "Fahrzeug = {" << z.getTyp() << ", " << z.getRad()
			<< ", " << z.getJahr() << ", " << z.getMotor() << "}";
	}
	else
	{
		s << z.getTyp() << ';' << z.getRad()
			<< ';' << z.getJahr() << ';';
		z.getMotor() ? (s << 1 << ';') : (s << 1 << ';');
		s << endl;
		return s;
	}
}

istream& operator >> (istream& s, Fahrzeug& z)
{
	string typ; 
	int jahr, rad;
	bool motor;
	if (typeid(s) == typeid(cin))
	{
		cout << "Geben Sie die Fahrzeugdaten in der Reihenfolge Typ, Anzahl der Räder, Baujahr und motorisiert ein: " << endl;
		s >> typ >> rad >> jahr >> motor;
	}
	else
	{
#define N 3 
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
		z.Rad = w[0];
		z.Jahr = w[1];
		int m = w[2];
		z.Motor = m == 1 ? true : false;
	}
	return s;
}
