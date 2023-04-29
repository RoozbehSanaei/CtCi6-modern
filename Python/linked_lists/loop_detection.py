class Node:
    """
    A class representing a node in a linked list.
    """

    def __init__(self, data, next=None):
        """
        Initializes a new Node object with the specified data and next node.

        Args:
            data: The value to store in the node.
            next: The next node in the linked list.
        """
        self.data = data
        self.next = next

    def __repr__(self):
        return str(self.data)

def remove_loop(loop_node, head):
    ptr1, ptr2 = head, loop_node

    while ptr1.next != ptr2.next:
        ptr1, ptr2 = ptr1.next, ptr2.next

    ptr2.next = None

def detect_and_remove_cycle(head):
    if not head:
        return False

    fast_ptr = slow_ptr = head

    while slow_ptr and fast_ptr and fast_ptr.next:
        fast_ptr, slow_ptr = fast_ptr.next.next, slow_ptr.next

        if fast_ptr == slow_ptr:
            remove_loop(slow_ptr, head)
            return True

    return False


def insert(head, c):
    """
    Inserts a new node with the specified value at the beginning of the linked list.

    Args:
        head: The current head of the linked list.
        c: The value to insert as a new node.

    Returns:
        The new head of the linked list.
    """
    # Create a new node with the specified value and set its next node to the current head.
    # This effectively inserts the new node at the beginning of the linked list.
    return Node(c, head)


def create_linked_list(data):
    """
    Creates a linked list from a list of data values.

    Args:
        data: A list of data values to be added to the linked list.

    Returns:
        The head of the newly created linked list.
    """
    # Initialize head to None
    head = None
    
    # Iterate through the data list and create a new Node object for each data value
    for c in data:
        new_node = Node(c)
        
        # Set the next attribute of the new Node to the current head of the linked list
        new_node.next = head
        
        # Update the head to point to the new Node
        head = new_node
    
    # Return a reference to the head of the newly created linked list
    return head

def print_list(head):
    """
    Prints the values of each node in the linked list.

    Args:
        head: The head of the linked list.

    Returns:
        None
    """
    # Initialize an empty list to store the values of each node.
    nodes = []

    # Iterate through the linked list and add each node's data value to the nodes list.
    while head:
        nodes.append(str(head.data))
        head = head.next

    # Print the nodes list as a string, with each node's data value separated by an arrow.
    print(" --> ".join(nodes))


if __name__ == '__main__':
    head = create_linked_list(range(1,6))
    print("Current List:")
    print_list(head)
    print("Inserting loop, connecting 5 to 3")
    head.next.next.next.next.next = head.next
    print("Detecting and deleting loop")
    detect_and_remove_cycle(head)
    print("Back to the same old list")
    print_list(head)
