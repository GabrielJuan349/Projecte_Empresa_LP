#include "Empresa.h"

static int m_nextCR;

string Empresa::generaCodiRus(const string& model) {
/*
	vector<char> CR;

	char modelc[30];
	
	strcpy(modelc, model.c_str());
	int endchar = model.size();

	for (int y = 0; y < endchar; y++) {
		CR.push_back(modelc[y]);
	}
	char next = (char) m_nextCR;
	CR.push_back(next);
	
 
	std::string codi(CR.begin(), CR.end());*/

	string codi;
	
	codi = to_string(m_nextCR);
	m_nextCR++;

	return model + codi;

 }

/*
string Empresa::generaCodiRus(const string& model)
{
	return model + to_string(m_nextCR++);
}

int Empresa::getSeguentCodiRus() {
	return m_nextCR;
}
*/

Empresa::Empresa(string name, int numBotigues, Magatzem* magatzemPrincipal, Proveidor& p)
{
	m_name = name;
	m_magatzem = magatzemPrincipal;
	setProveidor(p);
	if (numBotigues > 0) { 

		for (int i = 0; i < numBotigues; i++)
		{
			string nom = "botiga" + to_string(i);
			string codi = "codi" + to_string(i);

			Botiga* bot = new Botiga(nom, codi);
			m_TotalBotigues.push_back(bot);
		}
	}
}


Empresa::Empresa(string name, vector<Botiga*> botiguesGraf, vector<Aresta>
	conexionsBotigues, Magatzem* magatzemPrincipal, Proveidor& p) { 
	
	Graf graf(botiguesGraf, conexionsBotigues);

	m_name = name;
	m_graf = graf;
	m_magatzem = magatzemPrincipal;
	m_proveidor = p;
		
	for (auto it : m_graf.getVertexs()) {
		
		Botiga* bot = it->botiga;
		bot->setMatgatzem(m_magatzem);
		bot->setveinesOrdenades(m_graf.getBotiguesOrdenades(it));
		m_TotalBotigues.push_back(bot);

	}
}
static map<string, DadesSeguiment>  m_taulaSeguiment;

bool Empresa::afegeixSeguiment(Bicicleta* bicicleta) {
	
	bool seguiment = false;
	if (bicicleta != nullptr) {
		if (m_taulaSeguiment.count(bicicleta->getCodiRus()) == 0 && bicicleta->getCodiRus() != "")
		{
			DadesSeguiment io;
			io.m_bicicleta = bicicleta;
			m_taulaSeguiment[bicicleta->getCodiRus()] = io;
			seguiment = true;
		}
	}
	return seguiment;
}

bool Empresa::actualitzaEstat(const string& codiRus, EstatBicicleta nouEstat, Entitat* novaEntitat) {

	bool ha = false;

	if (novaEntitat != nullptr) {
		if (m_taulaSeguiment.count(codiRus) > 0)
		{
			pair<EstatBicicleta, Entitat*> R;
			R.first = nouEstat;
			R.second = novaEntitat;
			m_taulaSeguiment[codiRus].m_historic.push_back(R);
			ha = true;
		}

	}
	
	return ha;

}

bool Empresa::comprobaEstatCodi(string codiRus, EstatBicicleta objectiu)
{
	if (m_taulaSeguiment.count(codiRus) > 0)
	{
		bool t = false;
		vector<pair<EstatBicicleta, Entitat*>> histo = m_taulaSeguiment[codiRus].m_historic;
		vector<pair<EstatBicicleta, Entitat*>>::iterator it = histo.begin();
		while (!t && it != histo.end())
		{
			t = (*it).first == objectiu;
			it++;
		}
		return t;
	}
	return false;

}
