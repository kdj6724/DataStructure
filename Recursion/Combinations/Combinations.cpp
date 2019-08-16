// Combinations.cpp
// 2019-08-16
// kdj6724@naver.com
#include <iostream>

int Combinations(int group, int members) {
	if (members == 1)
		return group;
	else if (members == group)
		return 1;
	else if (members > group)
		return 0;
	else
		return (Combinations(group-1, members-1) +
				Combinations(group-1, members));
}

int main(int argc, char* argv[]) {
	using namespace std;
	if (argc < 3)
		return -1;
	cout << "Number of combinations = " <<
			Combinations(atoi(argv[1]), atoi(argv[2])) << endl;
	return 0;
}

