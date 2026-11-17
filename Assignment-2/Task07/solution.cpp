#include <iostream>
#include <iomanip>
using namespace std;

class Matrix2D {
private:
    double grid[3][3];
public:
    void Initialize();
    bool SetElement(int row, int col, double value);
    double GetElement(int row, int col) const;
    void Display() const;
    friend double ComputeCrossTrace(Matrix2D A, Matrix2D B);
};

void Matrix2D::Initialize() {
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
            grid[r][c] = 0.0;
}
bool Matrix2D::SetElement(int row, int col, double value) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        cout << "Error: index (" << row << ", " << col << ") out of bounds" << endl;
        return false;
    }
    grid[row][col] = value;
    return true;
}
double Matrix2D::GetElement(int row, int col) const {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        cout << "Error: index (" << row << ", " << col << ") out of bounds" << endl;
        return 0.0;
    }
    return grid[row][col];
}
void Matrix2D::Display() const {
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) cout << setw(6) << grid[r][c];
        cout << endl;
    }
}

double ComputeCrossTrace(Matrix2D A, Matrix2D B) {
    double sum = 0.0;
    for (int i = 0; i < 3; ++i) {
        double term = A.grid[i][i] * B.grid[i][i];
        sum += term;
        cout << "i=" << i << ": " << A.grid[i][i] << " x " << B.grid[i][i]
             << " = " << term << ", running sum = " << sum << endl;
    }
    return sum;
}

int main() {
    double a[3][3] = {{2, 0, 1}, {3, 4, 0}, {0, 5, 6}};
    double b[3][3] = {{1, 2, 0}, {0, 3, 4}, {7, 0, 5}};
    Matrix2D A, B;
    A.Initialize();
    B.Initialize();
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c) {
            A.SetElement(r, c, a[r][c]);
            B.SetElement(r, c, b[r][c]);
        }
    A.SetElement(3, 0, 9.0);
    cout << fixed << setprecision(1);
    cout << "Matrix A:" << endl; A.Display();
    cout << "Matrix B:" << endl; B.Display();
    cout << "A.GetElement(1, 1) = " << A.GetElement(1, 1) << endl;
    double result = ComputeCrossTrace(A, B);
    cout << "Cross-trace (diagonal dot product) = " << result << endl;
    return 0;
}
