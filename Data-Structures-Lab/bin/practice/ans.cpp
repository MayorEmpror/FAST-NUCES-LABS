#include <iostream>
using namespace std;

// Student class to represent a student
class Student {
    private:
        string name;
        int rollNumber;
    public:
        Student() {
            this->name = "";
            this->rollNumber = -1;
        }

        Student(string name, int rollNumber) : name(name), rollNumber(rollNumber) {}

        Student(const Student& other) {
            this->name = other.name;
            this->rollNumber = other.rollNumber;
        }

        Student& operator=(const Student& other) {
            if (this != &other) {
                this->name = other.name;
                this->rollNumber = other.rollNumber;
                return *this;
            }
            return *this; // No need to assign to the local variable
        }

        string getName() {
            return this->name;
        }

        int getRollNumber() {
            return this->rollNumber;
        }

        ~Student() {}
};

// LinkedList class to represent a linked list
class LinkedList {
    public:
        Node* head;
        Node* tail;
        LinkedList() : head(nullptr), tail(nullptr) {}

        void addNodeStart() {
            if (head == nullptr) {
                head = new Node();
                tail = head;
            } else {
                Node* newNode = new Node();
                newNode->next = head;
                head = newNode;
                tail = head;
            }
        }

        void addNodeEnd() {
            if (tail == nullptr) {
                tail = head = new Node();
            } else {
                Node* newNode = new Node();
                tail->next = newNode;
                tail = newNode;
            }
        }

        void addNodeMiddle() {
            if (head == nullptr) {
                head = new Node();
                tail = head;
            } else {
                Node* newNode = new Node();
                Node* temp = head;
                while (temp != nullptr) {
                    if (temp->next == nullptr) {
                        newNode->next = temp;
                        tail = newNode;
                        break;
                    } else {
                        temp = temp->next;
                    }
                }
                temp->next = newNode;
                tail = newNode;
            }
        }

        void delNodeStart() {
            if (head == nullptr) {
                cout << "List is empty" << endl;
            } else if (head->next == nullptr) {
                delete head;
                head = nullptr;
            } else {
                Node* temp = head;
                while (temp->next != nullptr) {
                    if (temp->next->next == nullptr) {
                        delete temp;
                        head = temp;
                        break;
                    } else {
                        temp = temp->next;
                    }
                }
                delete temp;
            }
        }

        void delNodeEnd() {
            if (tail == nullptr) {
                cout << "List is empty" << endl;
            } else if (tail->next == nullptr) {
                delete tail;
                tail = nullptr;
            } else {
                Node* temp = tail;
                while (temp->next != nullptr) {
                    if (temp->next->next == nullptr) {
                        delete temp;
                        tail = temp;
                        break;
                    } else {
                        temp = temp->next;
                    }
                }
                delete temp;
            }
        }

        void delNodeMiddle() {
            if (head == nullptr) {
                cout << "List is empty" << endl;
            } else if (head->next == nullptr) {
                delete head;
                head = nullptr;
            } else {
                Node* temp = head;
                while (temp->next->next != nullptr) {
                    if (temp->next->next->next == nullptr) {
                        delete temp->next;
                        break;
                    } else {
                        temp = temp->next;
                    }
                }
                delete temp->next;
                delete temp;
            }
        }

        void printList() {
            if (head == nullptr) {
                cout << "List is empty" << endl;
            } else {
                Node* temp = head;
                while (temp != nullptr) {
                    cout << temp->name << " " << temp->rollNumber << endl;
                    temp = temp->next;
                }
            }
        }
};

// Bubble sort function
void bubbleSort(LinkedList& list) {
    for (Node* i = list.head; i != nullptr; i = i->next) {
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (i->rollNumber < j->rollNumber) {
                swapNodes(i, j);
            }
        }
    }
}

// Swap two nodes in a linked list
void swapNodes(Node& a, Node& b) {
    Node temp = a;
    a = b;
    b = temp;
}

// Main function
int main() {
    LinkedList list;

    // Add some nodes to the linked list
    list.addNodeStart();
    list.addNodeEnd();
    list.addNodeMiddle();
    list.addNodeEnd();

    cout << "Original List:" << endl;
    list.printList();

    cout << "Sorted List:" << endl;
    bubbleSort(list);

    cout << "Student Information:" << endl;
    while (list.head != nullptr) {
        list.printList();
        list.delNodeEnd();

        // Update rollNumber based on bubble sort
        list.rollNumber++;
        list.printList();
        cout << "Updated Roll Number: " << list.rollNumber << endl;
    }

    return 0;
}