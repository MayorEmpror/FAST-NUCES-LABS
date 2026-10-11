#include <iostream>
#include <stack>
using namespace std;

char digitToSymbol(int digit) {
    if (digit < 10)
        return '0' + digit;
    else
        return 'A' + (digit - 10);
}

// Convert a decimal number to a given base (2–27)
string convertBase(int num, int base) {
    if (num == 0) return "0";

    stack<char> remStack;
    
    while (num > 0) {
        int remainder = num % base;
        remStack.push(digitToSymbol(remainder));
        num /= base;
    }

    // Build final string from stack
    string result = "";
    while (!remStack.empty()) {
        result += remStack.top();
        remStack.pop();
    }

    return result;
}


int main(){

    int num, base;
    
    cout << "Enter decimal number: ";
    cin >> num;

    cout << "Enter base (2–27): ";
    cin >> base;

    if (base < 2 || base > 27) {
        cout << "Invalid base!" << endl;
        return 0;
    }

    string converted = convertBase(num, base);
    cout << "Converted: " << converted << endl;
    return 0;
    
}