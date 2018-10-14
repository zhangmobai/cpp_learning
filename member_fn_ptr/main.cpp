#include <iostream>

using namespace std;

class MyClass {
	public:
		virtual void foo(void) { }
};

int main(int argc, char **) {
	void (MyClass::*p)(void) = &MyClass::foo;
	cout << "sizeof(p) = " << sizeof(p) << endl;
	return 0;
}
