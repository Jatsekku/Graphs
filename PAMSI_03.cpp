#include "Graph.hpp"
#include <iostream>
#include "list/dlist.hpp"




int main(void)
{

	dlinklist<int> test;
	test.push_back(-1);
	test.push_back(-2);
	test.push_front(0);
	test.push_front(5);
	test.push_front(4);

	test.push_back(-3);

	/*
	for(auto it = test.begin(); it != test.end(); it++)
		cout << *it <<endl;
	 */
	test.display_list();
/*
	cout << "chuj" << endl;
	Graph<int, int> graf_seba;
	auto v1 = graf_seba.insertVertex(1);
	auto v2 = graf_seba.insertVertex(2);
	auto v3 = graf_seba.insertVertex(3);
	auto v4 = graf_seba.insertVertex(4);
	auto e1 = graf_seba.insertEdge(v1, v2, 93);

	cout << v1 << endl << v2 << endl << v3 << endl << v4 << endl;
	//graf_seba.removeVertex(v3);
*/


}
