#include <utility>

template <typename T>
class Stack
{
public:
    Stack();
    Stack(Stack &&other);
    ~Stack();

    template <typename U>
    void push(U &&value);
    T &peek();
    T pop();
    bool isEmpty() const;
    size_t size() const;
    class StackIsEmptyException
    {
    };

private:
    struct Node
    {
        T value;
        Node *next;

        Node(T &&v, Node *n);
        Node(const T &v, Node *n);
    };

    Node *top;
    size_t stackSize;
};

template <typename T>
Stack<T>::Stack(Stack &&other) : top(std::move(other.top)), stackSize(std::move(other.stackSize))
{
}

template <typename T>
Stack<T>::Stack() : top(nullptr), stackSize(0)
    {
    }


template <typename T>
Stack<T>::~Stack() 
    {
        while (!isEmpty())
            pop();
    }

template<typename T>
template<typename U>
void Stack<T>::push(U &&value)
{
    auto n = new Node(std::forward<U>(value), top);
    top = n;
    ++stackSize;
}

template<typename T>
T &Stack<T>::peek()
{
    if (!top)
        throw StackIsEmptyException();
    return top->value;
}

template<typename T>
T Stack<T>::pop()
{
    if (!top)
        throw StackIsEmptyException();
    auto value(std::move(top->value));
    auto n = top;
    top = n->next;
    delete n;
    --stackSize;
    return value;
}

template<typename T>
bool Stack<T>::isEmpty() const
{
    return !top;
}

template<typename T>
size_t Stack<T>::size() const
{
    return stackSize;
}

template<typename T>
Stack<T>::Node::Node(T &&v, Node *n) : 
    value(std::move(v)), next(n)
{
}

template<typename T>
Stack<T>::Node::Node(const T &v, Node *n) : value(v), next(n)
{
}
