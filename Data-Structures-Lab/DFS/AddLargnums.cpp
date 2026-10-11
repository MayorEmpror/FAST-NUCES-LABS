#include <iostream>
#include <stack>
using namespace std;

// Function to add two large numbers represented as stacks
stack<int> largnums(stack<int> num1, stack<int> num2) {
    stack<int> result;
    int carry = 0;

    while (!num1.empty() || !num2.empty() || carry != 0) {
        int x = 0, y = 0;

        if (!num1.empty()) {
            x = num1.top();
            num1.pop();
        }

        if (!num2.empty()) {
            y = num2.top();
            num2.pop();
        }

        int sum = x + y + carry;
        result.push(sum % 10);
        carry = sum / 10;
    }

    return result;
}

// Utility function to print a number represented as a stack
void printStackNumber(stack<int> s) {
    stack<int> temp;
    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }
    while (!temp.empty()) {
        cout << temp.top();
        temp.pop();
    }
    cout << endl;
}

int main() {
    // Example: 1234 + 567
    stack<int> num1;
    stack<int> num2;

    int arr1[] = {4, 3, 2, 1}; // represents 1234
    int arr2[] = {7, 6, 5};    // represents 567

    // Use classic for loops for pre-C++11
    for (int i = 0; i < 4; i++)
        num1.push(arr1[i]);
    for (int i = 0; i < 3; i++)
        num2.push(arr2[i]);

    stack<int> sum = largnums(num1, num2);

    cout << "Sum: ";
    printStackNumber(sum); // Output: 1801

    return 0;
}
