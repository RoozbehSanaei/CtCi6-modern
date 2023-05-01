#include<iostream>
#include<queue>
using namespace std;
/**
 * @file animal.h
 * @brief A class for managing dogs and cats using a queue-based data structure.
 */


/**
 * @brief A class for managing dogs and cats using a queue-based data structure.
 */
class animal {
private:
    std::queue<int> dog; /**< Queue of dog order numbers */
    std::queue<int> cat; /**< Queue of cat order numbers */
    int order; /**< Counter for the order number of enqueued animals */

public:
    /**
     * @brief Constructor for the animal class.
     * Initializes the order counter to 1.
     */
    animal() {
        order = 1;
    }

    /**
     * @brief Enqueues a new animal (dog or cat) to the appropriate queue.
     * @param a A string indicating the type of animal to add ("dog" or "cat").
     * @return The order number of the added animal.
     */
    int enque(std::string a) {
        // Check the type of animal to enqueue
        if(a == "dog") {
            // If it's a dog, add its order number to the dog queue
            dog.push(order);
        } else if(a == "cat") {
            // If it's a cat, add its order number to the cat queue
            cat.push(order);
        }
        // Increment the order counter and return the order number of the added animal
        order++;
        return order - 1;
    }

    /**
     * @brief Dequeues the oldest animal (either a dog or a cat) from the queue.
     * @return The order number of the dequeued animal.
     */
    int dequeAny() {
        int tmp;
        // If there are no dogs in the queue, dequeue the oldest cat
        if(dog.empty()) {
            tmp = cat.front();
            cat.pop();
        // If there are no cats in the queue, dequeue the oldest dog
        } else if(cat.empty()) {
            tmp = dog.front();
            dog.pop();
        // If there are both dogs and cats in the queue, compare their order numbers and dequeue the oldest one
        } else if(dog.front() > cat.front()) {
            tmp = cat.front();
            cat.pop();
        } else {
            tmp = dog.front();
            dog.pop();
        }
        // Return the order number of the dequeued animal
        return tmp;
    }

    /**
     * @brief Dequeues the oldest dog from the queue.
     * @return The order number of the dequeued dog.
     * @note Prints an error message and exits the program if there are no dogs in the queue.
     */
    int dequeDog() {
        // If there are no dogs in the queue, print an error message and exit the program
        if(dog.empty()) {
            printf("There is no more dogs!");
            getchar();
            exit(0);
        }
        // Dequeue the oldest dog and return its order number
        int tmp = dog.front();
        dog.pop();
        return tmp;
    }

    /**
     * @brief Dequeues the oldest cat from the queue.
     * @return The order number of the dequeued cat.
     * @note Prints an error message and exits the program if there are no cats in the queue.
     */
    int dequeCat() {
        // If there are no cats in the queue, print an error message and exit the program
        if(cat.empty()) {
            printf("There is no more cats!");
            getchar();
            exit(0);
        }
        // Dequeue the oldest cat and return its order number
        int tmp = cat.front();
        cat.pop();
        return tmp;
    }
};

int main(){
    animal a;
    cout<<"Shelter received an dog with index "<<a.enque("dog")<<'\n';
    cout<<"Shelter received an cat with index "<<a.enque("cat")<<'\n';
    cout<<"Shelter received an cat with index "<<a.enque("cat")<<'\n';
    cout<<"Shelter received an dog with index "<<a.enque("dog")<<'\n';
    cout<<"Shelter received an cat with index "<<a.enque("cat")<<'\n';
    cout<<"Shelter received an dog with index "<<a.enque("dog")<<'\n';
    cout<<"Shelter received an cat with index "<<a.enque("cat")<<'\n';
    cout<<"Get an animal of any kind. The index is "<<a.dequeAny()<<'\n';
    cout<<"Get a dog. The index is "<<a.dequeDog()<<'\n';
    cout<<"Get a cat. The index is "<<a.dequeCat()<<'\n';
    cout<<"Get a dog. The index is "<<a.dequeDog()<<'\n';
    cout<<"Get a dog. The index is "<<a.dequeDog()<<'\n';
    cout<<"Get a dog. The index is "<<a.dequeDog()<<'\n';
}