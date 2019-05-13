#include <iostream>
#include "Graph_AdjList.hpp"
#include "Graph_AdjMatrix.hpp"
#include "priority_queue/priority_queue.hpp"
#include "pair.hpp"
//#include<bits/stdc++.h>


int main(void)
{
	/*
	GraphAdjList<int, int> graf_l(50, 0.25);
	GraphAdjMx<int, int> graf_m(50, 0.25);

	cout << "GRAF ADJENCY LIST" << endl;
	graf_l.displayEdges();
	graf_l.displayVertices();

	cout << "GRAF MATRIX LIST" << endl;
	graf_m.displayEdges();
	graf_m.displayVertices();
*/


	priority_queue< pq_node_t<int> > pq(10);

	pq_node_t< int > a(20,10);
	pq_node_t< int > b(5,10);
	pq_node_t< int > c(6,10);

	pq.push(a);
	pq.push(b);
	pq.push(c);

	pq.display();




}
