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
		for(int i = 0; i < V1->inclist.size(); i++)
			for(int j = 0; i < V2->inclist.size(); j++)
				if( V1->inclist.acces(i) == V2->inclist.acces(j))
					return true;
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
		cout <<"Vertex arg: " << V << endl;



	}

	void removeEdge(Edge* E)
	{

	}

	void displayVertexs(void)
	{
		Vertex* node_tmp = vertex_list.front();
		int size = vertex_list.size();
		int i = 0;
		while(size --)
		{
			node_tmp = vertex_list.acces(i++);
			cout << node_tmp->data << endl;
		}
	}

	void displayEdges(void)
	{
		Edge* node_tmp = edge_list.front();
		int size = edge_list.size();
		int i = 0;
		while(size --)
		{
			node_tmp = edge_list.acces(i++);
			cout << node_tmp->weight << endl;
		}
	}

	dlinklist<Vertex*> vertices(void)
	{
		return vertex_list;
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
