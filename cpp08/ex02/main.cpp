#include <iostream>
#include <stack>
#include "MutantStack.hpp"

void compareStacks(MutantStack<int>& mstack, std::stack<int>& sstack) {
    if (mstack.size() != sstack.size()) {
        std::cout << "Stacks have different sizes!" << std::endl;
        return;
    }

    MutantStack<int>::iterator mit = mstack.begin();
    std::stack<int> tempStack;
    while (!sstack.empty()) {
        tempStack.push(sstack.top());
        sstack.pop();
    }

    while (mit != mstack.end()) {
        if (*mit != tempStack.top()) {
            std::cout << "Stacks have different elements!" << std::endl;
            return;
        }
        ++mit;
        tempStack.pop();
    }

    std::cout << "Stacks are identical!" << std::endl;
}

int main()
{
    MutantStack<int> mstack;
    std::stack<int> sstack;

    mstack.push(5);
    sstack.push(5);
    mstack.push(17);
    sstack.push(17);
    std::cout << "MutantStack top: " << mstack.top() << std::endl;
    std::cout << "std::stack top: " << sstack.top() << std::endl;
    mstack.pop();
    sstack.pop();
    std::cout << "MutantStack size: " << mstack.size() << std::endl;
    std::cout << "std::stack size: " << sstack.size() << std::endl;
    mstack.push(3);
    sstack.push(3);
    mstack.push(5);
    sstack.push(5);
    mstack.push(737);
    sstack.push(737);
    mstack.push(0);
    sstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    compareStacks(mstack, sstack);

    return 0;
}