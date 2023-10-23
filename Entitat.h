#pragma once
#include <string>

using namespace std;

class Entitat
{
public:
	string getNom() const { return m_nom; }
	string getCodi() const { return m_codiID; }
	void setNom(string nom) { m_nom = nom; }
	void setCodi(string codiID){ m_codiID = codiID;}
protected:
	Entitat(){}
	Entitat(string nom, string codiIdentificatiu): m_nom(nom), m_codiID(codiIdentificatiu){}
	string m_nom;
	string m_codiID;
	
};

