#include <iostream>
#include <string>
#include <vector>

class Bird {
protected:
    std::string name;

public:
    Bird(const std::string& name) : name(name) {}
    virtual ~Bird() = default;

    std::string eat() const {
        return name + "eating";
    }
};


class FlyingBird : public Bird {
public:
    FlyingBird(const std::string& name) : Bird(name) {}

    std::string fly() const {
        return name + "flying";
    }
};

class SwimmingBird : public Bird {
public:
    SwimmingBird(const std::string& name) : Bird(name) {}

    std::string swim() const {
        return name + "swimming";
    }
};

class Eagle : public FlyingBird {
public:
    Eagle(const std::string& name) : FlyingBird(name) {}
};

class Sparrow : public FlyingBird {
public:
    Sparrow(const std::string& name) : FlyingBird(name) {}
};

class Penguin : public SwimmingBird {
public:
    Penguin(const std::string& name) : SwimmingBird(name) {}
};

void makeBirdsFly(const std::vector<const FlyingBird*>& birds) {
    for (const FlyingBird* bird : birds)
        std::cout << bird->fly() << "\n";
}

void feedBirds(const std::vector<const Bird*>& birds) {
    for (const Bird* bird : birds)
        std::cout << bird->eat() << "\n";
}

int main() {
    Eagle eagle("eagle");
    Sparrow sparrow("sparrow");
    Penguin penguin("penguin");

    makeBirdsFly({&eagle, &sparrow});
    std::cout << "---\n";

    feedBirds({&eagle, &sparrow, &penguin});
    std::cout << "---\n";

    std::cout << penguin.swim() << "\n";

    return 0;
}
