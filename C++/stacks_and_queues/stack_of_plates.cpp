#include <iostream>
#include "stack.h"

/**
 * @brief A stack of stacks with a limited capacity for each individual stack.
 * 
 * @tparam T The type of the elements stored in the stacks.
 * @tparam Capacity The maximum capacity of each individual stack in the set.
 */
template <typename T, size_t Capacity>
class SetOfStacks
{
public:
    /**
     * @brief Adds a new element to the top of the stack.
     * 
     * @tparam U The type of the element being pushed onto the stack.
     * @param value The value of the element being pushed onto the stack.
     */
    template<typename U>
    void push(U &&value)
    {
        // If the current stack is empty or at capacity, start a new stack.
        if (stacks.isEmpty() || stacks.peek().size() >= Capacity)
            stacks.push(Stack<T>()); // start new stack
        // Push the value onto the top stack.
        stacks.peek().push(std::forward<U>(value));
    }

    /**
     * @brief Returns a reference to the top element of the top stack.
     * 
     * @return T& A reference to the top element of the top stack.
     */
    T &peek()
    {
        return stacks.peek().peek();
    }

    /**
     * @brief Removes and returns the top element of the top stack.
     * 
     * @return T The value of the top element of the top stack.
     */
    T pop()
    {
        T value = stacks.peek().pop();
        // If the top stack is now empty, remove it.
        if (stacks.peek().isEmpty())
            stacks.pop();
        return value;
    }

    /**
     * @brief Returns the number of limited stacks.
     * 
     * @return size_t The number of limited stacks.
     */
    size_t size() const
    {
        return stacks.size();
    }

private:
    // A stack of stacks.
    Stack<Stack<T>> stacks;
};

/**
 * @brief If Capacity is 1 we do not need stack of stacks.
 * 
 * @tparam T The type of the elements stored in the stacks.
 */
template <typename T>
class SetOfStacks<T, 1> : public Stack<T>
{
};

/**
 * @brief Forbid Capacity 0.
 * 
 * @tparam T The type of the elements stored in the stacks.
 */
template <typename T>
class SetOfStacks<T, 0>
{
public:
    /**
     * @brief Disallow construction of SetOfStacks with Capacity 0.
     */
    SetOfStacks() = delete;
};


/**
 * @brief The main function of the program.
 * @return 0 if the program runs successfully.
 */
int main()
{
    // Create a SetOfStacks with a capacity of 2 elements per stack.
    SetOfStacks<int, 2> stack;

    // Push 11 elements onto the stack and print a message for each element.
    for (int i = 0; i < 11; ++i)
    {
        stack.push(i);
        std::cout << i << " is pushed into the stack " << stack.size() << std::endl;
    }

    std::cout << std::endl;

    // Pop elements from the stack and print a message for each popped element and stack number.
    while (stack.size() != 0)
    {
        size_t stackNo = stack.size();
        std::cout << stack.pop() << " is popped from the stack " << stackNo << std::endl;
    }

    std::cout << std::endl;

    // Create a SetOfStacks with a capacity of 1 element per stack.
    SetOfStacks<int, 1> stack1;

    // Push 11 elements onto the stack and print a message for each element.
    for (int i = 0; i < 11; ++i)
    {
        stack1.push(i);
        std::cout << i << " is pushed into the stack " << stack1.size() << std::endl;
    }

    std::cout << std::endl;

    // Pop elements from the stack and print a message for each popped element and stack number.
    while (!stack1.isEmpty())
    {
        size_t stackNo = stack1.size();
        std::cout << stack1.pop() << " is popped from the stack " << stackNo << std::endl;
    }

    return 0;
}