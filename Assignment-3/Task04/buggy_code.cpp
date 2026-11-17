#include <iostream>

class StepCounter {
private:
    int steps;

public:
    StepCounter(int s = 0) : steps(s) {}

    // Line 10: Intended as POSTFIX, but missing dummy int parameter
    StepCounter operator++() {
        StepCounter temp = *this;
        steps++;
        return temp;
    }

    // Line 17: Intended as PREFIX, but includes dummy int parameter
    StepCounter& operator++(int) {
        steps++;
        return *this;
    }

    void display() const {
        std::cout << "Steps: " << steps << std::endl;
    }
};

int main() {
    StepCounter c1(10);

    // Developer expects prefix (++c1) to increment immediately and return modified object
    StepCounter c2 = ++c1;
    c2.display(); // Prints 10 instead of 11!
    c1.display(); // Prints 11

    return 0;
}
