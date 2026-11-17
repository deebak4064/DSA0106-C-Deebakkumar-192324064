#include <iostream>
#include <string>

class Student {
private:
    int rollNumber;
    std::string name;

public:
    // Technique A: explicit default constructor
    Student() : rollNumber(0), name("Unassigned") {}

    Student(int r, const std::string &n) : rollNumber(r), name(n) {}

    void display() const {
        std::cout << "Roll: " << rollNumber << ", Name: " << name << std::endl;
    }
};

int main() {
    Student batch[3]; // each element built with Student()

    batch[0] = Student(101, "Aarav");
    batch[1] = Student(102, "Bhavna");
    batch[2] = Student(103, "Chirag");

    for (int i = 0; i < 3; ++i) {
        batch[i].display();
    }
    return 0;
}
