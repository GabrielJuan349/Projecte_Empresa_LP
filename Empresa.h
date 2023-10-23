#pragma once
#include <string>

#include "Comanda.h"
#include "Botiga.h"
#include "Magatzem.h"
#include "Proveidor.h"
#include "Graf.h"

/**
 *
* La clase empresa aglutina la inforamcion para gestionar la comunicacion del almacen con el proveedor, asi como las tiendas.
* La empresa se define por un conjunto de tiendas, un almacen y un proveedor.
* La empresa realizar� pedidos al provedor y recibira una notificacion indicando si el pedido ha llegado correctamente a almacen.
* 
**/

enum class EstatBicicleta {
	EN_MAGATZEM,
	EN_BOTIGA,
	VENUDA,
	RETORNADA
};

struct DadesSeguiment {
	Bicicleta* m_bicicleta;
	vector<pair<EstatBicicleta, Entitat*>> m_historic;
	DadesSeguiment() {
		m_bicicleta = nullptr;
		m_historic = vector<pair<EstatBicicleta, Entitat*>>();
	}
};


class Empresa
{
public:

	string getName() const { return m_name; }
	Magatzem*& getMagatzem() {	return m_magatzem; }
	vector<Botiga*>& getBotigues() { return m_TotalBotigues; }
	void setProveidor(Proveidor& proveidor) { this->m_proveidor = proveidor; }
	Proveidor& getProveidor() { return m_proveidor; }
	static int getSeguentCodiRus();
	void afegeixBotiga(Botiga* b) { this->m_TotalBotigues.emplace_back(b); };

	bool realitzaComanda(Comanda& c, Proveidor& p){ return p.procesaComanda(c, getMagatzem()); }
	string static generaCodiRus(const string& model);

// 2n part projecte
	Empresa(string name, vector<Botiga*> botiguesGraf, vector<Aresta>
		conexionsBotigues, Magatzem* magatzemPrincipal, Proveidor& p);
	Empresa(string name, int numBotigues, Magatzem* magatzemPrincipal, Proveidor& p);	
	bool realitzaComanda(Comanda& c) { return realitzaComanda(c,m_proveidor); }
	static bool afegeixSeguiment(Bicicleta* bicicleta);
	static bool actualitzaEstat(const string& codiRus, EstatBicicleta nouEstat, Entitat* novaEntitat);
	static bool comprobaEstatCodi(string codiRus, EstatBicicleta objectiu);



private:
	string m_name;
	Magatzem* m_magatzem;
	Proveidor m_proveidor;
	vector<Botiga*> m_TotalBotigues;
	Graf m_graf;

	
};
