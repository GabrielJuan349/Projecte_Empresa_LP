#pragma once

#include "Bicicleta.h"

enum class ModalitatC {
	AERO,
	GRANFONDO,
	GRAVEL,
	RENDIMIENTO,
};

/**
* BicicletaCarretera contine la inforacion relenavte para definir una bicicleta de carretera.
* 
**/
class BicicletaCarretera: public Bicicleta
{
public:

	BicicletaCarretera();
	BicicletaCarretera(const string& model, string descripcio, const int& temporada, const Talla& talla,
		const Quadre& quadre, const Roda& roda, const Fre& fre, TipusBicicleta tipus, ModalitatC modalitat,
		bool electrica) : Bicicleta(model, descripcio, temporada, talla, quadre, Roda::RODA_700, fre, TipusBicicleta::CARRETERA), m_modalitat(modalitat),
		m_electrica(electrica) {}
	
	~BicicletaCarretera() {}

	void setModalitat(const ModalitatC& modalitat) { m_modalitat = modalitat; }
	ModalitatC getModalitat() const { return m_modalitat; }
	void setElectricaC(const bool& electrica) { m_electrica = electrica; }
	bool getElectrica() const { return m_electrica; }

	void setRoda(const Roda& roda) override { if (roda == Roda::RODA_700) { this->m_roda = roda; }; }
	void setTipus(TipusBicicleta tipus) override { if (tipus == TipusBicicleta::CARRETERA) { this->m_tipus = tipus; } }

protected:
	ostream& format(ostream& os) const override {return os;}
private:
	bool m_electrica;
	ModalitatC m_modalitat;

};

