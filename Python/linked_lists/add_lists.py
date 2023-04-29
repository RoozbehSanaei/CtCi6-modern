class Node:
    """
    This class represents a node in a linked list.

    Attributes:
        data: The data stored in the node.
        next: A reference to the next node in the linked list.
    """
    def __init__(self, data):
        """
        Constructs a new Node object with the given data.

        Args:
            data: The data to be stored in the node.
        """
        self.data = data
        self.next = None

class Node:
    def __init__(self, data):
        """
        Initializes a new node with the provided data.

        Args:
            data: The data to be stored in the node.
        """
        self.data = data
        self.next = None

def insert(head, data):
    """
    Inserts a new node with the provided data at the beginning of the linked list.

    Args:
        head: A reference to the first node of the linked list.
        data: The data to be stored in the new node.

    Returns:
        A reference to the new head of the linked list.
    """
    new_node = Node(data)
    new_node.next = head
    head = new_node
    return head

def printList(head):
    """
    Prints the contents of a linked list, starting at the given head node.

    Args:
        head: The head node of the linked list.
    """
    node = head
    while node:
        print(str(node.data) + "-->", end="")
        node = node.next
    print("NULL")


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def add_iterative(list1, list2):
    """Add two non-negative integers represented as linked lists in reverse order.

    Args:
        list1 (Node): Linked list representing first non-negative integer.
        list2 (Node): Linked list representing second non-negative integer.

    Returns:
        Node: Linked list representing the sum of the input integers in reverse order.
    """
    # Initialize variables
    list3 = list3Tail = Node(0)
    carry = 0

    # Traverse both lists and add digits
    while list1 or list2 or carry:
        # Add digits and carry-over
        value = carry + (list1.data if list1 else 0) + (list2.data if list2 else 0)
        carry, value = divmod(value, 10)
        
        # Create new node for sum and add to result list
        list3Tail.next = list3Tail = Node(value)
        
        # Move to next digit in both input lists
        list1 = list1.next if list1 else None
        list2 = list2.next if list2 else None

    # Return the result list, skipping the initial dummy node
    return list3.next



def add_recursive(list1, list2, carry=0):
    """
    Adds two linked lists representing numbers in reverse order recursively.

    Args:
        list1: The first linked list.
        list2: The second linked list.
        carry: The carry value from the previous digit addition (default 0).

    Returns:
        The head node of the resulting linked list.

    """
    # If both lists are empty and carry is 0, end of addition.
    if not list1 and not list2 and carry == 0:
        return None

    # Calculate the sum of the current digits and carry.
    value = carry + (list1.data if list1 else 0) + (list2.data if list2 else 0)

    # Create a new node with the result mod 10.
    result_node = Node(value % 10)

    # Recursively get the next node by passing the next nodes of both lists and the carry from the current addition.
    result_node.next = add_recursive(list1.next if list1 else None, list2.next if list2 else None, 1 if value > 9 else 0)

    return result_node

def length(head):
    """
    Calculates the length of a linked list.

    Args:
        head: The starting node of the linked list.

    Returns:
        The length of the linked list.
    """
    len = 0  # Initialize a variable to keep track of the length
    while head:  # Loop through the linked list as long as there are nodes
        len += 1  # Increment the length by 1 for each node
        head = head.next  # Move to the next node in the linked list
    return len  # Return the final length of the linked list


def pad_list(list_head, padding):
    """
    Adds padding number of nodes with value 0 to the beginning of a linked list.

    Args:
        list_head (Node): Head node of the linked list
        padding (int): Number of nodes to add at the beginning of the linked list

    Returns:
        Node: Updated head node of the linked list with padding number of nodes added at the beginning
    """
    
    # Iterate padding number of times to add new nodes with value 0 at the beginning
    for i in range(padding):
        new_node = Node(0)  # Create a new node with value 0
        new_node.next = list_head  # Point the new node's next to the current head node
        list_head = new_node  # Update the head node to the new node

    return list_head  # Return the updated head node of the linked list

def add_followup_helper(list1, list2, carry):
    """
    Recursively adds two linked lists representing non-negative integers, with a carry digit.

    Args:
        list1 (Node): The head node of the first linked list.
        list2 (Node): The head node of the second linked list.
        carry (int): A digit to carry over from a previous addition.

    Returns:
        Node: The head node of a linked list representing the sum of list1 and list2, with any carry digit.

    Raises:
        None.

    """
    # Base case: if both linked lists are empty and there is no carry digit, return None
    if not list1 and not list2 and carry == 0:
        return None
    
    # Get the next node for each linked list (or None if at the end)
    next_list1 = list1.next if list1 else None
    next_list2 = list2.next if list2 else None
    
    # Recursively add the next nodes, along with the carry digit
    result = add_followup_helper(next_list1, next_list2, carry)
    
    # Calculate the sum of the current nodes and carry digit
    value = carry + (list1.data if list1 else 0) + (list2.data if list2 else 0)
    
    # Insert the ones digit of the sum into the result linked list
    # If result is None, create a new node for the head of the linked list
    # Use the walrus operator to assign the new head node to result if it was None
    return insert(result, value % 10) if (result := insert(result, value % 10)) else result
    
    # Update the carry digit for the next recursive call
    carry = 1 if value > 9 else 0

def add_followup(list1: list, list2: list) -> list:
    """
    Takes two lists of integers and returns their sum as another list.
    If one list is shorter than the other, it is padded with zeroes to make them of equal length.
    """
    # Check the lengths of the input lists
    len1, len2 = length(list1), length(list2)

    # Pad the shorter list with zeroes to make them of equal length
    if len1 > len2:
        list2 = pad_list(list2, len1 - len2)
    else:
        list1 = pad_list(list1, len2 - len1)

    # Initialize carry value to 0 and call helper function to add the corresponding elements
    carry = 0
    list3 = add_followup_helper(list1, list2, carry)

    # If there is a carry value, insert it at the beginning of the result list
    if carry:
        list3 = insert(list3, carry)

    return list3

if __name__ == '__main__':
    # Create the first linked list (6 -> 1 -> 7)
    list1 = None
    list1 = insert(list1, 6)
    list1 = insert(list1, 1)
    list1 = insert(list1, 7)
    print("List1:  ", end="")
    printList(list1)

    # Create the second linked list (2 -> 9 -> 5)
    list2 = None
    list2 = insert(list2, 2)
    list2 = insert(list2, 9)
    list2 = insert(list2, 5)
    print("List2:  ", end="")
    printList(list2)

    # Add the two linked lists iteratively and print the result
    list3 = add_iterative(list1, list2)
    print("Iterative Solution: ")
    print("List3:  ", end="")
    printList(list3)

    # Add the two linked lists recursively and print the result
    list4 = add_recursive(list1, list2, 0)
    print("Recursive Solution: ")
    print("List4:  ", end="")
    printList(list4)

    # Create the first linked list in reverse order (9 -> 2 -> 3 -> 4)
    list1 = None
    list1 = insert(list1, 4)
    list1 = insert(list1, 3)
    list1 = insert(list1, 2)
    list1 = insert(list1, 9)
    print("\n\nNow follow up case, lists are stored such that 1's digit is at the tail of list")
    print("List1:  ", end="")
    printList(list1)

    # Create the second linked list in reverse order (8 -> 9 -> 9)
    list2 = None
    list2 = insert(list2, 9)
    list2 = insert(list2, 9)
    list2 = insert(list2, 8)
    print("List2:  ", end="")
    printList(list2)

    # Add the two linked lists where digits are in reverse order and print the result
    list3 = add_followup(list1, list2)
    print("Adding two above lists")
    print("List3:  ", end="")
    printList(list3)

