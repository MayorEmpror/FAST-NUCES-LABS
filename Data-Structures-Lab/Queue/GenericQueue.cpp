#include <iostream>
using namespace std;

template<class type_nodeClassObject>
class Node {
private:
    type_nodeClassObject value_NodeObject;

public:
    Node<type_nodeClassObject>* next_NodeObject;

    Node(type_nodeClassObject NodeObjectvalue) {
        this->value_NodeObject = NodeObjectvalue;
        this->next_NodeObject = nullptr;
    }

    Node(const Node<type_nodeClassObject>& other) {
        this->value_NodeObject = other.value_NodeObject;
        this->next_NodeObject = other.next_NodeObject;
    }
    
    Node<type_nodeClassObject>& operator=(const Node<type_nodeClassObject>& other) {
        if (this != &other) {
            this->value_NodeObject = other.value_NodeObject;
            this->next_NodeObject = other.next_NodeObject;
        }
        return *this;
    }

    type_nodeClassObject getValue_NodeObject() {
        return this->value_NodeObject;
    }

    void setValue_NodeObject(type_nodeClassObject newObjectvalue) {
        this->value_NodeObject = newObjectvalue;
    }

    ~Node() {
        this->next_NodeObject = nullptr;
    }
};

template<class type_QueueValueStorage>
class Queue {
private:
    Node<type_QueueValueStorage>* header_QueueNode;
    Node<type_QueueValueStorage>* tail_QueueNode;
    int capacity;
    int size;

public:
    Queue(int capacity) : capacity(capacity), size(0), header_QueueNode(nullptr), tail_QueueNode(nullptr) {}

    void Enqueue_NodeObject(type_QueueValueStorage newNodeObjectvalue) {
        if (this->size >= this->capacity) {
            cout << "Queue is full!\n";
            return;
        }

        Node<type_QueueValueStorage>* newNode = new Node<type_QueueValueStorage>(newNodeObjectvalue);

        if (this->size > 0) {
            this->tail_QueueNode->next_NodeObject = newNode;
            this->tail_QueueNode = newNode;
        } else {
            this->header_QueueNode = newNode;
            this->tail_QueueNode = newNode;
        }

        this->size++;
    }

    void DeQueue() {
        if (this->size == 0) {
            cout << "Queue is already empty\n";
            return;
        }

        Node<type_QueueValueStorage>* nodetodequeue = this->header_QueueNode;
        this->header_QueueNode = nodetodequeue->next_NodeObject;

        if (this->header_QueueNode == nullptr) {
            this->tail_QueueNode = nullptr;
        }

        delete nodetodequeue;
        this->size--;
    }

    Node<type_QueueValueStorage>* top() {
        if (this->header_QueueNode == nullptr) {
            cout << "Queue is empty\n";
            return nullptr;
        }
        return this->header_QueueNode;
    }

    bool isEmpty() {
        return this->size == 0;
    }

    bool isFull() {
        return this->size == this->capacity;
    }

    void display() {
        Node<type_QueueValueStorage>* temp = this->header_QueueNode;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->getValue_NodeObject() << " ";
            temp = temp->next_NodeObject;
        }
        cout << endl;
    }
};

int main() {
    Queue<int> q(5);
    q.Enqueue_NodeObject(10);
    q.Enqueue_NodeObject(20);
    q.Enqueue_NodeObject(30);
    q.display();

    q.DeQueue();
    q.display();

    Node<int>* front = q.top();
    if (front)
        cout << "Front element: " << front->getValue_NodeObject() << endl;

    return 0;
}
