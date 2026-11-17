#include <iostream>

double taxRate = 0.18; // Global Standard Tax Rate (18%)

int main() {
    double itemPrice = 1000.0;
    double taxRate = 0.05; // Local Subsidized Rate (5%)

    std::cout << "Local Rate: " << taxRate << std::endl;

    // Line 11: Developer attempts to use the global tax rate
    double totalWithGlobalTax = itemPrice + (itemPrice * :taxRate);

    {
        int taxRate = 12; // Nested local variable shadowing

        // Line 16: Developer attempts to access the outer local rate (0.05)
        double totalWithLocalTax = itemPrice + (itemPrice * ::taxRate);
        std::cout << "Inner total: " << totalWithLocalTax << std::endl;
    }

    std::cout << "Final Global Calculation: " << totalWithGlobalTax
              << std::endl;
    return 0;
}
