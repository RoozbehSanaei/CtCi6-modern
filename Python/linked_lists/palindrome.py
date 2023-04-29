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


def printList(head):
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


def reverse(head):
    """
    Reverses the linked list.

    Args:
        head: The head of the linked list.

    Returns:
        The new head of the reversed linked list.
    """
    # Initialize new_head to None
    new_head = None
    
    # Iterate through the linked list
    while head:
        # Save the next node in a temporary variable
        temp = head.next
        
        # Reverse the direction of the current node
        head.next = new_head
        
        # Update new_head to the current node
        new_head = head
        
        # Move head to the next node in the original linked list
        head = temp
        
    # Return the new head of the reversed linked list
    return new_head


def isPalindromeIter1(head):
    """
    Checks whether the linked list is a palindrome or not using iterative approach.

    Args:
        head: The head of the linked list.

    Returns:
        True if the linked list is a palindrome, False otherwise.
    """
    # Initialize pointers ptr1 and ptr2 to the head of the linked list
    ptr1 = ptr2 = head

    # Find the middle node of the linked list using two pointers
    while ptr2 and ptr2.next:
        ptr1, ptr2 = ptr1.next, ptr2.next.next

    # Reverse the second half of the linked list
    ptr2 = reverse(ptr1) if ptr2 else reverse(ptr1.next)

    # Compare the values of the nodes in the first half of the linked list
    # with the reversed nodes in the second half of the linked list
    while ptr2:
        if head.data != ptr2.data:
            return False
        head, ptr2 = head.next, ptr2.next

    # If all values match, return True
    return True

def isPalindromeIter2(head):
    """
    Checks whether the linked list is a palindrome or not using iterative approach.

    Args:
        head: The head of the linked list.

    Returns:
        True if the linked list is a palindrome, False otherwise.
    """
    # Initialize an empty stack and pointers slow and fast to the head of the linked list
    stack = []
    slow = fast = head

    # Traverse the linked list using pointers slow and fast
    while fast and fast.next:
        # Add the value of the node pointed to by slow to the stack
        stack.append(slow)

        # Move slow one node forward and fast two nodes forward
        slow, fast = slow.next, fast.next.next

    # If the linked list has an odd number of nodes, skip the middle node
    if fast:
        slow = slow.next

    # Compare the second half of the linked list with the values in the stack
    # to determine whether the linked list is a palindrome or not
    return all(slow.data == stack.pop().data for _ in range(len(stack)))

def isPalindromeRecur_helper(left, right):
    """
    Helper function for recursive approach to check whether the linked list is a palindrome or not.

    Args:
        left: The left node being compared.
        right: The right node being compared.

    Returns:
        True if the linked list is a palindrome, False otherwise.
    """
    # If right is None, the end of the linked list has been reached and all values have been compared
    if not right:
        return True

    # Compare the values of the nodes pointed to by left and right
    values_match = left.data == right.data

    # Call isPalindromeRecur_helper recursively with the next nodes in the linked list
    # and return True if all values match, False otherwise
    return values_match and isPalindromeRecur_helper(left.next, right.next)

def isPalindromeRecur(head):
    """
    Checks whether the linked list is a palindrome or not using recursive approach.

    Args:
        head: The head of the linked list.

    Returns:
        True if the linked list is a palindrome, False otherwise.
    """
    # Call isPalindromeRecur_helper with head as both left and right to start the recursive palindrome check
    return isPalindromeRecur_helper(head, head)


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


if __name__ == '__main__':
    # Test palindrome check with iterative approach 1
    head1 = create_linked_list('abccba')
    print('List 1: ', end='')
    printList(head1)
    print(f'List 1 is a palindrome list: {isPalindromeIter1(head1)}')
    print('List 1: ', end='')
    printList(head1)

    # Test palindrome check with iterative approach 2
    head2 = create_linked_list('radar')
    print('List 2: ', end='')
    printList(head2)
    print(f'List 2 is a palindrome list: {isPalindromeIter2(head2)}')
    print('List 2: ', end='')
    printList(head2)

    # Test palindrome check with recursive approach
    head3 = create_linked_list('abcba')
    print('List 3: ', end='')
    printList(head3)
    print(f'List 3 is a palindrome list: {isPalindromeRecur(head3)}')
    print('List 3: ', end='')
    printList(head3)
