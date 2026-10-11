#include <iostream>
#include <vector>
using namespace std;

// =============================
// 1️⃣ Vector-based Stack class
// =============================
template<class TemplateCustom, int capacity = 30>
class Stack {
private:
    vector<TemplateCustom> PoolStack;

public:
    Stack() {
        PoolStack.reserve(capacity);
    }

    bool IsStackEmpty() const { 
        return PoolStack.empty();
    }

    TemplateCustom& GetTopElement() {
        return PoolStack.back();
    }

    TemplateCustom Pop_PoolStack() {
        TemplateCustom PopedElement_head = PoolStack.back();
        PoolStack.pop_back();
        return PopedElement_head;
    }

    void Push_PoolElement(const TemplateCustom& newNode) {
        PoolStack.push_back(newNode);
    }
};

// =============================
// 2️⃣ Node class (for linked list stack)
// =============================
template<class TemplateCustomListelem>
class Node {
private:
    TemplateCustomListelem value;
    Node* next;

public:
    Node(TemplateCustomListelem newVal) {
        value = newVal;
        next = nullptr;
    }

    Node(const Node& other) {
        this->value = other.value;
        this->next = other.next;
    }

    Node& operator=(const Node& other) {`
        if (this != &other) {
            this->value = other.value;
            this->next = other.next;
        }
        return *this;
    }

    TemplateCustomListelem& getValue() {
        return value;
    }

    void setValue(const TemplateCustomListelem& newValue) {
        value = newValue;
    }

    Node* getNext() {
        return next;
    }

    void setNext(Node* newNext) {
        next = newNext;
    }

    ~Node() {
        next = nullptr;
    }
};

// =============================
// 3️⃣ Linked List-based Stack
// =============================
template<class T>
class LinkedListStack {
private:
    Node<T>* head;

public:
    LinkedListStack() {
        head = nullptr;
    }

    ~LinkedListStack() {
        while (head) {
            Node<T>* temp = head;
            head = head->getNext();
            delete temp;
        }
    }

    bool IsEmpty() const {
        return head == nullptr;
    }

    void Push(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->setNext(head);
        head = newNode;
    }

    T Pop() {
        if (IsEmpty()) {
            throw runtime_error("Stack underflow!");
        }
        Node<T>* temp = head;
        T value = temp->getValue();
        head = head->getNext();
        delete temp;
        return value;
    }

    T& Top() {
        if (IsEmpty()) {
            throw runtime_error("Stack is empty!");
        }
        return head->getValue();
    }
};










// =============================
// 4️⃣ Main function test
// =============================
int main() {
    // Test vector-based stack
    Stack<int> s;
    s.Push_PoolElement(10);
    s.Push_PoolElement(20);
    cout << "Vector Stack Top: " << s.GetTopElement() << endl;

    // Test linked list-based stack
    LinkedListStack<int> ls;
    ls.Push(5);
    ls.Push(15);
    cout << "Linked List Stack Top: " << ls.Top() << endl;
    cout << "Popped: " << ls.Pop() << endl;
    cout << "Now Top: " << ls.Top() << endl;

    return 0;
}
