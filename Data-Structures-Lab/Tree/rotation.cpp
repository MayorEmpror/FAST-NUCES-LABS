#include <iostream>
using namespace std;

template <class treetypenode>
class Node{
    private :
    treetypenode value;
  
    public:
    Node<treetypenode>* right;
    Node<treetypenode>* left;

    Node(treetypenode value){
        this->value = value ;
        this->right = nullptr;
        this->left = nullptr;
    }
    Node(const Node<treetypenode>& other){
        this->value = other.value;
        this->right = other.right;
        this->left = other.left;
    }

    treetypenode getvalue(){ return this->value;}
    void setvalue(treetypenode newvalue){ this->value = newvalue;}


    Node<treetypenode>& operator =(const Node<treetypenode>& other){
        if(this != &other){
            this->value = other.value;
            this->right = other.right;
            this->left = other.left;
        }
        return *this;
    }
    ~Node(){}
    
};

template<class avltreetype>
class AVLtrees {
        private:
        Node<avltreetype> rootnode;
        public:
            AVLtrees() {
                this->rootnode = nullptr;
            }

            void insertnode(Node<avltreetype> node, int val, int dir ){
                if(!node) return;
                if(dir == 'L' || dir == 'l'){ 
                   if(node->left)  insertnode(node.left,val,dir);
                   else node->left = new Node<avltreetype>(val);
                }
                if(dir=='R' || dir == 'r'){
                    if(node->right) insertnode(node.right,val,dir);
                     else node->right = new Node<avltreetype>(val);
                }
            }
            
            
            int countNode(Node<avltreetype>* noderoot){
                if(!rootnode) return  0;
                return 1 + countNode(rootnode->left) + countNode(rootnode->right);
            }


            void storeinorder(Node<avltreetype>* noderoot, avltreetype inorder[], int& index){
                if(!root) return;
                storeinorder(noderoot->left, inorder,index);
                inorder[index++] = rootnode->value;
                storeinorder(noderoot->right,inorder,index);
            }


            Node<avltreetype>* buildingbalencingbintree(Node<avltreetype>* inorder[], int start, int end ){
                if(start > end) return nullptr;
                int mid = (start +  left)/2;
                Node<avltreetype>* root = inorder[mid];
                root->left = buildingbalencingbintree(inorder, start, mid-1);
                root->right = buildingbalencingbintree(indorder, mid+1, end);
                return root;

            }

            Node<avltreetype>* balencingtree(Node<avltreetype>* node){
                int n  =this->countNode(node);
                avltreetype* inorderarr = new avltreetype[n];
                int index = 0;
                this->storeinorder(node,inorderarr,index);
                Node<inorderarr>* balencedtree = this->buildingbalencingbintree(inorderarr,0, n-1);
                delete[] inorderarr;
                return balencedtree;
            }


            void inorder(Node<avltreetype>* root){
                if(root == nullptr) return;
                inorder(root->left);
                cout<<" val : "<<root->value<<' -> ';
                inorder(root->right);
            }

            void preorder(Node<avltreetype>* root){
                if(root == nullptr) return;
                cout<<" val : "<<root->value<<' -> ';
                preorder(root->left);
                preorder(root->right);
            }

            void postorder(Node<avltreetype>* root){
                if(!root) return ;
                 postorder(root->left);
                 postorder(root->right);
                 cout<<" val : "<<root->value<<' -> ';
            }


}

int main() {
    Node<int>* root = nullptr;
    int val, choice;
    char dir;
    cout << "Create your unbalanced binary tree:\n";
    cout << "Enter root value: ";
    cin >> val;
    root = new Node(val);
    do {
    cout << "\nEnter node value to insert: ";
    cin >> val;
    cout << "Insert on Left or Right of existing tree? (L/R): ";
    cin >> dir;
    insert(root, val, dir);
    cout << "Do you want to insert another node? (1 = Yes, 0 = No): ";
    cin >> choice;
    } while (choice == 1);
    cout << "\nInorder traversal of Unbalanced Tree: ";
    inorder(root);
    cout << "\nPreorder traversal of Unbalanced Tree: ";
    preorder(root);
    // Balance the tree
    root = balanceTree(root);
    cout << "\n\nAfter balancing the tree:\n";
    cout << "Inorder traversal: ";
    inorder(root);
    cout << "\nPreorder traversal (shows structure): ";
    
    preorder(root);
    cout << endl;
    return 0;
    }