#include "Magatzem.h"
#include "Empresa.h"
#include <algorithm>
#include <vector>
#include <fstream>

Bicicleta* Magatzem::agafaBicicletaAntiga(const string& model) {


	priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta> aux = m_stockMag[model];

	Bicicleta* ret = aux.top();

	m_stockMag[model].pop(); 
	return ret;
}

void Magatzem::mostraCataleg() {

	map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>>::iterator it;


	for (it = m_stockMag.begin(); it != m_stockMag.end(); it++) {

		cout << "Model: " << it->first << endl;
		cout << "Quantity: " << it->second.size() << endl;
		cout << "Oldest bicycle: " << it->second.top() << endl;
	}
}

bool Magatzem::rebreComanda(Comanda& c, vector<Bicicleta*>& paquet, Data dataRecepcioPaquet) {

	float price;


	enmagatzemarComanda(paquet, dataRecepcioPaquet);
	price = procesQA(c, paquet, dataRecepcioPaquet);


	if (c.getCostTotal() == price)
	{
		generaFactura(true, price, c);
		return true;
	}
	else
	{
	    generaFactura(false, price, c);
		return false;
	}

}

void Magatzem::enmagatzemarComanda(vector<Bicicleta*>& paquet, Data dataEntrada) {

	string Nom;
	
	for (int i = 0; i < paquet.size(); i++) { 
		Nom = paquet[i]->getModel();
		paquet[i]->setCodiRus(Empresa::generaCodiRus(Nom));
		paquet[i]->setDataEntrada(dataEntrada);

		Empresa::afegeixSeguiment(paquet[i]);
		Empresa::actualitzaEstat(paquet[i]->getCodiRus(), EstatBicicleta::EN_MAGATZEM, this); 

		m_stockMag[Nom].push(paquet[i]); 
	}
}

float Magatzem::procesQA(Comanda& c, vector<Bicicleta*>& paquet, Data dataActual) {

	if ((dataActual <= c.getDataEntregaPrevista()) && (c.getTotalBicicletes() == paquet.size()))
		return c.getCostTotal();
	else
	    return (c.getCostTotal() * 1.1);
}

void Magatzem::generaFactura(bool paquetComplet, float costCorregit, Comanda& c) {

	vector<lineaComanda> comanda = c.getLlistaComanda();
	
	
	ofstream factura;
	factura.open("factura.txt");

	if (factura.is_open()) {

		factura << "Resum comanda." << endl
				<< "Dades Entitat responsable:" << endl
				<< "Nom: " << getNom() << endl
				<< "Codi identificatiu: " << getCodi() << endl
				<< "Articles." << endl;

		if (paquetComplet == true) {

			for (int i = 0; i < comanda.size(); i++)
			{
				factura << comanda[i].m_model << " * " << comanda[i].m_quantitat << endl << endl;
			}
			
			factura << "Preu final: " << costCorregit << endl;
		
		}
		else
		{
			factura << "El paquet no pasa els test de qualitat." << endl
				<< "Es redueix el cost del paquet en un 1.1"
				<< "Preu final: " << costCorregit << endl;
		}
	}
	factura.close();
}