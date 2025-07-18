
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Account {
private:
    string accountNumber;
    string holderName;
    double balance;

public:
    void createAccount() {
        cout << "\nEnter Account Number: ";
        cin >> accountNumber;
        cout << "Enter Holder Name: ";
        cin.ignore();
        getline(cin, holderName);
        cout << "Enter Initial Deposit: ";
        cin >> balance;
        cout << "\nAccount Created Successfully!\n";
    }

    void showAccount() const {
        cout << left << setw(15) << accountNumber
             << left << setw(25) << holderName
             << "Balance: ₹" << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "₹" << amount << " deposited successfully.\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance.\n";
        } else {
            balance -= amount;
            cout << "₹" << amount << " withdrawn successfully.\n";
        }
    }

    string getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }
};

void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    vector<Account> accounts;
    int choice;

    do {
        cout << "\n=== Bank Management System ===\n";
        cout << "1. Create New Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Deposit Amount\n";
        cout << "4. Withdraw Amount\n";
        cout << "5. Search Account\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string accNum;
        double amount;
        bool found;

        switch (choice) {
            case 1: {
                Account newAcc;
                newAcc.createAccount();
                accounts.push_back(newAcc);
                break;
            }
            case 2:
                cout << "\n--- All Accounts ---\n";
                for (const auto& acc : accounts) {
                    acc.showAccount();
                }
                break;
            case 3:
                cout << "Enter Account Number: ";
                cin >> accNum;
                found = false;
                for (auto& acc : accounts) {
                    if (acc.getAccountNumber() == accNum) {
                        cout << "Enter Amount to Deposit: ";
                        cin >> amount;
                        acc.deposit(amount);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Account not found.\n";
                break;
            case 4:
                cout << "Enter Account Number: ";
                cin >> accNum;
                found = false;
                for (auto& acc : accounts) {
                    if (acc.getAccountNumber() == accNum) {
                        cout << "Enter Amount to Withdraw: ";
                        cin >> amount;
                        acc.withdraw(amount);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Account not found.\n";
                break;
            case 5:
                cout << "Enter Account Number: ";
                cin >> accNum;
                found = false;
                for (const auto& acc : accounts) {
                    if (acc.getAccountNumber() == accNum) {
                        acc.showAccount();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Account not found.\n";
                break;
            case 6:
                cout << "Thank you for using the system.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
}
