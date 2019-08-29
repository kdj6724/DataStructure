// PQType.h
// 2019-08-28
// kdj6724@naver.com

template <class ItemType>
struct HeapType {
	void ReheapDown(int root, int bottom);
	void ReheapUp(int root, int bottom);
	ItemType* elements;
	int numElements;
};

template <class ItemType>
inline void Swap(ItemType& item1, ItemType& item2) {
  ItemType tempItem;
  tempItem = item1;
  item1 = item2;
  item2 = tempItem;
}

template <class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom) {
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = root*2 + 1;
	rightChild = root*2 + 2;
	if (leftChild <= bottom) {
		if (leftChild == bottom) {
			maxChild = leftChild;
		} else {
			if (elements[leftChild] <= elements[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		if (elements[root] < elements[maxChild]) {
			Swap(elements[root], elements[maxChild]);
			ReheapDown(maxChild, bottom);
		}
	}
}

template <class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom) {
	int parent;
	if (bottom > root) {
		parent = (bottom - 1) / 2;
		if (elements[parent] < elements[bottom]) {
			Swap(elements[parent], elements[bottom]);
			ReheapUp(root, parent);
		}
	}
}

class FullPQ {
};
class EmptyPQ {
};

template <class ItemType>
class PQType {
public:
	PQType(int max);
	~PQType();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(ItemType item);
	void Dequeue(ItemType& item);
private:
	int length_;
	HeapType<ItemType> items_;
	int maxItems_;
};

template <class ItemType>
PQType<ItemType>::PQType(int max) {
	maxItems_ = max;
	items_.elements = new ItemType[max];
	length_ = 0;
}

template <class ItemType>
PQType<ItemType>::~PQType() {
	delete [] items_.elements;
}

template <class ItemType>
void PQType<ItemType>::MakeEmpty() {
	length_ = 0;
}

template <class ItemType>
bool PQType<ItemType>::IsEmpty() const {
	return (length_ == 0);
}

template <class ItemType>
bool PQType<ItemType>::IsFull() const {
	return (length_ == maxItems_);
}

template <class ItemType>
void PQType<ItemType>::Enqueue(ItemType item) {
	if (length_ == maxItems_)
		throw FullPQ();
	else {
		length_++;
		items_.elements[length_ - 1] = item;
		items_.ReheapUp(0, length_ - 1);
	}
}

template <class ItemType>
void PQType<ItemType>::Dequeue(ItemType& item) {
	if (length_ == 0) {
		throw EmptyPQ();
	} else {
		item = items_.elements[0];
		items_.elements[0] = items_.elements[length_ - 1];
		length_--;
		items_.ReheapDown(0, length_-1);
	}
}
