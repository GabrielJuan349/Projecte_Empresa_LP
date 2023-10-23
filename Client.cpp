#include "Client.h"
#include "Empresa.h"

bool Client::comprarBicicleta(string model, Botiga& b) {

    bool t = false;
	Bicicleta* bici = nullptr;
	if (b.procesa_venda(model, bici))
	{
		m_bicicletes.push_back(bici);
		Empresa::actualitzaEstat(bici->getCodiRus(), EstatBicicleta::VENUDA, this);
		t = true;
	}
	return t;
}
