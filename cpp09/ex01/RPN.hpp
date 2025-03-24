#pragma once
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>

class RPN {
public:
    RPN();
    ~RPN();
    int evaluate(const std::string& expression);

private:
    std::stack<int> _stack;
    void performOperation(char op);
};