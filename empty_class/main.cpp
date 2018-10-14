#include <iostream>

using namespace std;

class A {
};

class B: public A {
	int x;
};

class C {
	public:
		virtual ~C() noexcept {}
};

class D : public C {
	public:
		//void abc() noexcept {}
	private:
		uint32_t y;
};

int main (int argc, char **argv) {
	cout << "sizeof(A) : " << sizeof(A) << endl;
	cout << "sizeof(B) : " << sizeof(B) << endl;
	cout << "sizeof(C) : " << sizeof(C) << endl;
	cout << "sizeof(D) : " << sizeof(D) << endl;
	return 0;
}
