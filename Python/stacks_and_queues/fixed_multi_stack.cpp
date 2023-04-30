#include <iostream>
#include <cstdlib>
#include <cassert>

class FixedMultiStack
{
public:
  //Create 3 stacks, each stack is of size stackCapacity.
  FixedMultiStack(int stackCapacity);
  virtual ~FixedMultiStack();

  //Push an element onto stack stackNum, where stackNum is from 0 to 2.
  void push(int stackNum, int value);

  //Pop the top element from stack stackNum, where stackNum is from 0 to 2.
  void pop(int stackNum);

  //Return the top element on stack stackNum, where stackNum is from 0 to 2.
  int top(int stackNum) const;

  bool isEmpty(int stackNum) const;
  bool isFull(int stackNum) const;

private:
  int numOfStack = 3;
  int stackCapacity;
  int *stackArray;
  int *stackCapacityUsed;

  //Return the top index of stack stackNum, where stackNum is from 0 to 2.
  int indexOfTop(int stackNum) const;
};


FixedMultiStack::FixedMultiStack(int stackCapacity)
{
  this->stackCapacity = stackCapacity;
  stackArray = new int[numOfStack * stackCapacity]();
  stackCapacityUsed = new int[numOfStack]();
}

FixedMultiStack::~FixedMultiStack()
{
  delete [] stackArray;
  delete [] stackCapacityUsed;
}

void FixedMultiStack::push(int stackNum, int value)
{
  if(isFull(stackNum))
    std::cout << "Stack " << stackNum << " is full.\n";
  else
  {
    stackCapacityUsed[stackNum]++;
    stackArray[indexOfTop(stackNum)] = value;
  }
}

void FixedMultiStack::pop(int stackNum)
{
  if(isEmpty(stackNum))
    std::cout << "Stack " << stackNum << " is empty.\n";
  else
  {
    int topIndex = indexOfTop(stackNum);
    stackArray[topIndex] = 0;
    stackCapacityUsed[stackNum]--;
  }
}

int FixedMultiStack::top(int stackNum) const
{
  if(isEmpty(stackNum))
  {
    std::cout << "Stack " << stackNum << " is empty.\n";
    exit(1); //Or throw an exception.
  }
  else
    return stackArray[indexOfTop(stackNum)];
}

bool FixedMultiStack::isEmpty(int stackNum) const
{
  return (stackCapacityUsed[stackNum] == 0);
}

bool FixedMultiStack::isFull(int stackNum) const
{
  return (stackCapacityUsed[stackNum] == stackCapacity);
}

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
