#include "list/list.hpp"
#include "Graph.hpp"
#include <iostream>



int main(void)
{


	cout << "chuj" << endl;
	Graph<int, int> graf_seba;
	auto v1 = graf_seba.insertVertex(69);
	auto v2 = graf_seba.insertVertex(80);
	auto v3 = graf_seba.insertVertex(80);
	auto v4 = graf_seba.insertVertex(70);
	auto e1 = graf_seba.insertEdge(v1, v2, 93);

	graf_seba.displayVertexs();
	graf_seba.displayEdges();
	cout << graf_seba.areAdjacent(v1, v2) << endl;
	cout << graf_seba.areAdjacent(v1, v3) << endl;
	cout << v1 << endl << v2 << endl << v3 << endl;
	cout << graf_seba.opposite(v2, e1) << endl;
	graf_seba.replace(v1, 21);
	graf_seba.replace(e1, 18);
	graf_seba.displayVertexs();
	graf_seba.displayEdges();


}
