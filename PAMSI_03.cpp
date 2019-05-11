#include "Graph.hpp"
#include <iostream>
#include "list/dlist.hpp"
#include "matrix/matrix.hpp"
#include <list>
#include "GraphM.hpp"


int main(void)
{

	//Graph<int, int> graf;
	//dlinklist<int> list;

	Matrix<int> m(10);
	m(0,0) = 12;
	m(0,1) = 13;
	m.display();
	m.resize(20);
	cout << "Resize" << endl;
	m.display();



	/*

	cout << "LISTA" << endl;
	list.push_front(0);
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	for(auto i = list.begin(); i != list.end(); i++)
		cout << *i << endl;


 for(auto i = list.begin(); i != list.end(); i++){
	 list.insert(i,1);}

	for(auto i = list.begin(); i != list.end(); i++)
		cout << *i << endl;

*/
/*

	auto v1 = graf.insertVertex(1);
	auto v2 = graf.insertVertex(2);
	auto v3 = graf.insertVertex(3);
	auto v4 = graf.insertVertex(4);
	auto v5 = graf.insertVertex(5);
	graf.displayVertices();

	auto e12 = graf.insertEdge(v1, v2, 12);
	auto e23 = graf.insertEdge(v2, v3, 23);
	auto e34 = graf.insertEdge(v3, v4, 34);
	auto e45 = graf.insertEdge(v4, v5, 45);
	auto e51 = graf.insertEdge(v5, v1, 51);
	graf.displayEdges();

	graf.removeEdge(e12);
//	graf.removeEdge(e45);
//	graf.removeEdge(e51);

	graf.displayVertices();
	graf.displayEdges();


*/



}
