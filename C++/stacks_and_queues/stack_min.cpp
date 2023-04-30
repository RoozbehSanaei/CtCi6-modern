// StackMin: How would you design a stack which, in addition to push and pop, has a function min
// which returns the minimum element? Push, pop and min should all operate in O(1) time.

#include <iostream>
#include "stack.h"

int main()
{
    StackMin<int> stack;
    for (auto v : {5, 10, 4, 9, 3, 3, 8, 2, 2, 7, 6})
    {
        stack.push(v);
        std::cout << "Pushed value: " << v << ", min value: " << stack.min() << std::endl;
    }
    while (!stack.isEmpty())
    {
        auto v = stack.pop();
        std::cout << "Popped value: " << v;
        if (stack.isEmpty())
            std::cout << ", stack is empty" << std::endl;
        else
            std::cout << ", min value: " << stack.min() << std::endl;
    }
    return 0;
}