#pragma once
#include <limits.h>
#include "Botiga.h"
#include <algorithm>


struct Node
{
	bool visitat;
	Botiga* botiga;
	int distanciaMinima;
	Node(Botiga* b) :visitat(false), botiga(b), distanciaMinima(INT_MAX) {}
};

struct Aresta
{
	int inici, desti, pes;
};
class Graf
{
private:
	const int ARESTA_NULA = -1;


	int getPes(Node* inici, Node* desti) { return m_matriuadj[getIndex(inici)][getIndex(desti)]; }
	int getIndex(Node* vertex);
	Node* distanciaMinima();
	vector<Node*> dijkstra(Node* nodeInici);



	//variables
	vector<Node*> m_vertex;
	vector<vector<int>> m_matriuadj;
	
public:
	Graf();
	Graf(vector<Botiga*> llistaVertexs, vector<Aresta> llistaArestes);
	vector<Node*> getVertexs() const { return m_vertex; }
	vector<vector<int>> getArestes() const { return m_matriuadj; }
	vector<Botiga*> getBotiguesOrdenades(Node* nodeInici);
	Graf& operator=(Graf g);
};


