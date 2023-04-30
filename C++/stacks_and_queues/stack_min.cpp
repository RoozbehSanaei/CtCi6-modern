// StackMin: How would you design a stack which, in addition to push and pop, has a function min
// which returns the minimum element? Push, pop and min should all operate in O(1) time.

#include <iostream>
#include "stack.h"


template<typename T>
class StackMin
{
public:
    /**
     * @brief Pushes the given value onto the stack.
     * 
     * The value can be of any type U that is convertible to the template type T.
     * 
     * @tparam U The type of the value being pushed onto the stack.
     * @param value The value to be pushed onto the stack.
     */
    template<typename U>
    void push(U &&value);

    /**
     * @brief Returns a reference to the top element of the stack without removing it.
     * 
     * @return A reference to the top element of the stack.
     */
    T &peek();

    /**
     * @brief Returns a reference to the minimum element of the stack without removing it.
     * 
     * @return A reference to the minimum element of the stack.
     */
    T &min();

    /**
     * @brief Removes and returns the top element of the stack.
     * 
     * @return The top element of the stack.
     */
    T pop();

    /**
     * @brief Returns a boolean value indicating whether the stack is empty or not.
     * 
     * @return True if the stack is empty, false otherwise.
     */
    bool isEmpty();

private:
    Stack<T> stack; /**< The main stack that holds the actual data elements. */
    Stack<T> minStack; /**< The stack that keeps track of the minimum element in the stack. */
};



/**
 * @brief Inserts an element at the top of the stack.
 * 
 * @tparam T The type of element stored in the stack.
 * @tparam U The type of element to be pushed onto the stack.
 * @param value The value to be pushed onto the stack.
 */
template<typename T>
template<typename U>
void StackMin<T>::push(U &&value)
{
    // If the minStack is empty or the value is less than or equal
    // to the current minimum, push the value onto the minStack.
    if (minStack.isEmpty() || value <= minStack.peek())
        minStack.push(value);
    
    // Push the value onto the main stack.
    stack.push(std::forward<U>(value));
}


/**
 * @brief Returns a reference to the value at the top of the stack, without modifying the stack.
 * 
 * @tparam T The type of element stored in the stack.
 * @return T& A reference to the value at the top of the stack.
 */
template<typename T>
T& StackMin<T>::peek()
{
    // Return a reference to the value at the top of the main stack.
    return stack.peek();
}

/**
 * @brief Returns a reference to the minimum value in the stack, without modifying the stack.
 * 
 * @tparam T The type of element stored in the stack.
 * @return T& A reference to the minimum value in the stack.
 * @throws StackIsEmptyException if the stack is empty.
 */
template<typename T>
T& StackMin<T>::min()
{
    // Return a reference to the value at the top of the minStack
    return minStack.peek();
}

/**
 * @brief Removes and returns the value at the top of the stack.
 * 
 * @tparam T The type of element stored in the stack.
 * @return T The value at the top of the stack.
 * @throws StackIsEmptyException if the stack is empty.
 */
template<typename T>
T StackMin<T>::pop()
{
    // Pop the value from the main stack
    auto value = stack.pop();
    
    // If the popped value is equal to the current minimum,
    // pop the value from the minStack as well.
    if (value == min())
        minStack.pop();

    // Return the value that was removed from the stack
    return value;
}

/**
 * @brief Returns whether the stack is empty.
 * 
 * @tparam T The type of element stored in the stack.
 * @return true if the stack is empty, false otherwise.
 */
template<typename T>
bool StackMin<T>::isEmpty()
{
    // Return whether the main stack is empty
    return stack.isEmpty();
}

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