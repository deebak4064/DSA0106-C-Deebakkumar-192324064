#include <iostream>
#include <string>

// Base custom exception
class BankingException {
protected:
    std::string msg;
public:
    BankingException(std::string m) : msg(m) {}
    virtual std::string getMessage() const { return msg; }
};

// Derived specific exception
class InsufficientFundsException : public BankingException {
private:
    double shortfall;
public:
    InsufficientFundsException(std::string m, double sf)
        : BankingException(m), shortfall(sf) {}

    double getShortfall() const { return shortfall; }
};

void processWithdrawal(double balance, double amount) {
    if (amount > balance) {
        throw InsufficientFundsException("Account overdrawn!", amount - balance);
    }
}

int main() {
    try {
        processWithdrawal(500.0, 750.0);
    }
    // Line 34: Base handler placed FIRST!
    catch (const BankingException &be) {
        std::cout << "General Banking Error: " << be.getMessage() << std::endl;
    }
    // Line 38: Specific derived handler placed SECOND!
    catch (const InsufficientFundsException &ife) {
        std::cout << "Shortfall of: $" << ife.getShortfall() << std::endl;
    }

    return 0;
}
