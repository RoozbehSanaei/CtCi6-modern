
#include <iostream>
#include <cstdlib>


/**
 * @brief A single node in the stack.
 */
class StackNode
{
public:
  /**
   * @brief Constructor.
   * 
   * @param data The value to be stored in the node.
   * @param next A pointer to the next node in the stack.
   */
  StackNode(int data, StackNode *next);

private:
  int data; /**< The value stored in the node. */
  StackNode *next; /**< A pointer to the next node in the stack. */
  StackNode *minimum; /**< A pointer to the node that has the minimum value until this node. */

  friend class Stack; /**< Declare Stack as a friend class so it can access private members. */
};

/**
 * @brief A stack data structure.
 */
class Stack
{
public:
  /**
   * @brief Constructor.
   */
  Stack();

  /**
   * @brief Destructor.
   */
  virtual ~Stack();

  /**
   * @brief Adds an item to the top of the stack.
   * 
   * @param item The value to be added.
   */
  void push(int item);

  /**
   * @brief Removes the item from the top of the stack.
   */
  void pop();

  /**
   * @brief Returns the value of the item at the top of the stack.
   * 
   * @return The value at the top of the stack.
   */
  int top() const;

  /**
   * @brief Returns the minimum value of the stack at the moment.
   * 
   * @return The minimum value of the stack.
   */
  int getMinimum() const;

  /**
   * @brief Returns true if the stack is empty, false otherwise.
   * 
   * @return Whether the stack is empty.
   */
  bool isEmpty() const;

  /**
   * @brief Returns the number of items in the stack.
   * 
   * @return The size of the stack.
   */
  int getSize() const;
  
private:
  StackNode *head; /**< A pointer to the top node in the stack. */
  int stackSize; /**< The current size of the stack. */
};

/**
 * @file stack.cpp
 * @brief Implements a stack data structure with a minimum element tracker.
 */


/**
 * @brief Constructs a new StackNode object.
 * @param data The value to store in the node.
 * @param next A pointer to the next node in the stack.
 */
StackNode::StackNode(int data, StackNode *next)
{
  this->data = data;
  this->next = next;
  minimum = nullptr;
}

/**
 * @brief Constructs a new Stack object.
 */
Stack::Stack()
{
  head = nullptr;
  stackSize = 0;
}

/**
 * @brief Destroys the Stack object and frees any memory it occupied.
 */
Stack::~Stack()
{
  StackNode *discard;
  while(head != nullptr)
  {
    discard = head;
    head = head->next;
    delete discard;
  }
}
/**
 * @brief Adds a new item to the top of the stack
 * @param item The integer to add to the stack
 *
 * If the stack is empty, a new StackNode is created with the minimum value set to itself.
 * If the new item is smaller or equal to the current minimum value of the stack, a new StackNode is created with the minimum value set to itself.
 * Otherwise, a new StackNode is created with the minimum value set to the current minimum value of the stack.
 */
void Stack::push(int item)
{
  if(isEmpty()) // if stack is empty, create new node with minimum set to itself
  {
    head = new StackNode(item, nullptr);
    head->minimum = head;
  }
  else if(item <= head->minimum->data) // if new item is smaller than or equal to current minimum, create new node with minimum set to itself
  {
    head = new StackNode(item, head);
    head->minimum = head;
  }
  else // create new node with minimum set to current minimum
  {
    head = new StackNode(item, head);
    head->minimum = head->next->minimum;
  }

  stackSize++; // increment stack size
}

/**
 * @brief Removes the top item from the stack
 *
 * If the stack is empty or the head node is null, this function does nothing.
 */
void Stack::pop()
{
  if(stackSize == 0 || head == nullptr) // if stack is empty or head node is null, do nothing
    return;

  StackNode *discard = head; // save pointer to top node
  head = head->next; // move head to next node
  delete discard; // delete saved node
  stackSize--; // decrement stack size
}

/**
 * @brief Returns the top element of the stack without removing it.
 * 
 * @return The top element of the stack.
 * 
 * If the stack is empty, an error message is printed to the console
 * and the program exits with an error code of 1.
 */
int Stack::top() const
{
  // Check if the stack is empty
  if(stackSize == 0 || head == nullptr)
  {
    std::cout << "Stack is empty.\n";
    exit(1); // Exit the program with an error code
  }
  // Return the top element of the stack
  return head->data;
}

/**
 * Returns the minimum element in the stack.
 *
 * @return The minimum element in the stack.
 * @throw std::runtime_error If the stack is empty.
 */
int Stack::getMinimum() const
{
  // Throw an exception if the stack is empty
  if (stackSize == 0 || head == nullptr)
  {
    throw std::runtime_error("Stack is empty.");
  }

  // Return the minimum element
  return (head->minimum->data);
}



/**
 * Checks whether the stack is empty.
 *
 * @return True if the stack is empty, false otherwise.
 */
bool Stack::isEmpty() const
{
  // The stack is empty if its size is zero or if its head pointer is null
  return (stackSize == 0 || head == nullptr);
}

/**
 * Returns the current size of the stack.
 *
 * @return The size of the stack.
 */
int Stack::getSize() const
{
  // The size of the stack is stored in the stackSize member variable
  return stackSize;
}


int main() {
  // Create a new Stack object
  Stack myStack;

  // Push several integers onto the stack
  std::cout << "Pushing 5, 3, 7, 2, 8 onto stack\n";
  myStack.push(5);
  myStack.push(3);
  myStack.push(7);
  myStack.push(2);
  myStack.push(8);

  // Print the minimum and top values of the stack
  std::cout << "Minimum value in stack: " << myStack.getMinimum() << "\n";
  std::cout << "Top value in stack: " << myStack.top() << "\n";

  // Pop the top element off the stack
  std::cout << "Popping top value from stack\n";
  myStack.pop();

  // Print the new minimum and top values of the stack
  std::cout << "Minimum value in stack: " << myStack.getMinimum() << "\n";
  std::cout << "Top value in stack: " << myStack.top() << "\n";

  // Push another value onto the stack
  std::cout << "Pushing -1 onto stack\n";
  myStack.push(-1);

  // Print the new minimum and top values of the stack
  std::cout << "Minimum value in stack: " << myStack.getMinimum() << "\n";
  std::cout << "Top value in stack: " << myStack.top() << "\n";

  // Pop all the elements off the stack
  std::cout << "Popping all values from stack\n";
  while(!myStack.isEmpty()) {
    std::cout << "Popped value: " << myStack.top() << "\n";
    myStack.pop();
  }

  // Print the final size of the stack
  std::cout << "Stack size: " << myStack.getSize() << "\n";

  return 0;
}
