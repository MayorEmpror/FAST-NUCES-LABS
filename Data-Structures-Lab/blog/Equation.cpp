#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T val;
    Node* next;
    Node(T val) {
        this->val = val;
        this->next = nullptr;
    }
};

template <typename T>
class Stack {
    Node<T>* top;
    int capacity;
    int size;

public:
    Stack(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->top = nullptr;
    }

    bool isEmpty() {
        return this->size == 0;
    }

    void pushdata(T value) {
        if (this->size == this->capacity) {
            cout << "Stack overflow" << endl;
            return;
        }
        Node<T>* newNode = new Node<T>(value);
        newNode->next = this->top;
        this->top = newNode;
        this->size++;
    }

    T pop() {
        if (this->size == 0) {
            cout << "Stack underflow" << endl;
            return T();
        }
        T returnvalue = this->top->val;
        Node<T>* nodetopop = this->top;
        this->top = this->top->next;
        delete nodetopop;
        this->size--;
        return returnvalue;
    }

    T peek() {
        if (this->isEmpty()) {
            cout << "Stack is empty" << endl;
            return T();
        }
        return this->top->val;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int precedence_function(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string infixtopostfix(string infix) {
    string postfix = "";
    Stack<char> stack_operators(infix.length());

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // Operand
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            postfix += c;
        }
        // Opening bracket
        else if (c == '(') {
            stack_operators.pushdata(c);
        }
        // Closing bracket
        else if (c == ')') {
            while (!stack_operators.isEmpty() && stack_operators.peek() != '(') {
                postfix += stack_operators.pop();
            }
            if (!stack_operators.isEmpty() && stack_operators.peek() == '(')
                stack_operators.pop(); // remove '('
        }
        // Operator
        else {
            while (!stack_operators.isEmpty() &&
                   precedence_function(c) <= precedence_function(stack_operators.peek())) {
                postfix += stack_operators.pop();
            }
            stack_operators.pushdata(c);
        }
    }

    // Append remaining operators
    while (!stack_operators.isEmpty()) {
        postfix += stack_operators.pop();
    }

    return postfix;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix:   " << infix << endl;
    cout << "Postfix: " << infixtopostfix(infix) << endl;
    return 0;
}
