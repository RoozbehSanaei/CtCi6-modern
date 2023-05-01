#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int> *st){
    stack<int> sorted; // Create an empty stack called sorted to store the sorted elements.

    // While the input stack is not empty, do the following:
    while(!(*st).empty()){
        int tmp = (*st).top(); // Pop the top element from the input stack and store it in a temporary variable called tmp.
        (*st).pop();

        // While the sorted stack is not empty and the top element of the sorted stack is greater than tmp, do the following:
        while(!sorted.empty() && tmp < sorted.top()){
            (*st).push(sorted.top()); // Pop the top element from the sorted stack and push it back onto the input stack.
            sorted.pop();
        }

        sorted.push(tmp); // Push tmp onto the sorted stack.
    }

    // Once the input stack is empty, sorted stack will contain the elements in ascending order. 
    // To reverse the order and obtain the sorted elements in the input stack, do the following:
    while(!sorted.empty()){
        (*st).push(sorted.top()); // Pop the top element from the sorted stack and push it back onto the input stack.
        sorted.pop();
    }

    // The input stack now contains the sorted elements in ascending order.
}


int main(){
stack<int> mystack; // Create an empty stack of integers called mystack.

int arr[] = {6, 4, 8, 9, 10, 99, 7, 1, 100}; // Create an array of integers called arr.

// Loop through each element of the array and push it onto the stack.
for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
    cout<<"Push in element "<<arr[i]<<endl; // Print a message to indicate which element is being pushed onto the stack.
    mystack.push(arr[i]); // Push the current element onto the stack.
}

sortStack(&mystack); // Sort the stack using the sortStack function.

cout<<"The sorted stack is: "<<endl; // Print a message to indicate that the sorted stack is being printed.

// Loop through each element of the sorted stack and print it out.
while(!mystack.empty()){
    cout<<mystack.top()<<'\n'; // Print the top element of the stack.
    mystack.pop(); // Pop the top element off the stack.
}

}