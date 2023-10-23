#include "Proveidor.h"
#include"Empresa.h"


Data Proveidor::generaDataEnviament(Data dataprevista, int diesmaxim) {

	Data dataenviament;
	srand(time(NULL));

	int numero = (-diesmaxim)+(rand() % ((diesmaxim + 1) - (-diesmaxim)));

	int dia = dataprevista.getDia();
	int mes = dataprevista.getMes();
	int any = dataprevista.getAny();
	dia = dia + numero; 

	if ((dia <= 30)&&(dia >= 1)) {
		dataenviament.setDia(dia);
		dataenviament.setMes(mes);
		dataenviament.setAny(any);

	}
	else if (dia > 30) {
		dia = dia - 29;
		mes++;
		if (mes > 12) {
			mes = mes - 11;
			any++;
			
		}

		dataenviament.setDia(dia);
		dataenviament.setMes(mes);
		dataenviament.setAny(any);

	}
	else {
		dia = dia + 29;
		mes--;
		if (mes < 12) {
			mes = mes + 11;
			any--;

		}

		dataenviament.setDia(dia);
		dataenviament.setMes(mes);
		dataenviament.setAny(any);
	}

	return dataenviament;

}

bool Proveidor::procesaComanda(Comanda c, Magatzem*& m){

	vector<lineaComanda> comand = c.getLlistaComanda();
	vector<Bicicleta*> paquetbici; 
	string desc;

	for (int i = 0; i < comand.size(); i++)
	{
		TipusBicicleta tip = comand[i].tipus;

		switch (tip)
		{
		case TipusBicicleta::CARRETERA:
			for (int j = 0; j < c.getLlistaComanda()[i].m_quantitat; j++) {
				paquetbici.push_back(new BicicletaCarretera("Bicicleta de Carretera" + c.getLlistaComanda()[i].m_model, "", 0, randomTalla(), randomQuadre(), randomRoda(), randomFre(), TipusBicicleta::CARRETERA, randomModalitatC(), randomBool()));
			}
			break;
		case TipusBicicleta::INFANTIL:
			for (int j = 0; j < c.getLlistaComanda()[i].m_quantitat; j++){
				paquetbici.push_back(new BicicletaInfantil("Bicicleta Infantil" + c.getLlistaComanda()[i].m_model, "", 0, randomTalla(), randomQuadre(), randomRoda(), randomFre(), TipusBicicleta::INFANTIL, randomBool()));
			}
			break;
		case TipusBicicleta::MTB:
			
			for (int j = 0; j < c.getLlistaComanda()[i].m_quantitat; j++){
				paquetbici.push_back(new BicicletaMTB("Bicicleta de Montanya" + c.getLlistaComanda()[i].m_model, "", 0, randomTalla(), randomQuadre(), randomRoda(), randomFre(), TipusBicicleta::MTB, randomCategoria(), randomModalitat(), randomBool()));
			}
			break;
		}

	}
	
	return m->rebreComanda(c, paquetbici, c.getDataEntregaPrevista());

}