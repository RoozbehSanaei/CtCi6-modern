#include <iostream>
#include <random>

/**
 * @brief The Node struct represents a node in a singly linked list.
 */
struct Node {
  int data; ///< The integer data stored in the node.
  Node * next; ///< A pointer to the next node in the list.

  /**
   * @brief Construct a new Node object.
   * 
   * @param d The integer data to be stored in the node.
   */
  Node( int d ) : data{ d }, next{ nullptr } { }
};



/**
 * @brief Insert a new node with the given integer data at the end of a singly linked list.
 * 
 * @param head A reference to a pointer to the head of the list.
 * @param data The integer data to be stored in the new node.
 */
void insert( Node * & head, int data ) {
  // Create a new node with the given data value.
  Node * newNode = new Node(data);

  // If the list is empty, make the new node the head of the list.
  if ( head == nullptr ) {
    head = newNode;
  } else {
    // Otherwise, traverse the list to the end and insert the new node there.
    Node * curr = head;
    while( curr->next ) {
      curr = curr->next;
    }
    curr->next = newNode;
  }
}


/**
 * @brief Print the contents of a linked list.
 *
 * This function prints the contents of a linked list starting from the head node until
 * the end of the list is reached. The format of the output is "data-->data-->...-->nullptr".
 *
 * @param head Pointer to the head node of the linked list.
 */
void printList(Node* head) {
  // Iterate over the linked list using a while loop, printing the data value of each node
  while (head) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  
  // Print nullptr to indicate the end of the linked list
  std::cout << "nullptr" << std::endl;
}


/**
 * @brief Partition a linked list into two lists based on a pivot value.
 *
 * This function partitions a linked list into two separate lists based on whether each node's
 * data value is less than or greater than a given pivot value. The nodes with data values less
 * than the pivot value are put into a new list that becomes the "head" list, while the nodes
 * with data values greater than or equal to the pivot value are put into another new list
 * that becomes the "tail" list. The function then connects the tail list to the end of the
 * head list and returns a pointer to the head node of the combined list.
 *
 * @param listhead Pointer to the head node of the linked list to be partitioned.
 * @param x The pivot value used to partition the list.
 * @return Pointer to the head node of the partitioned linked list.
 */
Node* partition(Node* listhead, int x) {
   Node * head = nullptr;
   Node * headInitial = nullptr;   /*The initial node of list head*/
   Node * tail = nullptr;
   Node * tailInitial = nullptr;   /*The initial node of list tail*/
   Node * curr = listhead;
   
   // Iterate over the linked list
   while (curr != nullptr) {
     Node * nextNode = curr->next;
     
     // Check if current node's data is less than the pivot value
     if (curr->data < x) {
       // If head is null, set it to the current node
       if (head == nullptr) {
           head = curr;
           headInitial = head;
       }
       
       // Insert the current node at the end of the head list
       head->next = curr;
       head = curr;
     } else {
       // If tail is null, set it to the current node
       if (tail == nullptr) {
           tail = curr;
           tailInitial = tail;
       }
       
       // Insert the current node at the end of the tail list
       tail->next = curr;
       tail = curr;
     }
     
     // Move to the next node in the original list
     curr = nextNode;
   }
   
   // Connect the tail list to the end of the head list
   head->next = tailInitial;
   tail->next = nullptr;
   
   // Return a pointer to the head node of the combined list
   return headInitial;
}


int main() {
  Node * head = nullptr;
  
  // Insert random integer values into the linked list
  for (int i = 0; i < 10; ++i) {
    insert(head, rand() % 9);
  }
  
  // Print the original list before partitioning
  std::cout << "List before partition around 5:\n";
  printList(head);
  
  // Partition the list around the value 5 and print the modified list
  std::cout << "List after partition around 5:\n";
  printList(partition(head, 5));
  
  return 0;
}
