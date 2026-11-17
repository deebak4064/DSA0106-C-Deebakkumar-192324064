#include <iostream>

double taxRate = 0.18; // Global Standard Tax Rate (18%)

int main() {
    double itemPrice = 1000.0;
    double localTaxRate = 0.05; // Local Subsidized Rate (5%)

    std::cout << "Local Rate: " << localTaxRate << std::endl;

    // :: (two colons) selects the global taxRate
    double totalWithGlobalTax = itemPrice + (itemPrice * ::taxRate);

    {
        int corporateTaxRate = 12; // Corporate rate in percent

        double totalWithLocalTax = itemPrice + (itemPrice * localTaxRate);
        std::cout << "Corporate Rate: " << corporateTaxRate << "%" << std::endl;
        std::cout << "Inner total: " << totalWithLocalTax << std::endl;
    }

    std::cout << "Final Global Calculation: " << totalWithGlobalTax
              << std::endl;
    return 0;
}
