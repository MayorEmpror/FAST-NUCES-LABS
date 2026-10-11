#include <iostream>
#include <stdexcept>
using namespace std;

class Queue {
private:
    int* arr;
    int span;   // capacity
    int count;  // current number of elements
    int head;   // index of front
    int tail;   // index of rear

public:
    Queue(int span) : span(span), count(0), head(0), tail(-1) {
        this->arr = new int[span]; // allocate memory
    }

    ~Queue() {
        delete[] this->arr;
    }

    void Enque(int value) {
        if (isFull()) {
            throw overflow_error("Queue overflowed");
        }
        tail = (tail + 1) % span;
        arr[tail] = value;
        count++;
    }

    int Deque() {
        if (isEmpty()) {
            throw underflow_error("Queue underflow");
        }
        int return_value = arr[head];
        head = (head + 1) % span;
        count--;
        return return_value;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(head + i) % span] << " ";
        }
        cout << endl;
    }

    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == span; }
    int size() const { return count; }
};

// Test
int main() {
    try {
        Queue myqueue(7);

        myqueue.Enque(6);
        myqueue.Enque(10);
        myqueue.Enque(15);

        myqueue.display();

        cout << "Dequeued: " << myqueue.Deque() << endl;
        myqueue.display();

    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
