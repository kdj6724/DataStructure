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
	void PrintEdge(VertexType vertex);
	void PrintVertex(VertexType vertex);
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

// copy constructor 추가 필요
template <class VertexType>
GraphType<VertexType>::~GraphType() {
	HeadNodeType<VertexType>* vertexTemp;
	EdgeNodeType<VertexType>* edgePtr;
	EdgeNodeType<VertexType>* edgeTemp;
	while (topVertex_ != nullptr) {
		edgePtr = topVertex_->edge;	
		while (edgePtr != nullptr) {
			edgeTemp = edgePtr;
			edgePtr = edgePtr->edge;
			delete edgeTemp;
		}
		vertexTemp = topVertex_;
		topVertex_ = topVertex_->next;
		delete vertexTemp;
	}
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
 	EdgeNodeType<VertexType>* prevEdge = nullptr;

	temp = IndexIs(topVertex_, fromVertex);
	if (temp == nullptr) {
		std::cout << "Can not found Vertex" << std::endl;
		return;
	}
	edgeTemp = temp->edge;
	while(!(edgeTemp == nullptr)) {
		prevEdge = edgeTemp;
		edgeTemp = edgeTemp->edge;
	}
	if (!IsFull()) {
		throw FullGraph();
	} else {	
		edgeTemp = new EdgeNodeType<VertexType>;
		edgeTemp->vertex = toVertex;
		edgeTemp->weight = weight;
		edgeTemp->edge = nullptr;
		if (prevEdge == nullptr)
			temp->edge = edgeTemp;
		else
			prevEdge->edge = edgeTemp;
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
	return true;
}

template <class VertexType>
bool GraphType<VertexType>::IsFull() const {
	return true;
}

template <class VertexType>
void GraphType<VertexType>::ClearMarks() {
	HeadNodeType<VertexType>* temp = topVertex_;
	while (temp != nullptr) {
		temp->mark = 0;
		temp = temp->next;
	}
}

template <class VertexType>
void GraphType<VertexType>::MarkVertex(VertexType vertex) {
	HeadNodeType<VertexType>* temp;
	temp = IndexIs(topVertex_, vertex);
	if (temp == nullptr)
		return;
	temp->mark = 1;
}

template <class VertexType>
bool GraphType<VertexType>::IsMarked(VertexType vertex) {
	HeadNodeType<VertexType>* temp;
	temp = IndexIs(topVertex_, vertex);
	if (temp == nullptr)
		return false;
	return (temp->mark == 1);
}

template <class VertexType>
void GraphType<VertexType>::PrintEdge(VertexType vertex) {
	HeadNodeType<VertexType>* temp = topVertex_;
	EdgeNodeType<VertexType>* edgeTemp;
	while(!(temp->vertex == vertex)) {
		temp = temp->next;
		if (temp == nullptr)
			return;
	}
	edgeTemp = temp->edge;
	std::cout << "vertex : " << temp->vertex << " ";
	while (edgeTemp != nullptr) {
		std::cout << edgeTemp->vertex << " ";
		edgeTemp = edgeTemp->edge;
	}
	std::cout << std::endl;
}

template <class VertexType>
void GraphType<VertexType>::PrintVertex(VertexType vertex) {
	HeadNodeType<VertexType>* temp = topVertex_;
	std::cout << "vertex : : ";
	while (temp != nullptr) {
		std::cout << temp->vertex << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

