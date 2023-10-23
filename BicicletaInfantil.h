#pragma once

#include "Bicicleta.h"
#include <string>

/**
* BicicletaInfantil contine la inforacion relenavte para definir una bicicleta infantil.
* 
**/
class BicicletaInfantil: public Bicicleta
{
public:

	BicicletaInfantil();
	BicicletaInfantil(const string& model, string descripcio, const int& temporada, const Talla& talla, const Quadre& quadre, 
		const Roda& roda, const Fre& fre, TipusBicicleta tipus, const bool& plegable): 
		Bicicleta(model, descripcio, temporada, talla, Quadre::ALUMINI, Roda::RODA_14, Fre::RIM, TipusBicicleta::INFANTIL), m_plegable(plegable){}
	
	~BicicletaInfantil() {}

	bool getPlegable() const { return m_plegable; }
	void setPlegable(const bool& plegable) { m_plegable = plegable; }

	void setQuadre(const Quadre& quadre) { if (quadre == Quadre::ALUMINI) { this->m_quadre = Quadre::ALUMINI; } }
	void setFre(const Fre& fre) override { if (fre == Fre::RIM) { this->m_fre = fre; } };
	void setRoda(const Roda& roda) override { if (roda == Roda::RODA_14 || roda == Roda::RODA_20) { this->m_roda = roda; } }
	void setTipus(TipusBicicleta tipus) override { if (tipus == TipusBicicleta::INFANTIL) { this->m_tipus = tipus; } }

protected:
	ostream& format(ostream& os) const override{return os;}
private:
	bool m_plegable;

};

