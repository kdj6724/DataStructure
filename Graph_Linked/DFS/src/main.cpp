// main.c
// 2019-08-25
// kdj6724@naver.com
#include <iostream>
#include "GraphType.h"

template <class VertexType>
void DepthFirstSearch(GraphType<VertexType>* graph,
		VertexType startVertex, VertexType endVertex) {
	using namespace std;
	StackType<VertexType> stack;
	QueType<VertexType> vertexQ;

	bool found = false;
	VertexType vertex;
	VertexType item;
	graph->ClearMarks();
	stack.Push(startVertex);
	do {
		vertex = stack.Top();
		stack.Pop();
		if (vertex == endVertex) {
			cout << vertex << endl;
			found = true;
		} else {
			if (!graph->IsMarked(vertex)) {
				graph->MarkVertex(vertex);
				cout << vertex << endl;
				graph->GetToVertices(vertex, vertexQ);

				while (!vertexQ.IsEmpty()) {
					vertexQ.Dequeue(item);
					if (!graph->IsMarked(item))
						stack.Push(item);
				}
			} 
		}
	} while (!stack.IsEmpty() && !found);
	if (!found)
		cout << "Path not found." << endl;
}

template <class VertexType>
void FillGraph(GraphType<VertexType>* graph) {
	using namespace std;
	graph->AddVertex("Austin");	
	graph->AddVertex("Dallas");	
	graph->AddVertex("Denver");	
	graph->AddVertex("Chicago");	
	graph->AddVertex("Washington");	
	graph->AddVertex("Atlanta");	
	graph->AddVertex("Houston");	

	graph->AddEdge("Austin", "Dallas", 200);
	graph->AddEdge("Austin", "Houston", 160);
	graph->AddEdge("Dallas", "Denver", 780);
	graph->AddEdge("Dallas", "Austin", 200);
	graph->AddEdge("Dallas", "Chicago", 900);
	graph->AddEdge("Denver", "Chicago", 1000);
	graph->AddEdge("Denver", "Atlanta", 1400);
	graph->AddEdge("Chicago", "Denver", 1000);
	graph->AddEdge("Washington", "Atlanta", 600);
	graph->AddEdge("Washington", "Dallas", 1300);
	graph->AddEdge("Atlanta", "Houston", 800);
	graph->AddEdge("Atlanta", "Washington", 600);
	graph->AddEdge("Houston", "Atlanta", 800);
}

int main(void) {
	using namespace std;
	GraphType<string> graph;
	FillGraph<string>(&graph);
	DepthFirstSearch<string>(&graph, "Austin", "Washington");
	return 0;
}
