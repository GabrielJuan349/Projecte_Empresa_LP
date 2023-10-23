 #pragma once
#include "Magatzem.h"
#include "Entitat.h"


/**
* Clase para gestionar las acciones y el estoc de cada una de las tiendas que pertenecen a la empresa.
* Las tiendas pueden solicitar a un almacen un pedido.
* Cuando solicitien un pedido "recojeran" de almacen aquellos objetos que puedan, con tal de cubrir su pedido.
* Moveran los objetos del almacen a su propio estoc interno, que estar� ordenado igual que el del almacen.
* Ademas, la tienda necesita saber su estoc total.
**/
	
class Botiga : public Entitat
{
public:
	Botiga(string nom, string codi) { setCodi(codi); setNom(nom); m_magatzem = nullptr; }
	~Botiga() = default;
	bool solicitaComanda(Comanda& c); //
	bool solicitaComanda(Comanda& c, Magatzem& m);
	map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>> getStockBotiga() const { return m_stockBot; }
	void mostraCataleg();
	int calculaStockTotal();
	void setStockBotiga(const map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>>& stock) { m_stockBot = stock; }

	//segona part projecte
	vector<Botiga*> getBotiguesProperes() { return m_botigues; }
	Magatzem* getMagatzem(){ return m_magatzem; }
	void setMatgatzem(Magatzem* m) { m_magatzem = m; }
	void setveinesOrdenades(vector<Botiga*> veines) { m_botigues = veines; }
	bool solicitaBicicletaAMagatzem(const string& model, Bicicleta*& bicicleta);//
	bool procesa_venda(const string& model, Bicicleta*& bicicleta);
	bool comprobaBicicletaEnStock(const string& model, Bicicleta*& bicicleta);//
	bool ComprobaStockEnVeines(const string& model, Bicicleta*& bicicleta);


private:
	Magatzem* m_magatzem;
	vector<Botiga*> m_botigues;
	map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>> m_stockBot;
};
