#include <iostream>
#include <iomanip>
using namespace std;

class ATM_SessionController {
private:
    static const int PRESET_PIN = 4821, MAX_ATTEMPTS = 3, NOTE_VALUE = 100;
    double balance;
    bool cardLocked;

    bool Authenticate() {
        int attempts = 0, enteredPIN;
        while (attempts < MAX_ATTEMPTS) {
            cout << "Enter 4-digit PIN: ";
            cin >> enteredPIN;
            attempts++;
            if (enteredPIN == PRESET_PIN) { cout << "PIN accepted." << endl; return true; }
            cout << "Incorrect PIN. Attempts left: " << MAX_ATTEMPTS - attempts << endl;
        }
        cardLocked = true;
        cout << "Card locked: 3 incorrect attempts." << endl;
        return false;
    }
    void Deposit(double amount) {
        if (amount > 0.0) {
            balance += amount;
            cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
        } else cout << "Declined: deposit must be a positive amount." << endl;
    }
    void Withdraw(int amount) {
        if (amount <= 0)                    cout << "Declined: amount must be positive." << endl;
        else if (amount > balance)          cout << "Declined: insufficient balance." << endl;
        else if (amount % NOTE_VALUE != 0)  cout << "Declined: amount must be a multiple of 100." << endl;
        else {
            balance -= amount;
            cout << "Please collect $" << amount << ". New balance: $" << balance << endl;
        }
    }
public:
    explicit ATM_SessionController(double openingBalance) : balance(openingBalance), cardLocked(false) {}

    void RunSession() {
        int choice = 0, withdrawAmount;
        double depositAmount;
        cout << fixed << setprecision(2);
        if (!Authenticate()) return;
        while (choice != 4) {
            cout << "1: Balance  2: Deposit  3: Withdraw  4: Exit" << endl;
            cout << "Choice: ";
            cin >> choice;
            switch (choice) {
                case 1: cout << "Available balance: $" << balance << endl; break;
                case 2: cout << "Enter deposit amount: "; cin >> depositAmount; Deposit(depositAmount); break;
                case 3: cout << "Enter withdrawal amount: "; cin >> withdrawAmount; Withdraw(withdrawAmount); break;
                case 4: cout << "Thank you. Session ended." << endl; break;
                default: cout << "Invalid option. Choose 1 to 4." << endl;
            }
        }
    }
};

int main() {
    ATM_SessionController atm(5000.00);
    atm.RunSession();
    return 0;
}
