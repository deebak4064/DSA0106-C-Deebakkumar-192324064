#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class BranchOffice {
private:
    string branchID, branchName;
    double currentBalance;
    static double totalVaultReserves;
    static int totalBranchesActive;
public:
    BranchOffice(const string &id, const string &name, double openingDeposit)
        : branchID(id), branchName(name), currentBalance(openingDeposit) {
        totalVaultReserves += openingDeposit;
        totalBranchesActive += 1;
    }
    void Deposit(double amount) {
        currentBalance += amount;
        totalVaultReserves += amount;
        cout << branchID << " deposited $" << amount << " -> branch balance $" << currentBalance << endl;
    }
    bool Withdraw(double amount) {
        if (amount > 0 && amount <= currentBalance) {
            currentBalance -= amount;
            totalVaultReserves -= amount;
            cout << branchID << " withdrew $" << amount << " -> branch balance $" << currentBalance << endl;
            return true;
        }
        cout << branchID << " withdrawal of $" << amount << " DECLINED (insufficient funds)" << endl;
        return false;
    }
    static void GetVaultSummary() {
        cout << "Branches active: " << totalBranchesActive
             << " | Vault reserves: $" << totalVaultReserves << endl;
    }
    static double GetGlobalLiquidityRatio(double targetReserve) {
        if (targetReserve <= 0.0) return 0.0;
        return totalVaultReserves / targetReserve;
    }
};

double BranchOffice::totalVaultReserves = 0.0;
int BranchOffice::totalBranchesActive = 0;

int main() {
    cout << fixed << setprecision(2);
    BranchOffice::GetVaultSummary();
    BranchOffice branch1("BR001", "Chennai Central", 500000.00);
    BranchOffice branch2("BR002", "Coimbatore North", 300000.00);
    BranchOffice::GetVaultSummary();
    branch1.Deposit(150000.00);
    branch2.Withdraw(50000.00);
    branch2.Withdraw(400000.00);
    BranchOffice::GetVaultSummary();
    cout << "Liquidity ratio (target $1000000.00): "
         << BranchOffice::GetGlobalLiquidityRatio(1000000.00) << endl;
    return 0;
}
