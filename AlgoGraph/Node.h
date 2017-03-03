#pragma once
#include "stdafx.h"
#include "Edge.h"




class Node {
	int id;
protected:
	int fanIN;
	int fanOUT;
public:
	friend bool&& operator==(Node a, int b);
	friend bool&& operator==(int a, Node b);
	friend bool&& operator==(Node a, Node b);
};

bool&& operator==(Node a, int b) {
	return (a.id == b);
}

bool&& operator==(int a, Node b) {
	return (a == b.id);
}

bool&& operator==(Node a, Node b) {
	return (a.id == b.id);
}
