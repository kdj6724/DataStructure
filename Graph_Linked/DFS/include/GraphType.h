// GraphType.h
// 2019-08-26
// kdj6724@naver.com
#include "QueType.h"
#include "StackType.h"

const int MAX_VERTEX = 50;
class FullGraph {
};

class EmptyGraph {
};

template <class VertexType>
struct EdgeNodeType {
  VertexType vertex;
	int weight;
  EdgeNodeType<VertexType>* edge;
};

template <class VertexType>
struct HeadNodeType {
  VertexType vertex;
	bool mark;
  HeadNodeType<VertexType>* next;
  EdgeNodeType<VertexType>* edge;
};

template <class VertexType>
class GraphType {
public:
	GraphType();
	~GraphType();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void AddVertex(VertexType);
	void AddEdge(VertexType, VertexType, int);
	int WeightIs(VertexType, VertexType);
	void GetToVertices(VertexType, QueType<VertexType>&);
	void ClearMarks();
	void MarkVertex(VertexType);
	bool IsMarked(VertexType);
private:
	HeadNodeType<VertexType>* IndexIs(HeadNodeType<VertexType>* vertices,
			VertexType vertex);
	int numVertices_;
	int maxVertices_;
	HeadNodeType<VertexType>* vertices_;
	HeadNodeType<VertexType>* topVertex_;
};

template <class VertexType>
GraphType<VertexType>::GraphType() {
	numVertices_ = 0;
	vertices_ = nullptr;
	topVertex_ = nullptr;
}

template <class VertexType>
GraphType<VertexType>::~GraphType() {
}

const int NULL_EDGE = 0;
template <class VertexType>
void GraphType<VertexType>::AddVertex(VertexType vertex) {
	HeadNodeType<VertexType>* temp;
	if (!IsFull()) {
		throw FullGraph();
	} else {	
		temp = new HeadNodeType<VertexType>;
		temp->vertex = vertex;
		temp->next = nullptr;
		temp->edge = nullptr;
		if (vertices_ != nullptr)
			vertices_->next = temp;
		else
			topVertex_ = temp;
		vertices_ = temp;
		numVertices_++;
	}
}

template <class VertexType>
HeadNodeType<VertexType>* GraphType<VertexType>::IndexIs(HeadNodeType<VertexType>* 
		vertices, VertexType vertex) {
	HeadNodeType<VertexType>* temp;
	while (!(vertex == vertices->vertex)) {
		vertices = vertices->next;
		if (vertices == nullptr)
			break;
	}
	return vertices;
}

template <class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex, 
		VertexType toVertex, int weight) {
	HeadNodeType<VertexType>* temp;
  EdgeNodeType<VertexType>* edgeTemp;

	temp = IndexIs(topVertex_, fromVertex);
	if (temp == nullptr) {
		std::cout << "Can not found Vertex" << std::endl;
		return;
	}
	edgeTemp = temp->edge;
	while(!(edgeTemp == nullptr)) {
		edgeTemp = edgeTemp->edge;
	}
	if (!IsFull()) {
		throw FullGraph();
	} else {	
		edgeTemp = new EdgeNodeType<VertexType>;
		edgeTemp->vertex = toVertex;
		edgeTemp->weight = weight;
		edgeTemp->edge = nullptr;
	}
}

template <class VertexType>
int GraphType<VertexType>::WeightIs(VertexType fromVertex, 
		VertexType toVertex) {
	HeadNodeType<VertexType>* temp;
  EdgeNodeType<VertexType>* edgeTemp;

	temp = IndexIs(topVertex_, fromVertex);
	if (temp == nullptr) {
		std::cout << "Can not found Vertex" << std::endl;
		return 0;
	}
	edgeTemp = temp->edge;
	while(edgeTemp != nullptr) {
		if (edgeTemp->vertex == toVertex)
			return edgeTemp->weight;
		edgeTemp = edgeTemp->edge;
	}
	return 0;
}

template <class VertexType>
void GraphType<VertexType>::GetToVertices(VertexType vertex,
		QueType<VertexType>& adjVertices) {
	HeadNodeType<VertexType>* temp;
  EdgeNodeType<VertexType>* edgeTemp;

	temp = IndexIs(topVertex_, vertex);
	edgeTemp = temp->edge;
	while(edgeTemp != nullptr) {
		adjVertices.Enqueue(edgeTemp->vertex);
		edgeTemp = edgeTemp->edge;
	}
}

template <class VertexType>
void GraphType<VertexType>::MakeEmpty() {
}

template <class VertexType>
bool GraphType<VertexType>::IsEmpty() const {
}

template <class VertexType>
bool GraphType<VertexType>::IsFull() const {
	return true;
}

template <class VertexType>
void GraphType<VertexType>::ClearMarks() {
	HeadNodeType<VertexType>* temp;
	while (temp != nullptr) {
		temp->mark = 0;
		temp = temp->next;
	}
}

template <class VertexType>
void GraphType<VertexType>::MarkVertex(VertexType vertex) {
	HeadNodeType<VertexType>* temp;
	temp = IndexIs(vertices_, vertex);
	temp->mark = 1;
}

template <class VertexType>
bool GraphType<VertexType>::IsMarked(VertexType vertex) {
	HeadNodeType<VertexType>* temp;
	temp = IndexIs(vertices_, vertex);
	return (temp->mark == 1);
}

