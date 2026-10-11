#include <iostream> 
using namespace std;

template<class typedatanode>
class Node {
    public:
        typedatanode data;
        Node<typedatanode>* left;
        Node<typedatanode>* right;

    Node(){
        this->right = nullptr;
        this->left = nullptr;
        this->data = NULL;
    }
    Node(typedatanode data):data(data){
        this->right = nullptr;
        this->left = nullptr;
    }
    Node (const Node<typedatanode>& other){
        this->data = other.data;
        this->left = other.left;
        this->right = other.right;
    }

    Node<typedatanode>& operator =(const Node<typedatanode>& other){
        if(this != &other){
            this->data = other.data;
            this->left = other.left;
            this->right = other.right;
        }
        return *this;
    }
    ~Node(){
        this->left = nullptr;
        this->right = nullptr;
        
        delete this->right;
        delete this->left;
    }
};  


//create node
//insert node
//search node
//find min node
//fin max node

template <class typetreenodedata>
class tree{
        public:
        Node<typetreenodedata>* root;


        Node<typetreenodedata>* createNode(typetreenodedata inputdata){
            Node<typetreenodedata> newNode = new Node<typetreenodedata>(inputdata);
            return newNode;
        }
        tree(typetreenodedata inputdata){
            Node<typetreenodedata>* newNode = this->createNode(input);
            this->root = newNode;
        }


      
        Node<typetreenodedata>* insertnode(Node<typetreenodedata>* root , typetreenodedata data){          
            if(root == nullptr || root->data == data){
              return  Node<typetreenodedata>* newNode = this->createNode(data);
            }else if(data < root->data){
                root->left = this->insertnode(root->left ,data);
            }else if(data > root->data){
                root->right = this->insertnode(root->right,data);
            }      
        }


        Node<typetreenodedata>* findmin(){
           Node<typetreenodedata>* iterator = this->root;
            while(iterator && iterator.left != nullptr){
                iterator = iterator->left;
            }
            return iterator;
        }


        Node<typetreenodedata>*findminrootNav(Node<typetreenodedata>* node){
            while(node && node->left != nullptr;) { node = node->left;}
            return node;
        }

        Node<typetreenodedata>* findmax(){
            Node<typetreenodedata>* iterator = this.root;
            while(iterator && iterator->right != nullptr) {iterator = iterator->right;}
            return iterator;
        }

        
        Node<typetreenodedata>* searchtreenode(Node<typetreenodedata>* root   ,typetreenodedata datakey ){
             if(root->data == datakey || root == nullptr){ return root;}
        else if(root->data > datakey ) return  searchtreenode(root->right, datakey);
        else return searchtreenode(root->left,datakey);
        }


        Node<typetreenodedata>* deleteNode(Node<typetreenodedata>* node, typetreenodedata data){
             if(root == nullptr){ return root;}// return the root base condition, append the child substree sucessor
             if(data < root->right ) return this->deleteNodedeleteNode(root->left, data); // find the node to the root that matches the data entered on the right
        else if(data > root->left ) return this->deleteNode(root.right,data);// find the node to the root that matches the data entered on the left
        else { // if there is no sub tree available
                if(root->left == nullptr){
                    Node<typetreenodedata>* temp = root->right; //save the left node 
                    delete root;// delete the root to delete 
                    return temp; // so return the right branch as the successor if there is no left one;
                }   
                else if(root->right == nullptr){
                    Node<typetreenodedata>* temp = root->left;// save the right node 
                    delete root;// delete root node and move the rest branch upwards in the later code
                    return temp; // again return the left branch as the successor if there is no right one;
                }
                Node<typetreenodedata>* temp = this->findminrootNav(root->right);// get the minimmu root on the right, which obviosly
                // would be greater than all the ones on the left of the rooot
                root->data = temp->data; // replace the root data with the succesor data
                root->right = deleteNode(root->right, temp->data);// move the right branch upwards since after replacing 
                // the root data with the right child there is a duplication,hence move right branch upwards 
        }
                return root; // return the root as the new root;

        }
        
};


template <class T>
int height(Node<T>* node) {
    if (node == nullptr)
        return 0;

    int leftHeight  = height(node->left);
    int rightHeight = height(node->right);

    return 1 + max(leftHeight, rightHeight);
}



template<class typefunctionrightR>
Node<typefunctionrightR> rightRotate(Node oldparrent ){
    Node orphan = oldparrent.left.right;
    Node newParrent = oldparrent.left;
    newParrent.right = oldparrent;
    oldParent.left = orphan;


    oldparrent.height =  height(oldparrent);
    newParrent.height = height(newParrent);
    return newParrent;


}



int main(){
    return 0;
}