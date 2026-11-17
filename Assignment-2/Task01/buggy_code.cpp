#include <iostream>

// Line 4: Utility to scale and return the larger value
int& getMaximumScaled(int a, int b, int scaleFactor) {
    int maxVal = (a > b) ? a : b;
    int result = maxVal * scaleFactor;
    return result; // Warning / Undefined Behavior!
}

// Line 11: Array element modifier
int& getArrayElement(int arr[], int index) {
    return arr[index];
}

int main() {
    int x = 10, y = 20;

    // Line 19: Receiving the reference
    int &danglingRef = getMaximumScaled(x, y, 2);
    std::cout << "Scaled Max: " << danglingRef << std::endl;

    int data[3] = {100, 200, 300};
    getArrayElement(data, 1) = 999; // Lvalue assignment
    std::cout << "Updated Array[1]: " << data[1] << std::endl;

    // Line 27: Reading reference after subsequent stack calls
    std::cout << "Dangling Ref Value: " << danglingRef << std::endl;
    return 0;
}
