
from stack import Stack

class Node():
    def __init__(self, value):
        self.minimum = None
        self.value = value

class ExtStack(Stack):
    def __init__(self):
        super().__init__()

    def push(self, value):
        if self.is_empty():
            super().push(Node(value))
            self.items[-1].minimum = self.items[-1]
        elif value <= self.items[-1].minimum.value:
            super().push(Node(value))
            self.items[-1].minimum = self.items[-1]
        else:
            super().push(Node(value))
            self.items[-1].minimum = self.items[-2].minimum

    def min(self):
        if self.is_empty():
            print("Stack is empty.")
            exit(1)
        return self.items[-1].minimum.value


if __name__ == "__main__":
    stack = ExtStack()
    for v in [5, 10, 4, 9, 3, 3, 8, 2, 2, 7, 6]:
        stack.push(v)
        print(f"Pushed value: {v}, min value: {stack.min()}")
    while not stack.is_empty():
        v = stack.pop()
        if stack.is_empty():
            print(f"Popped value: {v}, stack is empty")
        else:
            print(f"Popped value: {v}, min value: {stack.min()}")