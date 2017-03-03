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
	
	//Ein Vektor von Knoten die auf den Knoten entsprechend dem "index" zeigen, wird zur�ckgegeben.
	std::vector<int>& AllNodesIN(int index);
	
	//Ein Vektor von Knoten auf die der Knoten entsprechend dem "index" zeigt wird ausgegeben.
	std::vector<int>& AllNodesOUT(int index);
	
	//Gibt die Anzahl der Knoten entsprechend dem Wert von "nodes" aus. Getter-Methode f�r "nodes".
	int& countNodes();

	//Gibt den ersten Knoten auf den "index" zeigt aus.
	//H�ngt von der Reihenfolge der Abspeicherung im Vektor "edges" ab welcher Knoten ausgegeben wird.
	int& NextNode(int index);
	
	//F�gt eine neue Kante hinzu falls Kante nicht bereits existiert.
	//Wenn "from" oder "to" keine g�ltigen Werte f�r Knoten im Graph sind wird eine Fehlermeldung ausgegeben. 
	void addEdge(int from, int to, int weight);
	
	//Falls Kante im Graph vorhanden wird sie gel�scht.
	void deleteEdge(int from, int to);

	//L�scht Knoten im Graph und dekrementiert die "nodes" Variable.
	void deleteNode(int index);

	//Gew�hnlicher Konstrukto der die Anzahl der Knoten als Parameter �berkommen bekommt.
	wdGraph(int nodes) : nodes(nodes) {};

	//Gibt alle Kanten im Graph aus.
	void printEdges();

	//Gibt den Eingangsgrad des Knoten entsprechend "index" aus.
	size_t&& fanIN(int index);

	//Gibt den Ausgangsgrad des Knoten entsprechend "index" aus.
	size_t&& fanOUT(int index);

	//Gibt Knotenfolge f�r einen Eulerkreis oder einen Eulerpfad aus.
	std::vector<int>& eulerTour();

};




