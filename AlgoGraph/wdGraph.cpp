#include "wdGraph.h"


int& wdGraph::countNodes()
{
	return nodes;
}

int&& wdGraph::Base() {
	//Gibt den Startknoten aus.
	if (nodes > 0) return 0;
	else return -1;
}

int& wdGraph::NextNode(int index)
{
	//Gibt erste Kante die vom Knoten "index" wegzeigt aus dem Vektor. Wenn nichts gefunden dann wird -1 zurückgegeben.
	int notfound = -1;
	if (index >= nodes || index < 0)
	{
		std::cerr << "Knoten ist nicht im Graph vorhanden\n.";
	}
	else
	{
		for (auto i : edges)
			if (i.from == index) return i.to;
	}
	return notfound;
}



void wdGraph::addEdge(int from, int to, int weight) {
	//Wenn Kante nicht bereits in Vektor dann füge sie ans Ende des Vektor hinzu.
	Edge* tmp = new Edge(from, to, weight);
	for (auto i : edges)
	{
		if (i == *tmp) {
			std::cout << "Kante bereits vorhanden!" << std::endl;
			return;
		}
	}
	edges.push_back(*tmp);
}

void wdGraph::deleteEdge(int from, int to)
{
	//Sind die angegebenen Knoten im gültigen Bereich. Existieren sie im Graph?
	if (from >= nodes || to >= nodes
		|| from < 0 || to < 0)
		std::cout << "Knoten ist nicht im Graph vorhanden." << std::endl;
	else {
		//Finde Kante aus Kantenliste und lösche sie aus dem Vektor
		Edge tmp(from, to);
		int count = 0;
		for (auto i : edges)
		{
			edges.erase(edges.begin() + count);
			++count;
		}
	}
}

std::vector<int>& wdGraph::AllNodesIN(int index)
{
	//Sammle "from" werte in denen "to" == "index". Das entspricht der Kanten die auf "index" zeigen.
	std::vector<int> result;
	for (auto i : edges)
		if (i.to == index)
			result.push_back(i.from);
	if (result.size()) std::cout << "Keine Kanten führenn zu diesem Knoten." << std::endl;
	return result;
}

std::vector<int>& wdGraph::AllNodesOUT(int index)
{
	//Sammle alle "to" Werte in denen "from" == "index". Das entspricht der Kanten die auf "index" zeigen.
	std::vector<int> result;
	for (auto i : edges)
		if (i.from == index)
			result.push_back(i.to);
	if (result.size() == 0) std::cout << "Sackgasse: Knoten hat keine Kanten die wegführen." << std::endl;
	return result;
}

void wdGraph::printEdges()
{
	//Wenn Knoten und Kanten vorhanden dann werden Kanten auf die Konsole ausgegeben.
	if (nodes < 0) std::cout << "Graph hat keine Knoten." << std::endl;
	if (edges.size() == 0) std::cout << "Graph hat keine Kanten." << std::endl;
	else
		for (auto i : edges)
			std::cout << i.from << " --> " << i.to << " Weight: " << i.weight << std::endl;
}

size_t&& wdGraph::fanIN(int index)
{
	std::vector<int> tmp = this->AllNodesIN(index);
	return  tmp.size();
}

size_t&& wdGraph::fanOUT(int index) {
	std::vector<int> tmp = this->AllNodesOUT(index);
	return  tmp.size();
}



std::vector<int>& wdGraph::eulerTour()
{
	using vec = std::vector<int>;
	vec sample = vec();
	return sample;
}

void wdGraph::deleteNode(int index) {
	int count = 0;
	for (auto i : edges)
	{
		if (i.from == index || i.to == index)
			edges.erase(edges.begin() + count);
	}

}























