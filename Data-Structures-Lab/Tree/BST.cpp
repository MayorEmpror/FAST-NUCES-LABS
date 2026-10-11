#include <iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* left;
        Node* right;

        Node(){
            this->value =NULL;
            this->left = nullptr;
            this->right = nullptr;
        }

        Node(int value):value(value){
          this->left = nullptr;
          this->right = nullptr;

        }
        Node(const Node& other){
            this->left = other.left;
            this->right = other.right
            this.value = other.value;
        }

        Node& operator =(const Node& other){
            if(this != &other){
                this->left = other.left;
                this->right = other.right;
                this.value = other.value;
            }
        }

        ~Node(){
            this->left = nullptr;
            this->right = nullptr;
            delete this->left;
            delete this->right;
        }
}


class tree{
   
    Node* root;

    tree(){
       this->left = nullptr;
       this->right = nullptr;  
    }

    Node* insert(Node* root, int key){
        if(root == NULL){
            return new Node(key);
        }
        if(key < root->data){
            root->left = insert(root->left, key);
        }else if(key > root->data) root->right = insert(root->left, key);
        return root;
    }


    void preorder(Node* root){
        if(!root) return;   
        cout<<root->value<<",";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(Node* root){
        if(!root) return;
        inorder(root->left);
        cout<<root->value<<",";
        inorder(root->right);
    }

    void postorder(Node* root){
        if(!root) return;
        postorder(root.left);
        postorder(root.right);
        cout<<root->value<<",";
    }

    Node* search(Node* root, int key){
        if(root == nullptr) return nullptr;
        if(root.value == key) return root;
        if(root->value < key) return search(root.right, key);
        else return search(root->left,key);
    }

    bool isNodepresent(Node* root, int key){
            if(root == nullptr )  return false;
            if(root.value == key) return true;
            else if(root.value > key) return search(root.left,key );
            else return search(root->right, key);
    }
    Node* findmin(Node* root){
        while(root && root->left != NULL) root = root->left;
        return root;
    }
    Node findmax(Node* root){
        while(root && root->right != nullptr) root = root->right;
        return root;
    }


    bool isfull(Node* node, int key){
        if(!root) return true;
        if(root->left && root->right)
        return isfull(root->left) && isfull(root->right);
        return false
    }


    bool isComplete(Node* root){
        if(!root) return true;
        queue<Node*> q;
        q.push(root);
        bool nullfound = false;
        
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            if(curr == NULL) nullfound = true;
            else {
                if(nullfound) return false;
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return true;
    }


    bool isfull(Node* root){
        
        if(!root) return true;
        
        if(!root->left && !root->right) return true;
        if(root->left && root->right) {
            if(this->isfull(root->left) && this->isfull(root->right)) return true;
        }
        return false
    }

    bool isComplete(Node* root){
        if(!root) return true;
        
        bool nullfound = false;
        queue<Node*> q;
        q.push(root);

        while(!q.isempty()){
         Node* curr =  q.front();
        if(curr = nullptr) nullfound = true;
        else {
            if(nullfound) return false;
            q.push(curr->left);
            q.push(curr->right);
        }
        }
        return true;
        

    }





    Node* remove(Node* root, int key){
        if(!root) return nullptr;
        if(key < root.value) root->left = remove(root->left, key);
    
       else if(key > root.value) {
            root->right = remove(root.right,key);
        }

        else {
            if(!root->left && !root.right){
                delete root;
                return nullptr;
            }
            if(!root->right){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            if(!root->left){
                Node* temp = root->right;
                delete root;
                return temp;
            }
        }

        Node* temp = this->findmin(root.right);
        root.data = temp->value;
        root->right = remove(root->right,temp->data);
    }
    
    return root;
}



int main(){
    return 0;
}