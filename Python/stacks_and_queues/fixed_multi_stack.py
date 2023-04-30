import pytest

class MultiStack:
    """
    A class representing a multi-stack data structure, consisting of multiple
    stacks stored in a single array.
    """
    def __init__(self, stack_size: int, number_of_stacks: int) -> None:
        """
        Initializes a new MultiStack object with the specified parameters.

        :param stack_size: an integer representing the maximum size of each stack
        :param number_of_stacks: an integer representing the total number of stacks
        """
        self.number_of_stacks = number_of_stacks  # store number of stacks
        self.array = [[] for _ in range(number_of_stacks)]  # initialize an empty list for each stack
        self.sizes = [0] * self.number_of_stacks
        self.stack_size = stack_size  # store the maximum size of each stack


    def push(self, value: int, stack_num: int) -> None:
        """
        Pushes the given value onto the specified stack.

        :param value: The value to be pushed onto the stack.
        :param stack_num: The number of the stack onto which the value is to be pushed.
        :raises StackFullError: If the specified stack is already full.
        """
        self._assert_valid_stack_num(stack_num)
        if self.is_full(stack_num):
            raise StackFullError(f"Push failed: stack #{stack_num} is full")
        # Append the value to the appropriate stack in the array
        self.array[stack_num].append(value)
        # Increment the size of the stack
        self.sizes[stack_num] += 1

    def pop(self, stack_num: int) -> int:
        """
        Pops the top element from the specified stack and returns it.
        
        @param stack_num: the stack number to pop from (0, 1, or 2)
        @return the popped value
        @throws StackEmptyError if the specified stack is empty
        """
        self._assert_valid_stack_num(stack_num)  # validate stack_num is within range
        if self.is_empty(stack_num):
            raise StackEmptyError(f"Cannot pop from empty stack #{stack_num}")
        return self.array[stack_num].pop()  # pop the top element from the specified stack and return it


    def peek(self, stack_num: int) -> int:
        """
        Returns the top element of the specified stack without removing it.
        
        @param stack_num: the stack number to peek at (0, 1, or 2)
        @return the top element of the specified stack
        @throws StackEmptyError if the specified stack is empty
        """
        self._assert_valid_stack_num(stack_num)  # validate stack_num is within range
        if self.is_empty(stack_num):
            raise StackEmptyError(f"Cannot peek at empty stack #{stack_num}")
        return self.array[stack_num][-1]  # return the top element of the specified stack

    def is_empty(self, stack_num: int) -> bool:
        """
        Returns True if the specified stack is empty, False otherwise.
        
        @param stack_num: the stack number to check (0, 1, or 2)
        @return True if the specified stack is empty, False otherwise
        """
        self._assert_valid_stack_num(stack_num)  # validate stack_num is within range
        return len(self.array[stack_num]) == 0  # check if the specified stack is empty and return the result


    def is_full(self, stack_num: int) -> bool:
        """
        Returns True if the specified stack is full, False otherwise.
        
        @param stack_num: the stack number to check (0, 1, or 2)
        @return True if the specified stack is full, False otherwise
        """
        self._assert_valid_stack_num(stack_num)  # validate stack_num is within range
        return len(self.array[stack_num]) == self.stack_size  # check if the specified stack is full and return the result

    def _assert_valid_stack_num(self, stack_num: int) -> None:
        """
        Helper method that raises an exception if the given stack number is invalid.
        
        @param stack_num: the stack number to check (0 to number_of_stacks-1)
        @throws StackDoesNotExistError if the specified stack does not exist
        """
        if stack_num >= self.number_of_stacks:  # check if stack_num is out of range
            raise StackDoesNotExistError(f"Stack #{stack_num} does not exist")  # raise an exception if stack_num is invalid


class MultiStackError(Exception):
    """multistack operation error"""


class StackFullError(MultiStackError):
    """the stack is full"""


class StackEmptyError(MultiStackError):
    """the stack is empty"""


class StackDoesNotExistError(ValueError):
    """stack does not exist"""


def test_multistack():
    num_stacks = 3
    stack_size = 6
    s = MultiStack(stack_size=stack_size, number_of_stacks=num_stacks)

    for stack_num in range(num_stacks):
        assert s.is_empty(stack_num)
        assert not s.is_full(stack_num)
        with pytest.raises(StackEmptyError):
            s.pop(stack_num)

        for i in range(stack_size - 1):
            s.push(i, stack_num=stack_num)
            assert s.peek(stack_num) == i
            assert not s.is_empty(stack_num)
            assert not s.is_full(stack_num)

        s.push(999, stack_num=stack_num)
        with pytest.raises(StackFullError):
            s.push(777, stack_num=stack_num)

        assert not s.is_empty(stack_num)
        assert s.is_full(stack_num)

        assert s.peek(stack_num) == 999
        assert s.pop(stack_num) == 999
        assert not s.is_empty(stack_num)
        assert not s.is_full(stack_num)

        for i in range(stack_size - 2, 0, -1):
            assert s.peek(stack_num) == i
            assert s.pop(stack_num) == i
            assert not s.is_empty(stack_num)
            assert not s.is_full(stack_num)

        assert s.peek(stack_num) == 0
        assert s.pop(stack_num) == 0
        assert s.is_empty(stack_num)
        assert not s.is_full(stack_num)

        with pytest.raises(StackEmptyError):
            s.peek(stack_num)
        with pytest.raises(StackEmptyError):
            s.pop(stack_num)


def test_stack_does_not_exist():
    s = MultiStack(stack_size=3, number_of_stacks=1)
    with pytest.raises(StackDoesNotExistError):
        s.push(1, 1)


if __name__ == "__main__":
    newstack = MultiStack(2, 2)
    print(newstack.is_empty(1))
    newstack.push(3, 1)
    print(newstack.peek(1))
    print(newstack.is_empty(1))
    newstack.push(2, 1)
    print(newstack.peek(1))
    print(newstack.pop(1))
    print(newstack.peek(1))
    newstack.push(3, 1)