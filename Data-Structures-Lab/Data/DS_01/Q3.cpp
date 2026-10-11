#include <iostream>
using namespace std;

class Box {
private:
    int* value;  // Dynamically allocated integer

public:
    // Default constructor
    Box(int val = 2005) {
        value = new int(val);
        cout << "Constructor called. Value = " << *value << endl;
    }

    // Destructor
    ~Box() {
        cout << "Destructor called. Deleting value = " << *value << endl;
        delete value;
    }

    // Copy Constructor (Deep Copy)
    Box(const Box& other) {
        value = new int(*other.value);
        cout << "Copy Constructor called. Value copied = " << *value << endl;
    }

    // Copy Assignment Operator (Deep Copy)
    Box& operator=(const Box& other) {
        if (this != &other) {
            delete value;  // clean up existing
            value = new int(*other.value);  // deep copy
            cout << "Copy Asignment Operator called. Value copied = " << *value << endl;
        }
        return *this;
    }

    // Setter
    void setValue(int val) {
        *value = val;
    }

    // Getter
    int getValue() const {
        return *value;
    }

    // Display value
    void display() const {
        cout << "Value: " << *value << " (Adress: " << value << ")" << endl;
    }
};


int main() {
    cout << "=== Creating box1 ===" << endl;
    Box box1(1974);
    box1.display();

    cout << "\n=== Creating box2 using copy constructor ===" << endl;
    Box box2 = box1;  // Calls copy constructor (deep copy)
    box2.display();

    cout << "\n=== Changing box2's value to 42 ===" << endl;
    box2.setValue(42);

    cout << "box1: ";
    box1.display();
    cout << "box2: ";
    box2.display();

    cout << "\n=== Creating box3 and using copy assignment ===" << endl;
    Box box3;
    box3 = box1;  // Calls copy assignment operator
    box3.display();

    cout << "\n=== Changing box3's value to 33 ===" << endl;
    box3.setValue(33);
    cout << "box1: ";
    box1.display();
    cout << "box3: ";
    box3.display();

    return 0;
}
