#include <iostream>
using namespace std;

template <class T>
class Node{ 
    public :   
        T value;
        Node<T> next;

        Node(T val): value(val){
            this->next = nullptr ;
        }
        Node(const Node<T>& other){
            this->value = other.value;
            this->next =  other.next;
        }
        Node<T>& operator =(const Node<T>& other){
            if(this != &other){
                this->value = other.value;
                this->next =  other.next;
            }
        ~Node(){}
}


class LinkList{
        public:
           
            Node<T> top;

            LinkList(T value){
                this->top = nullptr;
            }
           void insertnode(T value){
                Node<T> newnode = new Node<T>(value);
                if(this->top == nullptr){
                    this->top = newnode;
                    return;
                }

                Node<T> temp = this->top;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
               temp->next = newnode;
            }

            Node<T> Listunion(Node<T> top, Node<T> top_sec){
                    Node<T>* temp = top;
                    while(temp->next != nullptr){
                        temp = temp->next;
                    }
                    temp->next = top_sec;
                    return top;
            }
  
            void putinorder(){
                Node<T>* temp = this->top;
                LinkList* Orderedlistodd = new LinkList();
                LinkList* Orderedlisteven = new LinkList();
                while(temp != nullptr){
                    if(temp->value%2){
                        Orderedlisteven->insertnode(temp->value);
                    }else {
                        Orderedlistodd->insertnode(temp->value);
                    }
                
                    Node<T> newtop = this->Listunion(Orderedlisteven->top,Orderedlistodd->top);
                }
               

            }

            ~LinkList(){}

}








int main(){

}