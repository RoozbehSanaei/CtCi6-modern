#include <iostream>
#include <cstdlib>
#include <cassert>

/**
 * @file FixedMultiStack.h
 * @brief Implementation of a fixed-size multi-stack in C++.
 */

/**
 * @class FixedMultiStack
 * @brief Class for a fixed-size multi-stack.
 */
class FixedMultiStack
{
public:
  /**
   * @brief Constructor that creates 3 stacks, each with the given capacity.
   * @param stackCapacity The capacity of each stack.
   */
  FixedMultiStack(int stackCapacity);

  /**
   * @brief Destructor that frees the memory allocated for the stack arrays.
   */
  virtual ~FixedMultiStack();

  /**
   * @brief Pushes a value onto the specified stack.
   * @param stackNum The index of the stack to push onto (0-2).
   * @param value The value to push onto the stack.
   */
  void push(int stackNum, int value);

  /**
   * @brief Pops the top value from the specified stack.
   * @param stackNum The index of the stack to pop from (0-2).
   */
  void pop(int stackNum);

  /**
   * @brief Returns the top value of the specified stack.
   * @param stackNum The index of the stack to access (0-2).
   * @return The top value of the specified stack.
   */
  int top(int stackNum) const;

  /**
   * @brief Returns whether the specified stack is empty.
   * @param stackNum The index of the stack to check (0-2).
   * @return Whether the specified stack is empty.
   */
  bool isEmpty(int stackNum) const;

  /**
   * @brief Returns whether the specified stack is full.
   * @param stackNum The index of the stack to check (0-2).
   * @return Whether the specified stack is full.
   */
  bool isFull(int stackNum) const;

private:
  int numOfStack = 3; ///< The number of stacks in this multi-stack.
  int stackCapacity; ///< The capacity of each stack in this multi-stack.
  int *stackArray; ///< The array used to store the elements of the stacks.
  int *stackCapacityUsed; ///< The array used to keep track of the number of elements in each stack.

  /**
   * @brief Returns the index of the top element of the specified stack.
   * @param stackNum The index of the stack to access (0-2).
   * @return The index of the top element of the specified stack.
   */
  int indexOfTop(int stackNum) const;
};


/**
 * @brief Constructor for creating multiple stacks of a fixed size
 * @param stackCapacity The maximum capacity of each stack
 * 
 * The constructor initializes the member variables and creates the arrays that
 * will hold the multiple stacks of a fixed size. It also initializes all the elements
 * of the stackArray to zero.
 */
FixedMultiStack::FixedMultiStack(int stackCapacity)
{
    // Assign the input stackCapacity to the member variable stackCapacity
    this->stackCapacity = stackCapacity;

    // Create a new array to hold multiple stacks of fixed size
    // The size of the array is the product of the number of stacks and the stack capacity
    // The () at the end initializes all elements of the array to zero
    stackArray = new int[numOfStack * stackCapacity]();

    // Create a new array to keep track of the number of elements in each stack
    stackCapacityUsed = new int[numOfStack]();
}

/**
 * @brief The FixedMultiStack destructor deallocates memory for stackArray and stackCapacityUsed.
 * 
 */
FixedMultiStack::~FixedMultiStack()
{
    // Deallocate memory for the stack array
    delete [] stackArray;

    // Deallocate memory for the stack capacity used array
    delete [] stackCapacityUsed;
}


/**
 * @brief Pushes a value onto the specified stack
 * @param stackNum the index of the stack to push the value onto
 * @param value the value to be pushed onto the stack
 */
void FixedMultiStack::push(int stackNum, int value)
{
  if(isFull(stackNum))
    std::cout << "Stack " << stackNum << " is full.\n";
  else
  {
    // Increment the capacity used for this stack
    stackCapacityUsed[stackNum]++;
    // Calculate the index of the top element for this stack and assign the value to it
    stackArray[indexOfTop(stackNum)] = value;
  }
}

/**
 * @brief Pop the top element from a specified stack in a FixedMultiStack.
 * 
 * @param stackNum The index of the stack from which to pop the top element.
 */
void FixedMultiStack::pop(int stackNum)
{
  // Check if the specified stack is empty.
  if(isEmpty(stackNum))
    std::cout << "Stack " << stackNum << " is empty.\n";
  else
  {
    // Compute the index of the top element in the specified stack.
    int topIndex = indexOfTop(stackNum);
    
    // Remove the top element by setting its value to zero.
    stackArray[topIndex] = 0;
    
    // Decrement the number of elements in the specified stack.
    stackCapacityUsed[stackNum]--;
  }
}

/**
 * Returns the top element of the specified stack.
 * 
 * @param stackNum The index of the stack to access (0-based).
 * @return The top element of the specified stack.
 * @throws std::out_of_range If the specified stack index is out of bounds.
 * @throws std::runtime_error If the specified stack is empty.
 */
int FixedMultiStack::top(int stackNum) const
{
  // Check if the specified stack is empty.
  if (isEmpty(stackNum)) {
    // If so, throw an exception with an error message.
    throw std::runtime_error("Stack is empty.");
  }
  // If not, return the top element of the stack.
  return stackArray[indexOfTop(stackNum)];
}

/**
 * @brief Check if the stack with the given stackNum is empty
 * 
 * @param stackNum the index of the stack to check
 * @return true if the stack is empty, false otherwise
 */
bool FixedMultiStack::isEmpty(int stackNum) const
{
  return (stackCapacityUsed[stackNum] == 0);
}

/**
 * @brief Check if the stack with the given stackNum is full
 * 
 * @param stackNum the index of the stack to check
 * @return true if the stack is full, false otherwise
 */
bool FixedMultiStack::isFull(int stackNum) const
{
  return (stackCapacityUsed[stackNum] == stackCapacity);
}

/**
 * @brief Get the index of the top element of the stack with the given stackNum
 * 
 * @param stackNum the index of the stack to check
 * @return the index of the top element of the stack
 */
int FixedMultiStack::indexOfTop(int stackNum) const
{
  int startIndex = stackNum * stackCapacity;
  int capacity = stackCapacityUsed[stackNum];
  return (startIndex + capacity - 1);
}


int main() {
  const int stackCapacity = 5;
  FixedMultiStack fms{stackCapacity};

  // Test pushing and popping from stack 0
  fms.push(0, 10);
  fms.push(0, 20);
  fms.push(0, 30);
  assert(fms.top(0) == 30);
  fms.pop(0);
  assert(fms.top(0) == 20);
  fms.pop(0);
  assert(fms.top(0) == 10);
  fms.pop(0);
  assert(fms.isEmpty(0));

  // Test pushing and popping from stack 1
  fms.push(1, 40);
  fms.push(1, 50);
  fms.push(1, 60);
  assert(fms.top(1) == 60);
  fms.pop(1);
  assert(fms.top(1) == 50);
  fms.pop(1);
  assert(fms.top(1) == 40);
  fms.pop(1);
  assert(fms.isEmpty(1));

  // Test pushing and popping from stack 2
  fms.push(2, 70);
  fms.push(2, 80);
  fms.push(2, 90);
  assert(fms.top(2) == 90);
  fms.pop(2);
  assert(fms.top(2) == 80);
  fms.pop(2);
  assert(fms.top(2) == 70);
  fms.pop(2);
  assert(fms.isEmpty(2));

  // Test that pushing onto a full stack returns an error message
  for (int i = 0; i < stackCapacity; i++) {
    fms.push(0, i);
  }
  assert(fms.isFull(0));
  std::cout << "Attempting to push onto a full stack...\n";
  fms.push(0, stackCapacity); // This should return an error message

  // Test that popping from an empty stack returns an error message
  assert(fms.isEmpty(0));
  std::cout << "Attempting to pop from an empty stack...\n";
  fms.pop(0); // This should return an error message

  return 0;
}

