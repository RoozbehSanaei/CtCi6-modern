#include <iostream> //cout, endl

/**
 * @brief The Node struct represents a node in a linked list.
 * 
 * Each node contains an integer data member and a pointer to the next node in the list.
 * If this is the last node in the list, the next pointer will be set to nullptr.
 */
struct Node {
  int data; /**< The integer data stored in the node. */
  Node * next; /**< A pointer to the next node in the linked list. */

  /**
   * @brief Constructs a new Node object with the given data value and null next pointer.
   * 
   * @param d The integer data value to be stored in the new node.
   */
  Node( int d ) : data{ d }, next{ nullptr } { }
};


/**
 * @brief Removes a loop in a linked list.
 * 
 * This function takes in two arguments: a pointer to the node where the loop starts (loopNode) and a pointer to the head of the linked list (head).
 * 
 * @param loopNode Pointer to the node where the loop starts.
 * @param head Pointer to the head of the linked list.
 */
void removeLoop(Node* loopNode, Node* head)
{
  // Initialize two pointers ptr1 and ptr2 to head and loopNode, respectively
  Node* ptr1 = head;
  Node* ptr2 = loopNode;

  // Move ptr1 and ptr2 until they point to the same node, which is the start of the loop
  while (ptr1->next != ptr2->next) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  // Set the next pointer of ptr2 to null, effectively breaking the loop
  ptr2->next = nullptr;
}


/**
 * @brief Detects and removes a loop in a linked list using Floyd's Cycle detection algorithm.
 * 
 * This function takes in a pointer to the head of the linked list (head). It uses two pointers, fastPtr and slowPtr, to traverse the linked list. If there is a loop in the linked list, it removes the loop using the removeLoop() function.
 * 
 * @param head Pointer to the head of the linked list.
 * @return true if a loop was detected and removed, false otherwise.
 */
bool detectAndRemoveCycle(Node* head)
{
  // Check if head is null
  if (head == nullptr) {
    return false;
  }

  // Initialize two pointers, fastPtr and slowPtr, to head
  Node* fastPtr = head;
  Node* slowPtr = head;

  // Traverse the linked list using Floyd's Cycle detection algorithm
  while (slowPtr && fastPtr && fastPtr->next) {
    // Move fastPtr two steps forward and slowPtr one step forward
    fastPtr = fastPtr->next->next;
    slowPtr = slowPtr->next;

    // Check if fastPtr and slowPtr are pointing to the same node
    if (fastPtr == slowPtr) {
      // If there is a loop, remove it and return true
      removeLoop(slowPtr, head);
      return true;
    }
  }

  // If there is no loop, return false
  return false;
}


/**
 * @brief Inserts a new node with the specified data into the linked list.
 * 
 * @param head The head pointer of the linked list.
 * @param data The data to be inserted into the linked list.
 */
void insert( Node * & head, int data )
{
  // Create a new node with the specified data
  Node * newNode = new Node( data );
  
  // If the head pointer is null, set it to the new node
  if ( head == nullptr ) {
    head = newNode;
  } 
  // Otherwise, traverse the linked list to find the end and insert the new node
  else {
    // Use a temporary pointer to traverse the linked list
    Node * temp = head;
    while( temp->next != nullptr ) {
      temp = temp->next;
    }
    // Set the next pointer of the last node to the new node
    temp->next = newNode;
  }
}

/**
 * @brief Prints the contents of a linked list to the console.
 * 
 * @param head The head pointer of the linked list to be printed.
 */
void printList( Node * head )
{
  // Traverse the linked list until the end is reached
  while( head ) {
    // Print the data in the current node, followed by an arrow
    std::cout << head->data << "-->";
    // Move to the next node in the linked list
    head = head->next;
  }
  // Print "NULL" to indicate the end of the linked list
  std::cout << "NULL" << std::endl;
}


int main() {
    Node* head = nullptr;
    // Insert nodes with values 1 to 5 at the end of the list
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    std::cout << "Current List:\n";
    // Print the contents of the list
    printList(head);
    // Insert a loop by connecting the last node to the second node
    std::cout << "Inserting loop, connecting 5 to 3\n";
    head->next->next->next->next->next = head->next;
    // Detect and remove any loops in the list
    std::cout << "Detecting and deleting loop\n";
    detectAndRemoveCycle(head);
    std::cout << "Back to the same old list\n";
    // Print the contents of the list after removing the loop
    printList(head);
    return 0;
}





