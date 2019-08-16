// Factorial.cpp
// 2019-08-15
// kdj6724@naver.com
#include <iostream>
#include <cstdio>

using namespace std;
int Factorial(int number) {
	if (number == 0)
		return 1;
	else
		return number * Factorial(number - 1);
}

int main(int argc, char* argv[]) {
	int res;

	if (argc == 2)
		res = Factorial(atoi(argv[1]));	
	cout << "res : " << res << endl;	
	return 0;
}
