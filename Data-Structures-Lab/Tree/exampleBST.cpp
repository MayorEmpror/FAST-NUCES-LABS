#include <iostream>
#include <queue>
using namespace std;

// ===================================
// Node Structure (Private to BST)
// ===================================
class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) {
            data = val;
            left = right = NULL;
        }
    };

    Node* root;

    // ===============================
    // Recursive Helpers
    // ===============================

    Node* insert(Node* root, int key) {
        if (root == NULL)
            return new Node(key);

        if (key < root->data)
            root->left = insert(root->left, key);
        else if (key > root->data)
            root->right = insert(root->right, key);

        return root;
    }

    

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node* root) {
        if (!root) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    bool search(Node* root, int key) {
        if (!root) return false;
        if (root->data == key) return true;
        if (key < root->data)
            return search(root->left, key);
        return search(root->right, key);
    }

    Node* findMin(Node* root) {
        while (root && root->left != NULL)
            root = root->left;
        return root;
    }

    Node* remove(Node* root, int key) {
        if (!root) return NULL;

        if (key < root->data)
            root->left = remove(root->left, key);

        else if (key > root->data)
            root->right = remove(root->right, key);

        else {
            // Case 1: No child
            if (!root->left && !root->right) {
                delete root;
                return NULL;
            }

            // Case 2: One child
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
        return root;
    }

    int height(Node* root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    int count(Node* root) {
        if (!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }

    bool isFull(Node* root) {
        if (!root) return true;

        if (!root->left && !root->right) return true;

        if (root->left && root->right)
            return isFull(root->left) && isFull(root->right);

        return false;
    }

    bool isComplete(Node* root) {
        if (!root) return true;

        queue<Node*> q;
        q.push(root);
        bool nullFound = false;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr == NULL)
                nullFound = true;
            else {
                if (nullFound) return false;
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return true;
    }

public:
    // ===============================
    // Constructor
    // ===============================
    BST() { root = NULL; }

    // ===============================
    // Public BST APIs
    // ===============================
    void insert(int key) {
        root = insert(root, key);
    }

    void remove(int key) {
        root = remove(root, key);
    }

    bool search(int key) {
        return search(root, key);
    }

    // Traversals
    void inorder() {
        inorder(root);
        cout << endl;
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }

    void levelOrder() {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl;
    }

    int height() {
        return height(root);
    }

    int countNodes() {
        return count(root);
    }

    bool isFullBinaryTree() {
        return isFull(root);
    }

    bool isCompleteBinaryTree() {
        return isComplete(root);
    }
};

// ===============================
// MAIN
// ===============================
int main() {
    BST tree;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values)
        tree.insert(v);

    cout << "Inorder: ";
    tree.inorder();

    cout << "Preorder: ";
    tree.preorder();

    cout << "Postorder: ";
    tree.postorder();

    cout << "Level Order: ";
    tree.levelOrder();

    cout << "Search 60: " << (tree.search(60) ? "Found" : "Not Found") << endl;

    tree.remove(20);
    cout << "Inorder after deleting 20: ";
    tree.inorder();

    cout << "Height: " << tree.height() << endl;
    cout << "Total Nodes: " << tree.countNodes() << endl;

    cout << "Is Full Binary Tree? " << (tree.isFullBinaryTree() ? "Yes" : "No") << endl;
    cout << "Is Complete Binary Tree? " << (tree.isCompleteBinaryTree() ? "Yes" : "No") << endl;

    return 0;
}
