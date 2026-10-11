#include <iostream>          // Include input-output stream library
using namespace std;         // Use standard namespace

// Selection Sort function
void selectionSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {          // Outer loop to iterate over array
        int minIdx = i;                        // Assume current index is the minimum
        for (int j = i + 1; j < n; j++) {      // Inner loop to find the actual minimum
            if (arr[j] < arr[minIdx])          // If smaller element is found
                minIdx = j;                    // Update index of minimum element
        }
        swap(arr[i], arr[minIdx]);             // Swap the found minimum with current element
    }
}

// Interpolation Search function
int interpolationSearch(int* arr, int n, int target) {
    int low = 0, high = n - 1;                 // Set initial search boundaries

    // Continue search while target is within range
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {                     // If only one element left
            if (arr[low] == target)            // If it matches target
                return low;                    // Return its index
            return -1;                         // Else, not found
        }

        // Estimate position using interpolation formula
        int pos = low + ((double)(high - low) / 
                        (arr[high] - arr[low])) * (target - arr[low]);

        if (arr[pos] == target)                // If found at estimated position
            return pos;                        // Return position
        if (arr[pos] < target)                 // If target is larger
            low = pos + 1;                     // Search right side
        else                                   // If target is smaller
            high = pos - 1;                    // Search left side
    }
    return -1;                                 // Target not found
}

int main() {
    int n, target;                             // Variables for array size and search target
    cout << "Enter number of elements: ";
    cin >> n;                                  // Input number of elements

    int* arr = new int[n];                     // Dynamically allocate array
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)                // Input array elements
        cin >> arr[i];

    cout << "Enter target: ";
    cin >> target;                             // Input target element

    selectionSort(arr, n);                     // Sort array using selection sort

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)                // Print sorted array
        cout << arr[i] << " ";
    cout << endl;

    int index = interpolationSearch(arr, n, target); // Perform interpolation search
    if (index != -1)                           // If target found
        cout << "Target found at index: " << index << endl;
    else                                       // If target not found
        cout << "Target not found." << endl;

    delete[] arr;                              // Free dynamically allocated memory
    return 0;                                  // End program
}
