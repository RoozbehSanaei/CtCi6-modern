from linked_list import LinkedList


def partition(ll, x):
    """
    Rearranges the nodes of a linked list such that all nodes with values less than a given partition value
    come before all nodes with values greater than or equal to the partition value. Returns the partitioned linked list.

    Args:
    - ll: A linked list represented as a sequence of nodes. Each node has a value and a pointer to the next node.
    - x: The partition value.

    Returns:
    - A partitioned linked list represented as a sequence of nodes. Each node has a value and a pointer to the next node.
    """
    current = ll.tail = ll.head # Initialize current node and tail node to the head of the linked list

    # Iterate through the linked list
    while current:
        next_node = current.next # Save the next node in the list before modifying current.next
        current.next = None # Set the current node's next pointer to None

        # If the current node's value is less than x, move it to the front of the linked list
        if current.value < x:
            current.next = ll.head
            ll.head = current
        # Otherwise, move it to the back of the linked list
        else:
            ll.tail.next = current
            ll.tail = current
        
        # Move to the next node in the list
        current = next_node

    # Error check in case all nodes are less than x
    if ll.tail.next is not None:
        ll.tail.next = None

    return ll

def lr_partition(_ll: LinkedList, p: int) -> LinkedList:
    """
    Partitions a linked list into two new linked lists, one containing all nodes with values less than a given
    partition value and the other containing all nodes with values greater than or equal to the partition value.
    Combines these two linked lists into a single linked list and returns it.

    Args:
    - _ll: A linked list represented as a sequence of nodes. Each node has a value and a pointer to the next node.
    - p: The partition value.

    Returns:
    - A partitioned linked list represented as a sequence of nodes. Each node has a value and a pointer to the next node.
    """
    left = LinkedList() # Initialize the left linked list
    right = LinkedList() # Initialize the right linked list

    current = _ll.head # Initialize current node to the head of the original linked list

    # Iterate through the original linked list
    while current:
        # If the current node's value is less than p, add it to the left linked list
        if current.value < p:
            left.add(current.value)
        # Otherwise, add it to the right linked list
        else:
            right.add(current.value)

        # Move to the next node in the list
        current = current.next

    # Combine the left and right linked lists
    left.tail.next = right.head

    return left

def test_lr_partition():
    """
    Tests both partitioning functions with a book example and a random example.
    """
    partitioners = [partition, lr_partition]
    for partition_func in partitioners:
        # book example
        ll = LinkedList([3, 5, 8, 5, 10, 2, 1])
        assert not is_partitioned(ll, x=5)
        ll = partition_func(ll, 5)
        assert is_partitioned(ll, x=5), f"{partition_func} did not partition {ll}"

        # random example
        ll = LinkedList.generate(10, 0, 99)
        x = ll.head.value
        ll = partition_func(ll, x)
        assert is_partitioned(ll, x=x), f"{partition_func} did not partition"
    """
    Test both partition functions with a book example and a random example.

    The function iterates through a list of partition functions (in this case, partition and lr_partition).
    For each partition function, it first creates a linked list with a book example (a pre-defined list of integers),
    checks if it is not already partitioned by calling the is_partitioned function with the value 5, and then partitions
    it using the partition_func passed as an argument. It then checks if the linked list is now partitioned by calling 
    is_partitioned again, and raises an assertion error with a message if the linked list is not properly partitioned.
    
    The function then creates another linked list with random integers, and repeats the same steps as above.
    """


def is_partitioned(ll, x):
    """
    Determines if a linked list is partitioned around a given value.

    Args:
    - ll: A linked list represented as a sequence of nodes. Each node has a value and a pointer to the next node.
    - x: The partition value.

    Returns:
    - True if the linked list is partitioned around x, i.e., all nodes with values less than x come before all nodes with
    values greater than or equal to x. False otherwise.
    """
    seen_gt_partition = False  # flag to indicate if we have seen any node with value greater than or equal to x
    for node in ll:
        if node.value >= x:  # if current node has value greater than or equal to x
            seen_gt_partition = True  # update flag
            continue  # skip to next iteration
        if seen_gt_partition and node.value < x:  # if we have seen a node with value greater than or equal to x before, and current node has value less than x
            return False  # the list is not partitioned
    return True  # the list is partitioned

if __name__ == "__main__":
    test_lr_partition()
