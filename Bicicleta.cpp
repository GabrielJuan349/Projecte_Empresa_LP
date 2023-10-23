#include "Bicicleta.h"

Bicicleta::Bicicleta()
{
    m_Model = "";
    m_Descripcio = "";
    m_Temporada = 0;
    m_talla = Talla::XS;
    m_quadre = Quadre::ALUMINI;
    m_roda = Roda::RODA_14;
    m_fre = Fre::RIM;
    m_tipus = TipusBicicleta::INFANTIL;
}