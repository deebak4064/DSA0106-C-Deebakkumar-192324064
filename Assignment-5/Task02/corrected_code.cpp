#include <iostream>
#include <string>

class BankingException {
protected:
    std::string msg;
public:
    BankingException(const std::string &m) : msg(m) {}
    virtual ~BankingException() {}
    virtual std::string getMessage() const { return msg; }
};

class InsufficientFundsException : public BankingException {
private:
    double shortfall;
public:
    InsufficientFundsException(const std::string &m, double sf)
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
    // Most derived (specific) handler first
    catch (const InsufficientFundsException &ife) {
        std::cout << "Insufficient Funds: " << ife.getMessage() << std::endl;
        std::cout << "Shortfall of: $" << ife.getShortfall() << std::endl;
    }
    // Then the base class handler
    catch (const BankingException &be) {
        std::cout << "General Banking Error: " << be.getMessage() << std::endl;
    }
    // Catch-all fallback: always last
    catch (...) {
        std::cout << "Unknown error occurred." << std::endl;
    }

    return 0;
}
