#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class Machine {
public:
    virtual void print(const std::string& doc) const = 0;
    virtual void scan(const std::string& doc) const = 0;
    virtual void fax(const std::string& doc) const = 0;
    virtual ~Machine() = default;
};

class AllInOnePrinter : public Machine {
public:
    void print(const std::string& doc) const override {
        std::cout << "AllInOne: printing " << doc << "\n";
    }
    void scan(const std::string& doc) const override {
        std::cout << "AllInOne: scanning " << doc << "\n";
    }
    void fax(const std::string& doc) const override {
        std::cout << "AllInOne: faxing " << doc << "\n";
    }
};

class SimplePrinter : public Machine {
public:
    void print(const std::string& doc) const override {
        std::cout << "SimplePrinter: printing " << doc << "\n";
    }
    void scan(const std::string& doc) const override {
        throw std::runtime_error("SimplePrinter can't scan " + doc);
    }
    void fax(const std::string& doc) const override {
        throw std::runtime_error("SimplePrinter can't fax " + doc);
    }
};

void scanAll(const std::vector<const Machine*>& machines) {
    for (const Machine* m : machines)
        m->scan("passport.pdf");
}

int main() {
    AllInOnePrinter allInOne;
    SimplePrinter simple;

    std::vector<const Machine*> machines = {&allInOne, &simple};

    try {
        scanAll(machines);
    } catch (const std::exception& e) {
        std::cout << "wrong: " << e.what() << "\n";
    }
    return 0;
}
