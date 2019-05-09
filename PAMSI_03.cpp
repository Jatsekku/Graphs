#include "Graph.hpp"
#include <iostream>
#include "list/slist.hpp"



int main(void)
{


	cout << "chuj" << endl;
	Graph<int, int> graf_seba;
	auto v1 = graf_seba.insertVertex(1);
	auto v2 = graf_seba.insertVertex(2);
	auto v3 = graf_seba.insertVertex(3);
	auto v4 = graf_seba.insertVertex(4);
	auto e1 = graf_seba.insertEdge(v1, v2, 93);

	cout << v1 << endl << v2 << endl << v3 << endl << v4 << endl;
	graf_seba.removeVertex(v3);

}
