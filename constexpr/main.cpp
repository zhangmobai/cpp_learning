#include <iostream>
#include <vector>

using namespace std;

int f(void);
//constexpr int f(void);

class foo {
public:
	constexpr foo() noexcept = default;
	constexpr foo(int xx) noexcept : x{xx} {}

#if 0
	foo(foo &&f) noexcept: x{f.x} {
		cout << "move" << endl;
	}

	foo(const foo &f) : x{f.x} {
		cout << "copy" << endl;
	}
#endif

	foo(foo &&f) noexcept = default;


	int x{0};
};

#if 0
namespace std {

template<>
struct is_trivially_move_constructible<foo> : public integral_constant<bool, true> {
};

}

#endif

int main (int argc, char **argv) {
	foo f;
	constexpr foo ff(2);
	int xx = 10;
	foo fff(xx);

	cout << "is_trivially_move_constructible<foo> = " << std::boolalpha << is_trivially_move_constructible<foo>::value << endl;

	vector<foo> v;
	for (auto i = 0; i != 3; ++i) {
		cout << "capacity = " << v.capacity() << endl;
		v.push_back(foo(0));
	}
	return 0;
}
