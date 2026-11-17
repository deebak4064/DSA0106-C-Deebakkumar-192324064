#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee {
protected:
    string employeeID, name;
public:
    Employee(const string &id, const string &n) : employeeID(id), name(n) {}
    virtual ~Employee() {}
    virtual double CalculatePay() const = 0;      // pure virtual
    void DisplayHeader() const { cout << employeeID << "  " << left << setw(14) << name << right; }
};

class SalariedEmployee : public Employee {
private:
    double monthlySalary;
public:
    SalariedEmployee(const string &id, const string &n, double salary)
        : Employee(id, n), monthlySalary(salary) {}
    double CalculatePay() const override { return monthlySalary; }
};

class HourlyEmployee : public Employee {
private:
    double hourlyWage, hoursWorked;
public:
    HourlyEmployee(const string &id, const string &n, double wage, double hours)
        : Employee(id, n), hourlyWage(wage), hoursWorked(hours) {}
    double CalculatePay() const override {
        const double REGULAR_LIMIT = 40.0, OVERTIME_RATE = 1.5;
        if (hoursWorked <= REGULAR_LIMIT) return hourlyWage * hoursWorked;
        double regularPay  = hourlyWage * REGULAR_LIMIT;
        double overtimePay = hourlyWage * OVERTIME_RATE * (hoursWorked - REGULAR_LIMIT);
        return regularPay + overtimePay;
    }
};

int main() {
    const int N = 2;
    Employee **staff = new Employee*[N];
    staff[0] = new SalariedEmployee("E101", "Anita Sharma", 8500.00);
    staff[1] = new HourlyEmployee("E102", "Ravi Kumar", 50.00, 48.0);

    double totalDisbursement = 0.0;
    cout << fixed << setprecision(2);
    for (int i = 0; i < N; ++i) {
        double pay = staff[i]->CalculatePay();    // dynamic dispatch
        totalDisbursement += pay;
        staff[i]->DisplayHeader();
        cout << " Pay: $" << setw(8) << pay << endl;
    }
    cout << "Total disbursement: $" << totalDisbursement << endl;

    for (int i = 0; i < N; ++i) delete staff[i];
    delete[] staff;
    cout << "All payroll objects deallocated." << endl;
    return 0;
}
