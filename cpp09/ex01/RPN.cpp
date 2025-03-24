#include "RPN.hpp"
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <climits>

RPN::RPN() {}

RPN::~RPN() {}

int RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        bool is_number = true;
        for (size_t i = 0; i < token.size(); ++i) {
            if (!std::isdigit(token[i])) {
                is_number = false;
                break;
            }
        }

        if (is_number) {
            char* endptr;
            long value = std::strtol(token.c_str(), &endptr, 10);
            if (*endptr != '\0' || value > INT_MAX || value < INT_MIN) {
                throw std::runtime_error("Error: invalid number or out of range");
            }
            _stack.push(static_cast<int>(value));
        } else if (token.size() == 1 && std::strchr("+-*/", token[0])) {
            if (_stack.size() < 2) {
                throw std::runtime_error("Error: insufficient operands");
            }
            performOperation(token[0]);
        } else {
            throw std::runtime_error("Error: invalid token");
        }
    }

    if (_stack.size() != 1) {
        throw std::runtime_error("Error: invalid expression");
    }

    return _stack.top();
}

void RPN::performOperation(char op) {
    int b = _stack.top(); _stack.pop();
    int a = _stack.top(); _stack.pop();
    long result; // Use long to check for overflow

    switch (op) {
        case '+':
            result = static_cast<long>(a) + static_cast<long>(b);
            if (result > INT_MAX || result < INT_MIN) {
                throw std::runtime_error("Error: result overflow or underflow");
            }
            break;
        case '-':
            result = static_cast<long>(a) - static_cast<long>(b);
            if (result > INT_MAX || result < INT_MIN) {
                throw std::runtime_error("Error: result overflow or underflow");
            }
            break;
        case '*':
            result = static_cast<long>(a) * static_cast<long>(b);
            if (result > INT_MAX || result < INT_MIN) {
                throw std::runtime_error("Error: result overflow or underflow");
            }
            break;
        case '/': 
            if (b == 0) {
                throw std::runtime_error("Error: division by zero");
            }
            result = static_cast<long>(a) / static_cast<long>(b);
            if (result > INT_MAX || result < INT_MIN) {
                throw std::runtime_error("Error: result overflow or underflow");
            }
            break;
        default:
            throw std::runtime_error("Error: unknown operator");
    }

    _stack.push(static_cast<int>(result));
}