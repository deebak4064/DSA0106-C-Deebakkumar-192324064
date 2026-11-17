#include <iostream>

class StepCounter {
private:
    int steps;

public:
    StepCounter(int s = 0) : steps(s) {}

    // PREFIX: no parameter, increment first, return the object itself
    StepCounter& operator++() {
        ++steps;
        return *this;
    }

    // POSTFIX: dummy int, save old state, increment, return the old copy
    StepCounter operator++(int) {
        StepCounter temp = *this;
        ++steps;
        return temp;
    }

    void display() const {
        std::cout << "Steps: " << steps << std::endl;
    }
};

int main() {
    StepCounter c1(10);

    StepCounter c2 = ++c1;            // prefix
    std::cout << "c2 = ++c1 -> c2 "; c2.display();
    std::cout << "              c1 "; c1.display();

    StepCounter c3 = c1++;            // postfix
    std::cout << "c3 = c1++ -> c3 "; c3.display();
    std::cout << "              c1 "; c1.display();

    ++(++c1);                         // chained prefix acts on c1 itself
    std::cout << "++(++c1)  -> c1 "; c1.display();
    return 0;
}
