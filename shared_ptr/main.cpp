#include <iostream>
#include <memory>

using namespace std;

class MyClass {
};

int main(int argc, char **argv) {
	shared_ptr<MyClass> p1 = make_shared<MyClass>();

	cout << "sizeof p1: " << sizeof(p1) << endl;

	return 0;
}
