#include <iostream>
#include <string>

class Person {
public:
    int idNumber;
    Person(int id = 0) : idNumber(id) {
        std::cout << "Person initialized: " << idNumber << std::endl;
    }
};

// Virtual inheritance: Student and Employee share one Person subobject
class Student : virtual public Person {
public:
    Student(int id) : Person(id) {
        std::cout << "Student constructed" << std::endl;
    }
};

class Employee : virtual public Person {
public:
    Employee(int id) : Person(id) {
        std::cout << "Employee constructed" << std::endl;
    }
};

class TeachingAssistant : public Student, public Employee {
public:
    // The most derived class initialises the virtual base directly;
    // the Person(id) calls inside Student and Employee are skipped
    TeachingAssistant(int sId, int eId)
        : Person(sId), Student(sId), Employee(eId) {
        std::cout << "TeachingAssistant constructed" << std::endl;
    }
};

int main() {
    TeachingAssistant ta(101, 202);

    std::cout << "TA ID: " << ta.idNumber << std::endl;
    std::cout << "Via Student path : " << ta.Student::idNumber << std::endl;
    std::cout << "Via Employee path: " << ta.Employee::idNumber << std::endl;
    std::cout << "Address via Student : " << static_cast<void*>(&ta.Student::idNumber) << std::endl;
    std::cout << "Address via Employee: " << static_cast<void*>(&ta.Employee::idNumber) << std::endl;
    return 0;
}
