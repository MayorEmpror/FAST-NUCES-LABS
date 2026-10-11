#include <iostream>
#include <cstring>

struct Destination {
    char destination[50];
    int ETA;
};

// QuickSort partition without STL
int partition(Destination arr[], int low, int high) {
    Destination pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].ETA < pivot.ETA || (arr[j].ETA == pivot.ETA && strcmp(arr[j].destination, pivot.destination) < 0)) {
            i++;
            Destination temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Destination temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quicksort(Destination arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

struct Review {
    int rating;
    char review[255];
};

// Merge function without STL
void merge(Review arr[], int left, int mid, int right, Review temp[]) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i].rating > arr[j].rating || 
           (arr[i].rating == arr[j].rating && strcmp(arr[i].review, arr[j].review) < 0)) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (int idx = left; idx <= right; idx++) {
        arr[idx] = temp[idx];
    }
}

void mergeSort(Review arr[], int left, int right, Review temp[]) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, temp);
        mergeSort(arr, mid + 1, right, temp);
        merge(arr, left, mid, right, temp);
    }
}

int main() {
    // Example data for Q1
    Destination deliveries[] = {
        {"Store A", 120},
        {"Customer B", 45},
        {"Store C", 90},
        {"Store B", 90}
    };
    int n_deliveries = sizeof(deliveries) / sizeof(deliveries[0]);
    quicksort(deliveries, 0, n_deliveries - 1);
    std::cout << "Sorted Delivery Destinations by ETA:\n";
    for (int i = 0; i < n_deliveries; i++) {
        std::cout << deliveries[i].destination << ", ETA: " << deliveries[i].ETA << "\n";
    }

    // Example data for Q2
    Review reviews[] = {
        {4, "Good product"},
        {5, "Excellent"},
        {4, "Average"},
        {3, "Bad experience"}
    };
    int n_reviews = sizeof(reviews) / sizeof(reviews[0]);
    Review temp[n_reviews]; // Temporary array for merge sort
    mergeSort(reviews, 0, n_reviews - 1, temp);
    std::cout << "\nSorted Reviews by Rating:\n";
    for (int i = 0; i < n_reviews; i++) {
        std::cout << "Rating: " << reviews[i].rating << ", Review: " << reviews[i].review << "\n";
    }

    return 0;
}


