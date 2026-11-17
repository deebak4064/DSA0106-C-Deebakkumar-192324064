#include <iostream>

class Person {
public:
    int idNumber;
    Person(int id = 0) : idNumber(id) {
        std::cout << "Person initialized: " << idNumber << std::endl;
    }
};
class Student : public Person { public: Student(int id) : Person(id) {} };
class Employee : public Person { public: Employee(int id) : Person(id) {} };
class TeachingAssistant : public Student, public Employee {
public:
    TeachingAssistant(int sId, int eId) : Student(sId), Employee(eId) {}
};

int main() {
    TeachingAssistant ta(101, 202);
    // Qualified access shows the two separate Person subobjects
    std::cout << "ta.Student::idNumber  = " << ta.Student::idNumber << std::endl;
    std::cout << "ta.Employee::idNumber = " << ta.Employee::idNumber << std::endl;
    std::cout << "sizeof(TeachingAssistant) = " << sizeof(ta) << " bytes" << std::endl;
    return 0;
}
