#include "Botiga.h"
#include "Empresa.h"

void Botiga::mostraCataleg() {

	map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>>::iterator it;

	for (it = m_stockBot.begin(); it != m_stockBot.end(); it++) {

		cout << "Model: " << it->first << endl;
		cout << "Quantity: " << it->second.size() << endl;
		cout << "Oldest bicycle: " << it->second.top() << endl;
	}
}

int Botiga::calculaStockTotal() {

	map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>>::iterator it = m_stockBot.begin();
	int stock = 0;

	for (it = m_stockBot.begin(); it != m_stockBot.end(); it++) {

		stock = stock + it->second.size();
	}
	return stock;
}

bool Botiga::solicitaComanda(Comanda& c, Magatzem& m)
{
	vector<lineaComanda> comand;
	comand = c.getLlistaComanda();

	int full = 0;
	int stockReq = 0, stock = 0;

	for (int i = 0; i < comand.size(); i++)
	{
		lineaComanda comandaux = comand[i];

		string model = comandaux.m_model;

		stockReq = comandaux.m_quantitat;
		stock = m.getStock()[model].size();


		if (stockReq <= stock && stock != 0) { 

			for (int i = 0; i < stockReq; i++)
			{
				Bicicleta* b = m.agafaBicicletaAntiga(model);
				m_stockBot[model].push(b);
			}

			full++;
		}

		stockReq = 0;
		stock = 0;
	}

	return full == c.getLlistaComanda().size();
}

bool Botiga::solicitaComanda( Comanda& c) {

	if (m_magatzem == nullptr) {
		m_magatzem = new Magatzem(); 
	}

	vector<lineaComanda> comand = c.getLlistaComanda();
	vector<Bicicleta*> bicis;
	int full = 0;
	int stockReq = 0, stockMag = 0;

	for (int i = 0; i < comand.size(); i++)
	{
		lineaComanda comandaux = comand[i];

		string model = comandaux.m_model;

		stockReq = comandaux.m_quantitat;
		stockMag = m_magatzem->getStock()[model].size();

		
		if (stockReq <= stockMag && stockMag != 0) { 


			for (int i = 0; i < stockReq; i++)
			{
				Bicicleta* b = m_magatzem->agafaBicicletaAntiga(model);
				m_stockBot[model].push(b);
				Empresa::actualitzaEstat(b->getCodiRus(), EstatBicicleta::EN_BOTIGA, this);
			}

			full++;
		}
		else if (stockMag < stockReq && stockMag != 0) { 
			for (int i = 0; i < stockMag; i++)
			{
				Bicicleta* b = m_magatzem->agafaBicicletaAntiga(model);
				m_stockBot[model].push(b);
				Empresa::actualitzaEstat(b->getCodiRus(), EstatBicicleta::EN_BOTIGA, this);
			}
		}
		else { 
			Bicicleta* b;
			for (int i = 0; i < stockReq && procesa_venda(model, b); i++)
			{
				m_stockBot[model].push(b);
				Empresa::actualitzaEstat(b->getCodiRus(), EstatBicicleta::EN_BOTIGA, this);
			}
		}

		stockReq = 0;
		stockMag = 0;
	}

	return full == c.getLlistaComanda().size();
}

bool Botiga::solicitaBicicletaAMagatzem(const string& model, Bicicleta*& bicicleta) {
    
    int stock = 0;

    if (!getMagatzem()->getStock()[model].empty()) {
        
        
        stock = getMagatzem()->getStock()[model].size();
        
        
        if (stock > 0) 
        {
            bicicleta = getMagatzem()->agafaBicicletaAntiga(model);
        }
    }

    return stock > 0; 
}

bool Botiga::procesa_venda(const string& model, Bicicleta*& bicicleta) {

    if (comprobaBicicletaEnStock(model, bicicleta))
    { 
        return true;
    }
    else if(ComprobaStockEnVeines(model,bicicleta))
    { 
        return true;
    }
    else if(solicitaBicicletaAMagatzem(model,bicicleta))
    {
        return true;
    }
    
    return false;
}

bool Botiga::comprobaBicicletaEnStock(const string& model, Bicicleta*& bicicleta) {
	
int stock = 0;

    if (getStockBotiga().size() > 0) 
    {
        stock = getStockBotiga()[model].size();
       
       if (stock > 0) 
       {

            priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta> aux = m_stockBot[model];

            bicicleta = aux.top(); 
            
            m_stockBot[model].pop();
        }
    }

    return stock > 0; 

}

bool Botiga::ComprobaStockEnVeines(const string& model, Bicicleta*& bicicleta) {

	for (int i = 0; i < getBotiguesProperes().size(); i++)
	{
		if (getBotiguesProperes()[i]->comprobaBicicletaEnStock(model, bicicleta)) 
			return true;
	}
	return false;

}