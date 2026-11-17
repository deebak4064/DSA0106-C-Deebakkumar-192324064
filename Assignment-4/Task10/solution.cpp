#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Product {
public:
    string sku;
    double price;
    int stockCount;
    Product(const string &s, double p, int stock) : sku(s), price(p), stockCount(stock) {}
    void PrintProduct() const {
        cout << left << setw(9) << sku << right << " $" << setw(8) << price
             << "  stock " << setw(4) << stockCount << "  @ " << static_cast<const void*>(this) << endl;
    }
};

int main() {
    const int N = 3;
    Product *catalog[N];
    catalog[0] = new Product("LAPTOP", 1200.00, 15);
    catalog[1] = new Product("MOUSE", 25.00, 120);
    catalog[2] = new Product("MONITOR", 350.00, 40);
    cout << fixed << setprecision(2);

    cout << "Before sorting:" << endl;
    for (int i = 0; i < N; ++i) catalog[i]->PrintProduct();

    for (int pass = 1; pass <= N - 1; ++pass) {
        bool swapped = false;
        for (int j = 0; j < N - pass; ++j) {
            if (catalog[j]->price > catalog[j + 1]->price) {
                Product *temp = catalog[j];        // swap pointers only
                catalog[j] = catalog[j + 1];
                catalog[j + 1] = temp;
                swapped = true;
                cout << "Pass " << pass << ": swapped pointers " << j << " and " << j + 1 << endl;
            }
        }
        if (!swapped) { cout << "Pass " << pass << ": no swaps, done" << endl; break; }
    }

    cout << "After sorting (objects did not move):" << endl;
    for (int i = 0; i < N; ++i) catalog[i]->PrintProduct();

    for (int i = 0; i < N; ++i) { delete catalog[i]; catalog[i] = nullptr; }
    cout << "All products deallocated." << endl;
    return 0;
}
