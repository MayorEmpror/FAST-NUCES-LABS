#include <iostream>
using namespace std;

class BankAccount {
private:
    double accBalance; 

public:
    // 1. Default constructor
    BankAccount() {
        accBalance = 0.0;
    }

    // 2. Parameterized constructor
    BankAccount(double initialAmt) {
        accBalance = initialAmt;
    }

    // 3. Copy constructor
    BankAccount(const BankAccount& sourceAccount) {
        accBalance = sourceAccount.accBalance;
    }

    // Method to withdraw money
    void withdrawAmount(double amountToWithdraw) {
        if (amountToWithdraw <= accBalance)
            accBalance -= amountToWithdraw;
        else
            cout << "Insufficient funds!" << endl;
    }

    // Method to get current balance
    double retrieveBalance() const {
        return accBalance;
    }
};


// Main Function
int main() {
    // 1. Default constructor
    BankAccount userAccount1;
    cout << "userAccount1 balnce: $" << userAccount1.retrieveBalance() << endl;

    // 2. Parameterized constructor
    BankAccount userAccount2(27281.0);
    cout << "userAccount2 balance: $" << userAccount2.retrieveBalance() << endl;

    // 3. Copy constructor
    BankAccount userAccount3(userAccount2);
    userAccount3.withdrawAmount(235.08);
    cout << "userAccount3 after withdrawing balance $235.08: $" << userAccount3.retrieveBalance() << endl;
    cout << "userAcount2 (unchanged): $" << userAccount2.retrieveBalance() << endl;

    return 0;
}
