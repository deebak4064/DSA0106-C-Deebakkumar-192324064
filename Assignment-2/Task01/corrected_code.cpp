#include <iostream>

// Return by value: the result is copied out before the stack frame is destroyed
int getMaximumScaled(int a, int b, int scaleFactor) {
    int maxVal = (a > b) ? a : b;
    int result = maxVal * scaleFactor;
    return result;
}

// Safe return by reference: arr[index] lives in the caller's array
int& getArrayElement(int arr[], int index) {
    return arr[index];
}

int main() {
    int x = 10, y = 20;

    // Store a copy of the returned value in a variable owned by main()
    int scaledMax = getMaximumScaled(x, y, 2);
    std::cout << "Scaled Max: " << scaledMax << std::endl;

    int data[3] = {100, 200, 300};
    getArrayElement(data, 1) = 999; // Lvalue assignment through reference
    std::cout << "Updated Array[1]: " << data[1] << std::endl;

    // Still valid after further function calls
    std::cout << "Scaled Max (re-read): " << scaledMax << std::endl;
    return 0;
}
