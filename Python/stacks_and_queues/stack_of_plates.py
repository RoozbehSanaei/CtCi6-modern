import unittest


class Node:
    """
    This class represents a node in a data structure.

    Attributes:
        value: The value stored in the node.
        above: A reference to the node above this node, if any.
        below: A reference to the node below this node, if any.
    """

    def __init__(self, value):
        """
        Initializes a new instance of the Node class.

        Args:
            value: The value to be stored in the node.
        """
        self.value = value
        self.above = None
        self.below = None


class Stack:
    """
    A class that represents a stack data structure.

    Attributes:
        capacity (int): The maximum number of elements the stack can hold.
        size (int): The current number of elements in the stack.
        top (Any): A reference to the top element of the stack.
        bottom (Any): A reference to the bottom element of the stack.
    """

    def __init__(self, capacity):
        """
        Initializes a new instance of the Stack class.

        Args:
            capacity (int): The maximum number of elements the stack can hold.
        """
        self.capacity = capacity
        self.size = 0
        self.top = None
        self.bottom = None

    def is_full(self):
        """
        Determines whether the stack is full.

        Returns:
            bool: True if the stack is full, False otherwise.
        """
        return self.size == self.capacity

    def is_empty(self):
        """
        Determines whether the stack is empty.

        Returns:
            bool: True if the stack is empty, False otherwise.
        """
        return self.size == 0
    

    def join(self, above, below):
        """
        Connects two elements in the stack.

        Args:
            above (Any): The element above the current element.
            below (Any): The element below the current element.
        """
        if below:
            below.above = above
        if above:
            above.below = below

def push(self, v):
    """
    Adds a new element to the top of the stack.

    Args:
        v (Any): The value of the element to be added.

    Returns:
        bool: True if the push operation was successful, False otherwise.
    """
    # Check if the stack is already full
    if self.size >= self.capacity:
        return False
    
    # Increase the size of the stack
    self.size += 1
    
    # Create a new Node object to represent the new element
    n = Node(v)
    
    # If the stack was previously empty, set the bottom element to the new element
    if self.size == 1:
        self.bottom = n
    
    # Connect the new element to the current top of the stack
    self.join(n, self.top)
    
    # Set the new element as the top of the stack
    self.top = n
    
    # Return True to indicate that the push operation was successful
    return True


def pop(self):
    """
    Removes and returns the top element of the stack.

    Returns:
        Any: The value of the popped element, or None if the stack is empty.
    """
    # Check if the stack is empty
    if not self.top:
        return None
    
    # Store a reference to the current top element
    t = self.top
    
    # Update the top element to reference the element below it
    self.top = self.top.below
    
    # Decrease the size of the stack
    self.size -= 1
    
    # Return the value of the popped element
    return t.value

def remove_bottom(self):
    """
    Removes and returns the bottom element of the stack.

    Returns:
        Any: The value of the removed element, or None if the stack is empty.
    """
    # Check if the stack is empty
    if not self.bottom:
        return None
    
    # Store a reference to the current bottom element
    b = self.bottom
    
    # Update the bottom element to reference the element above it
    self.bottom = self.bottom.above
    
    # If the new bottom element is not None, set its below attribute to None
    if self.bottom:
        self.bottom.below = None
    
    # Decrease the size of the stack
    self.size -= 1
    
    # Return the value of the removed element
    return b.value



class SetOfStacks:
    """
    A class representing a stack data structure with a fixed capacity.

    Attributes:
        capacity (int): The maximum number of elements that can be stored in the stack.
        stacks (list): The list where stack elements will be stored.
    """

    def __init__(self, capacity):
        """
        Initializes a new instance of the Stack class.

        Args:
            capacity (int): The maximum number of elements that can be stored in the stack.
        """
        self.capacity = capacity
        self.stacks = []  # Initialize an empty list to store the stack elements.


    def get_last_stack(self):
        """
        Returns the last stack in the list of stacks.

        Returns:
            The last stack in the list, or None if the list is empty.
        """
        if not self.stacks:
            return None
        return self.stacks[-1]  # Return the last element of the list
    
    def is_empty(self):
        """
        Checks whether the stack is empty.

        Returns:
            True if the stack is empty, False otherwise.
        """
        last = self.get_last_stack()
        return not last or last.is_empty()  # Return True if last is None or if last.is_empty() is True


    def push(self, v):
        """
        Adds a new element to the stack. If the last stack is full, creates a new stack with the same capacity.

        Args:
            v: The new element to add to the stack.
        """
        last = self.get_last_stack()
        if last and not last.is_full():
            # If the last stack exists and is not full, add the new element to that stack.
            last.push(v)
        else:
            # If the last stack does not exist or is full, create a new stack and add the new element to that stack.
            stack = Stack(self.capacity)
            stack.push(v)
            self.stacks.append(stack)  # Add the new stack to the list of stacks


    def pop(self):
        """
        Removes and returns the last element from the stack.

        Returns:
            The last element from the stack, or None if the stack is empty.
        """
        last = self.get_last_stack()
        if not last:
            return None  # Return None if the last stack does not exist
        v = last.pop()  # Remove the last element from the last stack and store it in v
        if last.size == 0:
            del self.stacks[-1]  # If the last stack is now empty, remove it from the list of stacks
        return v  # Return the removed element

    def pop_at(self, index):
        """
        Removes and returns the last element from a specific sub-stack in the list of stacks.

        Args:
            index (int): The index of the sub-stack to remove the element from.

        Returns:
            The last element from the sub-stack, or None if the sub-stack is empty or the index is out of range.
        """
        return self.left_shift(index, True)


    def left_shift(self, index, remove_top):
        """
        Shifts elements to the left in the list of stacks after an element is removed from a sub-stack.

        Args:
            index (int): The index of the sub-stack where the element was removed from.
            remove_top (bool): A boolean indicating whether the removed element was the top element of the sub-stack.

        Returns:
            The removed element.
        """
        # Get the sub-stack at the given index
        stack = self.stacks[index]
        # Remove the top or bottom element of the sub-stack depending on the value of remove_top,
        # and store the removed element in the removed_item variable
        removed_item = stack.pop() if remove_top else stack.remove_bottom()
        # If the sub-stack is now empty, remove it from the list of stacks
        if stack.is_empty():
            del self.stacks[index]
        # If the sub-stack is not empty and there is another sub-stack to the right of it in the list of stacks,
        # recursively call this method with the next sub-stack and a remove_top value of False,
        # and add the returned element to the end of the current sub-stack
        elif len(self.stacks) > index + 1:
            v = self.left_shift(index + 1, False)
            stack.push(v)
        # Return the removed element
        return removed_item


import unittest


class Tests(unittest.TestCase):
    """
    A class representing a collection of unit tests for the SetOfStacks class.
    """

    def test_stacks(self):
        """
        Tests the push and pop methods of the SetOfStacks class.
        """
        # Create a new SetOfStacks instance with a capacity of 5
        stacks = SetOfStacks(5)
        # Add 35 elements to the instance using the push method
        for i in range(35):
            stacks.push(i)
        # Remove all 35 elements from the instance using the pop method,
        # and store them in a list
        lst = []
        for _ in range(35):
            lst.append(stacks.pop())
        # Assert that the list of removed elements is equal to the list of integers from 0 to 34 in reverse order
        assert lst == list(reversed(range(35)))

    def test_pop_at(self):
        """
        Tests the pop_at method of the SetOfStacks class.
        """
        # Create a new SetOfStacks instance with a capacity of 5
        stacks = SetOfStacks(5)
        # Add 35 elements to the instance using the push method
        for i in range(35):
            stacks.push(i)
        # Remove the first 31 elements from the first sub-stack of the instance using the pop_at method,
        # and store them in a list
        lst = []
        for _ in range(31):
            lst.append(stacks.pop_at(0))
        # Assert that the list of removed elements is equal to the list of integers from 4 to 34
        assert lst == list(range(4, 35))



if __name__ == "__main__":
    unittest.main()