#include <iostream>

int main() {
    int size = 5;

    // Line 7: Allocating dynamic array
    int *readings = new int[size];

    // Line 10: Loop initialization with a punctuation defect
    for (int i = 0; i < size; ++i);
    {
        readings[i] = (i + 1) * 10;
    }

    int total = 0;
    for (int i = 0; i < size; ++i) {
        total += readings[i];
    }
    std::cout << "Total: " << total << std::endl;

    // Line 21: Heap memory deallocation
    delete readings;

    return 0;
}
