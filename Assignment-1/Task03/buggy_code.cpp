#include <iostream>

int main() {
    int tokenType = 2;
    float tokenValue = 0.0f;

    switch (tokenType) {
        case 1:
            int offset = 10;
            tokenValue = 50.0f + offset;
            break;

        case 2:
            int multiplier = 5; // Error occurs here!
            tokenValue = 20.0f * multiplier;
            // Developer forgot break statement here

        case 3:
            tokenValue += 100.0f;
            break;

        case 4.5: // Error occurs here!
            std::cout << "Float token detected" << std::endl;
            break;

        default:
            std::cout << "Unknown token" << std::endl;
    }

    std::cout << "Calculated Value: " << tokenValue << std::endl;
    return 0;
}
