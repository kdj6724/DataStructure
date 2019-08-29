// main.cpp
// 2019-08-28
// kdj6724@naver.com
#include <iostream>

template <class ItemType>
struct HeapType {
	void ReheapDown(int root, int bottom);
	void ReheapUp(int root, int bottom);
	ItemType* elements;
	int numElements;
};

template <class ItemType>


int main(int argc, char* argv[]) {
	char buf[10] = {'3', '5', '6', '2', '1', '7', '8', '9', '4', '0'};
	MergeSort<char>(buf, 0, 9);
	for (int i=0; i<10; i++) {
		std::cout << buf[i] << std::endl;
	}
	return 0;
}
