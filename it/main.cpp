#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (int argc, char **argv) {
	vector<int> v { 9,8,7,6,5,4,3,2,1 };
	sort(v.begin(), v.end());

	for (auto i : v) {
		cout << i <<  " ";
	}

	cout << endl;

	return 0;
}
