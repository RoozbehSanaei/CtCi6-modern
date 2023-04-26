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


// Recursive helper function to add two linked lists representing integers.
// Takes two linked lists (list1 and list2) and a carry value (carry) as input.
// Returns a pointer to the head node of the new linked list containing the sum.
Node * add_followup_helper( Node * list1, Node * list2, int & carry ) {
  
  // If both input linked lists and the carry value are null, there are no more digits to add.
  // Return a null pointer to signify the end of the sum.
  if ( list1 == nullptr && list2 == nullptr && carry == 0 ) {
    return nullptr;
  }

  // Recursively call this function with the next nodes of both input linked lists and the carry value.
  Node * result = add_followup_helper(list1 ? (list1->next) : nullptr,
                                      list2 ? (list2->next) : nullptr,
                                      carry);

  // Calculate the sum of the current nodes and the carry value.
  int value = carry + (list1 ? list1->data : 0 ) + (list2 ? list2->data : 0);

  // Insert the ones digit of the sum as a new node at the head of the result list.
  insert( result, value % 10 );

  // Update the carry value based on whether the sum is greater than 9.
  carry = ( value > 9 ) ? 1 : 0;

  // Return a pointer to the head node of the result list.
  return result;
}


// Add two linked lists representing integers.
// Takes two linked lists (list1 and list2) as input.
// Returns a pointer to the head node of the linked list containing the sum.
Node * add_followup( Node * list1, Node * list2 ) {

  // Find the length of the two input linked lists.
  int len1 = length(list1);
  int len2 = length(list2);

  // Pad the smaller linked list with zeroes so that both lists are the same length.
  if ( len1 > len2 ) {
    padList( list2, len1 - len2 );
  } else {
    padList( list1, len2 - len1 );
  }

  // Initialize a carry variable to 0 and call the recursive helper function.
  int carry = 0;
  Node * list3 = add_followup_helper( list1, list2, carry);

  // If there is a carry value left over after adding the last digits, insert it as a new node at the head of the sum.
  if ( carry ) {
    insert( list3, carry);
  }

  // Return a pointer to the head node of the sum.
  return list3;
}

// Deallocate memory for a linked list.
// Takes a pointer to the head node of the linked list as input.
// Sets the head pointer to null after deallocating all nodes.
void deleteList( Node * & head ) {

  // Initialize a temporary pointer to the next node in the list.
  Node * nextNode;

  // Traverse the list and deallocate memory for each node.
  while(head) {
    // Save the pointer to the next node in the list.
    nextNode = head->next;
    // Deallocate memory for the current node.
    delete(head);
    // Move the head pointer to the next node.
    head = nextNode;
  }

  // Set the head pointer to null after all nodes have been deallocated.
  head = nullptr;
}


int main()
{
  // Create a linked list to represent the number 617
  Node * list1 = nullptr; // Initialize an empty linked list
  insert(list1, 6); // Add the digit 6 to the list
  insert(list1, 1); // Add the digit 1 to the list
  insert(list1, 7); // Add the digit 7 to the list
  std::cout << "List1:  "; // Print a message to indicate which list is being printed
  printList(list1); // Print the linked list

  // Create a linked list to represent the number 295
  Node * list2 = nullptr; // Initialize an empty linked list
  insert(list2, 2); // Add the digit 2 to the list
  insert(list2, 9); // Add the digit 9 to the list
  insert(list2, 5); // Add the digit 5 to the list
  std::cout << "List2:  "; // Print a message to indicate which list is being printed
  printList(list2); // Print the linked list

  // Perform addition of the two linked lists iteratively
  Node * list3 = add_iterative(list1, list2); // Add the two lists using an iterative approach
  std::cout << "Iterative Solution: \n"; // Print a message to indicate that the iterative solution is being printed
  std::cout << "List3:  "; // Print a message to indicate which list is being printed
  printList(list3); // Print the linked list

  // Perform addition of the two linked lists recursively
  Node * list4= add_recursive(list1, list2, 0); // Add the two lists using a recursive approach
  std::cout << "Recursive Solution: \n"; // Print a message to indicate that the recursive solution is being printed
  std::cout << "List4:  "; // Print a message to indicate which list is being printed
  printList(list4); // Print the linked list

  // Free the memory used by the linked lists
  deleteList(list1); // Free the memory used by list1
  deleteList(list2); // Free the memory used by list2
  deleteList(list3); // Free the memory used by list3
  deleteList(list4); // Free the memory used by list4

  // Create two linked lists in the reverse order, to represent numbers 9234 and 889
  insert(list1, 4); // Add the digit 4 to the list
  insert(list1, 3); // Add the digit 3 to the list
  insert(list1, 2); // Add the digit 2 to the list
  insert(list1, 9); // Add the digit 9 to the list
  std::cout << "\n\nNow follow up case, lists are stored such that 1's digit is at the tail of list\n";
  std::cout << "List1:  "; // Print a message to indicate which list is being printed
  printList(list1); // Print the linked list

  insert(list2, 9); // Add the digit 9 to the list
  insert(list2, 9); // Add the digit 9 to the list
  insert(list2, 8); // Add the digit 8 to the list

  std::cout << "List2:  "; // Print a message to indicate which list is being printed
  printList(list2); // Print the linked list

  list3 = add_followup(list1, list2);  // Add the two lists using the followup approach
  std::cout << "Adding two above lists\n"; // Print a message to indicate which list is being printed
  std::cout << "List3:  "; // Print a message to indicate which list is being printed
  printList(list3); // Print the linked list

  deleteList(list1); //delete the list 1
  deleteList(list2);//delete the list 2
  deleteList(list3); //delete the list 3

  return 0;
}