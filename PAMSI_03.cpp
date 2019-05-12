#include <iostream>
#include "Graph_AdjList.hpp"
#include "Graph_AdjMatrix.hpp"



int main(void)
{
	GraphAdjList<int, int> graf_l(50, 0.25);
	GraphAdjMx<int, int> graf_m(50, 0.25);

	cout << "GRAF ADJENCY LIST" << endl;
	graf_l.displayEdges();
	graf_l.displayVertices();

	cout << "GRAF MATRIX LIST" << endl;
	graf_m.displayEdges();
	graf_m.displayVertices();




}
