#include <iostream>
#include <string>
using namespace std;

template <class type>
class Node {
private:
    type value;

public:
    Node<type>* next;

    Node(type value) {
        this->value = value;
        this->next = nullptr;
    }

    type getvalue() { return this->value; }

    void setvalue(type newvalue) { this->value = newvalue; }

    Node(const Node<type>& other) {
        this->value = other.value;
        this->next = other.next;
    }

    Node<type>& operator=(const Node<type>& other) {
        if (this != &other) {
            this->value = other.value;
            this->next = other.next;
        }
        return *this;
    }

    ~Node() { next = nullptr; }
};

template <class typeNode>
class Stack {
public:
    Node<typeNode>* top;
    int size;
    int capacity;

    Stack(int cap = 100) {
        this->capacity = cap;
        this->size = 0;
        this->top = nullptr;
    }

    void push(typeNode c) {
        if (size >= capacity) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        Node<typeNode>* newNode = new Node<typeNode>(c);
        newNode->next = this->top;
        this->top = newNode;
        this->size++;
    }

    typeNode topElement() {
        if (this->top == nullptr) {
            cout << "Stack is empty!" << endl;
            return typeNode();
        }
        return this->top->getvalue();
    }

    void pop() {
        if (this->top == nullptr) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        Node<typeNode>* nodetodel = this->top;
        this->top = this->top->next;
        delete nodetodel;
        this->size--;
    }

    bool isEmpty() { return this->top == nullptr; }

    ~Stack() {
        while (!isEmpty()) pop();
    }
};


bool isOperator(char c) { return (c == '+' || c == '-' || c == '*' || c == '/'); }

string postfixToPrefix(const string& postfix) {
    Stack<string> st(postfix.length());
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        if (isOperator(c)) {
            string operand1 = st.topElement(); st.pop();
            string operand2 = st.topElement(); st.pop();
            string temp = string(1, c) + operand2 + operand1;
            st.push(temp);
        } else {
            st.push(string(1, c));
        }
    }
    return st.topElement();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;
    string prefix = postfixToPrefix(postfix);
    cout << "Converted expression: " << prefix << endl;
    return 0;
}
