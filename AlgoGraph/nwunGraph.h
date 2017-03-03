#pragma once

#include <vector>

class nwunGraph {
public:
	int nodes;
	std::vector<std::vector<int>> edges;
	int Base();
	std::vector<int> allNodes(int index);
	int nextNode(int index);
	void addEdge(int i, int j);
	void delEdge(int i, int j);
	void printEdges();
	nwunGraph(int nodes) : nodes(nodes) {};
};


