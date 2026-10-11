#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}



void displayArray(int arr[],int size){
    cout<<"{ ";
    for(int i = 0; i< size; i++){
        cout<<arr[i]<<",";
    }
    cout<<"}"<<endl;
}

int partition(int arr[], int left, int right){
    int pivot = arr[right];
    int i = left -1;
    for(int j = left; j < right ; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[right]);
    return i+1;
}


void QuickSort(int arr[], int left, int right){
  if(left < right){
    int pivot = partition(arr, left, right);
    QuickSort(arr,left,pivot-1);
    QuickSort(arr,pivot+1,right);
  }
}


int main(){
    int arr[10] = {1,3,5,3,6,5,3,6,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);


    displayArray(arr,size);
    QuickSort(arr, 0, size-1);
    displayArray(arr,size);

    return 0;

}