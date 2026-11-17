#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Person {
protected:
    string personID, fullName, email;
public:
    Person(const string &id, const string &name, const string &mail)
        : personID(id), fullName(name), email(mail) {
        cout << "[1] Person(" << personID << ") constructed" << endl;
    }
};

class Student : virtual public Person {
protected:
    double gpa;
    int creditsEarned;
public:
    Student(const string &id, const string &name, const string &mail, double g, int credits)
        : Person(id, name, mail), gpa(g), creditsEarned(credits) {
        cout << "[2] Student part constructed" << endl;
    }
};

class Faculty : virtual public Person {
protected:
    string academicDepartment, rankTitle;
public:
    Faculty(const string &id, const string &name, const string &mail, const string &dept, const string &rank)
        : Person(id, name, mail), academicDepartment(dept), rankTitle(rank) {
        cout << "[3] Faculty part constructed" << endl;
    }
};

class TeachingAssistant : public Student, public Faculty {
private:
    double stipendAmount;
    string assignedCourse;
public:
    TeachingAssistant(const string &id, const string &name, const string &mail, double g, int credits,
                      const string &dept, const string &rank, double stipend, const string &course)
        : Person(id, name, mail),
          Student(id, name, mail, g, credits),
          Faculty(id, name, mail, dept, rank),
          stipendAmount(stipend), assignedCourse(course) {
        cout << "[4] TeachingAssistant constructed" << endl;
    }
    void DisplayTARecord() const {
        cout << fixed << setprecision(2);
        cout << "---------- TA RECORD ----------" << endl;
        cout << "Person ID  : " << personID << endl;
        cout << "Name       : " << fullName << endl;
        cout << "Email      : " << email << endl;
        cout << "GPA        : " << gpa << " (" << creditsEarned << " credits)" << endl;
        cout << "Department : " << academicDepartment << " / " << rankTitle << endl;
        cout << "Course     : " << assignedCourse << endl;
        cout << "Stipend    : Rs. " << stipendAmount << endl;
    }
};

int main() {
    TeachingAssistant ta("TA-2024-017", "Priya Raman", "priya.r@univ.edu", 9.12, 142,
                         "Computer Science", "Junior Instructor", 18000.00, "CS201 Data Structures");
    ta.DisplayTARecord();
    return 0;
}
