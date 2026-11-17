#include <iostream>

int main() {
    int a = 25;

    // Reference bound at the point of declaration
    int &refA = a;

    // const reference may bind to a literal (temporary is lifetime-extended)
    const int &refLiteral = 100;

    // Explicit conversion into a named int, then bind a normal reference
    double pi = 3.14159;
    int piWhole = static_cast<int>(pi);
    int &refInt = piWhole;

    // Read through the const reference; store the result in a new variable
    const int &constRef = 50;
    int updatedValue = constRef + 10;

    std::cout << a << " " << refA << std::endl;
    std::cout << refLiteral << " " << refInt << " "
              << constRef << " " << updatedValue << std::endl;
    return 0;
}
