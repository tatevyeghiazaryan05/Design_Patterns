#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class Bird {
protected:
    std::string name;

public:
    Bird(const std::string& name) : name(name) {}
    virtual ~Bird() = default;

    virtual std::string fly() const {
        return name + " flying";
    }
};

class Eagle : public Bird {
public:
    Eagle(const std::string& name) : Bird(name) {}
};

class Penguin : public Bird {
public:
    Penguin(const std::string& name) : Bird(name) {}

    std::string fly() const override {
        throw std::runtime_error(name + " can't fly!");
    }
};

void makeBirdsFly(const std::vector<const Bird*>& birds) {
    for (const Bird* bird : birds)
        std::cout << bird->fly() << "\n";
}

int main() {
    Eagle eagle("eagle");
    Penguin penguin("penguin");

    std::vector<const Bird*> birds = {&eagle, &penguin};

    try {
        makeBirdsFly(birds);
    } catch (const std::exception& e) {
        std::cout << "wrong: " << e.what() << "\n";
    }
    return 0;
}
