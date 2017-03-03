#pragma once

class Edge {
public:
	int from;
	int to;
	int weight;
	Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {};
	Edge(int from, int to) : from(from), to(to), weight(1) {};
	~Edge() {};
	Edge& operator=(const Edge& input) {
		if (this->from == input.from && this->to == input.to && this->weight == input.weight)
			return *this;
		this->from = input.from;
		this->to = input.to;
		this->weight = input.weight;
		return *this;
	}
	bool&& operator==(const Edge& second)
	{
		if (from == second.from &&
			to == second.to)
			return true;
		else return false;
	}
	bool&& operator!=(const Edge& second)
	{
		return !(this->operator==(second));
	}
	Edge(const Edge& copy) : Edge(copy.from, copy.to, copy.weight) {};
	void setWeight(int weight) { this->weight = weight; };
};

