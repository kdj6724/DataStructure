// main.cpp
// 2019-08-28
// kdj6724@naver.com
#include <iostream>
#include "PQType.h"

int main(int argc, char* argv[]) {
	PQType<char> queue(10);
	char tmp = 0;
	queue.Enqueue('4');
	queue.Enqueue('1');
	queue.Enqueue('2');
	queue.Enqueue('3');
	queue.Enqueue('5');
	queue.Enqueue('6');
	queue.Enqueue('7');
	queue.Enqueue('8');
	queue.Enqueue('9');
	queue.Enqueue('0');
	
	for (int i=0; i<10; i++) {
		queue.Dequeue(tmp);
		std::cout << tmp << std::endl; 
	}
	return 0;
}
