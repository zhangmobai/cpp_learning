#include <iostream>
#include <functional>

using namespace std;

int foo(void) {
	return 0;
}

int main (int argc, char **argv) {
	function<int(void)> f = foo;
	function<int(void)> g = []() { return 1; };
	function<int(void)> h;

	int y = 2;
	function<int(void)> i = [&]() { return y++; };
	cout << "sizeof(f) == " << sizeof(f) << endl;
	cout << "sizeof(g) == " << sizeof(g) << endl;
	cout << "sizeof(h) == " << sizeof(h) << endl;
	cout << "sizeof(i) == " << sizeof(i) << endl;
	return 0;
}
