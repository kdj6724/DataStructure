// Heap.h
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

