#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class StudentRecord {
private:
    int rollNo;
    string studentName;
    double marks[3];
    double percentage;
    char grade;
    void CalculateResult() {
        percentage = (marks[0] + marks[1] + marks[2]) / 3.0;
        if (percentage >= 85.0)      grade = 'A';
        else if (percentage >= 70.0) grade = 'B';
        else if (percentage >= 50.0) grade = 'C';
        else                         grade = 'F';
    }
public:
    StudentRecord() : rollNo(0), studentName("-"), marks{0, 0, 0}, percentage(0.0), grade('-') {}
    void ReadData(int r, const string &name, double m1, double m2, double m3) {
        rollNo = r; studentName = name;
        marks[0] = m1; marks[1] = m2; marks[2] = m3;
        CalculateResult();
    }
    double GetPercentage() const { return percentage; }
    void Display() const {
        cout << left << setw(6) << rollNo << setw(10) << studentName << right
             << setw(6) << marks[0] << setw(6) << marks[1] << setw(6) << marks[2]
             << setw(9) << percentage << "   " << grade << endl;
    }
};

int main() {
    const int N = 3;
    StudentRecord roster[N];
    roster[0].ReadData(101, "Aarav", 65, 70, 72);
    roster[1].ReadData(102, "Bhavna", 88, 92, 85);
    roster[2].ReadData(103, "Chirag", 75, 80, 70);
    cout << fixed << setprecision(2);

    for (int pass = 1; pass <= N - 1; ++pass) {
        bool swapped = false;
        for (int j = 0; j < N - pass; ++j) {
            if (roster[j].GetPercentage() < roster[j + 1].GetPercentage()) {
                StudentRecord temp = roster[j];
                roster[j] = roster[j + 1];
                roster[j + 1] = temp;
                swapped = true;
                cout << "Pass " << pass << ": swapped positions " << j << " and " << j + 1 << endl;
            }
        }
        if (!swapped) { cout << "Pass " << pass << ": no swaps, sorting complete" << endl; break; }
    }

    cout << setw(4) << "Rank" << " " << left << setw(6) << "Roll" << setw(10) << "Name" << right
         << setw(6) << "M1" << setw(6) << "M2" << setw(6) << "M3" << setw(9) << "Percent" << "   Grade" << endl;
    for (int i = 0; i < N; ++i) { cout << setw(4) << i + 1 << " "; roster[i].Display(); }
    return 0;
}
