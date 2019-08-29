// main.cpp
// 2019-08-28
// kdj6724@naver.com
#include <iostream>

template<class ItemType>
void Merge(ItemType values[], int leftFirst, int leftLast, 
		int rightFirst, int rightLast) {
	ItemType temp[leftFirst + rightLast];
	int index = leftFirst;
	int saveFirst = leftFirst;

	while (leftFirst <= leftLast && rightFirst <= rightLast) {
		if (values[leftFirst] < values[rightFirst]) {
			temp[index] = values[leftFirst];
			leftFirst = leftFirst + 1;
		} else {
			temp[index] = values[rightFirst];
			rightFirst = rightFirst + 1;
		}
		index++;
	}
	while (leftFirst <= leftLast) {
		temp[index] = values[leftFirst];
		leftFirst++;
		index++;
	}
	while (rightFirst <= rightLast) {
		temp[index] = values[rightFirst];
		rightFirst++;
		index++;
	}
	for (index = saveFirst; index<=rightLast; index++) {
		values[index] = temp[index];
	}
}

template <class ItemType>
void MergeSort(ItemType values[], int first, int last) {
	std::cout << "(" << first << ", " << last << ")" << std::endl;
	if (first < last) {
		int middle = (first+last) / 2;
		MergeSort(values, first, middle);
		MergeSort(values, middle + 1, last);
		Merge(values, first, middle, middle + 1, last);
	}
}

int main(int argc, char* argv[]) {
	char buf[10] = {'3', '5', '6', '2', '1', '7', '8', '9', '4', '0'};
	MergeSort<char>(buf, 0, 9);
	for (int i=0; i<10; i++) {
		std::cout << buf[i] << std::endl;
	}
	return 0;
}
