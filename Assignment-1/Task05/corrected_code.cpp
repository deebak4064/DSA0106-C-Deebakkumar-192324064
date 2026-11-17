#include <iostream>

int main() {
    int size = 5;

    // Allocating dynamic array
    int *readings = new int[size];

    // No semicolon after the for header: the block is the loop body
    for (int i = 0; i < size; ++i) {
        readings[i] = (i + 1) * 10;
    }

    int total = 0;
    for (int i = 0; i < size; ++i) {
        total += readings[i];
    }
    std::cout << "Total: " << total << std::endl;

    // Array form of delete matches new[]
    delete[] readings;
    readings = nullptr;

    return 0;
}
