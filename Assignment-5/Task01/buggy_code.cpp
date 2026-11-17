#include <iostream>

class Shape {
public:
    Shape() { std::cout << "Shape created." << std::endl; }

    // Line 7: Non-virtual destructor in base class!
    ~Shape() {
        std::cout << "Shape destroyed." << std::endl;
    }

    virtual void render() const {
        std::cout << "Rendering generic shape." << std::endl;
    }
};

class ComplexPolygon : public Shape {
private:
    double *vertexArray;
    int vertexCount;

public:
    ComplexPolygon(int count) : vertexCount(count) {
        vertexArray = new double[vertexCount * 2];
        std::cout << "Allocated " << vertexCount << " vertices on heap." << std::endl;
    }

    ~ComplexPolygon() {
        std::cout << "Deallocating polygon vertex heap memory." << std::endl;
        delete[] vertexArray; // Never executed!
    }

    void render() const override {
        std::cout << "Rendering polygon with " << vertexCount << " vertices." << std::endl;
    }
};

int main() {
    Shape *shapePtr = new ComplexPolygon(1000);
    shapePtr->render();

    // Line 41: Polymorphic deletion through base pointer
    delete shapePtr;

    return 0;
}
