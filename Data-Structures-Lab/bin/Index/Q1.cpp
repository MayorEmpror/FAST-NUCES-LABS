#include <iostream>          // Include input-output stream library
using namespace std;         // Use standard namespace for easier syntax

// Insertion Sort function
void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {       // Loop through array starting from index 1
        int key = arr[i];               // Store the current element (key) to be placed correctly
        int j = i - 1;                  // Start checking from the previous element

        // Shift elements of arr[0..i-1] that are greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];        // Move element one step forward
            j--;                        // Move backwards in the array
        }

        arr[j + 1] = key;               // Place key in its correct position
    }
}

// Binary Search function
int binarySearch(int* arr, int n, int target) {
    int left = 0, right = n - 1;        // Define search boundaries

    while (left <= right) {             // Repeat until search space is valid
        int mid = left + (right - left) / 2; // Find middle index safely (avoids overflow)

        if (arr[mid] == target)         // If target found at mid
            return mid;                 // Return index
        else if (arr[mid] < target)     // If target is larger, ignore left half
            left = mid + 1;
        else                            // If target is smaller, ignore right half
            right = mid - 1;
    }

    return -1;                          // Target not found, return -1
}

int main() {
    int n, target;                      // Variables for size of array and search target
    cout << "Enter number of elements: ";
    cin >> n;                           // Input size of array

    int* arr = new int[n];              // Dynamically allocate memory for array
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)         // Loop to input elements
        cin >> arr[i];

    cout << "Enter target: ";
    cin >> target;                      // Input element to search for

    insertionSort(arr, n);              // Sort the array using insertion sort

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)         // Print sorted array
        cout << arr[i] << " ";
    cout << endl;

    int index = binarySearch(arr, n, target); // Perform binary search on sorted array

    if (index != -1)                    // If element found
        cout << " found at index: " << index << endl;
    else                                // If element not found
        cout << " not found." << endl;

    delete[] arr;                       // Free dynamically allocated memory
    return 0;                           // End program
}
