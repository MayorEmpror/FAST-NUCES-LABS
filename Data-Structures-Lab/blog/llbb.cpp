#include <iostream>
#include <string>
using namespace std;

// -------------------- Abstract Student --------------------
class Student {
protected:
    string name;
    int roll;
public:
    Student(string name, int roll) : name(name), roll(roll) {}
    virtual void displayInfo() = 0; // pure virtual
    virtual ~Student() {}
};

// -------------------- Undergrad Class --------------------
class Undergrad : public Student {
private:
    string major;
    string uni;
public:
    Undergrad(string name, string uni, string major, int roll)
        : Student(name, roll), major(major), uni(uni) {}

    // default constructor
    Undergrad() : Student("", 0), major(""), uni("") {}

    // copy constructor
    Undergrad(const Undergrad& other) : Student(other.name, other.roll) {
        this->major = other.major;
        this->uni = other.uni;
    }

    // assignment operator
    Undergrad& operator=(const Undergrad& other) {
        if (this != &other) {
            this->name = other.name;
            this->roll = other.roll;
            this->uni = other.uni;
            this->major = other.major;
        }
        return *this;
    }

    void displayInfo() override {
        cout << "Name: " << name
             << ", Roll: " << roll
             << ", University: " << uni
             << ", Major: " << major << endl;
    }

    // getters
    string getMajor() const { return major; }
    string getName() const { return name; }
    int getRoll() const { return roll; }
    string getUniversityName() const { return uni; }

    // setters
    void setMajor(const string& newVal) { major = newVal; }
    void setName(const string& newVal) { name = newVal; }
    void setRoll(int newVal) { roll = newVal; }
    void setUniversityName(const string& newVal) { uni = newVal; }

    ~Undergrad() {}
};

// -------------------- Node Class --------------------
class Node {
public:
    Undergrad student;
    Node* next;

    Node(const Undergrad& input_student_data)
        : student(input_student_data), next(nullptr) {}

    Node() : student(), next(nullptr) {}

    Node(const Node& other) : student(other.student), next(other.next) {}

    Node& operator=(const Node& other) {
        if (this != &other) {
            this->student = other.student;
            this->next = other.next;
        }
        return *this;
    }

    ~Node() {}
};

// -------------------- LinkedList Class --------------------
class LinkedList_students_undergrads {
public:
    Node* head;

    LinkedList_students_undergrads() : head(nullptr) {}

    // add at beginning
    void add_Undergrad_begin(const Undergrad& other) {
        Node* newNode = new Node(other);
        newNode->next = head;
        head = newNode;
    }

    // add at end
    void add_Undergrad_end(const Undergrad& other) {
        Node* newNode = new Node(other);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // delete from beginning
    void delUndergrad_begin() {
        if (head != nullptr) {
            Node* node_to_del = head;
            head = head->next;
            delete node_to_del;
        }
    }

    // delete from end
    void delUndergrad_end() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // add in middle at index
    void addmiddle(int index, const Undergrad& other) {
        if (index == 0) {
            add_Undergrad_begin(other);
            return;
        }
        Node* newNode = new Node(other);
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < index - 1; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) return; // index out of bounds
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // delete from middle at index
    void delmiddle(int index) {
        if (head == nullptr) return;
        if (index == 0) {
            delUndergrad_begin();
            return;
        }
        Node* temp = head;
        for (int i = 0; temp->next != nullptr && i < index - 1; i++) {
            temp = temp->next;
        }
        if (temp->next == nullptr) return; // index out of bounds
        Node* node_to_del = temp->next;
        temp->next = node_to_del->next;
        delete node_to_del;
    }

    // bubble sort by roll number
    void bubbleSort() {
        if (head == nullptr) return;
        bool swapped;
        Node* ptr;
        Node* last = nullptr;
        do {
            swapped = false;
            ptr = head;
            while (ptr->next != last) {
                if (ptr->student.getRoll() > ptr->next->student.getRoll()) {
                    this->printList();
                    cout<<endl;
                    Undergrad temp = ptr->student;
                    ptr->student = ptr->next->student;
                    ptr->next->student = temp;
                    swapped = true;
                }
                ptr = ptr->next;
            }
            last = ptr;
        } while (swapped);
    }

        void CustomBubbleSort_desending(){
            if(head == nullptr){
                reutrn;
            }
            bool swaped;
            Node* ptr;
            Node* last = nullptr;
            do{
            swaped= false;
            while(ptr->next != last){
                if(ptr->student.get()<ptr->next->student.getRoll){
                    Undergrad student = ptr->student;
                    ptr->student = ptr->next->student;
                    ptr->next->student = student;
                    swaped = true;               
                }
                ptr = ptr->next;
            }while(swaped);
            }
        }



// Helper function to find the middle node
Node* getMiddle(Node* start, Node* end) {
    if (start == nullptr) return nullptr;

    Node* slow = start;
    Node* fast = start->next;

    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}


Node* getMiddleCustom(Node* start, Node* end){
    if(this->head == nullptr) return nullptr;
    Node*  slow = start;
    Node* fast = start->next;
    while(fast != end){
        fast = fast->next;
    if(fast != end){
        slow = slow->next;
        fast = fast->next;
    }
    }
    return slow;
}


// Binary Search by roll number
Undergrad* binarySearch(int targetRoll) {
    Node* start = this->head;
    Node* end = nullptr;

    while (start != end) {
        Node* mid = getMiddle(start, end);
        if (mid == nullptr) return nullptr;

        int roll = mid->student.getRoll();

        if (roll == targetRoll) {
            return &mid->student; // found
        } else if (roll < targetRoll) {
            start = mid->next; // search right half
        } else {
            end = mid; // search left half
        }
    }
    return nullptr; // not found
};





Undergrad* binarySearch(int target){
    Node* start = this->head;
    Node* end = nullptr;

    while(start != end){
      Node* midd  =  getMiddle(start,end);
      int roll_tocompare = midd->student.getRoll;
      if(roll_tocompare == target){
        return midd;
      }else if(roll_tocompare > target){
        //search left block; to far front
        end = midd->next;
      }else if(roll_tocompare < target){
        //search right too far below
        start = midd->next;
      }
    }
    return nullptr;
}



int interpolationSearch(int arr[], int n, int x) {
    int lo = 0, hi = n - 1;

    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        if (arr[lo] == arr[hi]) {
            if (arr[lo] == x) return lo;
            else return -1;
        }

        // Estimate mid using interpolation formula
        int mid = lo + ((hi - lo) * (x - arr[lo])) / (arr[hi] - arr[lo]);

        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1; // not found
}



Node* getNodeAt(int index) {
    Node* temp = this->head;
    int count = 0;
    while (temp != nullptr && count < index) {
        temp = temp->next;
        count++;
    }
    return temp;
}


Undergrad* interpolationSearch(int targetRoll) {
    // Step 1: Find length of the list
    int n = 0;
    Node* temp = this->head;
    while (temp != nullptr) {
        n++;
        temp = temp->next;
    }

    int lo = 0, hi = n - 1;

    while (lo <= hi) {
        Node* loNode = getNodeAt(lo);
        Node* hiNode = getNodeAt(hi);

        if (loNode == nullptr || hiNode == nullptr) return nullptr;

        int loVal = loNode->student.getRoll();
        int hiVal = hiNode->student.getRoll();

        if (targetRoll < loVal || targetRoll > hiVal) break;

        if (loVal == hiVal) {
            if (loVal == targetRoll) return &loNode->student;
            else break;
        }

        // Step 2: Calculate mid using interpolation formula
        int mid = lo + ((hi - lo) * (targetRoll - loVal)) / (hiVal - loVal);

        Node* midNode = getNodeAt(mid);
        if (midNode == nullptr) return nullptr;

        int midVal = midNode->student.getRoll();

        if (midVal == targetRoll) {
            return &midNode->student; // found
        } else if (midVal < targetRoll) {
            lo = mid + 1; // right half
        } else {
            hi = mid - 1; // left half
        }
    }
    return nullptr; // not found
}

void InsertionSort(){
    n =  0;
    Node* temp = this->head;
    while(temp->next != nullptr){
        temp = temp->next
        n++;
    }
    for(int j = 0, j< n; j++){
        do {
            Undergrad* key = getNodeAt(j)->student;
        while(int i > 0){

        }
        }while();
    }
}

Node* getNodeat(int index){
    int count = 0;
    temp = this->head;
    while(temp->next != nullptr && count < index){
       temp = temp->next;
       count++;
    }
  return temp;
}

Undergrad interpolationsearch(int rollnum){
    start = this->head;
    end  = nullptr;
   

    int n = 0;
    temp = this->head;
    while(temp->next != nullptr ){
        temp  = temp->next;
        n++
    }

    int lo = 0;  hi = n-1;
    while(lo <= hi){
        Node* loNode = getNodeAt(lo);
        Node* hiNode = getNodeAt(hi);

        if(loNode == nullptr || hiNode == nullptr )return nullptr;
        int loNodeval = loNode->student.getRoll();
        int hiNodeval = hiNode->student.getRoll();

        if(rollnum < loNodeval || rollnum > hiNodeval) break;
        if(loNodeval == hiNodeval) {
            if(loNodeval == rollnum) return &loNode->student;
            else break;
        }
        int midd = lo + (hi - lo)* (rollnum - loNodeval )/(hiNodeval - loNodeval);
        Node* middNode - getNodeAt(midd);
        int middNodeval = middNode->student.getRoll()
        if(middNodeval == rollnum){
            return &middNode->student; //found
        } else  if(middNodeval < rollnum){
            //search right
            lo = midd -1;
        }else  if(middNodeval > rollnum){
            //search left
            hi = midd -1 ;
        }
    }

   return nullptr;
}


void insertionSort() {
    if (!head || !head->next) return;

    Node* sorted = nullptr;  // new sorted list

    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;  // save next node
        // insert current in sorted list
        if (!sorted || current->student.getRoll() < sorted->student.getRoll()) {
            // insert at beginning
            current->next = sorted;
            sorted = current;
        } else {
            // find the correct position
            Node* temp = sorted;
            while (temp->next && temp->next->student.getRoll() < current->student.getRoll()) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;  // move to next node
    }

    head = sorted;
}


void insertionSort() {
    if (!head || !head->next) return; // nothing to sort

    Node* i = head->next;   // start from 2nd node
    while (i != nullptr) {
        Node* j = i;        // take current node

        // Move backward through the list, swapping values until in correct place
        Node* k = head;
        while (k != j) {
            if (j->student.getRoll() < k->student.getRoll()) {
                // swap the student objects
                Undergrad temp = j->student;
                j->student = k->student;
                k->student = temp;
            }
            k = k->next;
        }

        i = i->next; // move to next node
    }
}


void insertionSort(){
    if(this->head == nullptr) return;
Node* i = head->next;
while (i != nullptr){
    Node* j = i ;
    Node* k = head;
    while(k != j){
       if(j->student.getRoll < k->student.getRoll()){
        Undergrad temp = j->student;
        j->student = k->student;
        k->student = temp;
       }
       k = k->next;
    }
    i = i->next;
}

}



void insertionsortcustom(){
    if(this->head = nullptr) return;
    Node i = this->head->next;
   

    while(i != nullptr){
        Node* j = i;
        Node* k = this->head;
        while(k != j){
            if(j->student.getRoll()<k.student.getRoll()){
                Undergrad temp = j->student;
                j->student = k.student;
                k.student = temp;
            }
            k =k->next;
        }
        i= i->next;
    }
}

void InsertionSortdec(){
    if(this->head != nullptr) return;
    Node* i = this->head;
    while(i != nullptr){
        Node* j  = i;
        Node* k  = head;
        while(k != j){
            if(j->student.getRoll() > k->student.getRoll()){
                Undergrad temp = j->student;
                j->student = k->student;
                k->student = temp;
            }
            k = k->next;
        }
        i = i->next;
    }
}

void LinkedList_students_undergrads::selectionSort() {
    if (!head || !head->next) return; // nothing to sort

    Node* current = head;

    while (current != nullptr) {
        // Assume the minimum is the current node
        Node* minNode = current;

        // Search the rest of the list for a smaller element
        Node* temp = current->next;
        while (temp != nullptr) {
            if (temp->student.getRoll() < minNode->student.getRoll()) {
                minNode = temp;
            }
            temp = temp->next;
        }

        // Swap the student data of current and minNode
        if (minNode != current) {
            Undergrad t = current->student;
            current->student = minNode->student;
            minNode->student = t;
        }

        // Move to next node
        current = current->next;
    }
}


void SelectionSort(){
    if(head == nullptr) return;
    Node* curr = this->head;
    while(curr != nullptr){
        Node* minNode = curr;
        Node* temp = curr->next;
        while(temp != nullptr){
            if(temp->student.getRoll < minNode->student.getRoll){
                minNode = temp;
            }
            temp = temp->next;
        }
    if(minNode != curr){
        Undergrad t = curr->student;
        curr->student = minNode;
        minNode->student = t;
    }
    curr = curr->next;
    }

}



void SelectionSortCustom(){
    if(head == nullptr) return;
    Node* curr = this->head;
    Node* minNode = nullptr;
    while(curr != nullptr){
      Node* temp = curr->next;
      while(temp != nullptr){
        if(temp->student.getRoll() < curr->student.getRoll()){
            minNode = temp;
        }
        temp = temp->next;
      }
      if(curr->student.getRoll != minNode->student.getRoll){
        Undergrad t = curr->student;
        curr->student = minNode->student;
        minNode->student = t;
      }
      curr = curr->next;
    }

}


void combSort() {
    if (!head || !head->next) return; // empty or single node → already sorted

    // 1. Count the nodes
    int n = 0;
    Node* temp = head;
    while (temp != nullptr) {
        n++;
        temp = temp->next;
    }

    int gap = n;
    bool swapped = true;

    // 2. Keep sorting until gap = 1 and no swaps
    while (gap > 1 || swapped) {
        // Shrink gap
        gap = (gap * 10) / 13; // divide by 1.3
        if (gap < 1) gap = 1;

        swapped = false;

        // 3. Compare nodes that are gap apart
        Node* node1 = head;
        Node* node2 = head;

        // Move node2 ahead by gap
        for (int i = 0; i < gap && node2 != nullptr; i++) {
            node2 = node2->next;
        }

        while (node2 != nullptr) {
            if (node1->student.getRoll() > node2->student.getRoll()) {
                // Swap their student data
                Undergrad t = node1->student;
                node1->student = node2->student;
                node2->student = t;
                swapped = true;
            }

            node1 = node1->next;
            node2 = node2->next;
        }
    }
}


void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            temp->student.displayInfo();
            temp = temp->next;
        }
    }

    ~LinkedList_students_undergrads() {
        while (head != nullptr) {
            delUndergrad_begin();
        }
    }
};












// -------------------- Main --------------------
int main() {
    LinkedList_students_undergrads list;

    // Add more sample data
    Undergrad u1("Ali", "Harvard", "CS", 103);
    Undergrad u2("Sara", "MIT", "AI", 101);
    Undergrad u3("John", "Stanford", "Math", 105);
    Undergrad u4("Mary", "Oxford", "Physics", 110);
    Undergrad u5("David", "Cambridge", "History", 102);
    Undergrad u6("Emma", "Yale", "Biology", 107);
    Undergrad u7("Liam", "Princeton", "Economics", 104);
    Undergrad u8("Sophia", "Columbia", "Philosophy", 109);
    Undergrad u9("James", "UCLA", "Chemistry", 106);
    Undergrad u10("Olivia", "Berkeley", "Literature", 108);

    // Insert into the list
    list.add_Undergrad_end(u1);
    list.add_Undergrad_end(u2);
    list.add_Undergrad_end(u3);
    list.add_Undergrad_end(u4);
    list.add_Undergrad_end(u5);
    list.add_Undergrad_end(u6);
    list.add_Undergrad_end(u7);
    list.add_Undergrad_end(u8);
    list.add_Undergrad_end(u9);
    list.add_Undergrad_end(u10);

    // Print unsorted
    cout << "Unsorted list:\n";
    list.printList();

    // Bubble sort
    list.bubbleSort();

    // Print sorted
    cout << "\nSorted list (by roll):\n";
    list.printList();

    return 0;
}
