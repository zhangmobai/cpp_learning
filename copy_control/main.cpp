#include <iostream>
#include <vector>
#include <string>

using namespace std;

unsigned int n_default_constructor = 0;
unsigned int n_copy_constructor = 0;
unsigned int n_move_constructor = 0;
unsigned int n_assignment_operator = 0;
unsigned int n_move_assignment_operator = 0;
unsigned int n_destructor = 0;
unsigned int _id = 0;

class MyClass {
public:
	MyClass() : id (++_id) {
		cout << id << " default constructor " << ++n_default_constructor << endl;
	}
	MyClass(const MyClass &m) noexcept {
		id = m.id;
		cout << id << " copy constructor " << ++n_copy_constructor << endl;
	}
	MyClass(const MyClass &&m) noexcept {
		id = m.id;
		cout << id << " move constructor " << ++n_move_constructor << endl;
	}
	MyClass &operator=(const MyClass &m) {
		id = m.id;
		cout << id << " assignment operator " << ++n_assignment_operator << endl;
		return *this;
	}
	MyClass &operator=(const MyClass &&m) {
		id = m.id;
		cout << id << " move assignment operator " << ++n_move_assignment_operator << endl;
		return *this;
	}
	~MyClass() {
		cout << id << " destructor " << ++n_destructor << endl;
	}

	unsigned int id{0};
};

int main(int argc, char **argv) {
#if 0
	MyClass m1;
	MyClass m2 = move(m1);
	(void)m2;
	m2 = move(m1);

	cout << "LINE: " << __LINE__ << endl;
#endif
	vector<MyClass> v(3);
	cout << "v capacity " << v.capacity() << endl;

	for (int i = 0; i != 1; ++i) {
		v.push_back(MyClass());
		cout << "v capacity " << v.capacity() << endl;
		cout << "size: " << v.size() << endl;
	}

	return 0;
}
