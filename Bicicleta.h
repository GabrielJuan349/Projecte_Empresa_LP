#pragma once

#include <string>

#include "Data.h"



/**
* Enumeraciones necesarias para la creacion de bicicletas.
* Los valores son necesarios para poder realizar un control de errores eficiente.
* Si algun constructor recibe un parametro "ileagal" debeis establecer como valor por defecto
* el valor permitido mas peque�o del enum.
* 
**/

enum class TipusBicicleta
{
	INFANTIL = 100,
	MTB = 200,
	CARRETERA = 250
};

enum class Fre
{
	DISC = 0,
	RIM = 1,
};

enum class Quadre
{
	ALUMINI = 0,
	CARBONO = 1,
};

enum class Roda
{
	RODA_26 = 0,
	RODA_27 = 1,
	RODA_29 = 2,
	RODA_14 = 3,
	RODA_20 = 4,
	RODA_700 = 5,
};


enum class Talla
{
	XS = 0,
	S = 1,
	M = 2,
	L = 3,
	XL = 4,
};



/**
* Bicicleta es una clase que contiene toda la informacion relevante para definir una bicicleta generica.
* 
**/
class Bicicleta
{
public:
	Bicicleta(const string& model, string descripcio, const int& temporada, const Talla& talla,
		const Quadre& quadre, const Roda& roda, const Fre& fre, TipusBicicleta tipus): m_Model(model), m_Descripcio(descripcio),
		m_Temporada(temporada), m_talla(talla), m_quadre(quadre), m_roda(roda), m_fre(fre), m_tipus(tipus), 
		m_cost(static_cast<int>(m_tipus)) {}

	virtual ~Bicicleta() {}
	
	string getModel() const {return m_Model;}
	string getDescripcio() const { return m_Descripcio; }
	string getCodiRus() const { return m_CodiRus; }
	int getTemporada() const { return m_Temporada; }
	Talla getTalla() const { return m_talla; }
	Quadre getQuadre() const { return m_quadre; }
	Roda getRoda() const { return m_roda; }
	Fre getFre() const { return m_fre; }
	TipusBicicleta getTipus() const { return m_tipus; }
	Data getDataEntrada() const { return m_data; }

	virtual void setModel(const string& model) final { m_Model = model; }
	virtual void setDescripcio(const string& descripcio) final { m_Descripcio = descripcio; }
	virtual void setCodiRus(const string& codirus) final { m_CodiRus = codirus; }
	virtual void setTemporada(const int& temporada) final { m_Temporada = temporada; }
	virtual void setTalla(const Talla& talla) final { m_talla = talla; }
	virtual void setQuadre(const Quadre& quadre) { m_quadre = quadre; }
	virtual void setRoda(const Roda& roda) { m_roda = roda; }
	virtual void setFre(const Fre& fre) { m_fre = fre; }
	virtual void setTipus(TipusBicicleta tipus) { m_tipus = tipus; }
	virtual void setPreu(TipusBicicleta cost) { this->m_cost = float(cost); }
	float getPreu() const { return m_cost; }
	void setDataEntrada(Data d) { m_data = d; }

	bool operator<(const Bicicleta& b1) const { return m_data.operator<(b1.getDataEntrada()); }//
	
	
protected:
	Bicicleta();
	virtual ostream& format(ostream& os) const{return os;}
	friend ostream& operator << (ostream& os, const Bicicleta& b) { return b.format(os); }
	
	Data m_data;
	string m_Model;
	string m_Descripcio;
	string m_CodiRus;
	int m_Temporada;
	Talla m_talla;
	Roda m_roda;
	Fre m_fre;
	Quadre m_quadre;
	TipusBicicleta m_tipus;
	float m_cost;
};

struct CmpBicicleta {
	bool operator()(Bicicleta* a, Bicicleta* b) const
	{
		return b->getDataEntrada() < a->getDataEntrada();
	}

};
