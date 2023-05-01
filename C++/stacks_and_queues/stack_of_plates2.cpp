#include<iostream>
#include<stack>
#include<climits>
using namespace std;
#define STACK_NUM 100
class newStack{
private:
    std::stack<int> *myStack;   ///< Pointer to an array of stacks of integers.
    int threshold;              ///< Maximum size of each stack.
    int curStack;               ///< Index of the current stack in use.

public:
    /**
     * @brief Constructor that initializes the threshold to 10,
     * allocates memory for an array of stacks, and sets the current stack index to 0.
     */
    newStack(){
        threshold = 10;                     // Set the maximum size of each stack to 10.
        myStack = new std::stack<int>[STACK_NUM];   // Allocate memory for an array of stacks.
        curStack = 0;                       // Set the current stack index to 0.
    }

    /**
     * @brief Adds a new element to the current stack. If the current stack
     * is full (i.e., its size reaches the threshold), a new stack is created,
     * and the new element is added to it.
     * @param data The integer value to be added to the stack.
     */
    void push(int data){
        if(myStack[curStack].size()>=threshold){   // If the current stack is full,
            curStack++;                             // Switch to the next stack.
        }
        myStack[curStack].push(data);               // Add the element to the current stack.
    }

    /**
     * @brief Removes the top element of the current stack. If the current stack
     * is empty, it switches to the previous stack (if any) and removes its top element.
     */
    void pop(){
        if(myStack[curStack].empty()){              // If the current stack is empty,
            if(curStack == 0){                      // And it is the first stack,
                std::cout<<"Current stack is empty\n";   // Display a message.
                return;                             // Exit the function.
            }
            curStack--;                             // Switch to the previous stack.
        }
        myStack[curStack].pop();                    // Remove the top element of the current stack.
    }

    /**
     * @brief Returns the top element of the current stack. If the current stack
     * is empty, it switches to the previous stack (if any) and returns its top element.
     * If there is no element in any stack, it returns INT_MIN.
     * @return The top element of the current stack or INT_MIN if no element is present.
     */
    int top(){
        if(myStack[curStack].empty()){              // If the current stack is empty,
            if(curStack == 0){                      // And it is the first stack,
                return INT_MIN;                     // Return INT_MIN.
            }
            curStack--;                             // Switch to the previous stack.
        }
        return myStack[curStack].top();             // Return the top element of the current stack.
    }

    /**
     * @brief Returns true if the current stack is empty, false otherwise.
     * @return True if the current stack is empty, false otherwise.
     */
    bool empty(){
        if(curStack == 0){                          // If the current stack is the first stack,
            return myStack[curStack].empty();       // Return whether the stack is empty.
        }
        else                                        // Otherwise,
            return false;                           // Return false (the stack is not empty).
    }

    /**
     * @brief Removes the top element of the specified stack. If the stack is empty,
     * it displays a message indicating so.
     * @param index The index of the stack from which the top element should be removed.
     */
    void popAt(int index){
        if(myStack[index].empty()){                    // If the specified stack is empty,
            std::cout<<index<<"th sub-stack is empty"<<'\n';   // Display a message.
            return;                                     // Exit the function.
        }
        myStack[index].pop();                           // Remove the top element of the specified stack.
    }
};

int main(){
    // Create a new instance of newStack called mystack
    newStack mystack;

    // Push the integers 0 through 99 onto the stack
    for(int i=0; i<100; i++)
        mystack.push(i);

    // Pop the top element from the 4th sub-stack in the stack of stacks
    std::cout<<"Pop out one element from 4th stack "<<std::endl;
    mystack.popAt(4);

    // Pop all elements from the stack
    std::cout<<"Pop out all elements from plates of stack."<<std::endl;
    for(int i=0; i<101; i++){
        std::cout<<"Pop out the element: "<<mystack.top()<<std::endl;
        mystack.pop();
    }

    return 0;
}