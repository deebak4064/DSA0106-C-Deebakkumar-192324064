#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accHolder;
    double balance;
    static double totalBankReserves; // declaration only

public:
    BankAccount(const std::string &name, double initialDeposit)
        : accHolder(name), balance(initialDeposit) {
        totalBankReserves += initialDeposit;
    }

    // Static: uses class-level data only
    static void displayAudit() {
        std::cout << "Total Reserves in Vault: $" << totalBankReserves << std::endl;
    }

    // Non-static: has a this pointer, so it can read instance data
    void displayAccount() const {
        std::cout << "Account Holder: " << accHolder
                  << ", Balance: $" << balance << std::endl;
    }
};

// File-scope definition: allocates storage for the static member
double BankAccount::totalBankReserves = 0.0;

int main() {
    BankAccount acc1("Alice", 5000.0);
    BankAccount acc2("Bob", 3000.0);

    BankAccount::displayAudit();
    acc1.displayAccount();
    acc2.displayAccount();
    return 0;
}
