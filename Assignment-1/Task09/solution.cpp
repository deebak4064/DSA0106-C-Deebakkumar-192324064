#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, d, limit, pairedDivisor, sumOfDivisors;

InputPrompt:
    cout << "Enter a positive integer N: ";
    cin >> N;
    if (N <= 0) {
        cout << "Error: N must be greater than 0. Try again." << endl;
        goto InputPrompt;
    }

    if (N == 1) {
        cout << "N = 1 has no proper divisors. Sum = 0" << endl;
        cout << "Classification: Deficient (1 is neither prime nor composite)" << endl;
        goto Finish;
    }

    sumOfDivisors = 1;
    limit = static_cast<int>(floor(sqrt(static_cast<double>(N))));
    for (d = 2; d <= limit; ++d) {
        if (N % d != 0) continue;
        pairedDivisor = N / d;
        if (pairedDivisor == d) sumOfDivisors += d;
        else                    sumOfDivisors += d + pairedDivisor;
        cout << "Divisor pair: " << d << " and " << pairedDivisor << endl;
    }
    cout << "Sum of proper divisors = " << sumOfDivisors << endl;

    if (sumOfDivisors == 1) cout << N << " is Prime" << endl;
    else                    cout << N << " is Composite" << endl;

    if (sumOfDivisors == N)     cout << "Classification: Perfect Number" << endl;
    else if (sumOfDivisors > N) cout << "Classification: Abundant Number" << endl;
    else                        cout << "Classification: Deficient Number" << endl;

Finish:
    return 0;
}
