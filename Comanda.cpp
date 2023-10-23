#include <vector>

#include "Bicicleta.h"
#include "Data.h"
#include "Comanda.h"

#include <iostream>

Comanda::Comanda(const Data& entregaPrevista, vector<lineaComanda>& comanda) {

    m_dataprevista = entregaPrevista;

    for (int i = 0; i < comanda.size(); i++)
    {
        if (!comanda[i].m_model.empty() && comanda[i].m_quantitat > 0)
        {

            m_comanda.push_back(comanda[i]);
            
            switch (comanda[i].tipus)
            {

            case TipusBicicleta::CARRETERA:
               
               m_costTotal += comanda[i].m_quantitat * (float)TipusBicicleta::CARRETERA;
               
                break;

            case TipusBicicleta::INFANTIL:
            
                m_costTotal += comanda[i].m_quantitat * (float)TipusBicicleta::INFANTIL;
                
                break;

            case TipusBicicleta::MTB:
            
                m_costTotal += comanda[i].m_quantitat * (float)TipusBicicleta::MTB;
                
                break;

            }

        }

    }
    
    for (int i = 0; i < m_comanda.size(); i++)
    {

        m_nBicicletes += m_comanda[i].m_quantitat;

    }
}



