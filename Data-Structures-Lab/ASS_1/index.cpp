#include <iostream>          // for input/output
using namespace std;

// ================= NODE CLASS =================
class Node {
public:
    int value;               // value stored in the node
    Node* next;              // pointer to the next node

    // Default constructor
    Node() {
        // this->value = NULL;   // not safe for int (NULL is for pointers)
        this->next = nullptr;   // initially no next node
    }

    // Constructor with value
    Node(int value): value(value) {
        this->next = nullptr;   // next is null initially
    }

    // Copy constructor (shallow copy)
    Node(const Node& other) {
        this->value = other.value;
        this->next = other.next;   // shallow copy of pointer
    }

    // Assignment operator overload
    Node operator=(const Node& other) {
        if (this != &other) {       // avoid self-assignment
            this->value = other.value;
            this->next = other.next; // shallow copy
        }
        return *this;
    }

    // Destructor
    ~Node() {
        this->next = nullptr;   
        delete this;   // ❌ PROBLEM: this deletes itself again (infinite recursion)
                       // should just leave it empty
    }
};

// ================= LINKED LIST CLASS =================
class Linklist {
public:
    Node* head;      // pointer to first node
    Node* tail;      // pointer to last node
    int length;      // number of nodes

    // Constructor initializes empty list
    Linklist() {
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }

    // Destructor: deletes all nodes
    ~Linklist() {
        if (this->head == nullptr) {
            cout << "list is already empty" << endl;
        } else {
            Node* temp = this->head;
            Node* node_delete;
            while (temp != nullptr) {  
                node_delete = temp;    
                temp = temp->next;     
                delete node_delete;    // delete each node
            }
            this->head = nullptr;
            this->tail = nullptr;
        }
    }

    // Add node at beginning
    void Add_begin(int value) {
        Node* newnode = new Node(value); // create new node
        if (this->head != nullptr) {     // if list not empty
            newnode->next = this->head;  // link new node to current head
            this->head = newnode;        // update head to new node
            this->length++;
            return;
        }
        this->head = newnode;            // if list empty, newnode is head
        this->length++;
    }

    // Delete node at beginning
    void Delete_begin() {
        if (this->head == nullptr) {   // empty list
            return;
        }
        Node* to_delete = this->head;  // store head
        this->head = this->head->next; // move head forward
        delete to_delete;              // delete old head
    }

    // Delete node at end
    void Delete_end() {
        Node* nodetodel;
        Node* temp = this->head;
        Node* pre;
        while (temp->next != NULL) {   // traverse to last node
            pre = temp;                
            temp = temp->next;
        }
        nodetodel = temp;              // last node
        this->tail = pre;              // update tail
        pre->next = nullptr;           
        delete nodetodel;              // delete last node
        this->length--;
        return;
    }

    // Add node at end
    void Add_end(int value) {
        Node* newnode = new Node(value);
        if (this->head != nullptr) {   // if list not empty
            Node* temp = this->head;

            while (temp->next != nullptr) { 
                temp = temp->next;
            }
            newnode->next = this->tail;
            temp->next = newnode;
            this->length++;
            return;
        }
        this->head = newnode;          // if list empty, head = newnode
        newnode->next = this->tail;
        this->length++;
    }

    // Add node in middle at index
    void Add_middle(int value,int index) {
        Node* newnode = new Node(value);
        Node* temp = this->head;
        Node* pre;
        if (this->head == nullptr) {   // if list empty
            this->head = newnode;
            newnode->next = this->tail;
            this->length++;
            return;
        }
        // check valid index
        if (this->length < index) {
            cout << "invalid node index entered" << endl;
            return;
        }
        // traverse to index
        for (int i = 1; i <= index; i++) {
            pre = temp;
            temp = temp->next;
        }
        pre->next = newnode;           // insert new node
        newnode->next = temp;
        this->length++;
        return;
    }

    // Delete node from middle at index
    void delete_middle(int index) {
        Node* node_to_delete;
        Node* temp = this->head;
        Node* pre = nullptr;
        if (this->head == nullptr) {   // empty list
            cout << "list is already empty" << endl;
            return;
        }
        for (int i =1 ; i<=index; i++ ) {
            pre  = temp;
            temp = temp->next;
        }
        if (pre == nullptr) {          // deleting head
            node_to_delete = temp;
            if (temp->next != nullptr) {
                this->head = temp->next; 
            }
        } else if (temp->next != nullptr) { // middle node
            pre->next = temp->next;
            node_to_delete = temp;
        } else if (temp->next == nullptr) { // last node
            node_to_delete = temp;
            this->tail = pre;
            pre->next = nullptr;
        } else { 
            cout<<"invalid index entered"<<endl;
        }
        node_to_delete->next = nullptr;     
        delete node_to_delete;
        temp = nullptr;
        pre  = nullptr;
        this->length--;
        return;
    }

    // Display all nodes
    void display() {
        if (this->head == nullptr) {
            cout << "nothing to display here, enter nodes to see "<<endl;
        }
        Node* temp = this->head;
        for (int i = 0; i<this->length; i++) {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        return;
    }

    // ============ Sorting Helpers ============
    Node* mergeSortedLists(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;
    
        Node* result = nullptr;
        if (a->value > b->value) { // descending order
            result = a;
            result->next = mergeSortedLists(a->next, b);
        } else {
            result = b;
            result->next = mergeSortedLists(a, b->next);
        }
        return result;
    }
    
    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;
    
        // split list into two halves
        Node* slow = head;
        Node* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
    
        Node* mid = slow->next;
        slow->next = nullptr;
    
        Node* left = mergeSort(head);
        Node* right = mergeSort(mid);
    
        return mergeSortedLists(left, right);
    }
    
    // Rearrange list: evens first (descending), then odds (descending)
    void EvenOddRearrange() {
        if (this->head == nullptr || this->head->next == nullptr) return;
    
        Node* evenHead = nullptr;
        Node* evenTail = nullptr;
        Node* oddHead = nullptr;
        Node* oddTail = nullptr;
    
        Node* curr = this->head;
        while (curr != nullptr) {
            if (curr->value % 2 == 0) {  // even
                if (evenHead == nullptr) {
                    evenHead = evenTail = curr;
                } else {
                    evenTail->next = curr;
                    evenTail = evenTail->next;
                }
            } else {  // odd
                if (oddHead == nullptr) {
                    oddHead = oddTail = curr;
                } else {
                    oddTail->next = curr;
                    oddTail = oddTail->next;
                }
            }
            curr = curr->next;
        }
    
        // terminate sublists
        if (evenTail) evenTail->next = nullptr;
        if (oddTail) oddTail->next = nullptr;
    
        // sort evens and odds in descending order
        evenHead = mergeSort(evenHead);
        oddHead = mergeSort(oddHead);
    
        // combine
        if (evenHead != nullptr) {
            this->head = evenHead;
            Node* temp = evenHead;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = oddHead;
            this->tail = (oddHead) ? oddTail : temp;
        } else {
            this->head = oddHead;
            this->tail = oddTail;
        }
    }
};

// ================= MAIN =================
void Prompt_ll_input() {
    int size, value;
    cout << "enter size of linklist needed" << endl;
    cin >> size;
    Linklist* ll = new Linklist();
    
    for (int i = 0; i< size; i++) {
        cout << "Enter value for Node : " << i << ": ";
        cin >> value;
        ll->Add_begin(value);  // insert at beginning
    }
    cout << " Entered linklist : " << endl;
    ll->display();
    ll->EvenOddRearrange();  // rearrange and sort
    cout << endl;
    cout << " Sorted linklist : " << endl;
    ll->display();
    return;
}

int main() {
    Prompt_ll_input(); 
    return 0;
}
