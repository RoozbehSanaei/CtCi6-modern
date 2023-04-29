class Node:
    """A class that represents a node in a singly linked list."""

    def __init__(self, data):
        """
        Constructs a new node with the given data and a null next pointer.

        Args:
            data: The data to store in the node.
        """
        self.data = data
        self.next = None


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


def intersectionPoint(head1, head2):
    """
    Finds the intersection point of two singly linked lists.

    Args:
        head1: The head node of the first linked list.
        head2: The head node of the second linked list.

    Returns:
        The node where the two linked lists intersect, or None if they do not intersect.
    """
    len1 = len2 = 0
    node1, node2 = head1, head2

    # Calculate the lengths of the two lists
    while node1:
        len1 += 1
        node1 = node1.next

    while node2:
        len2 += 1
        node2 = node2.next

    # Adjust the head pointers of the longer list to the same distance from the end as the shorter list
    node1, node2 = head1, head2
    for i in range(abs(len1 - len2)):
        if len1 > len2:
            node1 = node1.next
        else:
            node2 = node2.next

    # Traverse both lists until an intersection point is found
    while node1 and node2:
        if node1 == node2:
            return node1
        node1 = node1.next
        node2 = node2.next

    # No intersection point found
    return None


if __name__ == "__main__":
    # Create two linked lists
    list1 = Node(3)
    list1.next = Node(6)
    list1.next.next = Node(9)
    list1.next.next.next = Node(12)
    list1.next.next.next.next = Node(15)
    list1.next.next.next.next.next = Node(18)

    list2 = Node(3)
    list2.next = list1.next
    list2.next.next = list1.next.next
    list2.next.next.next = list1.next.next.next
    list2.next.next.next.next = Node(15)
    list2.next.next.next.next.next = Node(18)

    # Print the linked lists
    print("List 1: ", end="")
    printList(list1)
    print("List 2: ", end="")
    printList(list2)

    # Find the intersection point of the two lists
    intersectingNode = intersectionPoint(list1, list2)
    if intersectingNode:
        print("Intersecting Node of lists is: ", end="")
        print(intersectingNode.data)
    else:
        print("Lists do not intersect")
