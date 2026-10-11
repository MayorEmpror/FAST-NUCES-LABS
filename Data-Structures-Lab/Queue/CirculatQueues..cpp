#include <iostream>
using namespace std;

template <class T>
class CircularQueue {
private:
    T* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    // Constructor
    CircularQueue(int capacity) {
        this->capacity = capacity;
        this->arr = new T[capacity];
        this->front = -1;
        this->rear = -1;
        this->size = 0;
    }

    // Check if empty
    bool isEmpty() const {
        return size == 0;
    }

    // Check if full
    bool isFull() const {
        return size == capacity;
    }

    // Enqueue
    void enqueue(T value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue.\n";
            return;
        }

        // First insertion
        if (front == -1) {
            front = 0;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    // Dequeue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue.\n";
            return;
        }

        // If removing the last element
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
    }

    // Get front element
    T peek() const {
        if (isEmpty()) {
            throw runtime_error("Queue is empty!");
        }
        return arr[front];
    }

    // Display the queue contents
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }

    // Destructor
    ~CircularQueue() {
        delete[] arr;
    }
};
