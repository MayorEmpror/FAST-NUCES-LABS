#include <iostream>
#include <queue>
using namespace std;


void reheapifyDownward(int heap[],int start, int end){
    int index, lchild, rchild, max, temp;
    lchild = 2* start;
    rchild = lchild +1;

    if(lchild <= end){
        max = heap[lchild];
        index = lchild;
        if(rchild <= end && heap[rchild] > max){
            max = heap[rchild];
            index = rchild;
        }
    }
    if(heap[start] < heap[index]){
        int temp = heap[start];
        heap[start]  = heap[index];
        heap[index] = temp;
        reheapifyDownward(heap, index, end);
    }
}

struct node{
    int val;
    node* left;
    node* right;
    node(int val){
        val = val;
    }
}

int getcountnodes(node* root){
    if(!root) return 0;
    return 1 + getcountnodes(root->left) + getcountnodes(root->right);
}



int* constructHeaparray(node* roottree){
    int totalnum_nodes = getcountnodes(roottree) ;
    int* arrayheap = new int[totalnum_nodes];
    queue<node*> que;
    que.push(root);

    int index = 0;
    while(!q.empty()){
        node* current = que.front();
        que.pop();
        
        arrayheap[index++] = current->val;
       if(current->left)  que.push(current->left);  
       if(current->right) que.push(current->right);

    }

}



void deleteingfromheap(){

}






int main(){

    return 0;
}