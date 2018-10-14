#include <iostream>

using namespace std;

void f(void);
// error
void f(void) noexcept;


void g();
void g() noexcept(false); // okay

// not okay since y isn't const
void h();
//bool y = false;
//void h() noexcept(y);

const bool z = false;
void i();
void i() noexcept(z);

int main (int argc, char **argv) {
	return 0;
}
