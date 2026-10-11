#include <iostream>          // Include input-output stream library
using namespace std;         // Use standard namespace to avoid std:: prefix

// Bubble Sort function
void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {               // Outer loop for each pass
        for (int j = 0; j < n - i - 1; j++) {       // Inner loop compares adjacent elements
            if (arr[j] > arr[j + 1])                // If current element is greater than next
                swap(arr[j], arr[j + 1]);           // Swap them
        }
    }
}

// Linear Search function
int linearSearch(int* arr, int n, int target) {
    for (int i = 0; i < n; i++) {                   // Traverse through the array
        if (arr[i] == target)                       // If current element matches target
            return i;                               // Return its index
    }
    return -1;                                      // If not found, return -1
}

int main() {
    int n, target;                                  // Variables for array size and target element
    cout << "Enter number of elements: ";           
    cin >> n;                                       // Input size of array

    int* arr = new int[n];                          // Dynamically allocate array of size n
    cout << "Enter elements: ";                     
    for (int i = 0; i < n; i++)                     // Input all elements
        cin >> arr[i];

    cout << "Enter target: ";                       
    cin >> target;                                  // Input target element to search

    bubbleSort(arr, n);                             // Sort array using bubble sort

    cout << "Sorted Array: ";                       
    for (int i = 0; i < n; i++)                     // Print sorted array
        cout << arr[i] << " ";                      
    cout << endl;

    int index = linearSearch(arr, n, target);       // Perform linear search on sorted array

    if (index != -1)                                // If found
        cout << " found at index: " << index << endl;
    else                                            // If not found
        cout << " not found." << endl;

    delete[] arr;                                   // Free dynamically allocated memory
    return 0;                                       // End program
}
