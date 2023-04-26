#include <iostream> // cout
#include <random> // random_device, mt19937, uniform_int_distribution
#include <unordered_map> //unordered_map


/**
 * @brief Represents a node in a linked list
 */
struct Node {
    int data = 0; ///< The value stored in the node
    Node * next = nullptr; ///< A pointer to the next node in the list (or nullptr if this is the last node)
};


/**
 * @brief Inserts a new node with the given data at the beginning of a linked list
 * @param head A reference to a pointer to the first node in the list
 * @param data The value to be stored in the new node
 */
void insert(Node *&head, int data) {
    Node *newNode = new Node; ///< Create a new node using the "new" keyword
    newNode->data = data; ///< Set the data member of the new node to the given value
    newNode->next = head; ///< Set the next member of the new node to the current head of the list
    head = newNode; ///< Set the head of the list to the new node
}


/**
 * @file node.h
 * @brief Defines the Node struct for use in linked lists
 */

/**
 * @brief Represents a node in a linked list
 */
struct Node {
    int data = 0; ///< The value stored in the node
    Node * next = nullptr; ///< A pointer to the next node in the list (or nullptr if this is the last node)
};

/**
 * @brief Prints the values of all the nodes in a linked list
 * @param head A pointer to the first node in the list
 */
void printList(Node *head) {
    while (head) { ///< While there are still nodes in the list
        std::cout << head->data << "-->"; ///< Print the value of the current node, followed by an arrow
        head = head->next; ///< Move to the next node in the list
    }
    std::cout << "nullptr" << std::endl; ///< Print "nullptr" to indicate the end of the list
}



/**
 * @brief Generates a random integer within a specified range
 * @param min The minimum value that the random number can take
 * @param max The maximum value that the random number can take
 * @return A random integer within the specified range
 */
static inline int random_range(const int min, const int max) {
    std::random_device rd; ///< Create a random_device object to obtain a seed for the random number generator
    std::mt19937 mt(rd()); ///< Create an mt19937 object, which is a pseudorandom number generator that uses the Mersenne Twister algorithm
    std::uniform_int_distribution<int> distribution(min, max); ///< Create a uniform_int_distribution object with the given range
    return distribution(mt); ///< Generate a random integer within the range using the distribution object, and return it
}


/**
 * @brief Removes duplicate nodes from a singly linked list.
 * 
 * @param head A pointer to the head of the linked list.
 */
void removeDuplicates(Node* head) {
    // Check if the list is empty or contains only one node
    if (head == nullptr || (head && (head->next == nullptr))) {
        return;
    }

    // Loop through each node in the list
    Node* curr = head;
    while (curr) {
        // Loop through the rest of the list to check for duplicates
        Node* runner = curr;
        while (runner->next != nullptr) {
            if (runner->next->data == curr->data) {
                // If a duplicate is found, remove it by skipping over it
                runner->next = runner->next->next;
            } else {
                // Otherwise, move on to the next node
                runner = runner->next;
            }
        }
        // Move on to the next node in the list
        curr = curr->next;
    }
}


/**
 * @brief Removes duplicate nodes from a singly linked list.
 * 
 * @param head A pointer to the head of the linked list.
 */
void removeDuplicates1(Node* head) {
    // If the linked list is empty or has only one node, there are no duplicates to remove.
    if (head == nullptr || (head && (head->next == nullptr))) {
        return;
    }
    
    // Create an unordered_map to keep track of nodes that have been seen before.
    std::unordered_map<int, int> node_map;
    
    // Initialize pointers to the head and next nodes.
    Node* prev = head;
    Node* curr = head->next;
    
    // Add the value of the head node to the node_map.
    node_map[head->data] = 1;
    
    // Iterate through the linked list.
    while (curr != nullptr) {
        // If the value of the curr node is already in the node_map, advance curr until it points to a node that has not been seen before.
        while (curr && node_map.find(curr->data) != node_map.end()) {
            curr = curr->next;
        }
        
        // Update prev to point to curr.
        prev->next = curr;
        prev = curr;
        
        // If curr is not nullptr, add its value to the node_map and advance to the next node.
        if (curr) {
            node_map[curr->data] = 1;
            curr = curr->next;
        }
    }
}

/**
 * @brief The main function for testing the removeDuplicates and removeDuplicates1 functions.
 * 
 * @return 0 on success.
 */
int main() {
    // Method 1: Remove duplicates from linked list using removeDuplicates function.
    std::cout << "Method 1 : \n";
    
    // Create an empty linked list and insert 10 random integers in the range of 1 to 7.
    Node* head = nullptr;
    for (int i = 0; i < 10; ++i) {
        insert(head, random_range(1, 7));
    }
    
    // Print the original list.
    printList(head);
    
    // Remove duplicate nodes from the list using removeDuplicates function.
    removeDuplicates(head);
    
    // Print the updated list without duplicates.
    printList(head);
    
    // Method 2: Remove duplicates from linked list using removeDuplicates1 function.
    std::cout << "Method 2 : \n";
    
    // Create another empty linked list and insert 10 random integers in the range of 1 to 7.
    Node* head1 = nullptr;
    for (int i = 0; i < 10; ++i) {
        insert(head1, random_range(1, 7));
    }
    
    // Print the original list.
    printList(head1);
    
    // Remove duplicate nodes from the list using removeDuplicates1 function.
    removeDuplicates1(head1);
    
    // Print the updated list without duplicates.
    printList(head1);
    
    // Return 0 on success.
    return 0;
}


