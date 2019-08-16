// ValueInList.cpp
// 2019-08-16
// kdj6724@naver.com
#include <iostream>

struct ListType {
	int length;
	int info[10];
};

bool ValueInList(ListType list, int value, int startIndex) {
	if (list.info[startIndex] == value)
		return true;
	else if (startIndex == list.length-1)
		return false;
	else
		return ValueInList(list, value, startIndex + 1);
};

int main(int argc, char* argv[]) {
	using namespace std;
	ListType list;
	if (argc < 2)
		return -1;
	list.length = 10;
	for (int i=0; i<10; i++)
		list.info[i] = i;
	if (ValueInList(list, atoi(argv[1]), 0))	
		cout << "found" << endl;
	else
		cout << "can not found" << endl;

	return 0;
}
