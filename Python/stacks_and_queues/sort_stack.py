# 3.5 Sort Stacks
import unittest
from stack import Stack

class SortedStack(Stack):
    """
    A stack data structure that maintains its items in sorted order, with the smallest item at the top of the stack.
    """

    def __init__(self):
        """
        Initializes an empty SortedStack object and creates a temporary stack object to help with sorting.
        """
        super().__init__()
        self.temp_stack = Stack()

    def push(self, item):
        """
        Pushes an item onto the stack while maintaining the sorted order.
        
        If the new item is smaller than or equal to the current top item of the stack, it is simply pushed onto the stack.
        If the new item is larger than the current top item, it is pushed onto the stack in sorted order.
        
        Args:
            item: The item to be pushed onto the stack.
        """
        if self.is_empty() or item < self.peek():
            super().push(item)
        else:
            # Move items from the original stack to the temporary stack until a larger item than the new item is found.
            while self.peek() is not None and item > self.peek():
                self.temp_stack.push(self.pop())
                
            # Push the new item onto the original stack in sorted order.
            super().push(item)
            
            # Move the items from the temporary stack back onto the original stack in their original order.
            while not self.temp_stack.is_empty():
                super().push(self.temp_stack.pop())



class Tests(unittest.TestCase):
    """
    A collection of unit tests for the SortedStack class.
    """

    def test_push_one(self):
        """
        Tests pushing a single item onto the stack.
        """
        queue = SortedStack()
        queue.push(1)
        assert len(queue) == 1

    def test_push_two(self):
        """
        Tests pushing two items onto the stack.
        """
        queue = SortedStack()
        queue.push(1)
        queue.push(2)
        assert len(queue) == 2

    def test_push_three(self):
        """
        Tests pushing three items onto the stack.
        """
        queue = SortedStack()
        queue.push(1)
        queue.push(2)
        queue.push(3)
        assert len(queue) == 3

    def test_pop_one(self):
        """
        Tests popping a single item from the stack.
        """
        queue = SortedStack()
        queue.push(1)
        assert queue.pop() == 1

    def test_pop_two(self):
        """
        Tests popping two items from the stack.
        """
        queue = SortedStack()
        queue.push(1)
        queue.push(2)
        assert queue.pop() == 1
        assert queue.pop() == 2

    def test_pop_three(self):
        """
        Tests popping three items from the stack.
        """
        queue = SortedStack()
        queue.push(1)
        queue.push(2)
        queue.push(3)
        assert queue.pop() == 1
        assert queue.pop() == 2
        assert queue.pop() == 3

    def test_push_mixed(self):
        """
        Tests pushing a mix of sorted and unsorted items onto the stack.
        """
        queue = SortedStack()
        queue.push(3)
        queue.push(2)
        queue.push(1)
        queue.push(4)
        assert queue.pop() == 1
        assert queue.pop() == 2
        assert queue.pop() == 3
        assert queue.pop() == 4
        
if __name__ == '__main__':
    # Create a TestSuite object and add all the tests from the Tests class
    suite = unittest.TestSuite()
    suite.addTest(unittest.makeSuite(Tests))

    # Run the tests and print the results
    runner = unittest.TextTestRunner()
    result = runner.run(suite)
    print(result)
