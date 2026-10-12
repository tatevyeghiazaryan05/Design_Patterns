#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle" << endl;
    }
};

class ShapeFactory {
public:
    static Shape* createShape(const string& type) {
        if (type == "circle") {
            return new Circle();
        }
        else if (type == "rectangle") {
            return new Rectangle();
        }

        return nullptr;
    }
};

int main() {
    Shape* shape = ShapeFactory::createShape("circle");

    if (shape != nullptr) {
        shape->draw();
        delete shape;
    }

    return 0;
}