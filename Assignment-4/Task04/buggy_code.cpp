#include <iostream>

class WindowBox {
private:
    int width;
    int height;

public:
    WindowBox() : width(0), height(0) {}

    // Line 11: Returns pointer 'WindowBox*' instead of reference 'WindowBox&'
    WindowBox* setWidth(int width) {
        this->width = width;
        return this; // Returns pointer!
    }

    // Line 18: Returns reference 'WindowBox&'
    WindowBox& setHeight(int height) {
        this->height = height;
        return *this;
    }

    void display() const {
        std::cout << "Window: " << width << " x " << height << std::endl;
    }
};

int main() {
    WindowBox box;

    // Line 30: Chaining fails compilation
    box.setWidth(800).setHeight(600);

    box.display();
    return 0;
}
