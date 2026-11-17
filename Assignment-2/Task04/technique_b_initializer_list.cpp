#include <iostream>
#include <string>
class Student {
    int rollNumber; std::string name;
public:
    Student(int r, const std::string &n) : rollNumber(r), name(n) {}
    void display() const { std::cout << "Roll: " << rollNumber << ", Name: " << name << std::endl; }
};
int main() {
    // Technique B: no default constructor needed
    Student batch[3] = { Student(101, "Aarav"), Student(102, "Bhavna"), Student(103, "Chirag") };
    for (const Student &s : batch) s.display();
}
