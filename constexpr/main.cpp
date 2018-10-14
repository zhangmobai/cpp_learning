#include <iostream>

using namespace std;

int f(void);
//constexpr int f(void);

int g(int x);
int g(constexpr int x);

int main (int argc, char **argv) {
	return 0;
}
