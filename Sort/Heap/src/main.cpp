// main.cpp
// 2019-08-28
// kdj6724@naver.com
#include <iostream>
#include "Heap.h"

template <class ItemType>
void HeapSort(HeapType<ItemType>* heap, ItemType values[], 
		int numValues) {
	int index;

	for (index = numValues/2 - 1; index >= 0; index--)
		heap->ReheapDown(index, numValues - 1);
	for (index = numValues - 1; index >= 1; index--) {
		Swap(heap->elements[0], heap->elements[index]);
		heap->ReheapDown(0, index - 1);
	}
}

int main(int argc, char* argv[]) {
	char buf[10] = {'3', '5', '6', '2', '1', '7', '8', '9', '4', '0'};
	HeapType<char> heap;
	heap.elements = buf;
	heap.numElements = sizeof(buf);
	HeapSort<char>(&heap, 0, 9);
	for (int i=0; i<10; i++) {
		std::cout << buf[i] << std::endl;
	}
	return 0;
}
