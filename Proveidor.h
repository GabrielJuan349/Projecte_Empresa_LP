#pragma once
#include <string>
#include "Comanda.h"
#include "Magatzem.h"
#include "Bicicleta.h"
#include <stdlib.h>
#include<time.h>
#include <vector>
#include "utils.h"
#include "BicicletaMTB.h"
#include "BicicletaCarretera.h"
#include "BicicletaInfantil.h"

/**
* Clase que produce las comandas recibidas y se encarga de que lleguen al almacen de destino.
* A falta de tener una API externa que nos facilite la implementacion del control de tiempo, el proveedor
* genera una fecha para simbolizar el tiempo que tarda en producir y enviar el pedido.
* 
**/

class Proveidor
{
public:
	Proveidor(): m_Cproveidor (0){}
	Proveidor(const int& codiProveidor) :m_Cproveidor(codiProveidor) {}
	Data generaDataEnviament(Data dataprevista, int diesmaxim);
	bool procesaComanda(Comanda c, Magatzem*& m);


	void setCodiProveidor(const int& proveidor) { m_Cproveidor = proveidor; }
	int getCodiProveidor() const { return m_Cproveidor; }
	
private:
	int m_Cproveidor;

};
