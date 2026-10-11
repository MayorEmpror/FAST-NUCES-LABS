#include <iostream>
using namespace std;

void InsertionSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void BubbleSort(int arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){ // ✅ changed to ascending
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int BinarySearch(int arr[], int size, int value) {
    int start = 0, end = size - 1;
    while (start <= end) {
        int midd = (start + end) / 2;
        if (arr[midd] == value) {
            return midd;   // return index
        }
        else if (arr[midd] < value) {
            start = midd + 1;
        }
        else {
            end = midd - 1;
        }
    }
    cout << "Not found" << endl;
    return -1;
}

int main(){
    int arr[9] = {1,3,10,4,2,9,7,4,6};
    InsertionSort(arr, 9); // or BubbleSort(arr, 9)
    int value = 9;
    int idx = BinarySearch(arr, 9, value);

    for(int i = 0; i < 9; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    if(idx != -1) cout << value << " found at index " << idx << endl;

    return 0;
}
