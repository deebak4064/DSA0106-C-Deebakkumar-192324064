#include <iostream>
#include <string>

class Student {
private:
    int rollNumber;
    std::string name;

public:
    // Parameterized constructor defined by programmer
    Student(int r, std::string n) {
        rollNumber = r;
        name = n;
    }

    void display() const {
        std::cout << "Roll: " << rollNumber << ", Name: " << name << std::endl;
    }
};

int main() {
    // Line 20: Array of 3 Student objects
    Student batch[3]; // Compilation Error!

    batch[0] = Student(101, "Aarav");
    batch[1] = Student(102, "Bhavna");
    batch[2] = Student(103, "Chirag");

    for (int i = 0; i < 3; ++i) {
        batch[i].display();
    }
    return 0;
}
