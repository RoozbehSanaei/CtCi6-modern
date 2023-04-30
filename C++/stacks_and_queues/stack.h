#include <utility>
#include <iostream>

/**
 * @brief A template class for a Stack data structure, implemented as a linked list.
 * 
 * @tparam T The type of elements the Stack can store.
 */
template <typename T>
class Stack
{
public:
    /**
     * @brief Constructs an empty Stack object.
     */
    Stack();
    
    /**
     * @brief Move constructor for Stack.
     * 
     * @param other The Stack object to move from.
     */
    Stack(Stack &&other);
    
    /**
     * @brief Destroys the Stack object and deallocates memory used by its nodes.
     */
    ~Stack();

    /**
     * @brief Pushes a new element onto the top of the stack.
     * 
     * @tparam U The type of the value to push onto the stack.
     * @param value The value to push onto the stack.
     */
    template <typename U>
    void push(U &&value);

    /**
     * @brief Returns a reference to the top element of the stack.
     * 
     * @return T& Reference to the top element of the stack.
     */
    T &peek();

    /**
     * @brief Removes and returns the top element of the stack.
     * 
     * @return T The top element of the stack.
     * @throws StackIsEmptyException If the stack is empty.
     */
    T pop();

    /**
     * @brief Checks if the stack is empty.
     * 
     * @return true If the stack is empty.
     * @return false If the stack is not empty.
     */
    bool isEmpty() const;

    /**
     * @brief Returns the number of elements currently stored in the stack.
     * 
     * @return size_t The number of elements in the stack.
     */
    size_t size() const;

    /**
     * @brief Exception class thrown when trying to pop an element from an empty stack.
     */
    class StackIsEmptyException
    {
    };

private:
    /**
     * @brief A struct representing a node in the linked list that makes up the stack.
     * 
     */
    struct Node
    {
        T value;    ///< The value stored in the node.
        Node *next; ///< A pointer to the next node in the stack.

        /**
         * @brief Constructs a new Node object.
         * 
         * @param v The value to store in the node.
         * @param n A pointer to the next node in the stack.
         */
        Node(T &&v, Node *n);

        /**
         * @brief Constructs a new Node object.
         * 
         * @param v The value to store in the node.
         * @param n A pointer to the next node in the stack.
         */
        Node(const T &v, Node *n);
    };

    Node *top;          ///< A pointer to the top node of the stack.
    size_t stackSize;   ///< The number of elements currently stored in the stack.
};

/**
 * @brief A stack data structure with the capability to keep track of the minimum value.
 * 
 * This class uses two stacks to maintain its functionality. The first stack holds the actual data elements, 
 * while the second stack is used to keep track of the minimum element in the stack at any given point in time.
 * 
 * @tparam T The type of the elements stored in the stack.
 */


/**
 * @brief Move constructor for the Stack class.
 * 
 * @tparam T The type of elements stored in the stack.
 * @param other The Stack object to move from.
 */
template <typename T>
Stack<T>::Stack(Stack &&other) : top(std::move(other.top)), stackSize(std::move(other.stackSize))
{
    // Move the top node and size from the other stack to this one.
}

/**
 * @brief Default constructor for the Stack class.
 * 
 * @tparam T The type of elements stored in the stack.
 */
template <typename T>
Stack<T>::Stack() : top(nullptr), stackSize(0)
{
    // Initialize an empty stack with null top pointer and size of zero.
}


/**
 * @brief Destructor function that deallocates all elements in the Stack.
 *
 * This function repeatedly calls the pop() function until the Stack becomes empty, deallocating memory
 * for each element that is removed. This ensures that there are no memory leaks when a Stack object is
 * destroyed or goes out of scope.
 *
 * @tparam T The type of data stored in the Stack.
 */
template <typename T>
Stack<T>::~Stack() 
{
    while (!isEmpty()) // continue until Stack is empty
    {
        pop(); // remove top element and deallocate memory
    }
}


/**
 * @brief Pushes a new element of type U onto the top of the stack.
 *
 * This function creates a new Node with the specified value and sets it as the new top of the stack.
 * The type of the value being pushed onto the stack is deduced at the call site, and perfect forwarding
 * is used to ensure that the value is properly forwarded to the constructor of the new Node.
 *
 * @tparam U The type of the value being pushed onto the stack.
 * @param value The value to be pushed onto the stack.
 */
template<typename T>
template<typename U>
void Stack<T>::push(U &&value)
{
    auto n = new Node(std::forward<U>(value), top); // create a new Node with the specified value and set it as the new top
    top = n; // update the top of the stack to point to the newly created Node
    ++stackSize; // increment the size of the stack
}


/**
 * @brief Returns a reference to the value at the top of the stack, without modifying the stack.
 * 
 * @tparam T The type of element stored in the stack.
 * @throws StackIsEmptyException if the stack is empty.
 * @return T& A reference to the value at the top of the stack.
 */
template<typename T>
T &Stack<T>::peek()
{
    // Check if the top of the stack is null, indicating an empty stack
    if (!top)
        throw StackIsEmptyException();
    
    // Return a reference to the value at the top of the stack
    return top->value;
}


/**
 * @brief Removes and returns the value at the top of the stack.
 * 
 * @tparam T The type of element stored in the stack.
 * @throws StackIsEmptyException if the stack is empty.
 * @return T The value at the top of the stack.
 */
template<typename T>
T Stack<T>::pop()
{
    // Check if the top of the stack is null, indicating an empty stack
    if (!top)
        throw StackIsEmptyException();

    // Move the value at the top of the stack to a new variable
    auto value(std::move(top->value));

    // Update the top of the stack to point to the next node
    auto n = top;
    top = n->next;

    // Free the memory for the old top node
    delete n;

    // Update the stack size
    --stackSize;

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
bool Stack<T>::isEmpty() const
{
    // Check if the top of the stack is null, indicating an empty stack
    return !top;
}

/**
 * @brief Returns the number of elements in the stack.
 * 
 * @tparam T The type of element stored in the stack.
 * @return size_t The number of elements in the stack.
 */
template<typename T>
size_t Stack<T>::size() const
{
    // Return the size of the stack
    return stackSize;
}


/**
 * @brief Constructor for a Node in the Stack.
 * 
 * @tparam T The type of element stored in the node.
 * @param v The value to be stored in the node.
 * @param n A pointer to the next node in the stack.
 */
template<typename T>
Stack<T>::Node::Node(T &&v, Node *n) : 
    value(std::move(v)), next(n)
{
    // This constructor simply initializes the value and next members
    // using the provided arguments. The value member is initialized
    // using std::move to move the value into the node, which can
    // improve performance in some cases.
}

/**
 * @brief Constructor for a Node in the Stack.
 * 
 * @tparam T The type of element stored in the node.
 * @param v The value to be stored in the node.
 * @param n A pointer to the next node in the stack.
 */
template<typename T>
Stack<T>::Node::Node(const T &v, Node *n) : value(v), next(n)
{
    // This constructor simply initializes the value and next members
    // using the provided arguments. The value member is initialized
    // using a copy of the provided value.
}


