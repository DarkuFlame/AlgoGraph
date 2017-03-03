#pragma once

#include "stdafx.h"
#include "Edge.h"
#include "Node.h"

class wdGraph {
	int nodes;
	std::vector<Edge> edges;
public:
	
	//Gibt Startknoten aus.
	int&& Base();
	
	//Ein Vektor von Knoten die auf den Knoten entsprechend dem "index" zeigen, wird zurückgegeben.
	std::vector<int>& AllNodesIN(int index);
	
	//Ein Vektor von Knoten auf die der Knoten entsprechend dem "index" zeigt wird ausgegeben.
	std::vector<int>& AllNodesOUT(int index);
	
	//Gibt die Anzahl der Knoten entsprechend dem Wert von "nodes" aus. Getter-Methode für "nodes".
	int& countNodes();

	//Gibt den ersten Knoten auf den "index" zeigt aus.
	//Hängt von der Reihenfolge der Abspeicherung im Vektor "edges" ab welcher Knoten ausgegeben wird.
	int& NextNode(int index);
	
	//Fügt eine neue Kante hinzu falls Kante nicht bereits existiert.
	//Wenn "from" oder "to" keine gültigen Werte für Knoten im Graph sind wird eine Fehlermeldung ausgegeben. 
	void addEdge(int from, int to, int weight);
	
	//Falls Kante im Graph vorhanden wird sie gelöscht.
	void deleteEdge(int from, int to);

	//Löscht Knoten im Graph und dekrementiert die "nodes" Variable.
	void deleteNode(int index);

	//Gewöhnlicher Konstrukto der die Anzahl der Knoten als Parameter überkommen bekommt.
	wdGraph(int nodes) : nodes(nodes) {};

	//Gibt alle Kanten im Graph aus.
	void printEdges();

	//Gibt den Eingangsgrad des Knoten entsprechend "index" aus.
	size_t&& fanIN(int index);

	//Gibt den Ausgangsgrad des Knoten entsprechend "index" aus.
	size_t&& fanOUT(int index);

	//Gibt Knotenfolge für einen Eulerkreis oder einen Eulerpfad aus.
	std::vector<int>& eulerTour();

};




