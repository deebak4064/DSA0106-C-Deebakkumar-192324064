#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class TransactionException {
protected:
    string reason;
public:
    TransactionException(const string &r) : reason(r) {}
    virtual ~TransactionException() {}
    string GetReason() const { return reason; }
};

class AccountFrozenException : public TransactionException {
public:
    AccountFrozenException(const string &r) : TransactionException(r) {}
};

class DailyLimitExceededException : public TransactionException {
private:
    double excessAmount;
public:
    DailyLimitExceededException(const string &r, double excess)
        : TransactionException(r), excessAmount(excess) {}
    double GetExcess() const { return excessAmount; }
};

struct Account {
    string id;
    bool frozen;
    double withdrawnToday;
};

void DebitLedger(Account &acc, double amount) {
    const double DAILY_LIMIT = 50000.00;
    cout << "  [DebitLedger] checking " << acc.id << endl;
    if (acc.frozen)
        throw AccountFrozenException("Account " + acc.id + " is frozen");
    if (acc.withdrawnToday + amount > DAILY_LIMIT)
        throw DailyLimitExceededException("Daily limit exceeded",
                                          acc.withdrawnToday + amount - DAILY_LIMIT);
    acc.withdrawnToday += amount;
    cout << "  [DebitLedger] debited $" << amount << endl;
}

void AuditTransactionWrapper(Account &acc, double amount) {
    try {
        DebitLedger(acc, amount);
    }
    catch (const TransactionException &e) {
        cout << "  [AUDIT] security log: " << e.GetReason() << endl;
        throw;                                // rethrow the active exception
    }
}

void Withdraw(Account &acc, double amount) {
    cout << "Withdraw $" << amount << " from " << acc.id << endl;
    try {
        AuditTransactionWrapper(acc, amount);
        cout << "Notice: withdrawal approved" << endl;
    }
    catch (const AccountFrozenException &e) {
        cout << "Notice: account frozen, contact your branch" << endl;
    }
    catch (const DailyLimitExceededException &e) {
        cout << "Notice: limit exceeded by $" << e.GetExcess() << endl;
    }
    catch (const TransactionException &e) {
        cout << "Notice: transaction failed: " << e.GetReason() << endl;
    }
    catch (...) {
        cout << "Notice: unexpected system error" << endl;
    }
}

int main() {
    cout << fixed << setprecision(2);
    Account frozenAcc {"ACC-1001", true, 0.0};
    Account busyAcc   {"ACC-2002", false, 49500.00};
    Account normalAcc {"ACC-3003", false, 0.0};
    Withdraw(frozenAcc, 1000.00);
    Withdraw(busyAcc, 1000.00);
    Withdraw(normalAcc, 1000.00);
    return 0;
}
