#include <iostream> //cout
#include <stack> //stack


/**
 * @brief Node structure for a singly linked list
 *
 * This structure represents a node in a singly linked list. Each node contains
 * a character value and a pointer to the next node in the list.
 */
struct Node {
    char data; /**< The character data stored in the node */
    Node *next; /**< Pointer to the next node in the list */

    /**
     * @brief Constructor for Node structure
     *
     * @param c The character value to be stored in the node
     */
    Node(char c) : data{c}, next{nullptr} {}
};


/**
 * Inserts a new node with the given character at the beginning of a linked list.
 *
 * @param head A pointer to the head of the linked list.
 * @param c The character to be stored in the new node.
 */
void insert(Node*& head, char c) {
  // Create a new node with the given character
  Node* newNode = new Node(c);

  // Set the 'next' pointer of the new node to point to the current head of the linked list
  newNode->next = head;

}


/**
 * Prints the data of each node in a linked list.
 *
 * @param head A pointer to the head of the linked list.
 */
void printList(Node* head) {
  // Loop through the linked list until the end is reached
  while (head) {
    // Output the data stored in the current node, followed by an arrow
    std::cout << head->data << "-->";

    // Update the 'head' pointer to point to the next node in the linked list
    head = head->next;
  }

  // Output "nullptr" to indicate the end of the linked list has been reached
  std::cout << "nullptr" << std::endl;
}


/**
 * Reverses a linked list in place.
 *
 * @param head A reference to a pointer to the head of the linked list.
 */
void reverse(Node*& head) {
  // If the linked list is empty or contains only one node, there's nothing to reverse
  if (head == nullptr || (head && (head->next == nullptr))) {
    return;
  }

  // Initialize pointers for the new head and the next node
  Node* newHead = nullptr;
  Node* nextNode = nullptr;

  // Loop through the linked list and reverse the order of the nodes
  while (head) {
    // Store the next node in a temporary pointer
    nextNode = head->next;

    // Reverse the 'next' pointer of the current node to point to the new head
    head->next = newHead;

    // Update the new head pointer to point to the current node
    newHead = head;

    // Update the current node pointer to point to the next node
    head = nextNode;
  }

  // Update the head pointer to point to the new head, which is now the last node in the original linked list
  head = newHead;
}


/**
 * Checks if a linked list is a palindrome using an iterative approach.
 *
 * @param head A pointer to the head of the linked list.
 * @return true if the linked list is a palindrome, false otherwise.
 */
bool isPalindromeIter1(Node* head) {
  // If the linked list is empty or contains only one node, it's considered a palindrome
  if (head == nullptr || head->next == nullptr) {
    return true;
  }

  // Step 1: Figure out the middle node of the linked list
  Node* ptr1 = head;
  Node* ptr2 = head;
  Node* middleNode = nullptr;

  while (ptr2 && ptr1 && ptr1->next) {
    ptr1 = ptr1->next->next;
    ptr2 = ptr2->next;
  }

  // In case of an odd number of nodes, skip the middle one
  if (ptr1 && ptr1->next == nullptr) {
    ptr2 = ptr2->next;
  }

  // Step 2: Reverse the second half of the linked list
  reverse(ptr2);

  middleNode = ptr2;

  // Step 3: Compare the two halves of the linked list
  ptr1 = head;
  while (ptr1 && ptr2 && ptr1->data == ptr2->data) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  // Step 4: Reverse the second half of the linked list again, to keep the sentence intact.
  reverse(middleNode);

  // If ptr2 is null, then the linked list is a palindrome, otherwise it's not
  if (ptr2 == nullptr) {
    return true;
  } else {
    return false;
  }
}


/**
 * @brief Helper function to check whether a sublist is a palindrome recursively.
 * 
 * @param left A reference to the leftmost node of the sublist.
 * @param right A pointer to the rightmost node of the sublist.
 * @return true if the sublist is a palindrome, false otherwise.
 */



/**
 * @brief Check whether a linked list is a palindrome or not using iterative approach.
 * 
 * @param head Pointer to the head node of the linked list.
 * @return true if the linked list is a palindrome, false otherwise.
 */
bool isPalindromeIter2(Node* head) {
  // If the list is empty or just contains one node, it is a palindrome.
  if (head == nullptr || head->next == nullptr) {
    return true;
  }

  // Initialize two pointers to traverse the list.
  Node* ptr1 = head;
  Node* ptr2 = head;

  // Create a stack to push the first half of the list.
  std::stack<Node*> nodeStack;

  // Traverse the list with ptr1 and ptr2, and push the nodes pointed by ptr2 to the stack.
  while (ptr2 && ptr1 && ptr1->next) {
    ptr1 = ptr1->next->next;
    nodeStack.push(ptr2);
    ptr2 = ptr2->next;
  }

  // In case of odd number of nodes, skip the middle one.
  if (ptr1 && ptr1->next == nullptr) {
    ptr2 = ptr2->next;
  }

  // Traverse the second half of the list and compare it with the nodes in the stack.
  while (!nodeStack.empty() && ptr2) {
    Node* curr = nodeStack.top();
    nodeStack.pop();
    if (curr->data != ptr2->data) {
      return false;
    }
    ptr2 = ptr2->next;
  }

  // If we have reached here, it means the linked list is a palindrome.
  return true;
}


/**
 * @brief Helper function to check if a linked list is a palindrome recursively.
 * 
 * @param left A reference to the left node of the current comparison.
 * @param right A pointer to the right node of the current comparison.
 * @return true if the linked list is a palindrome, false otherwise.
 */
bool isPalindromeRecurHelper(Node*& left, Node* right) {
  // Base case: stop when right becomes nullptr
  if (right == nullptr) {
    return true;
  }
  // Recursively check if the rest of the list is a palindrome
  bool isPalindrome = isPalindromeRecurHelper(left, right->next);
  if (!isPalindrome) {
    return false;
  }
  // Check if the current nodes have the same value
  isPalindrome = (left->data == right->data);
  // Move left to the next node for the next call
  left = left->next;
  return isPalindrome;
}

/**
 * @brief Check if a linked list is a palindrome recursively.
 * 
 * @param head A pointer to the head of the linked list.
 * @return true if the linked list is a palindrome, false otherwise.
 */
bool isPalindromeRecur(Node* head) {
  // Call the helper function with the head of the linked list and itself
  // to start the recursive comparison
  return isPalindromeRecurHelper(head, head);
}

int main()
{
  // Create the first linked list
  Node * head1 = nullptr;
  insert( head1, 'a' );
  insert( head1, 'b' );
  insert( head1, 'c' );
  insert( head1, 'c' );
  insert( head1, 'b' );
  insert( head1, 'a' );

  // Print the first list and check if it's a palindrome using isPalindromeIter1
  std::cout << "List 1: ";
  printList(head1);
  if ( isPalindromeIter1(head1) ) {
    std::cout << "List 1 is a palindrome list\n";
  } else {
    std::cout << "List 1 is not a palindrome list\n";
  }
  std::cout << "List 1: ";
  printList(head1);

  // Create the second linked list
  Node * head2 = nullptr;
  insert( head2, 'r');
  insert( head2, 'a');
  insert( head2, 'd');
  insert( head2, 'a');
  insert( head2, 'r');

  // Print the second list and check if it's a palindrome using isPalindromeIter2
  std::cout << "List 2: ";
  printList(head2);
  if ( isPalindromeIter2( head2 ) ) {
    std::cout << "List 2 is a palindrome list\n";
  } else {
    std::cout << "List 2 is not a palindrome list\n";
  }
  std::cout << "List 2: ";
  printList(head2);

  // Create the third linked list
  Node * head = nullptr;
  insert( head, 'a' );
  insert( head, 'b' );
  insert( head, 'c' );
  insert( head, 'b' );
  insert( head, 'd' );

  // Print the third list and check if it's a palindrome using isPalindromeRecur
  std::cout << "List 3: ";
  printList(head);
  if ( isPalindromeRecur(head) ) {
    std::cout << "List 3 is a palindrome list\n";
  } else {
    std::cout << "List 3 is not a palindrome list\n";
  }
  std::cout << "List 3: ";
  printList(head);
  return 0;
}
