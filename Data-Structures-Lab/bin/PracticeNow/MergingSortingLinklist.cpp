#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    explicit Node(int value) : value(value), next(nullptr) {}

    // Disable copy/assignment to avoid accidental shallow copies
   // Node(const Node& other) = delete;
   // Node& operator=(const Node& other) = delete;

    ~Node() {
        // do NOT delete 'next' here — list owner deletes nodes
        next = nullptr;
    }
};


class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Add node at the beginning
    void add_beg(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Add node at the end
    void add_end(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }

    // Delete node from the beginning
    void del_beg() {
        if (head == nullptr) return;
        Node* todel = head;
        head = head->next;
        delete todel;
    }

    // Display the list
    void display() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Delete node at ith position (1-based). If i is out of range, do nothing.
    void delete_ith(int i) {
        if (i <= 0 || head == nullptr) return;

        if (i == 1) {
            del_beg();
            return;
        }

        Node* prev = head;
        // move prev to (i-1)-th node
        for (int j = 1; j < i - 1 && prev != nullptr; ++j) {
            prev = prev->next;
        }

        if (prev == nullptr || prev->next == nullptr) return; // out of range

        Node* todel = prev->next;
        prev->next = todel->next;
        delete todel;
    }

    // Merge (concatenate) other onto this; transfer ownership of nodes
    void mergeWith(LinkedList& other) {
        if (!head) {
            head = other.head;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = other.head;
        }
        other.head = nullptr; // other loses ownership
    }

    // Delete nodes based on positions stored in another list (interprets node values as indices)
    void Takedifference(Node* list2) {
        Node* temp = list2;
        while (temp != nullptr) {
            delete_ith(temp->value);
            temp = temp->next;
        }
    }

    // Take difference from two lists (both interpreted as lists of indices)
    void TakeDifferenceTrio(Node* list1, Node* list2) {
        Node* temp1 = list1;
        Node* temp2 = list2;
        while (temp1 != nullptr) {
            delete_ith(temp1->value);
            temp1 = temp1->next;
        }
        while (temp2 != nullptr) {
            delete_ith(temp2->value);
            temp2 = temp2->next;
        }
    }

    // Delete nodes whose indices equal the values stored in nodes (walks original head order)
    void DeleteSelfIndex() {
        Node* temp = head;
        while (temp != nullptr) {
            int val = temp->value;
            temp = temp->next;
            delete_ith(val);
        }
    }

    // Make a copy of *tocopy and return it (deep copy of node values)
    LinkedList copyll(const LinkedList* tocopy) const {
        LinkedList newList;
        if (tocopy == nullptr) return newList;
        Node* temp = tocopy->head;
        while (temp != nullptr) {
            newList.add_end(temp->value);
            temp = temp->next;
        }
        return newList;
    }

    // Decrement each node's value by 1
    void decrecmentvalue() {
        Node* temp = head;
        while (temp != nullptr) {
            temp->value -= 1;
            temp = temp->next;
        }
    }

    // Uses copy of this list to repeatedly delete nodes — keeps intended behavior but safe
    void DeleteSelfNode() {
        LinkedList copy_ref = copyll(this);
        Node* traverser = copy_ref.head;
        while (traverser != nullptr) {
            // delete node at index = traverser->value (in the original list)
            delete_ith(traverser->value);
            // decrement copy so the next deletion is for the next intended index (per original logic)
            copy_ref.decrecmentvalue();
            traverser = traverser->next;
        }
    }

    // Check if contents and order match exactly with another head pointer
    bool ContentMatch(Node* head_other) const {
        Node* a = head;
        Node* b = head_other;
        while (a != nullptr && b != nullptr) {
            if (a->value != b->value) return false;
            a = a->next;
            b = b->next;
        }
        // both must end at same time to be identical
        return (a == nullptr && b == nullptr);
    }

    int GetSize() const {
        Node* temp = head;
        int size = 0;
        while (temp != nullptr) {
            ++size;
            temp = temp->next;
        }
        return size;
    }

    bool isSameSize(const LinkedList& otherlist) const {
        return GetSize() == otherlist.GetSize();
    }

    bool isValuePresent(int value) const {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->value == value) return true;
            temp = temp->next;
        }
        return false;
    }

    // Check whether two lists contain the same multiset of values regardless of order.
    // Note: This implementation checks presence only (and assumes no duplicates or
    // that duplicates correspond appropriately). For full multiset equality you'd
    // need counting (hashmap) — but this preserves the spirit of your original function.



    
    void ReverseList(Node* curr){
        
    }


    bool MatchContentRegaudlessoforder(const LinkedList& otherlist) const {
        if (!isSameSize(otherlist)) return false;
        Node* temp = head;
        while (temp != nullptr) {
            if (!otherlist.isValuePresent(temp->value)) return false;
            temp = temp->next;
        }
        return true;
    }

    // Destructor: delete all nodes safely
    ~LinkedList() {
        while (head != nullptr) del_beg();
    }
};


int main() {
    LinkedList list1;
    list1.add_beg(9);
    list1.add_beg(7);
    list1.add_beg(3);
    list1.add_beg(1);
    // list1 = 1 → 3 → 7 → 9

    LinkedList list2;
    list2.add_beg(1);
    list2.add_beg(2);
    // list2 = 2 → 1

    LinkedList list3;
    list3.add_beg(1);
    list3.add_beg(2);
    // list3 = 2 → 1

    cout << "List 1: ";
    list1.display();

    cout << "List 2: ";
    list2.display();

    // Merge both lists (append-style)
    list1.mergeWith(list2);

    cout << "After merge: ";
    list1.display();

    // Delete the 6th node (safe even if it doesn’t exist)
    list1.delete_ith(6);
    cout << "After deleting 6th node (if exists): ";
    list1.display();

    // Take difference (delete by index from list3 values)
    list1.Takedifference(list3.head);
    cout << "After Takedifference: ";
    list1.display();

    // add some nodes and perform TakeDifferenceTrio
    list1.add_beg(9);
    list1.add_beg(7);
    list1.add_beg(3);
    list1.add_beg(1);

    cout << "Before TakeDifferenceTrio: ";
    list1.display();

    list1.TakeDifferenceTrio(list3.head, list3.head);
    cout << "After TakeDifferenceTrio: ";
    list1.display();

    cout << "Now the self difference" << endl;
    LinkedList list5;
    list5.add_beg(8);
    list5.add_beg(7);
    list5.add_beg(5);
    list5.add_beg(3);
    list5.add_beg(1);

    cout << "List5 before DeleteSelfNode: ";
    list5.display();
    list5.DeleteSelfNode();
    cout << "List5 after DeleteSelfNode: ";
    list5.display();

    LinkedList list6;
    list6.add_beg(8);
    list6.add_beg(7);
    list6.add_beg(5);
    list6.add_beg(3);
    list6.add_beg(1);
    cout << "list 6 " << endl;
    list6.display();

    LinkedList list7;
    list7.add_beg(8);
    list7.add_beg(3);
    list7.add_beg(1);
    list7.add_beg(7);
    list7.add_beg(5);
   
    cout << "list 7 " << endl;
    list7.display();

    bool returnval = list6.MatchContentRegaudlessoforder(list7);
    if (returnval) {
        cout << "both are same" << endl;
    } else {
        cout << "both are not same" << endl;
    }

    return 0;
}
