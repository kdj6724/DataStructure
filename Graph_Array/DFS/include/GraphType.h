// GraphType.h
// 2019-08-26
// kdj6724@naver.com
#include "QueType.h"
#include "StackType.h"

const int MAX_VERTEX = 50;
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
	int IndexIs(VertexType* vertices, VertexType vertex);
	int numVertices_;
	int maxVertices_;
	VertexType vertices_[MAX_VERTEX];
	int edges_[MAX_VERTEX][MAX_VERTEX];
	bool marks_[MAX_VERTEX];
};

template <class VertexType>
GraphType<VertexType>::GraphType() {
	numVertices_ = 0;
	maxVertices_ = MAX_VERTEX;
}

template <class VertexType>
GraphType<VertexType>::~GraphType() {
}

const int NULL_EDGE = 0;
template <class VertexType>
void GraphType<VertexType>::AddVertex(VertexType vertex) {
	vertices_[numVertices_] = vertex;
	for (int index=0; index<numVertices_; index++) {
		edges_[numVertices_][index] = NULL_EDGE;
		edges_[index][numVertices_] = NULL_EDGE;
	}
	numVertices_++;
}

template <class VertexType>
int GraphType<VertexType>::IndexIs(VertexType* vertices, VertexType vertex) {
	int index = 0;
	while (!(vertex == vertices_[index]))
		index++;
	return index;
}

template <class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex, 
		VertexType toVertex, int weight) {
	int row;
	int col;
	row = IndexIs(vertices_, fromVertex);
	col = IndexIs(vertices_, toVertex);
	edges_[row][col] = weight;
}

template <class VertexType>
int GraphType<VertexType>::WeightIs(VertexType fromVertex, 
		VertexType toVertex) {
	int row;
	int col;
	row = IndexIs(vertices_, fromVertex);
	col = IndexIs(vertices_, toVertex);
	return edges_[row][col];
}

template <class VertexType>
void GraphType<VertexType>::GetToVertices(VertexType vertex,
		QueType<VertexType>& adjVertices) {
	int fromIndex;
	int toIndex;
	fromIndex = IndexIs(vertices_, vertex);
	for (toIndex = 0; toIndex < numVertices_; toIndex++) {
		if (edges_[fromIndex][toIndex] != NULL_EDGE)
			adjVertices.Enqueue(vertices_[toIndex]);
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
	memset(marks_, 0, maxVertices_);
}

template <class VertexType>
void GraphType<VertexType>::MarkVertex(VertexType vertex) {
	int index;
	index = IndexIs(vertices_, vertex);
	marks_[index] = 1;
}

template <class VertexType>
bool GraphType<VertexType>::IsMarked(VertexType vertex) {
	int index;
	index = IndexIs(vertices_, vertex);
	return (marks_[index] == 1);
}

