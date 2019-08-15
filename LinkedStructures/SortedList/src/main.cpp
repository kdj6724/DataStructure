 // main.cpp
 // kdj6724@naver.com
 // 2019-07-13

#include <iostream>
#include <fstream>
#include <string>
#include "SortedType.h"

void GetData(std::ifstream& dataFile, std::string& item) {
	int val;
	getline(dataFile, item);
}

void PrintList(std::ofstream& dataFile, 
		SortedType<std::string> list) {
	int length;
	std::string item;
	list.ResetList();
	length = list.LengthIs();
	printf("len : %d\n", length);
	for (int counter = 1; counter <= length; counter++) {
		list.GetNextItem(item);
		std::cout << "item : " << item << std::endl;
		dataFile << item << std::endl;
	}
}

void CreateListFromFile(std::ifstream& dataFile, 
		SortedType<std::string>& list) {
	std::string item;
	GetData(dataFile, item);
	while (dataFile) {
		if (!list.IsFull())
			list.InsertItem(item);
		GetData(dataFile, item);
	}
}

int main(void) {
	std::ifstream input("input.txt");
	std::ofstream output("output.txt");
	SortedType<std::string> list;
	if (input.fail()) {
		std::cout << "file open error" << std::endl;
		return -1;
	}
	CreateListFromFile(input, list);

	PrintList(output, list);
	
	return 0;
}
