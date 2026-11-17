#include <iostream>

class Shape {
public:
    Shape() { std::cout << "Shape created." << std::endl; }

    // Virtual destructor: dispatched through the vtable
    virtual ~Shape() {
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

    ~ComplexPolygon() override {
        std::cout << "Deallocating polygon vertex heap memory." << std::endl;
        delete[] vertexArray;
    }

    void render() const override {
        std::cout << "Rendering polygon with " << vertexCount << " vertices." << std::endl;
    }
};

int main() {
    Shape *shapePtr = new ComplexPolygon(1000);
    shapePtr->render();

    delete shapePtr; // ~ComplexPolygon() runs first, then ~Shape()

    return 0;
}
