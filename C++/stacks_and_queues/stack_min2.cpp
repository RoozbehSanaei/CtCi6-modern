#include "stack.h"

template<typename T>
class ExtStack : public Stack<T> {
public:
    struct Node : public Stack<T>::Node {
        Node* minimum;
        Node *next;
        Node(const T& v, Node* n = nullptr) : Stack<T>::Node(v, n), minimum(nullptr) {}
        Node(T&& v, Node* n = nullptr) : Stack<T>::Node(std::move(v), n), minimum(nullptr) {}
    };

    Node *top;    
    template <typename U>
    void push(U &&value);
    int min() const;
};

template<typename T>
template <typename U>
void ExtStack<T>::push(U &&value) 
{
    if(this->isEmpty())
    {
        this->top = new Node(std::forward<U>(value));
        this->top->minimum = this->top;
    }
    else if(value <= this->top->minimum->value)
    {
        this->top = new Node(std::forward<U>(value), this->top);
        this->top->minimum = this->top;
    }
    else
    {
        this->top = new Node(std::forward<U>(value), this->top);
        this->top->minimum = this->top->next->minimum;
    }

    this->stackSize++;
}

template<typename T>
int ExtStack<T>::min() const
{
    if(this->isEmpty())
    {
        std::cout << "Stack is empty." << std::endl;
        exit(1);
    }
    return (this->top->minimum->value);
}

int main()
{
    ExtStack<int> stack;
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
