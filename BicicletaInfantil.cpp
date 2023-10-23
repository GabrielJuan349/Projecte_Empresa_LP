#include "BicicletaInfantil.h"
BicicletaInfantil::BicicletaInfantil()
{
	m_Model = "";
	m_Descripcio = "";
	m_Temporada = 0;
	m_talla = Talla::XS;
	m_quadre = Quadre::ALUMINI;
	m_roda = Roda::RODA_14;
	m_fre = Fre::RIM;
	m_tipus = TipusBicicleta::INFANTIL;
	m_plegable = false;
}


/*ostream& BicicletaInfantil::format(ostream& os) const{

	os << "Model: " << m_Model << endl
		<< "Descripcio: " << m_Descripcio << endl
		<< "Codi rus: " << m_CodiRus << endl
		<< "Temporada: " << m_Temporada << endl
		<< "Talla: " << (int)m_talla << endl
		<< "Roda: " << (int)m_roda << endl
		<< "Quadre: " << (int)m_quadre << endl
		<< "Fre: " << (int)m_fre << endl
		<< "Tipus: " << (int)m_tipus << endl
		<< "Preu: " << m_cost << endl
		<< "Plegable: " << m_plegable << endl;

	return os;

}*/