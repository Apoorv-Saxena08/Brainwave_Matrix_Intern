#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
private:
    int accountNumber;
    string ownerName;
    double balance;

public:
    //
    Account(int accNum, string name, double bal = 0.0) : accountNumber(accNum), ownerName(name), balance(bal) {}

    // Getters
    int getAccountNumber() const { return accountNumber; }
    string getOwnerName() const { return ownerName; }
    double getBalance() const { return balance; }

    // Functions to deposit, withdraw and transfer
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful! New balance: $" << balance << endl;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

    void transfer(Account &recipient, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            recipient.balance += amount;
            cout << "Transfer successful! $" << amount << " transferred to account " << recipient.getAccountNumber() << endl;
        } else {
            cout << "Transfer failed due to insufficient balance or invalid amount!" << endl;
        }
    }

    void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class Bank {
private:
    vector<Account> accounts;
    int nextAccountNumber = 1001;

    Account* findAccount(int accNum) {
        for (auto &account : accounts) {
            if (account.getAccountNumber() == accNum) {
                return &account;
            }
        }
        return nullptr;
    }

public:
    // Create a new account
    void createAccount(string ownerName) {
        Account newAccount(nextAccountNumber++, ownerName);
        accounts.push_back(newAccount);
        cout << "Account created successfully! Your account number is " << newAccount.getAccountNumber() << endl;
    }

    // Deposit money into account
    void depositToAccount(int accNum, double amount) {
        Account* account = findAccount(accNum);
        if (account) {
            account->deposit(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    // Withdraw money from account
    void withdrawFromAccount(int accNum, double amount) {
        Account* account = findAccount(accNum);
        if (account) {
            account->withdraw(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    // Transfer money between accounts
    void transferBetweenAccounts(int fromAccNum, int toAccNum, double amount) {
        Account* fromAccount = findAccount(fromAccNum);
        Account* toAccount = findAccount(toAccNum);
        if (fromAccount && toAccount) {
            fromAccount->transfer(*toAccount, amount);
        } else {
            cout << "One or both accounts not found!" << endl;
        }
    }

    // Display all accounts
    void displayAllAccounts() const {
        if (accounts.empty()) {
            cout << "No accounts available!" << endl;
        } else {
            for (const auto &account : accounts) {
                account.displayAccountInfo();
                cout << "-----------------------" << endl;
            }
        }
    }
};

int main() {
    Bank bank;
    int choice, accountNumber;
    string ownerName;
    double amount;
    int fromAccNum, toAccNum;

    do {
        cout << "\n----- Online Banking System -----\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Funds\n";
        cout << "3. Withdraw Funds\n";
        cout << "4. Transfer Funds\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter owner name: ";
                cin.ignore();
                getline(cin, ownerName);
                bank.createAccount(ownerName);
                break;
            case 2:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter deposit amount: ";
                cin >> amount;
                bank.depositToAccount(accountNumber, amount);
                break;
            case 3:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                bank.withdrawFromAccount(accountNumber, amount);
                break;
            case 4:
                cout << "Enter your account number: ";
                cin >> fromAccNum;
                cout << "Enter recipient account number: ";
                cin >> toAccNum;
                cout << "Enter transfer amount: ";
                cin >> amount;
                bank.transferBetweenAccounts(fromAccNum, toAccNum, amount);
                break;
            case 5:
                bank.displayAllAccounts();
                break;
            case 6:
                cout << "Exiting system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
