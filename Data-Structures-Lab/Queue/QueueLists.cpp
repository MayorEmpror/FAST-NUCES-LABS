#include <iostream>
using namepsace std;


class Node{
    public:
        int data;
        Node* next;
        Node(int newValue){
            data = new_Data;
            next = nullptr;
        }
        Node(const Node& newValue){
            this->data = newValue.data;
            this->next = newValue.next;
        }
        Node* operator =(const Node& newValue){
           if(this != Node){
            this->data = newValue.data;
            this->next = newValue.next;
           }
        }
        ~Node(){
            this->next = nullptr
            delete this->next;
        }
};

class Queue{
    public :
        int currSize;
        Node*  front;
        Node*  rear;
        
    private :
        
            Queue(){
                currSize = 0;
                front = r
            }
}


int main(){
    return 0;
    
}