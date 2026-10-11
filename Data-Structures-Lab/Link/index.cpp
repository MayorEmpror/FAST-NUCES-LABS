#include <iostream>
using namespace std;

class Node{
    public :
        int value;
        Node* next;
    Node(int value):value(value){
        this->next = nullptr;
    }
    Node(){
        this->next = nullptr;
        this->value = NULL;
    }   
    Node(const Node& other){
        this->value = other.value;
        this->next = other.next;
    }
    Node operator=(const Node& other ){
     if(this != &other){
        this->value = other.value;
        this->next = other.next;
     }
    }
    ~Node(){
        delete this->next;
    }
};

class List{
    public :
        Node* head;
        Node* tail;
    List(){
        this->head = nullptr;
        this->tail = nullptr;
    }

    ~List(){
        Node* temp = this->head;
        Node* temp_node_delete = new Node();
        while(temp->next != this->tail){
            temp_node_delete = temp;
            temp = temp->next;
            temp_node_delete = nullptr;
            delete temp_node_delete;
        };

    void Add_nodebegin(int value) {

     Node* newNode = new Node(value);
     if(this->head == nullptr){
        this->head = newNode;
        return;
     }
     newNode->next = this.head;
     this->head = newNode;
     return;
    }

    };

    void DeleteNode_beg(){
    Node* node_delete = new Node();
   
    if(this->head == nullptr){
        cout<<"No node to delete"<<endl;
        return;
    }
    node_delete = this->head;
    this->head =  this->head->next;
    node_delete->next = nullptr;
    delete node_delete;
    }

    void AddNode_tail(int value){
        Node* newNode = new Node(value);
        if(this->tail == nullptr){
            this->tail = newNode;
        }
        newNode = this->tail ;
        this->tail = newNode;
    }


    void DeleteNode_end(){
        Node* node_delete;
        Node* temp;
        if(this->tail == nullptr){
            cout<<"No node to delete"<<endl;
            return;
        }

        while(temp->next != tail){
            temp= temp->next;
        }
        node_delete = tail;
        this->tail  = temp;
        this->tail->next  = nullptr;
        delete node_delete;
    
    }

    void addmiddle(int pos){
        Node* temp;
        Node* pre;
        Node* curr= this->head;
        Node* newNode = new Node(pos);
       for(int i = 0;i < pos;i++){
        pre = curr;
        curr = curr->next;
    
        }
        newNode->next = curr->
       
    }
}



int main(){
    

    return 0;
}