#include <iostream>
using namespace std;

class student {
   private: 
    string name;
    int rollnum;
    public :
    student(){
        this->name = "";
        this->rollnum = -1;
    }
    student(string name, int rollnum):name(name), rollnum(rollnum){}
    student(const student& stdother){
        this->name = stdother.getname();
        this->rollnum = stdother.getroll();
    }
    student operator=(const student& stdother){
     if(this != &stdother){
        this->name = stdother.getname();
        this->rollnum = stdother.getroll();
        return this;
     }
    }
    string getname(){
    return this->name; 
    }
    int getroll(){
    return this->rollnum;
    }
    ~student(){ }
};


class Node {
    public:
    Node* next;
    student std;
Node(){
    this->next = nullptr;
    this->std  = NULL;
}
Node(student stdinput ){
    this->std = stdinput;
}
Node(const Node& other){
    this->next = other.next;
    this->std = other.std;
}
Node operator=(const Node& other){
    if(this != &other){
    this->next = other.next;
    this->std = other.std;
    return this;
    }
}
~Node(){
    delete this->next
}
};

void swapNodes(Node A, Node B){
    Node temp = new Node[student];
    temp = A;
    A = B;
    B = temp;
    return;
}

class linklist(){
    public:
     Node* head;
     Node* tail;
     
    linklist(){
        this->head = nullptr;
        this->tail = nullptr;
    }
     addNode_start(){}
     delNode_start(){}
     addNode_end(){}
     delNode_end(){}
     addNode_middle(){}
     delNode_middle(){}

}

void bublesort(linklist ll){
    for(Node* i = ll->head; i != nullptr;i=i->next){
        for(Node* j = i->next; j != nullptr; j = j->next){
            if(i->std.rollnum < j->std.rollnum){
                swapNodes(i,j);
            }
            
        }
    }
}

void InsertionSort(){
    
}


int main(){
    return 0;
}
