#ifndef GRAPHM_HPP_
#define GRAPHM_HPP_
#include "list\dlist.hpp"
#include "matrix\matrix.hpp"

template <typename T, typename W>
class GraphM
{
  public:
	struct Edge;
	struct Vertex;

	Matrix<int> adjency_matrix;
	dlinklist<Edge*> edge_list;
	dlinklist<Vertex*> vertex_list;
	int vertices_idx;

	Vertex* insertVertex(W O)
	{
		Vertex* vertex_tmp = new Vertex;
		vertex_tmp->data = O;
		vertex_tmp->idx = vertices_idx;

		vertices_idx++;

		vertex_list.push(vertex_tmp);
		return vertex_tmp;
	}

	Edge* insertEdge(Vertex* V_start, Vertex* V_end, W O)
	{
		Edge* edge_tmp = new Edge;
		edge_tmp->weight = O;

	}

	void AdjencyMatrix_display(void) {adjency_matrix.display();};


	struct Vertex
	{
		W data;
		int idx;
	};

	struct Edge
	{
		T weight;
		struct Vertex* vertex_start;
		struct Vertex* vertex_end;
	};
};




#endif /* GRAPHM_HPP_ */
