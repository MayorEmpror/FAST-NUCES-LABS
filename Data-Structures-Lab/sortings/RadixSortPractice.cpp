#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(inr val){
        data = val;
        next = NULL;
    }
}

void insertBucket(Node*& head, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}


void clearbucket(Node*& head){
    Node* temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
}

int getMax(int arr[], int size){
    int mx = arr[0];
    for(int i = 0; i< size; i++){
        if(arr[i] > mx) mx = arr[i];
    }
    return mx;
}

void radixsort(int arr[], int n){
    int maxNum = getMax(arr, n);
    int exp = 1;
    Node* bukets[10];

    while(maxNum/ exp > 0){

        for(int i = 0; i< 10; i++) bukets[i] == NULL;


        for(int i = 0; i< n; i++){
            int digit = (arr[i]/exp) % 10;
            insertBucket(buckets[digit], arr[i]);
        }

        int idx = 0;
    for(int i = 0; i < 10; i++){
        Node* temp = buckets[i];
        while(temp != NULL){
            arr[idx++] = temp->data;
            temp = temp->next;
        }
        clearbucket(bukets[i]);
    }
        exp *= 10;
    }
}



void printarray(int arr[], int size){
    cout<<"{";
    for(int i = 0; i< size; i++){
        cout<<arr[i]<<","<<endl;
    }
    cout<<"}";
}

int main(){

    return 0;
}

