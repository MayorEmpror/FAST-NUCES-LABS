#include <iostream>
using namespace std;

int factorial(int i) {
    if (i <= 1) return 1;
    return i * factorial(i - 1);
}

int Catalan(int i) {
    return factorial(2 * i) / (factorial(i + 1) * factorial(i));
}

void backtrack(string* result, string current, int open, int close, int n, int& index) {
    if (open == n && close == n) {
        result[index++] = current;
        return;
    }
    if (open < n) {
        backtrack(result, current + "(", open + 1, close, n, index);
    }
    if (close < open) {
        backtrack(result, current + ")", open, close + 1, n, index);
    }
}

string* generateParenthesis(int n) {
    int totalCombinations = Catalan(n);
    string* result = new string[totalCombinations];
    int index = 0;
    backtrack(result, "", 0, 0, n, index);
    return result;
}

int main() {
    int number_brackets = 3;
    int totalCombinations = Catalan(number_brackets);
    string* values = generateParenthesis(number_brackets);

    cout << "Total combinations: " << totalCombinations << endl;
    for (int i = 0; i < totalCombinations; i++) {
        cout << values[i] << endl;
    }

    // Free allocated memory
    delete[] values;

    return 0;
}
