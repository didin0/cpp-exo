#include <iostream>
#include <exception>

template <typename T>
class Array {
private:
    T* _data;
    unsigned int _size;

public:
    // Default Constructor: Creates an empty array
    Array() : _data(nullptr), _size(0) {}

    // Constructor with size parameter
    Array(unsigned int n) : _size(n) {
        _data = new T[n]();  // Default initializes elements
    }

    // Copy Constructor (Deep Copy)
    Array(const Array& other) : _size(other._size) {
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
            _data[i] = other._data[i];
        }
    }

    // Assignment Operator (Deep Copy)
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _data;  // Free existing memory

            _size = other._size;
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _data[i] = other._data[i];
            }
        }
        return *this;
    }

    // Destructor
    ~Array() {
        delete[] _data;
    }

    // Overloaded [] operator (with bounds checking)
    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _data[index];
    }

    // Overloaded [] operator for const objects
    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _data[index];
    }

    // Size function (returns number of elements)
    unsigned int size() const {
        return _size;
    }
};

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}