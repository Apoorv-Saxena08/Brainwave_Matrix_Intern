#include <iostream>
#include <limits> // For 

using namespace std;

int main() 
{
    int option;
    double balance = 0.0, deposit, withdraw, transfer;
    string account;

    do {
        // Display menu
        cout << "\n\t***********MENU*************";
        cout << "\n\t*                                *";
        cout << "\n\t*      1. Check Balance          *";
        cout << "\n\t*      2. Deposit                *";
        cout << "\n\t*      3. Withdraw               *";
        cout << "\n\t*      4. Transfer               *";
        cout << "\n\t*      5. Exit                   *";
        cout << "\n\t*                                *";
        cout << "\n\t**********************************";
        cout << "\n\t Please Choose an Option: ";

        // Input validation for option
        while (!(cin >> option) || option < 1 || option > 5) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "\n\t Invalid input. Please enter a number between 1 and 5: ";
        }

        switch (option) {
            case 1:
                cout << "\n\tYour Current Balance is: $" << balance << endl;
                break;

            case 2:
                cout << "\n\tAmount You Want to Deposit: $";
                cin >> deposit;
                
                // Input validation for deposit
                while (cin.fail() || deposit <= 0) {
                    cin.clear(); // Clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    cout << "\n\t Invalid amount. Please enter a positive number: ";
                    cin >> deposit;
                }

                balance += deposit;
                cout << "\n\tYour Current Balance: $" << balance << endl;
                break;

            case 3:
                cout << "\n\tHow much do you want to withdraw? $";
                cin >> withdraw;
                
                // Input validation for withdraw
                while (cin.fail() || withdraw <= 0) {
                    cin.clear(); // Clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    cout << "\n\t Invalid amount. Please enter a positive number: ";
                    cin >> withdraw;
                }

                if (balance < withdraw) {
                    cout << "\n\tYou do not have enough money in your account to withdraw." << endl;
                } else {
                    balance -= withdraw;
                    cout << "\n\tYour Current Balance: $" << balance << endl;
                }
                break;

            case 4:
                cout << "\n\tEnter the 8-digit account number: ";
                cin >> account;
                
                cout << "\n\tEnter the amount to be transferred: $";
                cin >> transfer;
                
                // Input validation for transfer
                while (cin.fail() || transfer <= 0) {
                    cin.clear(); // Clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    cout << "\n\t Invalid amount. Please enter a positive number: ";
                    cin >> transfer;
                }

                if (balance < transfer) {
                    cout << "\n\tYou do not have enough money in your account to transfer." << endl;
                } else {
                    balance -= transfer;
                    cout << "\n\t$" << transfer << " has been transferred to account number " << account << " successfully!" << endl;
                }
                break;

            default:
                // Option 5: Exit
                break;
        }

    } while (option != 5);

    cout << "\n\tThank you for using the banking system. Goodbye!" << endl;
    return 0;
}
