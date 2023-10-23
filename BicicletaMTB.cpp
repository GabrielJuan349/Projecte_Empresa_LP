#include "BicicletaMTB.h"

BicicletaMTB::BicicletaMTB()
{
	m_Model = "";
	m_Descripcio = "";
	m_Temporada = 0;
	m_talla = Talla::XS;
	m_quadre = Quadre::ALUMINI;
	m_roda = Roda::RODA_26;
	m_fre = Fre::DISC;
	m_tipus = TipusBicicleta::MTB;
	m_categoria = Categoria::RIGIDA;
	m_modalitat = Modalitat::DESCENS;
	m_electrica = false;
}

/*ostream& BicicletaMTB::format(ostream& os) const {
	os << "Model: " << m_Model << endl
		<< "Descripcio: " << m_Descripcio << endl
		<< "Codi rus: " << m_CodiRus << endl
		<< "Temporada: " << m_Temporada << endl
		<< "Talla: " <<(int) m_talla << endl
		<< "Roda: " << (int)m_roda << endl
		<< "Quadre: " << (int)m_quadre << endl
		<< "Fre: " << (int)m_fre << endl
		<< "Tipus: " <<(int) m_tipus << endl
		<< "Preu: " << m_cost << endl
		<< "Categoria: " << (int)m_categoria << endl
		<< "Modalitat: " << (int)m_modalitat << endl
		<< "Electrica: " << m_electrica << endl;


		return os;

}*/
