// Defines a singly linked list data structure and provides functions to insert and print the list.
#include <iostream>

// A singly linked list node with an integer data member and a pointer to the next node.
struct Node {
  int data; // The integer data member of the node.
  Node * next; // A pointer to the next node in the list.
  
  // Constructs a new Node object with the given data.
  Node ( int d ) : data{ d }, next{ nullptr } { }
};

// Inserts a new node with the given data at the head of the list.
void insert( Node * & head, int data ) {
  Node * newNode = new Node(data); // Create a new node with the given data.
  newNode->next = head; // Set the new node's next pointer to the current head of the list.
  head = newNode; // Set the new node as the new head of the list.
}

// Prints the list starting from the given head node.
void printList( Node * head ) {
  while ( head ) { // Loop until the end of the list is reached (head is null).
    std::cout << head->data << "-->"; // Print the current node's data and an arrow.
    head = head->next; // Move to the next node in the list.
  }
  std::cout << "nullptr" << std::endl; // Print "nullptr" to indicate the end of the list.
}


Node * add_iterative( Node * list1, Node * list2 ) {
  // If one of the input lists is empty, return the other list
  if ( list1 == nullptr ) {
    return list2;
  }
  if ( list2 == nullptr ) {
    return list1;
  }

  // Create a new list to store the sum and a pointer to its tail
  Node * list3 = nullptr;
  Node * list3Tail = nullptr;

  // Initialize variables for carrying and summing values
  int value = 0, carry = 0;

  // Traverse both input lists simultaneously
  while( list1 || list2 ) {
    // Calculate the sum of the current nodes' values, adding any carry from previous sums
    value = carry + (list1 ? list1->data : 0 ) + (list2 ? list2->data : 0);

    // Update the carry if the sum is greater than 9, and take the last digit as the value of the new node
    if ( value > 9 ) {
      carry = 1;
      value = value % 10;
    } else {
      carry = 0;
    }

    // Create a new node for the sum, and append it to the result list
    Node * temp = new Node(value);

    // If the result list is empty, set the current node as its head
    if ( list3 == nullptr ) {
      list3 = temp;
    } else {
      // Otherwise, append the current node to the tail of the result list
      list3Tail->next = temp;
    }

    // Update the tail pointer to the current node
    list3Tail = temp;

    // Move to the next node in each input list, if it exists
    if (list1) {
      list1 = list1->next;
    }

    if (list2) {
      list2 = list2->next;
    }
  }

  // If there is still a carry left, add it as a new node to the result list
  if ( carry > 0 ) {
    list3Tail->next = new Node(carry);
  }

  // Return the result list
  return list3;
}


/**
 * @brief Add two linked lists representing non-negative integers.
 *
 * This function adds two linked lists representing non-negative integers.
 * The result is returned as a linked list with the least significant digit at the head.
 *
 * @param list1 Pointer to the head of the first linked list.
 * @param list2 Pointer to the head of the second linked list.
 * @param carry Carry from the previous addition. Default value is 0.
 * @return Pointer to the head of the resulting linked list.
 */
Node* add_recursive(Node* list1, Node* list2, int carry = 0) {
  // Base case: both input lists are empty and there is no carry.
  if (list1 == nullptr && list2 == nullptr && carry == 0) {
    return nullptr;
  }

  // Calculate the sum of the current digits and the carry from the previous addition.
  int value = carry;
  if (list1) {
    value += list1->data;
  }
  if (list2) {
    value += list2->data;
  }

  // Create a new node with the least significant digit of the sum.
  Node* resultNode = new Node(value % 10);

  // Recursively add the next digits and the carry from the current addition.
  resultNode->next = add_recursive(list1 ? (list1->next) : nullptr,
                                    list2 ? (list2->next) : nullptr,
                                    value > 9 ? 1 : 0);

  return resultNode;
}


/**
 * @brief Calculate the length of a linked list.
 *
 * This function calculates the length of a linked list.
 *
 * @param head Pointer to the head of the linked list.
 * @return The length of the linked list.
 */
int length(Node* head) {
  // Initialize a variable len to 0 to keep track of the length of the list.
  int len = 0;

  // Iterate through each node in the list.
  while (head) {
    // Increment the length for each node.
    len++;

    // Move to the next node in the list.
    head = head->next;
  }

  // Return the length of the list.
  return len;
}

/**
 * @brief Adds padding zeros to the beginning of a linked list representing a non-negative integer.
 *
 * This function pads a linked list representing a non-negative integer with zeros at the beginning,
 * to make it the same length as another linked list.
 *
 * @param list Reference to a pointer to the head of the linked list to pad.
 * @param padding Number of zeros to add at the beginning of the linked list.
 */
void padList(Node*& list, int padding) {
  // iterate through the number of zeros to add
  for (int i = 0; i < padding; ++i) {
    // insert a new node with a value of 0 at the beginning of the list
    insert(list, 0);
  }
}
