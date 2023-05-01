#include <iostream>
using namespace std;

class MyBaseClass {
public:
    int count; // public class-level variable
};

class MyDerivedClass : public MyBaseClass {
public:
    MyDerivedClass(int initialCount) : MyBaseClass({initialCount}) {}
    void incrementCount();
};

void MyDerivedClass::incrementCount() {
    count++; // accessing and modifying the class-level variable
}

// usage
int main() {
    MyDerivedClass derived(0); // create an object of MyDerivedClass with initial count 0
    cout << derived.count << endl; // output: 0

    derived.incrementCount();
    cout << derived.count << endl; // output: 1

    derived.incrementCount();
    cout << derived.count << endl; // output: 2

    return 0;
}
