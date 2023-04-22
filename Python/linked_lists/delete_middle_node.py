# Import the LinkedList class from the linked_list module
from linked_list import LinkedList

# Define a function that deletes a middle node from a linked list
def delete_middle_node(node):
    # Replace the value of the input node with the value of the next node
    node.value = node.next.value
    # Update the next pointer of the input node to skip the next node and point to the one after it
    node.next = node.next.next

# If this script is run directly (not imported as a module), do the following:
if __name__ == "__main__":
    # Create a new linked list instance
    ll = LinkedList()
    # Add multiple nodes to the linked list with values [1, 2, 3, 4]
    ll.add_multiple([1, 2, 3, 4])
    # Add a new node to the linked list with value 5, and store a reference to it in middle_node
    middle_node = ll.add(5)
    # Add multiple nodes to the linked list with values [7, 8, 9]
    ll.add_multiple([7, 8, 9])

    # Print the linked list before the middle node is deleted
    print(ll)
    # Call the delete_middle_node function on the middle node
    delete_middle_node(middle_node)
    # Print the linked list after the middle node is deleted
    print(ll)
