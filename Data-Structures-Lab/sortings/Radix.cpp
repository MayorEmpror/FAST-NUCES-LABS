#include <iostream>
using namespace std;

// Get the maximum value in the array
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// Perform counting sort based on a specific digit (exp = 1, 10, 100, ...)
void countingSort(int arr[], int n, int exp) {
    int output[n]; // output array
    int count[10] = {0};

    // Count occurrences of each digit
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that it contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array (stable sorting)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function that sorts arr[] using Radix Sort
void radixSort(int arr[], int n) {
    int m = getMax(arr, n); // Find the maximum number to know number of digits

    // Apply counting sort to each digit
    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}