#include <iostream>
#include <stack>

/**
 * @brief A queue implemented using two stacks
 * @tparam T the type of the elements in the queue
 */
template <typename T>
class MyQueue {
public:
    /**
     * @brief Adds an element to the back of the queue
     * @tparam U the type of the value being added
     * @param value the value to be added
     */
    template <typename U>
    void add(U &&value) {
        // Push the value onto the newValues stack
        newValues.push(std::forward<U>(value));
    }

    /**
     * @brief Returns the front element of the queue without removing it
     * 
     * If the reversed stack is empty, all the elements in the newValues stack
     * are moved to the reversed stack before the front element is returned.
     * 
     * @return the front element of the queue
     */
    T peek() {
        if (reversed.empty())
            // Move all the elements from the newValues stack to the reversed stack
            move(newValues, reversed);
        // Return the top element of the reversed stack
        return reversed.top();
    }

    /**
     * @brief Removes and returns the front element of the queue
     * 
     * If the reversed stack is empty, all the elements in the newValues stack
     * are moved to the reversed stack before the front element is removed and returned.
     * 
     * @return the front element of the queue
     */
    T remove() {
        if (reversed.empty())
            // Move all the elements from the newValues stack to the reversed stack
            move(newValues, reversed);
        // Pop and return the top element of the reversed stack
        T ret = reversed.top();
        reversed.pop();
        return ret;
    }

    /**
     * @brief Returns whether the queue is empty
     * @return true if the queue is empty, false otherwise
     */
    bool isEmpty() {
        // The queue is empty if both stacks are empty
        return newValues.empty() && reversed.empty();
    }

private:
    /**
     * @brief Moves all the elements from one stack to another
     * 
     * This method moves all the elements from the "from" stack to the "to" stack.
     * It does so by popping elements from the "from" stack and pushing them onto
     * the "to" stack until the "from" stack is empty.
     * 
     * @param from the stack to move elements from
     * @param to the stack to move elements to
     */
    static void move(std::stack<T> &from, std::stack<T> &to) {
        while (!from.empty()) {
            // Pop the top element from the "from" stack
            T elem = from.top();
            from.pop();
            // Push the popped element onto the "to" stack
            to.push(elem);
        }
    }

    std::stack<T> newValues; /**< The stack for new values */
    std::stack<T> reversed; /**< The stack for reversed values */
};


int main()
{

int main() {
    MyQueue<int> queue; // create a new queue object that holds integers

    for (int i = 0; i < 10; ++i) {
        queue.add(i); // add the integer i to the queue
        std::cout << "Queued value " << i << std::endl; // print a message to the console for each integer that is added
    }

    for (int i = 0; i < 5; ++i)
        std::cout << "Removed value " << queue.remove() << std::endl; // remove the first five integers from the queue and print a message to the console for each integer that is removed

    for (int i = 10; i < 15; ++i) {
        queue.add(i); // add the integer i to the queue
        std::cout << "Queued value " << i << std::endl; // print a message to the console for each integer that is added
    }

    while (!queue.isEmpty())
        std::cout << "Removed value " << queue.remove() << std::endl; // remove all the remaining integers from the queue and print a message to the console for each integer that is removed

    return 1; // return the value 1 to the calling process
}
}