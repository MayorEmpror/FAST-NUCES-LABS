#include <iostream>
#include <string>
using namespace std;

class Student_AbstractContainer {
protected:
    string name;
    int roll;
    string year;
public:
    Student_AbstractContainer(int roll, string name, string year) 
        : year(year), roll(roll), name(name) {}
    virtual void display_infoStudent_AbstractContainer() = 0;
    virtual ~Student_AbstractContainer() {}
};

class Student_AbstractContainer_InheritedUndergrad : public Student_AbstractContainer {
private:
    string Major_Name;
public:
    Student_AbstractContainer_InheritedUndergrad(string Major, int roll, string name, string year)
        : Major_Name(Major), Student_AbstractContainer(roll, name, year) {}

    Student_AbstractContainer_InheritedUndergrad() 
        : Student_AbstractContainer(0, " ", " "), Major_Name(" ") {}

    Student_AbstractContainer_InheritedUndergrad(const Student_AbstractContainer_InheritedUndergrad& other)
        : Student_AbstractContainer(other.roll, other.name, other.year) {
        this->Major_Name = other.Major_Name;
    }

    Student_AbstractContainer_InheritedUndergrad& operator=(const Student_AbstractContainer_InheritedUndergrad& other) {
        if (this != &other) {
            this->Major_Name = other.Major_Name;
            this->name = other.name;
            this->roll = other.roll;
            this->year = other.year;
        }
        return *this;
    }

    void display_infoStudent_AbstractContainer() {
        cout << "Name  : " << this->name << endl;
        cout << "Roll  : " << this->roll << endl;
        cout << "Year  : " << this->year << endl;
        cout << "Major : " << this->Major_Name << endl;
    }

    string getName() { return this->name; }
    string getYear() { return this->year; }
    string getMajorName() { return this->Major_Name; }
    int getrollnumber() { return this->roll; }

    void setName(string newName) { this->name = newName; }
    void setYear(string newYear) { this->year = newYear; }
    void setMajorName(string newMajor) { this->Major_Name = newMajor; }
    void setrollnumber(int newRoll) { this->roll = newRoll; }

    ~Student_AbstractContainer_InheritedUndergrad() {}
};

class Node_Student_AbstractContainer_InheritedUndergrad {
public:
    Student_AbstractContainer_InheritedUndergrad StudentValue_ofNode;
    Node_Student_AbstractContainer_InheritedUndergrad* Next_NodeValueIndex;

    Node_Student_AbstractContainer_InheritedUndergrad() {
        this->Next_NodeValueIndex = nullptr;
    }
    Node_Student_AbstractContainer_InheritedUndergrad(Student_AbstractContainer_InheritedUndergrad input_value_studentdata) {
        this->StudentValue_ofNode = input_value_studentdata;
        this->Next_NodeValueIndex = nullptr;
    }
    Node_Student_AbstractContainer_InheritedUndergrad(const Node_Student_AbstractContainer_InheritedUndergrad& other) {
        this->StudentValue_ofNode = other.StudentValue_ofNode;
        this->Next_NodeValueIndex = other.Next_NodeValueIndex;
    }
    Node_Student_AbstractContainer_InheritedUndergrad& operator=(const Node_Student_AbstractContainer_InheritedUndergrad& other) {
        if (this != &other) {
            this->StudentValue_ofNode = other.StudentValue_ofNode;
            this->Next_NodeValueIndex = other.Next_NodeValueIndex;
        }
        return *this;
    }
    ~Node_Student_AbstractContainer_InheritedUndergrad() {
        delete this->Next_NodeValueIndex; // recursive delete (cleans entire list from this node)
    }
};

class LinkedList_Student_AbstractContainer_InheritedUndergrad {
private:
    Node_Student_AbstractContainer_InheritedUndergrad* __HEAD_NODE;
    Node_Student_AbstractContainer_InheritedUndergrad* __TAIL_NODE;

public:
    LinkedList_Student_AbstractContainer_InheritedUndergrad() {
        this->__HEAD_NODE = nullptr;
        this->__TAIL_NODE = nullptr;
    }

    void add_NODE_Start(Student_AbstractContainer_InheritedUndergrad Input_value_StudentData) {
        Node_Student_AbstractContainer_InheritedUndergrad* newNode = 
            new Node_Student_AbstractContainer_InheritedUndergrad(Input_value_StudentData);

        if (this->__HEAD_NODE == nullptr) {
            this->__HEAD_NODE = this->__TAIL_NODE = newNode;
        } else {
            newNode->Next_NodeValueIndex = this->__HEAD_NODE;
            this->__HEAD_NODE = newNode;
        }
    }

    void delNode_Start() {
        if (this->__HEAD_NODE == nullptr) return;
        Node_Student_AbstractContainer_InheritedUndergrad* temp = this->__HEAD_NODE;
        this->__HEAD_NODE = this->__HEAD_NODE->Next_NodeValueIndex;
        temp->Next_NodeValueIndex = nullptr;
        delete temp;
        if (this->__HEAD_NODE == nullptr) this->__TAIL_NODE = nullptr;
    }

    // ✅ Implementations
    void AddNodeEnd(Student_AbstractContainer_InheritedUndergrad Input_value_StudentData) {
        Node_Student_AbstractContainer_InheritedUndergrad* newNode = 
            new Node_Student_AbstractContainer_InheritedUndergrad(Input_value_StudentData);

        if (this->__HEAD_NODE == nullptr) {
            this->__HEAD_NODE = this->__TAIL_NODE = newNode;
        } else {
            this->__TAIL_NODE->Next_NodeValueIndex = newNode;
            this->__TAIL_NODE = newNode;
        }
    }

    void delNodeEnd() {
        if (this->__HEAD_NODE == nullptr) return;

        if (this->__HEAD_NODE == this->__TAIL_NODE) {
            delete this->__HEAD_NODE;
            this->__HEAD_NODE = this->__TAIL_NODE = nullptr;
            return;
        }

        Node_Student_AbstractContainer_InheritedUndergrad* temp = this->__HEAD_NODE;
        while (temp->Next_NodeValueIndex != this->__TAIL_NODE) {
            temp = temp->Next_NodeValueIndex;
        }
        delete this->__TAIL_NODE;
        this->__TAIL_NODE = temp;
        this->__TAIL_NODE->Next_NodeValueIndex = nullptr;
    }

    void AddNodeArbiterary(Student_AbstractContainer_InheritedUndergrad Input_value_StudentData, int position) {
        if (position <= 0 || this->__HEAD_NODE == nullptr) {
            add_NODE_Start(Input_value_StudentData);
            return;
        }

        Node_Student_AbstractContainer_InheritedUndergrad* newNode =
            new Node_Student_AbstractContainer_InheritedUndergrad(Input_value_StudentData);

        Node_Student_AbstractContainer_InheritedUndergrad* temp = this->__HEAD_NODE;
        for (int i = 0; temp != nullptr && i < position - 1; i++) {
            temp = temp->Next_NodeValueIndex;
        }

        if (temp == nullptr || temp->Next_NodeValueIndex == nullptr) {
            AddNodeEnd(Input_value_StudentData);
        } else {
            newNode->Next_NodeValueIndex = temp->Next_NodeValueIndex;
            temp->Next_NodeValueIndex = newNode;
        }
    }

    void delNodeArbiterary(int position) {
        if (this->__HEAD_NODE == nullptr) return;

        if (position <= 0) {
            delNode_Start();
            return;
        }

        Node_Student_AbstractContainer_InheritedUndergrad* temp = this->__HEAD_NODE;
        for (int i = 0; temp->Next_NodeValueIndex != nullptr && i < position - 1; i++) {
            temp = temp->Next_NodeValueIndex;
        }

        if (temp->Next_NodeValueIndex == nullptr) return;

        Node_Student_AbstractContainer_InheritedUndergrad* nodeToDelete = temp->Next_NodeValueIndex;
        temp->Next_NodeValueIndex = nodeToDelete->Next_NodeValueIndex;

        if (nodeToDelete == this->__TAIL_NODE) {
            this->__TAIL_NODE = temp;
        }

        nodeToDelete->Next_NodeValueIndex = nullptr;
        delete nodeToDelete;
    }

    void displayList() {
        Node_Student_AbstractContainer_InheritedUndergrad* temp = this->__HEAD_NODE;
        while (temp != nullptr) {
            temp->StudentValue_ofNode.display_infoStudent_AbstractContainer();
            cout << "-----------------\n";
            temp = temp->Next_NodeValueIndex;
        }
    }

    ~LinkedList_Student_AbstractContainer_InheritedUndergrad() {
        delete this->__HEAD_NODE; // recursive cleanup
    }
};


//BubbleSort Array version
void BubbleSort_ImplementationArrayVersion(int Arr[], int size_Arr){
if(size == 0){
    return // nothing to sort
}
for(int i = 0; i < size -1; i++){
    for(int j = 0; j < size -i -1;i++){
        if(Arr[j]> Arr[j+1]){
           int temp =  Arr[j];
            Arr[j]  = Arr[j+1];
            Arr[j+1] = temp;
        }
    }
}
};



//InsertionSort Sort in Linkedlist flavor
void LinkedList_Student_AbstractContainer_InheritedUndergrad::InsertionSort_ImplementationLinkedListVersion( ){
    if(this->__HEAD_NODE == nullptr || this->__HEAD_NODE->Next_NodeValueIndex == nullptr) { return; }
    Node_Student_AbstractContainer_InheritedUndergrad* iterator = this->__HEAD_NODE->Next_NodeValueIndex;
    while( iterator != nullptr){
        Node_Student_AbstractContainer_InheritedUndergrad* currentNode = iterator;
        Node_Student_AbstractContainer_InheritedUndergrad* subIterator = this->__HEAD_NODE;
        // second node iteration for the shifting of all the elements less thant the key selected value 
        while(subIterator != currentNode){
            if(currentNode->StudentValue_ofNode.getrollnumber() < subIterator->StudentValue_ofNode.getrollnumber()){
              Student_AbstractContainer_InheritedUndergrad temp = currentNode->StudentValue_ofNode;
              currentNode->StudentValue_ofNode = subIterator->StudentValue_ofNode;
              subIterator->StudentValue_ofNode = temp;
            }
            subIterator = subIterator->Next_NodeValueIndex;
        }
        iterator = iterator->Next_NodeValueIndex;
    }
};


bool IsSafe_tomove(int arr**, int x, int y, int length){
if(x  < length, && y < length&& arr[x][y] == 1 && x >= 0 && y >= 0){
    return true;
}
return false;
}   

bool  MoveRatInMaze(int arr**, int x, int y, int length, int** solutionArray){
    if((x == (length-1)) && (y == (length-1))){
        solutionArray[x][y]; //reached the goal 
        return true;
    }
    if(IsSafe_tomove(arr, x, y, length)){
        solutionArray[x][y] = 1;
       if(MoveRatInMaze(arr, x+1, y, length, solutionArray)){
        return true;
       }
    if(MoveRatInMaze(arr, x, y+1, length, solutionArray)){
        return true;
       }
       if(MoveRatInMaze(arr, x-1, y, length, solutionArray)){
        return true;
       }
       if(MoveRatInMaze(arr, x-1, y-1, length, solutionArray)){
        return true;
       }
       if(MoveRatInMaze(arr, x+1, y+1, length, solutionArray)){
        return true;
       }

    }
    solutionArray[x][y] = 0;
    return false;

}




bool IsSafeToPlace(int*** arr, int x, int y, int z, int length, int*** solution) {
    if (x >= 0 && y >= 0 && z >= 0 && x < length && y < length && z < length 
        && arr[x][y][z] == 1 && solution[x][y][z] == 0) {
        return true;
    }
    return false;
}

// a more pbrane like solution, not that great on code optimization or elegance and specially on possiblities
bool MoveRocketInSpace(int*** arr, int x, int y, int z, int length, int*** SolArray) {
    // If destination is reached
    if (x == length - 1 && y == length - 1 && z == length - 1 && arr[x][y][z] == 1) {
        SolArray[x][y][z] = 1;
        return true;
    }

    if (IsSafeToPlace(arr, x, y, z, length, SolArray)) {
        // Mark the cell as part of the solution
        SolArray[x][y][z] = 1;

        // Possible moves in 3D
        if (MoveRocketInSpace(arr, x + 1, y, z, length, SolArray)) return true;
        if (MoveRocketInSpace(arr, x, y + 1, z, length, SolArray)) return true;
        if (MoveRocketInSpace(arr, x, y, z + 1, length, SolArray)) return true;

        // Diagonal & reverse directions
        if (MoveRocketInSpace(arr, x + 1, y + 1, z + 1, length, SolArray)) return true;
        if (MoveRocketInSpace(arr, x - 1, y - 1, z - 1, length, SolArray)) return true;
        if (MoveRocketInSpace(arr, x, y, z - 1, length, SolArray)) return true;
        if (MoveRocketInSpace(arr, x, y - 1, z, length, SolArray)) return true;
        if (MoveRocketInSpace(arr, x - 1, y, z, length, SolArray)) return true;
        if (MoveRocketInSpace(arr, x, y - 1, z - 1, length, SolArray)) return true;
        if (MoveRocketInSpace(arr, x - 1, y, z - 1, length, SolArray)) return true;
        if (MoveRocketInSpace(arr, x - 1, y - 1, z, length, SolArray)) return true;
        if (MoveRocketInSpace(arr, x, y + 1, z + 1, length, SolArray)) return true;
        if (MoveRocketInSpace(arr, x + 1, y, z + 1, length, SolArray)) return true;
        if (MoveRocketInSpace(arr, x + 1, y + 1, z, length, SolArray)) return true;

        // Backtrack
        SolArray[x][y][z] = 0;
        return false;
    }
    return false;
}








// or we could also try this which is a weay better solution on traversing through all the dimensions
// we can also restrict the dimensions relative to the condition in the is Safeto place creating a map and then traversing on that 
// map
bool MoveRocketInSpace(int*** arr, int x, int y, int z, int length, int*** SolArray) {
    // If destination is reached
    if (x == length - 1 && y == length - 1 && z == length - 1 && arr[x][y][z] == 1) {
        SolArray[x][y][z] = 1;
        return true;
    }

    if (IsSafeToPlace(arr, x, y, z, length, SolArray)) {
        // Mark the cell as part of solution
        SolArray[x][y][z] = 1;

        // Try all possible moves: -1, 0, +1 in each axis
        for (int dx = -1; dx <= 1; dx++) {
            // check all the x's 
            for (int dy = -1; dy <= 1; dy++) {
                // check all the y's
                for (int dz = -1; dz <= 1; dz++) {
                    // check all the z's 

                    //check all the combinations of above 
                    if (dx == 0 && dy == 0 && dz == 0) continue; // skip no-move

                    if (MoveRocketInSpace(arr, x + dx, y + dy, z + dz, length, SolArray)) {
                        return true;
                    }
                }
            }
        }

        // Backtrack
        SolArray[x][y][z] = 0;
        return false;
    }
    return false;
}


void InsertionSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i-1 ;
        while(j >= 0 && arr[j] > key){
            arr[j + 1 ] = arr[j];
            j--
        }
        arr[j + 1 ] = key;
    }
}



//N-queens problem in 3d 



//Bubble Sort in Linkedlist flavor
void LinkedList_Student_AbstractContainer_InheritedUndergrad::BubbleSort(){
    if(this.__HEAD_NODE == nullptr || this.__HEAD_NODE->Next_NodeValueIndex == nullptr) return;
    Node_Student_AbstractContainer_InheritedUndergrad* Last_valuetoReach = nullptr;
    bool wereNodesSwapped;
    Node_Student_AbstractContainer_InheritedUndergrad* Iterator;
    do{
        wereNodesSwapped = false
 
        while(Iterator != last){
            Iterator = Iterator->Next_NodeValueIndex;
            if(Iterator->StudentValue_ofNode.getrollnumber() > Iterator->Next_NodeValueIndex->StudentValue_ofNode.getrollnumber()){
                 Student_AbstractContainer_InheritedUndergrad temp = Iterator->StudentValue_ofNode;
                 Iterator->StudentValue_ofNode = Iterator->Next_NodeValueIndex->StudentValue_ofNode; 
                 Iterator->Next_NodeValueIndex->StudentValue_ofNode = temp;
                 wereNodesSwapped = true;
            }
        last = Iterator;
        }
    }while(wereNodesSwapped)
}

//Comb Sort in Linkedlist flavor
//Selection Sort in Linkedlist flavor



int main() {

    LinkedList_Student_AbstractContainer_InheritedUndergrad list;

    Student_AbstractContainer_InheritedUndergrad s1("CS", 1, "Alice", "2022");
    Student_AbstractContainer_InheritedUndergrad s2("Math", 2, "Bob", "2023");
    Student_AbstractContainer_InheritedUndergrad s3("EE", 3, "Charlie", "2024");

    list.add_NODE_Start(s1);
    list.AddNodeEnd(s2);
    list.AddNodeArbiterary(s3, 1);

    cout << "Linked List:\n";
    list.displayList();

    cout << "\nDeleting node at position 1...\n";
    list.delNodeArbiterary(1);
    list.displayList();

    return 0;
}


