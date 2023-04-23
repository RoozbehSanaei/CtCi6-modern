from linked_list import LinkedList

def kth_to_last(ll, k):
    """
    Returns the kth to last node of a linked list.

    Args:
        ll (LinkedList): The linked list to search.
        k (int): The position of the node to return, counting from the end of the list.

    Returns:
        Node: The kth to last node of the linked list.
    """
    # Initialize two pointers to the head of the linked list
    leader = follower = ll.head
    count = 0

    # Move the leader pointer k nodes ahead of the follower pointer
    while leader:
        if count >= k:  # If we've already moved k nodes ahead with the leader pointer...
            follower = follower.next  # ...move the follower pointer along with the leader pointer
        count += 1  # Increment the count for each node visited
        leader = leader.next  # Move the leader pointer one node ahead

    # Return the follower pointer, which is now pointing to the kth to last node
    return follower

def kth_last_recursive(ll, k):
    """Returns the kth to last element of a singly linked list using a recursive approach.

    Args:
        ll (LinkedList): A singly linked list.
        k (int): An integer representing the kth to last element to find.

    Returns:
        The kth to last element of the linked list if it exists, otherwise None.

    """
    head = ll.head  # Get the head of the linked list
    counter = 0  # Initialize a counter variable

    def helper(head, k):
        """Traverses the linked list recursively and returns the kth to last element.

        Args:
            head (Node): The current node being visited during the recursive traversal.
            k (int): An integer representing the kth to last element to find.

        Returns:
            The kth to last element of the linked list if it exists, otherwise None.

        """
        nonlocal counter  # We need to use nonlocal to modify the counter variable inside the helper function

        if not head:  # Base case: if the current node is None, return None
            return None

        helper_node = helper(head.next, k)  # Recursively traverse the rest of the linked list

        counter += 1  # Increment the counter for each node visited

        if counter == k:  # If we've reached the kth to last node, return it
            return head

        return helper_node  # If we haven't reached the kth to last node yet, return the node from the previous recursive call

    return helper(head, k)  # Call the helper function and return the result


test_cases = (
    # list, k, expected
    ((10, 20, 30, 40, 50), 1, 50),
    ((10, 20, 30, 40, 50), 5, 10),
)


def test_kth_to_last():
    """
    Test function for kth_to_last and kth_last_recursive functions.

    For each test case in test_cases, create a LinkedList object with the linked
    list values, call both kth_to_last and kth_last_recursive functions with
    the LinkedList object and k as arguments, and check that the returned value
    matches the expected output.
    """
    for linked_list_values, k, expected in test_cases:
        # Create a LinkedList object from the linked list values
        ll = LinkedList(linked_list_values)

        # Call kth_to_last function with the LinkedList object and k as arguments
        # and check that the returned value matches the expected output
        assert kth_to_last(ll, k).value == expected

        # Call kth_last_recursive function with the LinkedList object and k as
        # arguments and check that the returned value matches the expected output
        assert kth_last_recursive(ll, k).value == expected



if __name__ == "__main__":
    test_kth_to_last()