#include <iostream>
#include <exception>
using nampace std;

merg(int arr[], int left, int mid, int right){
    int n1 = left +1;
    int n2 = right - mid;

    int* lowarr = new int[n1];
    int* hiarr = new int[n2];

    for(int i = 0; i < n1; i++){
        lowarr[i] = arr[i];
    }
}

template<class typequeue>
class Node{
    private :
    typequeue value;
    public: 
    Node<typequeue>* next;
    Node(typequeue value):value(value){
        this->next = nullptr;
    }
    Node(const Node<typequeue>& other){
        this->value = other.value;
        this->next  = other.next;
    }


    typequeue getvalue(){ return this->value;}
    void setvalue(typequeue newvalue){ this->value = newvalue;}

    Node& operator =(const Node<typequeue>& other){
        if(this != &other){
            this->value = other.value;
            this->next  = other.next;
        }
        return *this;
    }
    ~Node(){

    }
};


#include <iostream>
using namespace std;

template<class typequeue>
class Node {
private:
    typequeue value;
public:
    Node<typequeue>* next;

    Node(typequeue value) : value(value) {
        this->next = nullptr;
    }

    Node(const Node<typequeue>& other) {
        this->value = other.value;
        this->next  = other.next;
    }

    typequeue getvalue() { return this->value; }
    void setvalue(typequeue newvalue) { this->value = newvalue; }

    Node& operator =(const Node<typequeue>& other) {
        if (this != &other) {
            this->value = other.value;
            this->next  = other.next;
        }
        return *this;
    }

    ~Node() {}
};


template<class TYPEDEFQUEUE>
class Queue {
public:
    Node<TYPEDEFQUEUE>* front;
    Node<TYPEDEFQUEUE>* rear;
    int capacity;
    int size;

    Queue(int capacity): capacity(capacity) {
        this->front = nullptr;
        this->rear = nullptr;
        this->size = 0;
    }

    bool isEmpty() {
        return this->size == 0;
    }

    bool isFull() {
        return this->size == this->capacity;
    }

    void enqueue(TYPEDEFQUEUE newValue) {
        if (this->isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }

        Node<TYPEDEFQUEUE>* newNode = new Node<TYPEDEFQUEUE>(newValue);

        if (this->rear == nullptr) {
            this->front = this->rear = newNode;
        } else {
            this->rear->next = newNode;
            this->rear = newNode;
        }

        this->size++;
    }

    TYPEDEFQUEUE top() {
        if (this->isEmpty()) {
            cout << "Queue is empty!\n";
            exit(1);
        }
        return this->front->getvalue();
    }

    void dequeue() {
        if (this->isEmpty()) { return; }

        Node<TYPEDEFQUEUE>* nodetodeq = this->front;
        this->front = this->front->next;
        delete nodetodeq;
        this->size--;

        if (this->front == nullptr)
            this->rear = nullptr;
    }

    ~Queue() {
        while (front != nullptr) {
            Node<TYPEDEFQUEUE>* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
};




int* mergingSorted(int* leftarr, int* rightarr, int sizeleft, int sizeright){
    int* arr = new int[sizeleft + sizeright];
    int i =0, j = 0, k = 0;
    while(i < sizeleft && j < sizeright){
        if(leftarr[i] < rightarr[j]){
            arr[k] = leftarr[i];
            i++
        }else {
            arr[k] = rightarr[j];
        }
        k++;
    }
    while(i < sizeleft){
        arr[k] = leftarr[i];
        i++;
        k++;
    }
    while(j < sizeright){
        arr[k] = rightarr[j];
        j++;
        k++;
    }
    return arr;
}




int main(){

    return 0;
}