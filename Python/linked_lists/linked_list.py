import random

class LinkedListNode:
    """
    A class for a node in a doubly linked list.
    """

    def __init__(self, value, next_node=None, prev_node=None):
        """
        Initialize a LinkedListNode with the given value and optional next and previous nodes.

        Args:
            value: The value to be associated with the node.
            next_node: The next node in the linked list, defaulting to None.
            prev_node: The previous node in the linked list, defaulting to None.
        """
        self.value = value
        self.next = next_node
        self.prev = prev_node

    def __str__(self):
        """
        Return a string representation of the node's value.

        Returns:
            A string representation of the node's value.
        """
        return str(self.value)
class LinkedList:
    """
    A class representing a linked list.

    Attributes:
        head (LinkedListNode): The head node of the linked list.
        tail (LinkedListNode): The tail node of the linked list.
    """

    def __init__(self, values=None):
        """
        Initializes a new linked list.

        Args:
            values (list): A list of values to add to the linked list.
        """
        self.head = None
        self.tail = None
        if values is not None:
            self.add_multiple(values)

    def __iter__(self):
        """
        Defines an iterator for the linked list.
        """
        current = self.head
        while current:
            yield current
            current = current.next

    def __str__(self):
        """
        Returns a string representation of the linked list.
        """
        values = [str(x) for x in self]
        return " -> ".join(values)

    def __len__(self):
        """
        Returns the length of the linked list.
        """
        length = 0
        node = self.head
        while node:
            length += 1
            node = node.next
        return length

    def values(self):
        """
        Returns a list of the values in the linked list.
        """
        return [x.value for x in self]

    def add(self, value):
        """
        Adds a new node with the given value to the end of the linked list.

        Args:
            value (any): The value to add to the linked list.

        Returns:
            LinkedListNode: The new tail node of the linked list.
        """
        if self.head is None:
            self.tail = self.head = LinkedListNode(value)
        else:
            self.tail.next = LinkedListNode(value)
            self.tail = self.tail.next
        return self.tail

    def add_to_beginning(self, value):
        """
        Adds a new node with the given value to the beginning of the linked list.

        Args:
            value (any): The value to add to the linked list.

        Returns:
            LinkedListNode: The new head node of the linked list.
        """
        if self.head is None:
            self.tail = self.head = LinkedListNode(value)
        else:
            self.head = LinkedListNode(value, self.head)
        return self.head

    def add_multiple(self, values):
        """
        Adds multiple values to the end of the linked list.

        Args:
            values (list): A list of values to add to the linked list.
        """
        for v in values:
            self.add(v)

    @classmethod
    def generate(cls, k, min_value, max_value):
        """
        Generates a new linked list with k random integers between min_value and max_value, inclusive.

        Args:
            k (int): The number of integers to generate.
            min_value (int): The minimum value of the generated integers.
            max_value (int): The maximum value of the generated integers.

        Returns:
            LinkedList: A new linked list with k random integers.
        """
        return cls(random.choices(range(min_value, max_value), k=k))


class DoublyLinkedList(LinkedList):
    """Subclass of LinkedList that creates a doubly linked list"""

    def add(self, value):
        """Add a new node with the given value to the end of the doubly linked list
        
        Args:
            value: The value to be added to the linked list
            
        Returns:
            The updated linked list
        """
        # If the list is empty, set the head and tail to a new node with the given value
        if self.head is None:
            self.tail = self.head = LinkedListNode(value)
        # Otherwise, add a new node with the given value to the end of the list
        else:
            # Set the next attribute of the current tail node to a new node with the given value
            # and set the previous attribute of the new node to the current tail node
            self.tail.next = LinkedListNode(value, None, self.tail)
            # Update the tail to the new node
            self.tail = self.tail.next
        # Return the updated linked list
        return self
