#include <iostream>

class WindowBox {
private:
    int width;
    int height;

public:
    WindowBox() : width(0), height(0) {}

    // Returns a reference to the current object for chaining
    WindowBox& setWidth(int width) {
        this->width = width;    // this-> resolves parameter shadowing
        return *this;
    }

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
    box.setWidth(800).setHeight(600);
    box.display();

    box.setHeight(720).setWidth(1280).display();
    return 0;
}
