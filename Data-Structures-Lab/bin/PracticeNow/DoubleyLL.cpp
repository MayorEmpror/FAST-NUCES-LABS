#include <iostream>
using namespace std;

class node {
    public :
        int value;
    public :
        node* prev;
        node* next;
  
        node(int value): value(value){
            this->next = nullptr;
            this->prev = nullptr;
        }
        node(const node& other){
            this->next = other.next;
            this->value = other.value;
            this->prev = other.prev;
        }
        node* operator=(const node& other){
            if(this != &other){
                this->next = other.next;
                this->value = other.value;
                this->prev = other.prev;
            }
        }
        int getvalue(){ return this->value;}
        void setvalue(int value){this->value = value;}

        ~node(){
            this->next = nullptr;
            delete this->next;
            this->prev = nullptr;
            delete this->prev;
        }
}

class Doubleylinklist{
    public:
    node* head;
    Doubleylinklist(){
        this->head = nullptr;
    }
    void addNodebeg(int value){
        node* newNode = new node[value];
        if(head != nullptr){ 
             head = newNode;
             newNode->prev = nullptr;
             newNode->next = nullptr;
        }
        else {
             Node* temp = this->head;
             head =  
        }
    }



}




int main(){

}