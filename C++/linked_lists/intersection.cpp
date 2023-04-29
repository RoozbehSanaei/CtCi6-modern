
#include <iostream>
#include <cmath>

/**
 * @file linkedlist.cpp
 * @brief Implementation of a singly linked list
 */

/**
 * @struct Node
 * @brief Represents a node in a singly linked list
 */
struct Node {
  int data; /**< The data stored in the node */
  Node * next; /**< Pointer to the next node in the list, or nullptr if there is none */

  /**
   * @brief Constructor for a node
   * @param d The data to be stored in the node
   */
  Node( int d ) : data{ d }, next{ nullptr } { }
};


/**
 * @brief Prints the data of each node in a singly linked list.
 * 
 * @param head A pointer to the head node of the linked list.
 */
void printList(Node* head)
{
    // Loop through the list until the head pointer is null
    while (head != nullptr) {
        // Print the data of the current node, followed by an arrow
        std::cout << head->data << "-->";

        // Move to the next node
        head = head->next;
    }

    // Print "NULL" to indicate the end of the list
    std::cout << "NULL" << std::endl;
}

/**
 * @brief Calculate the length of a linked list.
 *
 * This function takes a pointer to the head node of a singly-linked list as input and
 * returns an integer value representing the number of nodes in the list.
 *
 * @param head A pointer to the head node of the linked list.
 * @return An integer value representing the number of nodes in the list.
 */
int listLen(Node* head)
{
    int count = 0; // Initialize count to 0
    while (head) // Traverse the linked list until the end is reached (head == NULL)
    {
        head = head->next; // Move the head pointer to the next node
        count++; // Increment the count variable
    }
    return count; // Return the count of nodes
}


/**
 * [intersectionPoint Returns the point of intersection of two lists]
 * @param  head1 [ head of list 1 ]
 * @param  head2 [ head of list 2 ]
 * @return       [ Intersecting node, if lists intersect, else nullptr]
 */
Node * intersectionPoint( Node * head1, Node * head2 )
{
  int len1 = listLen(head1);
  int len2 = listLen(head2);
  //figure out the bigger list ( and smaller )
  //ptr points to bigger list, let us move the difference
  //between the two.
  Node * ptr1 = ( len1 > len2 ) ? head1 : head2;
  Node * ptr2 = ( len1 > len2 ) ? head2 : head1;
  int i = 0;
  while ( i < std::abs(len1 - len2) && ptr1 ) {
    ptr1 = ptr1->next;
    ++i;
  }
  //Now we have equal nodes to travel on both the nodes
  // traversing and comparing the pointers.

  while( ptr1 && ptr2 ) {
    if ( ptr1 == ptr2 ) {
      return ptr1;
    }
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  return nullptr;
}

#include <iostream>

// Node class for creating linked lists
class Node {
public:
    int data; // The data value stored in the node
    Node* next; // Pointer to the next node in the list

    // Constructor to create a new node with a given data value
    Node(int data) : data(data), next(nullptr) {}
};

// Function to print the nodes in a linked list
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Function to find the intersection point of two linked lists
Node* intersectionPoint(Node* head1, Node* head2) {
    // TODO: Implement algorithm to find intersection point
}

int main() {
    // Create linked list 1
    Node* list1 = new Node(3);
    list1->next = new Node(6);
    list1->next->next = new Node(9);
    list1->next->next->next = new Node(12);
    list1->next->next->next->next = new Node(15);
    list1->next->next->next->next->next = new Node(18);

    // Create linked list 2
    Node* list2 = new Node(3);
    list2->next = list1->next;
    list2->next->next = list1->next->next;
    list2->next->next->next = list1->next->next->next;
    list2->next->next->next->next = new Node(15);
    list2->next->next->next->next->next = new Node(18);

    // Print the two linked lists
    std::cout << "List 1: ";
    printList(list1);
    std::cout << "List 2: ";
    printList(list2);

    // Find the intersection point of the two linked lists
    Node* intersectingNode = intersectionPoint(list1, list2);
    if (intersectingNode) {
        std::cout << "Intersecting Node of lists is: " << intersectingNode->data << std::endl;
    } else {
        std::cout << "Lists do not intersect" << std::endl;
    }

    return 0;
}
