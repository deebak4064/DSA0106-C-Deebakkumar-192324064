#include <iostream>
#include <string>

class Person {
public:
    int idNumber;
    Person(int id = 0) : idNumber(id) {
        std::cout << "Person initialized: " << idNumber << std::endl;
    }
};

// Line 12: Standard non-virtual inheritance
class Student : public Person {
public:
    Student(int id) : Person(id) {}
};

// Line 18: Standard non-virtual inheritance
class Employee : public Person {
public:
    Employee(int id) : Person(id) {}
};

// Hybrid inheritance combining Student and Employee
class TeachingAssistant : public Student, public Employee {
public:
    TeachingAssistant(int sId, int eId)
        : Student(sId), Employee(eId) {}
};

int main() {
    TeachingAssistant ta(101, 202);

    // Line 33: Ambiguous member access!
    std::cout << "TA ID: " << ta.idNumber << std::endl;

    return 0;
}
