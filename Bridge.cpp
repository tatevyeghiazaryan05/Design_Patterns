#include <iostream>
#include <memory>
#include <string>

//Implementor
class Color {
public:
    virtual std::string fill() const = 0;
    virtual ~Color() = default;
};

//Concrete Implementors
class RedColor : public Color {
public:
    std::string fill() const override {
        return "Red";
    }
};

class BlueColor : public Color {
public:
    std::string fill() const override {
        return "Blue";
    }
};

//Abstraction 
class Shape {
protected:
    std::unique_ptr<Color> m_color;

public:
    explicit Shape(std::unique_ptr<Color> color) : m_color(std::move(color)) {}
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

//Refined Abstractions
class Circle : public Shape {
public:
    explicit Circle(std::unique_ptr<Color> color) : Shape(std::move(color)) {}

    void draw() const override {
        std::cout << "Drawing Circle filled with " << m_color->fill() << " color.\n";
    }
};

class Square : public Shape {
public:
    explicit Square(std::unique_ptr<Color> color) : Shape(std::move(color)) {}

    void draw() const override {
        std::cout << "Drawing Square filled with " << m_color->fill() << " color.\n";
    }
};


int main() {
    Shape* redCircle = new Circle(std::make_unique<RedColor>());
    redCircle->draw();

    Shape* blueSquare = new Square(std::make_unique<BlueColor>());
    blueSquare->draw();

    delete redCircle;
    delete blueSquare;
}