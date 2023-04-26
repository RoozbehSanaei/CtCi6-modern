
#include <iostream>

/**
 * @brief A struct representing a node in a singly linked list.
 */
struct Node {
  int data; /**< The integer data stored in the node. */
  Node * next; /**< Pointer to the next node in the list. */
  
  /**
   * @brief Constructor that initializes the node with the given data and a null next pointer.
   * 
   * @param d The integer data to be stored in the node.
   */
  Node(int d) : data{ d }, next{ nullptr } { }
};



/**
 * @brief Inserts a new node containing an integer data at the beginning of a linked list.
 * 
 * @param head Reference to a pointer to the head node of the list.
 * @param data Integer data to be inserted.
 */
void insert( Node * &head, int data ) {
  // Create a new Node object with the given data
  Node * newNode = new Node(data);
  // Set the new node's next pointer to the current head
  newNode->next = head;
  // Set the head pointer to the new node, making it the new head of the list
  head = newNode;
}


/**
 * @brief Deletes all the nodes in a linked list, starting from the head node.
 * 
 * @param head Reference to a pointer to the head node of the list.
 */
void deleteList( Node * & head ) {
  // Create a temporary pointer to hold the next node in the list
  Node * nextNode;
  
  // Loop through all nodes in the list
  while(head) {
    // Store a pointer to the next node
    nextNode = head->next;
    // Delete the current node
    delete(head);
    // Set the head to the next node, effectively removing the current node from the list
    head = nextNode;
  }
}

/**
 * @brief Prints the contents of a linked list to the standard output.
 * 
 * @param head Pointer to the head node of the list.
 */
void printList( Node * head ) {
  // Loop through all nodes in the list
  while(head) {
    // Print the current node's data followed by an arrow
    std::cout << head->data << "-->";
    // Move to the next node
    head = head->next;
  }
  // Print "null" to indicate the end of the list
  std::cout << "null" << std::endl;
}


/**
 * @brief Returns the kth to last element in a linked list using recursion.
 * 
 * @param head Pointer to the head node of the list.
 * @param k The number of elements from the end of the list to retrieve.
 * @param i Counter variable used to keep track of the current position in the list.
 * @return Pointer to the kth to last element in the list, or nullptr if the list is empty or k is out of range.
 */
Node * kthToLastHelper( Node * head, int k, int & i) {
  // Base case: reached the end of the list
  if ( head == nullptr ) {
    return nullptr;
  }

  // Recursively call the function on the next node in the list
  Node * node = kthToLastHelper(head->next, k, i);
  // Increment the counter
  i = i + 1;
  // If we have solved the problem k times from last
  if ( i == k ) {
    // Return a pointer to the current node, which is the kth to last node
    return head;
  }
  // Otherwise, return the result of the recursive call
  return node;
}


/**
 * @brief Finds the kth to last element in a linked list using recursion.
 * 
 * @param head Pointer to the head node of the list.
 * @param k The number of elements from the end of the list to retrieve.
 * @return Pointer to the kth to last element in the list, or nullptr if the list is empty or k is out of range.
 */
Node * kthToLastRecursive( Node * head, int k ) {
  // Initialize a counter variable to keep track of the current position in the list
  int i = 0;
  // Call the helper function with the head node, k, and the counter variable as arguments
  return kthToLastHelper(head, k, i);
}


/*
ptr1 is k nodes ahead of ptr2, the function moves both pointers together until ptr1 
reaches the end of the list. At this point, ptr2 points to the kth to last element
 of the list, which is what we want to return.
Overall, this algorithm has a time complexit*/

/**
 * @brief Finds the kth to last element in a linked list using two pointers.
 * 
 * @param head Pointer to the head node of the list.
 * @param k The number of elements from the end of the list to retrieve.
 * @return Pointer to the kth to last element in the list, or nullptr if the list is empty or k is out of range.
 */
Node * kthToLastIterative( Node * head, int k ) {
  // Return null if the list is empty
  if ( head == nullptr ) {
    return head;
  }

  // Initialize two pointers, ptr1 and ptr2, to the head of the list
  Node * ptr1 = head;
  Node * ptr2 = head;

  // Move ptr1 k nodes ahead of ptr2
  int i = 0;
  while( i < k && ptr1 ) {
    ptr1 = ptr1->next;
    ++i;
  }

  // If we've moved less than k nodes ahead of ptr2, we're out of bounds and return null
  if ( i < k ) {
    return nullptr;
  }

  // Move ptr1 and ptr2 together until ptr1 reaches the end of the list
  while( ptr1 != nullptr ) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  // Return ptr2, which is now k nodes from the end of the list
  return ptr2;
}


int main() {
  // Initialize an empty linked list
  Node * head = nullptr;
  
  // Insert 7 nodes into the list with data values from 1 to 7
  for ( int i = 7; i > 0; i-- ) {
    insert(head, i);
  }
  
  // Print the contents of the list
  std::cout << "List: ";
  printList(head);

  // Find the 4th to last element of the list using the recursive algorithm
  std::cout << "4th node from last (Recursive) : ";
  Node *node4 = kthToLastRecursive(head, 4);
  if ( node4 != nullptr ) {
    std::cout << node4->data << std::endl;
  } else {
    std::cout << "NULL NODE\n";
  }

  // Find the 4th to last element of the list using the iterative algorithm
  std::cout << "4th node from last (Iterative) : ";
  node4 = kthToLastIterative(head, 4);
  if ( node4 != nullptr ) {
    std::cout << node4->data << std::endl;
  } else {
    std::cout << "NULL NODE\n";
  }

  // Delete the list to free memory
  deleteList(head);

  return 0;
}
