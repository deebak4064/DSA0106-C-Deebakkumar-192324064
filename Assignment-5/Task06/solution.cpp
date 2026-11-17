#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

class PaymentGateway {
public:
    virtual ~PaymentGateway() { cout << "~PaymentGateway()" << endl; }
    virtual bool Authorize(double amount) = 0;
    virtual bool Capture() = 0;
};

class CreditCardGateway : public PaymentGateway {
private:
    string cardNumber, cvv;
    double authorizedAmount;
    static bool allDigits(const string &s) {
        for (char ch : s) if (!isdigit(static_cast<unsigned char>(ch))) return false;
        return true;
    }
public:
    CreditCardGateway(const string &card, const string &code)
        : cardNumber(card), cvv(code), authorizedAmount(0.0) {}
    ~CreditCardGateway() override { cout << "~CreditCardGateway()" << endl; }
    bool Authorize(double amount) override {
        cout << "CreditCardGateway::Authorize($" << amount << ")" << endl;
        bool cardOk = cardNumber.length() == 16 && allDigits(cardNumber);
        bool cvvOk = cvv.length() == 3 && allDigits(cvv);
        cout << "  card has 16 digits: " << (cardOk ? "yes" : "no")
             << ", CVV has 3 digits: " << (cvvOk ? "yes" : "no") << endl;
        if (!cardOk || !cvvOk) return false;
        authorizedAmount = amount;
        return true;
    }
    bool Capture() override {
        if (authorizedAmount <= 0.0) return false;
        cout << "CreditCardGateway::Capture() -> settled $" << authorizedAmount << endl;
        authorizedAmount = 0.0;
        return true;
    }
};

class CryptoGateway : public PaymentGateway {
private:
    string walletHash;
    double walletBalance, authorizedAmount;
    const double GAS_FEE = 2.75;            // simulated network fee
public:
    CryptoGateway(const string &wallet, double balance)
        : walletHash(wallet), walletBalance(balance), authorizedAmount(0.0) {}
    ~CryptoGateway() override { cout << "~CryptoGateway()" << endl; }
    bool Authorize(double amount) override {
        cout << "CryptoGateway::Authorize($" << amount << ")" << endl;
        bool prefixOk = walletHash.substr(0, 2) == "0x";
        cout << "  wallet prefix \"0x\": " << (prefixOk ? "yes" : "no") << endl;
        if (!prefixOk) return false;
        double required = amount + GAS_FEE;
        cout << "  amount + gas = $" << required << " vs balance $" << walletBalance << endl;
        if (required > walletBalance) return false;
        authorizedAmount = amount;
        return true;
    }
    bool Capture() override {
        if (authorizedAmount <= 0.0) return false;
        walletBalance -= authorizedAmount + GAS_FEE;
        cout << "CryptoGateway::Capture() -> settled $" << authorizedAmount
             << ", wallet now $" << walletBalance << endl;
        authorizedAmount = 0.0;
        return true;
    }
};

void ProcessPayment(const string &method, double amount) {
    PaymentGateway *gatewayPtr = nullptr;
    if (method == "CRYPTO")
        gatewayPtr = new CryptoGateway("0x4a9F2c7E1b3D8e5A6f0C2d4B7e9A1c3F", 2000.00);
    else
        gatewayPtr = new CreditCardGateway("4111111111111111", "123");
    cout << "== " << method << " payment of $" << amount << " ==" << endl;
    if (gatewayPtr->Authorize(amount) && gatewayPtr->Capture())
        cout << "Payment SUCCESSFUL" << endl;
    else
        cout << "Payment DECLINED" << endl;
    delete gatewayPtr;                       // virtual destructor chain
}

int main() {
    cout << fixed << setprecision(2);
    ProcessPayment("CRYPTO", 1500.00);
    ProcessPayment("CARD", 1500.00);
    return 0;
}
