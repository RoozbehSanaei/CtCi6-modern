# 3.4 Queue Via Stacks
import unittest
from stack import Stack

class MyQueue:
    """
    A queue data structure implemented using two stacks.
    """

    def __init__(self):
        """
        Initializes the queue with two empty stacks: new_stack and old_stack.
        """
        self.new_stack = Stack()    # create an empty stack for incoming elements
        self.old_stack = Stack()    # create an empty stack for outgoing elements

    def _shift_stacks(self):
        """
        Internal helper method that shifts elements from new_stack to old_stack,
        so that the oldest elements are always at the top of old_stack.
        """
        if self.old_stack.is_empty():   # if old_stack is empty
            while not self.new_stack.is_empty():   # while new_stack is not empty
                self.old_stack.push(self.new_stack.pop())    # pop an element from new_stack and push it to old_stack

    def add(self, value):
        """
        Adds an element to the end of the queue.

        @param value: The value to be added.
        """
        return self.new_stack.push(value)    # push the value onto new_stack

    def peek(self):
        """
        Returns the oldest element in the queue without removing it.

        @return: The oldest element in the queue, or False if the queue is empty.
        """
        if self.is_empty():    # if the queue is empty
            return False
        self._shift_stacks()    # shift elements from new_stack to old_stack
        return self.old_stack.peek()    # return the top element of old_stack

    def remove(self):
        """
        Removes and returns the oldest element in the queue.

        @return: The oldest element in the queue, or False if the queue is empty.
        """
        if self.is_empty():    # if the queue is empty
            return False
        self._shift_stacks()    # shift elements from new_stack to old_stack
        return self.old_stack.pop()    # pop and return the top element of old_stack

    def is_empty(self):
        """
        Checks if the queue is empty.

        @return: True if the queue is empty, False otherwise.
        """
        return len(self) == 0    # return True if the total length of new_stack and old_stack is 0

    def __len__(self):
        """
        Returns the number of elements in the queue.

        @return: The number of elements in the queue.
        """
        return len(self.new_stack) + len(self.old_stack)    # return the sum of the lengths of new_stack and old_stack


import unittest

class Tests(unittest.TestCase):
    # Define test cases to be used in the tests
    test_cases = [([1, 2, 3]), ([-1, 0, 1]), (["a", "b", "c", "d", "e", "f"])]

    def test_size(self):
        # Test whether add and remove methods correctly adjust the length of the queue
        for sequence in self.test_cases:
            q = MyQueue()
            for index, val in enumerate(sequence, start=1):
                q.add(val)
                # Assert that length of queue is the same as the number of elements added
                assert len(q) == index
            for index, val in enumerate(sequence, start=1):
                q.remove()
                # Assert that length of queue is the original length minus the number of elements removed
                assert len(q) == len(sequence) - index

    def test_add(self):
        # Test whether add method adds elements to the queue and that peek method returns first element
        for sequence in self.test_cases:
            q = MyQueue()
            for val in sequence:
                q.add(val)
            # Assert that the first element in the queue is the same as the first element in the sequence
            assert q.peek() == sequence[0]
            # Assert that the length of the queue is the same as the length of the sequence
            assert len(q) == len(sequence)

    def test_shift_stacks(self):
        # Test whether the MyQueue class correctly shifts elements from the new_stack to the old_stack when necessary
        for sequence in self.test_cases:
            q = MyQueue()
            for val in sequence:
                q.add(val)
            # Assert that the new_stack is empty
            assert len(q.old_stack) == 0
            # Assert that the new_stack is the same length as the sequence
            assert len(q.new_stack) == len(sequence)
            # Assert that the top element in the new_stack is the last element in the sequence
            assert q.new_stack.peek() == sequence[-1]
            q._shift_stacks()
            # Assert that the old_stack is the same length as the sequence
            assert len(q.old_stack) == len(sequence)
            # Assert that the new_stack is now empty
            assert len(q.new_stack) == 0
            # Assert that the top element in the old_stack is the first element in the sequence
            assert q.old_stack.peek() == sequence[0]

    def test_peek(self):
        # Test whether peek method returns the first element in the queue and updates its value correctly
        for sequence in self.test_cases:
            q = MyQueue()
            for val in sequence:
                q.add(val)
                # Assert that the first element in the queue is the same as the first element in the sequence
                assert q.peek() == sequence[0]
            q.remove()
            # Assert that the first element in the queue is now the second element in the sequence
            assert q.peek() == sequence[1]

    def test_remove(self):
        # Test whether remove method correctly removes and returns elements from the queue in the correct order
        for sequence in self.test_cases:
            q = MyQueue()
            for val in sequence:
                q.add(val)
            for i in range(len(sequence)):
                # Assert that the removed element is the same as the current element in the sequence
                assert q.remove() == sequence[i]

    def test_peek_simple(self):
        # Test the functionality of the peek method with a simple queue
        q = MyQueue()
        q.add(4)
        q.add(6)
        # Assert that the first element in the queue is the first element that was added
        assert q.peek() == 4

    def test_add_simple(self):
        # Test the functionality of the add method with a simple queue
        q = MyQueue()
        q.add(4)
        q.add(6)
        # Assert that the first element in the queue is the first element that was added
        assert q.peek() == 4
        q.add(101)
        # Assert that the first element in the queue is still the first element that was added
        assert q.peek() != 101

    def test_remove_simple(self):
        # Test the functionality of the remove method with a simple queue
        q = MyQueue()
        q.add(4)
        q.add(6)
        # Assert that the length of the queue is 2
        assert len(q) == 2
        # Assert that the removed element is the first element that was added
        assert q.remove() == 4
        # Assert that the removed element is the second element that was added
        assert q.remove() == 6
        # Assert that the length of the queue is now 0
        assert len(q) == 0
        # Assert that trying to remove an element from the queue returns None
        assert not q.remove()

if __name__ == '__main__':
    unittest.main()
