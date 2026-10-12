#include <iostream>
#include <memory>
#include <string>
using namespace std;


class Shape {
public:
    virtual unique_ptr<Shape> clone() const = 0;
    virtual void draw() const = 0;

    virtual ~Shape() = default;
};


class Circle : public Shape {
private:
    string color;
    int radius;

public:
    Circle(string c, int r)
        : color(c), radius(r) {}

    unique_ptr<Shape> clone() const override {
        return make_unique<Circle>(*this);
    }

    void draw() const override {
        cout << "Color: " << color
             << ", Radius: " << radius << endl;
    }
};


int main() {
    Circle original("Red", 10);

    unique_ptr<Shape> copy1 = original.clone();
    unique_ptr<Shape> copy2 = original.clone();

    original.draw();
    copy1->draw();
    copy2->draw();

    return 0;
}