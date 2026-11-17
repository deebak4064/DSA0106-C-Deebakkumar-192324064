#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const double CAP_80C = 150000.00, CAP_HEALTH = 25000.00;
    const double SLAB1_LIMIT = 250000.00, SLAB2_LIMIT = 500000.00, SLAB3_LIMIT = 1000000.00;
    const double RATE_SLAB2 = 0.05, RATE_SLAB3 = 0.20, RATE_SLAB4 = 0.30, CESS_RATE = 0.04;
    double grossAnnualSalary, deduction80C, deductionHealthInsurance;

    cout << "Enter gross annual salary       : "; cin >> grossAnnualSalary;
    cout << "Enter 80C deduction             : "; cin >> deduction80C;
    cout << "Enter health insurance deduction: "; cin >> deductionHealthInsurance;

    if (grossAnnualSalary < 0 || deduction80C < 0 || deductionHealthInsurance < 0) {
        cout << "Error: amounts cannot be negative." << endl;
        return 1;
    }
    double eligible80C    = (deduction80C > CAP_80C) ? CAP_80C : deduction80C;
    double eligibleHealth = (deductionHealthInsurance > CAP_HEALTH) ? CAP_HEALTH : deductionHealthInsurance;
    double totalDeduction = eligible80C + eligibleHealth;
    double taxableIncome  = (totalDeduction >= grossAnnualSalary) ? 0.0 : grossAnnualSalary - totalDeduction;

    double rawTax;
    if (taxableIncome > SLAB3_LIMIT)
        rawTax = (SLAB2_LIMIT - SLAB1_LIMIT) * RATE_SLAB2 + (SLAB3_LIMIT - SLAB2_LIMIT) * RATE_SLAB3
               + (taxableIncome - SLAB3_LIMIT) * RATE_SLAB4;
    else if (taxableIncome > SLAB2_LIMIT)
        rawTax = (SLAB2_LIMIT - SLAB1_LIMIT) * RATE_SLAB2 + (taxableIncome - SLAB2_LIMIT) * RATE_SLAB3;
    else if (taxableIncome > SLAB1_LIMIT)
        rawTax = (taxableIncome - SLAB1_LIMIT) * RATE_SLAB2;
    else
        rawTax = 0.0;

    double cess = rawTax * CESS_RATE;
    double totalTax = rawTax + cess;
    long finalTax = static_cast<long>(totalTax + 0.5);

    cout << fixed << setprecision(2);
    cout << "Taxable Income  : " << taxableIncome << endl;
    cout << "Raw Tax         : " << rawTax << endl;
    cout << "Cess (4%)       : " << cess << endl;
    cout << "Final Tax (int) : " << finalTax << endl;
    return 0;
}
