#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <stdint.h>

struct Data {
	int n;
};

class Serializer {
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
private:
    // Canonical form
    Serializer() {}
    ~Serializer() {}
    Serializer(const Serializer &copy);
    Serializer& operator=(const Serializer &assign);
};

#endif

