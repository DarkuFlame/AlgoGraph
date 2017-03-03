
#include <iostream>
#include "nwunGraph.h"

//Gibt den Startknoten aus 

int nwunGraph::Base()
{
	if (this->nodes == 0) return -1; //Wenn Anzahl der Knoten == 0 dann gibt es auch keinen Startknoten
	else return 0;                   //Startknoten ist immer 0
}

std::vector<int> nwunGraph::allNodes(int index) {
	std::vector<int> result(0);
	for (auto i : this->edges)
	{
		if (i[0] == index) result.insert(result.end(), i[1]);
		else if (i[1] == index) result.insert(result.end(), i[0]);
	}
	return result;
}

int nwunGraph::nextNode(int index)
{
	//Suche n�chste Kante im Vektor die einen Knoten enth�lt die Index entspricht.
	//Der gegen�berliegende Knoten wird ausgegeben.
	//Falls keine Kante den gesucht Knoten hat gibt diese Methode -1 aus.
	for (auto i : this->edges)
	{
		if (i[0] == index) return i[1];
		else if (i[1] == index) return i[0];
	}
	return -1;
}

void nwunGraph::addEdge(int j, int i)
{
	//Pr�fen ob beide Knoten g�ltig
	if (j >= nodes || i >= nodes)
		std::cout << "Ung�ltige Knoten!" << std::endl;
	else
	//Wenn beide Knoten g�ltig dann Kante ans Ende des Vektors hinzuf�gen
	this->edges.insert(this->edges.end(), { j, i });
}

void nwunGraph::delEdge(int j, int i) {
	//Pr�fen ob beide Knoten g�ltig.
	if (j >= nodes || i >= nodes)                        
		std::cout << "Ung�ltige Knoten!" << std::endl;
	else
	{
		//Alle Kanten aus dem Vektor l�schen die der Angegebenen entsprechen<
		int count = 0;
		for (auto k : this->edges)
		{
			if ((k[0] == j && k[1] == i) || (k[0] == i && k[1] == j))
				this->edges.erase(this->edges.begin() + count);
			++count;
		}
	}
}

void nwunGraph::printEdges() {
	for (auto edge : this->edges) {
		std::cout << "[" << edge[0] << ", " << edge[1] << "]" << std::endl;
	}
}

