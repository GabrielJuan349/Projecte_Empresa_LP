#include "Graf.h"
Graf::Graf()
{
}
Graf::Graf(vector<Botiga*> llistaVertexs, vector<Aresta> llistaArestes) {

	for (int i = 0; i < llistaVertexs.size(); i++) {
		Node* llistaNodes = new Node(llistaVertexs[i]);
		llistaNodes->visitat = false;
		llistaNodes->botiga = llistaVertexs[i];
		llistaNodes->distanciaMinima = INT_MAX;
		m_vertex.push_back(llistaNodes);
	}
	m_matriuadj.resize(llistaVertexs.size(), vector<int>(llistaVertexs.size()));
	for (int i = 0; i < llistaVertexs.size(); i++) {
		for (int y = 0; y < llistaVertexs.size(); y++)
			m_matriuadj[i][y] = ARESTA_NULA;
	}
	for (int i = 0; i < llistaArestes.size(); i++) {
		m_matriuadj[llistaArestes[i].inici][llistaArestes[i].desti] = llistaArestes[i].pes;
		m_matriuadj[llistaArestes[i].desti][llistaArestes[i].inici] = llistaArestes[i].pes;
	}
}

vector<Botiga*> Graf::getBotiguesOrdenades(Node* nodeInici) {

	vector<int> order;
	vector<Node*> result;
	vector<Botiga*> ResBotiga;


	for (int i = 0; i < m_vertex.size(); i++) {
		m_vertex[i]->distanciaMinima = INT_MAX;
		m_vertex[i]->visitat = false;
	}
	
	dijkstra(nodeInici);

	for (int i = 0; i < m_vertex.size(); i++) {
		order.push_back(m_vertex[i]->distanciaMinima);
	}

	sort(order.begin(), order.end());
	
	for (int i = 0; i < order.size(); i++) {
	
		for (int y = 0; y < m_vertex.size(); y++) {
		
			if (order[i] == m_vertex[y]->distanciaMinima && (find(result.begin(), result.end(), m_vertex[y]) == result.end())) {
			
				result.push_back(m_vertex[y]);
				ResBotiga.push_back(m_vertex[y]->botiga);
			
			}
		}
	}
	vector<Botiga*>::iterator it = ResBotiga.begin();
    ResBotiga.erase(it);
	return ResBotiga;
		
}
Graf& Graf::operator=(Graf g) {
	m_vertex = g.m_vertex;
	m_matriuadj = g.m_matriuadj;

	return *this;
}

int Graf::getIndex(Node* vertex) {
	
	int i = 0;
	while (m_vertex.size() > i && vertex != m_vertex[i]) {
		
		i++;
	
	}
	
	return i;

}

Node* Graf::distanciaMinima() {

	pair<int, Node*> Matdist;

	Matdist.first = INT_MAX;

	for (int i = 0; i < m_vertex.size(); i++)
	{
		if ((!m_vertex[i]->visitat) && (m_vertex[i]->distanciaMinima > -1))
		{
			if (m_vertex[i]->distanciaMinima <= Matdist.first) {
				Matdist.first = m_vertex[i]->distanciaMinima;
				Matdist.second = m_vertex[i];
			}
		}
	}

	m_vertex[getIndex(Matdist.second)]->visitat = true;
	
	return Matdist.second;
}
vector<Node*> Graf::dijkstra(Node* nodeInici) {

	m_vertex[getIndex(nodeInici)]->distanciaMinima = 0;
	
	for (int i = 0; i < m_vertex.size(); i++) {

		Node* dist = distanciaMinima();
		
		for (int y = 0; y < m_vertex.size(); y++) {
		
			bool vist = m_vertex[y]->visitat;
			bool distmin = m_vertex[y]->distanciaMinima > (m_matriuadj[getIndex(dist)][y] + m_vertex[getIndex(dist)]->distanciaMinima);
			bool ANula = m_matriuadj[getIndex(dist)][y] != -1;
			
			if ((!vist) && (distmin) && (ANula))
				m_vertex[y]->distanciaMinima = (m_matriuadj[getIndex(dist)][y] + m_vertex[getIndex(dist)]->distanciaMinima);
		}
	}

	return m_vertex;
}