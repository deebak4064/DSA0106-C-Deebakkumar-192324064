#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accHolder;
    double balance;
    static double totalBankReserves; // Line 8: Static data member

public:
    BankAccount(std::string name, double initialDeposit) {
        accHolder = name;
        balance = initialDeposit;
        totalBankReserves += initialDeposit;
    }

    // Line 17: Static member function
    static void displayAudit() {
        std::cout << "Total Reserves in Vault: $" << totalBankReserves << std::endl;
        std::cout << "Account Holder: " << accHolder << std::endl; // Error!
    }
};

int main() {
    BankAccount acc1("Alice", 5000.0);
    BankAccount acc2("Bob", 3000.0);

    BankAccount::displayAudit();
    return 0;
}
