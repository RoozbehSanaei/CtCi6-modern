import random

# Define a class for a node in the linked list
class LinkedListNode:
    def __init__(self, value, next_node=None, prev_node=None):
        # Set the value associated with the node
        self.value = value
        # Set the next node in the linked list, defaulting to None
        self.next = next_node
        # Set the previous node in the linked list, defaulting to None
        self.prev = prev_node

    def __str__(self):
        # Return a string representation of the node's value
        return str(self.value)

# Define a class for the linked list
class LinkedList:
    def __init__(self, values=None):
        # Set the head and tail of the linked list to None
        self.head = None
        self.tail = None
        # If values are provided, add them to the linked list
        if values is not None:
            self.add_multiple(values)

    def __iter__(self):
        # Define an iterator for the linked list
        current = self.head
        while current:
            yield current
            current = current.next

    def __str__(self):
        # Return a string representation of the linked list
        values = [str(x) for x in self]
        return " -> ".join(values)

    def __len__(self):
        # Return the length of the linked list
        length = 0
        node = self.head
        while node:
            length += 1
            node = node.next
        return length

    def values(self):
        # Return a list of the values in the linked list
        return [x.value for x in self]

    def add(self, value):
        # Add a new node with the given value to the end of the linked list
        if self.head is None:
            self.tail = self.head = LinkedListNode(value)
        else:
            self.tail.next = LinkedListNode(value)
            self.tail = self.tail.next
        return self.tail

    def add_to_beginning(self, value):
        # Add a new node with the given value to the beginning of the linked list
        if self.head is None:
            self.tail = self.head = LinkedListNode(value)
        else:
            self.head = LinkedListNode(value, self.head)
        return self.head

    def add_multiple(self, values):
        # Add multiple values to the end of the linked list
        for v in values:
            self.add(v)

    @classmethod
    def generate(cls, k, min_value, max_value):
        # Generate a new linked list with k random integers between min_value and max_value, inclusive
        return cls(random.choices(range(min_value, max_value), k=k))

# Define a subclass of LinkedList to create a doubly linked list
class DoublyLinkedList(LinkedList):
    def add(self, value):
        # Add a new node with the given value to the end of the doubly linked list
        if self.head is None:
            self.tail = self.head = LinkedListNode(value)
        else:
            self.tail.next = LinkedListNode(value, None, self.tail)
            self.tail = self.tail.next
        return self
