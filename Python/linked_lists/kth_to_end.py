from linked_list import LinkedList

def kth_to_last(ll, k):
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


# O(N) space
def kth_last_recursive(ll, k):
    # Initialize a counter variable and get the head of the linked list
    head = ll.head
    counter = 0

    # Define a helper function to traverse the linked list recursively
    def helper(head, k):
        nonlocal counter  # We need to use nonlocal to modify the counter variable inside the helper function

        if not head:  # Base case: if the current node is None, return None
            return None

        # Recursively traverse the rest of the linked list
        helper_node = helper(head.next, k)

        counter = counter + 1  # Increment the counter for each node visited

        if counter == k:  # If we've reached the kth to last node, return it
            return head

        # If we haven't reached the kth to last node yet, return the node from the previous recursive call
        return helper_node

    # Call the helper function and return the result
    return helper(head, k)


test_cases = (
    # list, k, expected
    ((10, 20, 30, 40, 50), 1, 50),
    ((10, 20, 30, 40, 50), 5, 10),
)


def test_kth_to_last():
    for linked_list_values, k, expected in test_cases:
        ll = LinkedList(linked_list_values)
        assert kth_to_last(ll, k).value == expected
        assert kth_last_recursive(ll, k).value == expected


if __name__ == "__main__":
    test_kth_to_last()