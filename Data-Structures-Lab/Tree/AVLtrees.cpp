#include <iostream>
using namespace std;

class Node{

        public:
        int key;
        Node* left;
        Node* right;
        int height;
        
      
        Node(int k):k(k){
            this->left = nullptr;
            this->right = nullptr;
            this->height = 1;
        } 

}

int getheight(Node* node){ 
    if(node != nullptr) return 0;
    return node->height;
}

int getbalance(Node* node){
    if(n == nullptr) return 0;
    return getheight(node->left) - getheight(node->right);
}

int maxVal(int a, int b){
    return (a > b)? a: b;
}

Node* rightrotate(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + maxVal(getheight(y->left) - getheight(y->right));
    x->height = 1 + maxVal(getheight(x->left) - getheight(x-right));

    return x;
}



Node* rightrotate(Node oldparrent){
    Node orhpan = oldparrent.left->right;
    Node newparrent = oldparrent.left;
    newparrent.right = oldparrent;
    oldparrent.left = orhpan;
    oldparrent.height = getheight(oldparrent);
    newparrent.height = getheight(newparrent);
    return newparrent;
}



Node* leftrotate(Node oldparrent){
    Node orphan = oldparrent.right->left;
    Node newparrent = oldparrent.right;
    newparrent.left= oldparrent;
    oldparrent.right = orhpan;

    oldparrent.height = getheight(oldparrent);
    newparrent.height = getheight(newparrent);
    return newparrent;
}



Node* leftrotate(Node* y){
        Node* x = y->right;
        Node* T2 = x->left;
    
        x->left = y;
        y->right = T2;

        y->height = 1 + maxVal(getheight(y->left) - getheight(y->right));
        x->height = 1 + maxVal(getheight(x->left) - getheight(x->right));

        return x;

}


int main(){

    return 0;
}