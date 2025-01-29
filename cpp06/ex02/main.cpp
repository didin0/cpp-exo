#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>


class Base {
	public:
		virtual ~Base(){}
};

class A : public Base {
};

class B : public Base {
};

class C : public Base {
};

Base * generate() {
	int random = std::rand() % 3;
	switch (random) {
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	default:
		return NULL;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "pointer: " << "Class identified as A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "pointer: " << "Class identified as B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "pointer: " << "Class identified as C" << std::endl;
	} else {
		std::cout << "Unknow class" << std::endl;
	}
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "reference: " << "Class identified as A" << std::endl;
		return;
		(void)a;
	} catch (std::exception& e) {}
	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "reference: " << "Class identified as B" << std::endl;
		return;
		(void)b;
	} catch (std::exception& e) {}
	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "reference: " << "Class identified as C" << std::endl;
		return;
		(void)c;
	} catch (std::exception& e) {}
	std::cout << "Unknown class" << std::endl;
}

int main() {
std::srand(static_cast<unsigned int>(time(0)));	
	Base* randomClass = generate();
	identify(randomClass);
	identify(*randomClass);

	return 0;
}
