#include <iostream>

using namespace std;

class A {
	public:
		int getX() const noexcept {
			return x;
		}
		int z;
		class AN {
			public:
				void bar() {
					cout << z;
				}
		};
	protected:
		int y;
	private:
		int x;
};

class B: public A {
	public:
#if 0
		int getXX() const noexcept {
			return x; // error
		}
#endif
		int getYY() const noexcept {
			return y;
		}

#if 0
		void getYYY(const A &a) noexcept {
			cout << a.y; // error
		}
#endif
};

class C: public B {
	public:
		int getZZ() const noexcept {
			return y;
		}
};

class D: private A {
};

void foo(A &a) {
}

int main (int argc, char **argv) {
	A a;
	cout << a.z;
	//cout << a.y; // error
	//cout << a.x; // error
	B b;
	cout << b.z;
	//cout << b.y;
	
	D d;
	(void)d;
	foo(a);
	foo(b);
	// foo(d); // error
	return 0;
}
