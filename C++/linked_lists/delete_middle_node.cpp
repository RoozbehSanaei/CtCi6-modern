#include <iostream>
// This code defines a singly linked list node structure and provides two helper functions, `printList()` and `deleteNode()`.

// Definition of a singly linked list node structure
struct Node {
  char data; // The data value stored in the node
  Node * next; // Pointer to the next node in the list

  // Constructor for Node structure
  Node( char c ) : data{ c }, next{ nullptr } { }
};

/**
 * Prints the data values for each node in the linked list
 * @param head Pointer to the head of the linked list
 */
void printList( Node * head ) {
  while( head ) { // loop while the head pointer is not null
    std::cout << head->data << "-->"; // output the data value of the current node, followed by an arrow
    head = head->next; // move to the next node
  }
  std::cout << "nullptr" << std::endl; // output "nullptr" to indicate the end of the list
}

/**
 * Deletes a node from the linked list
 * @param node Pointer to the node to be deleted
 */
void deleteNode( Node * node ) {
  if ( node == nullptr || node->next == nullptr ) { // check if the given node is null or the last node in the list
    return; // if so, return without doing anything
  }
  Node * nextNode = node->next; // store a pointer to the next node in the list
  node->data = nextNode->data; // copy the data value of the next node into the current node
  node->next = nextNode->next; // set the next pointer of the current node to skip the next node
  delete nextNode; // delete the next node from memory
}


/**
 * Main function to demonstrate usage of Node structure and helper functions
 */
int main() {
  Node * head = new Node('a'); // create a new node 'a' and set it as the head of the list
  head->next = new Node('b'); // create a new node 'b' and set it as the next node in the list
  head->next->next = new Node('c'); // create a new node 'c' and set it as the next node in the list
  head->next->next->next = new Node('d'); // create a new node 'd' and set it as the next node in the list
  head->next->next->next->next = new Node('e'); // create a new node 'e' and set it as the next node in the list

  std::cout << "List before deletion:\n";
  printList(head); // print the original list using the printList() function

  std::cout << "Deleting node containing data as 'c'\n";
  deleteNode(head->next->next); // delete the node containing data value 'c' using the deleteNode() function

  std::cout << "List after deletion:\n";
  printList(head); // print the resulting list after the deletion using printList() function

  return 0; // exit the program
}
