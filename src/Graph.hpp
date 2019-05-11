#ifndef GRAPH_HPP_
#define GRAPH_HPP_
#include <iostream>
#include "list\dlist.hpp"

using namespace std;

template <typename T, typename W>
struct Pair{
	T first;
	W second;
};


template <typename T, typename W>
class Graph{

public:

	struct Edge;
	struct Vertex;

	dlinklist<Edge*> edge_list;
	dlinklist<Vertex*> vertex_list;

	dlinklist<Vertex*> vertices(void) {return vertex_list;}

	dlinklist<Edge*> edges(void) {return edge_list;}

	dlinklist<Edge*> incidentEdges(Vertex* V) {return V->inclist;}

	Vertex* insertVertex(W O)
	{
		Vertex* vertex_tmp = new Vertex;
		vertex_tmp->data = O;
		vertex_list.push_front(vertex_tmp);
		return vertex_tmp;
	}

	Pair<Vertex*, Vertex*>endVertices(Edge *E)
	{
		Pair<Vertex*, Vertex*> pair_tmp;
		pair_tmp.first = E->start;
		pair_tmp.second = E->end;

		return pair_tmp;
	}

	Edge* insertEdge(Vertex* V_start, Vertex* V_end, W O)
	{
		Edge* edge_tmp = new Edge;
		edge_tmp->start = V_start;		//Wierzchołek początkowy
		edge_tmp->end = V_end;			//Wierzchołek końcowy
		edge_tmp->weight = O;

		V_start->inclist.push_front(edge_tmp);
		V_end->inclist.push_front(edge_tmp);

		edge_tmp->inclist_start = V_start->inclist.front();
		edge_tmp->inclist_end = V_end->inclist.front();

		edge_list.push_front(edge_tmp);
		return edge_tmp;
	}

	bool areAdjacent(Vertex* V1, Vertex* V2)
	{
		if((V1->inclist.begin() != nullptr) && (V2->inclist.begin() != nullptr))
		{
			for(auto i = V1->inclist.begin(); i != V1->inclist.end(); i++)
				for(auto j = V2->inclist.begin(); j != V2->inclist.end(); j++)
					if(*i==*j)
						return true;
		}
		return false;
	}

	Vertex* opposite(Vertex* V, Edge* E)
	{
		if(E->start == V)
			return E->end;
		return E->start;
	}

	void replace(Vertex* V, W X) { V->data = X;}

	void replace(Edge* E, W X) { E->weight = X;}

	void removeVertex(Vertex *V)
	{
		Edge* edge_tmp;
		for(auto j = vertex_list.begin(); j != vertex_list.end(); j++)
		{
			if(*j == V)
			{
				for(auto i = V->inclist.begin(); i != V->inclist.end(); i++)
				{
					cout << "chuj" << endl;
					edge_tmp = *i;
					cout << edge_tmp->weight << endl;
					removeEdge(edge_tmp);
				}

				vertex_list.erase(j);
				delete V;
				break;
			}
		}



	}

	void removeEdge(Edge* E)
	{
		auto i = E->start->inclist.begin();
		auto j = E->end->inclist.begin();

		for(; i != E->start->inclist.end(); i++)
		{
			if(*i == E->inclist_start)
			{
				cout << "ok1" <<endl;
				//E->start->inclist.erase(i);
				cout << "ok2" <<endl;
				break;
			}
		}

		for(; j != E->end->inclist.end(); j++)
		{
			if(*j == E->inclist_end)
			{
				cout << "ok3" << endl;
				//E->end->inclist.erase(j);
				cout << "ok4" <<endl;
				break;
			}
		}


		for(auto k = edge_list.begin(); k != edge_list.end(); k++)
		{

			if(*k == E)
			{
				E->start->inclist.erase(i);
				E->end->inclist.erase(j);
				edge_list.erase(k);
				delete E;
				break;
			}
		}


	}

	void displayVertices(void)
	{
		cout << "displayVertices:" << endl;
		Vertex* vertex_tmp;
		for(auto i = vertex_list.begin(); i != vertex_list.end(); i++)
		{
			vertex_tmp = *i;
			cout << vertex_tmp->data << endl;
		}
	}

	void displayEdges(void)
	{
		cout << "displayEdges:" << endl;
		Edge* edge_tmp;
		for(auto i = edge_list.begin(); i != edge_list.end(); i++)
		{
			edge_tmp = *i;
			cout << edge_tmp->weight << endl;
		}
	}




	struct Vertex
	{
		W data;
		dlinklist<Edge*> inclist;
	};

	struct Edge
	{
		W weight;
		struct Vertex* start;
		struct Vertex* end;
		Edge* inclist_start;
		Edge* inclist_end;
	};

};
#endif
