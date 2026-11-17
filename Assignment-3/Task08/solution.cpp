#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Currency {
private:
    int dollars, cents;
    void Normalize() {
        int totalCents = dollars * 100 + cents;
        dollars = totalCents / 100;   // truncates toward zero
        cents   = totalCents % 100;   // same sign as totalCents
    }
public:
    Currency(int d = 0, int c = 0) : dollars(d), cents(c) { Normalize(); }

    Currency operator-() const { return Currency(-dollars, -cents); }

    friend ostream& operator<<(ostream &outStream, const Currency &cur);
    friend istream& operator>>(istream &inStream, Currency &cur);
};

ostream& operator<<(ostream &outStream, const Currency &cur) {
    if (cur.dollars < 0 || cur.cents < 0) outStream << "-";
    outStream << "$" << abs(cur.dollars) << "." << setw(2) << setfill('0') << abs(cur.cents) << setfill(' ');
    return outStream;
}

istream& operator>>(istream &inStream, Currency &cur) {
    inStream >> cur.dollars >> cur.cents;
    cur.Normalize();
    return inStream;
}

int main() {
    Currency a(2, 150), b(5, -30);
    cout << "Currency(2, 150)  = " << a << endl;
    cout << "Currency(5, -30)  = " << b << endl;
    Currency cur;
    cout << "Enter dollars and cents: ";
    cin >> cur;
    cout << "Normalized        = " << cur << endl;
    cout << "Negated (-cur)    = " << -cur << endl;
    cout << "Negated twice     = " << -(-cur) << endl;
    return 0;
}
