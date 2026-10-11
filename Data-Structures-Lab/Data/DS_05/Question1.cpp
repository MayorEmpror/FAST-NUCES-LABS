#include <iostream>
using namespace std;

void backtrackSubsets(int arr[], int n, int target, int index, int currentSum, 
                      int* currentSet, int currentSize, int** results, int& found_any) {
    // Base case: reached end
    if (index == n) {
        if (currentSum == target) {
            // Store the subset
            results[found_any] = new int[n];
            for (int i = 0; i < n; i++) results[found_any][i] = 0;
            for (int i = 0; i < currentSize; i++) {
                results[found_any][currentSet[i]] = arr[currentSet[i]];
            }
            found_any++;
        }
        return;
    }

    // Choice 1: Include current element
    currentSet[currentSize] = index;
    backtrackSubsets(arr, n, target, index + 1, currentSum + arr[index], 
                     currentSet, currentSize + 1, results, found_any);

    // Choice 2: Exclude current element
    backtrackSubsets(arr, n, target, index + 1, currentSum, 
                     currentSet, currentSize, results, found_any);
}

int** findSubsetsWithSum(int arr[], int n, int target, int& found_any) {
    // Maximum possible subsets = 2^n
    int total = 1 << n;
    int** results = new int*[total];
    int* currentSet = new int[n];

    backtrackSubsets(arr, n, target, 0, 0, currentSet, 0, results, found_any);

    delete[] currentSet;

    if (found_any > 0) return results;
    delete[] results;
    return nullptr;
}

int main() {
    int arr[6] = {3, 34, 4, 12, 5, 2};
    int target = 9;
    int found_any = 0;

    int** subsets = findSubsetsWithSum(arr, 6, target, found_any);

    if (subsets != nullptr) {
        for (int i = 0; i < found_any; i++) {
            cout << "{ ";
            for (int j = 0; j < 6; j++) {
                if (subsets[i][j] != 0) cout << subsets[i][j] << " ";
            }
            cout << "}" << endl;
            delete[] subsets[i]; // free each subset
        }
        delete[] subsets;
    } else {
        cout << "No subset sums to " << target << endl;
    }

    return 0;
}
