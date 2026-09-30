#include <iostream>
#include <string>
#include <vector>

class Printer {
public:
    virtual void print(const std::string& doc) const = 0;
    virtual ~Printer() = default;
};

class Scanner {
public:
    virtual void scan(const std::string& doc) const = 0;
    virtual ~Scanner() = default;
};

class Fax {
public:
    virtual void fax(const std::string& doc) const = 0;
    virtual ~Fax() = default;
};

class SimplePrinter : public Printer {
public:
    void print(const std::string& doc) const override {
        std::cout << "SimplePrinter: printing " << doc << "\n";
    }
};

class DocumentScanner : public Scanner {
public:
    void scan(const std::string& doc) const override {
        std::cout << "DocumentScanner: scanning " << doc << "\n";
    }
};

class AllInOnePrinter : public Printer, public Scanner, public Fax {
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

void printAll(const std::vector<const Printer*>& printers) {
    for (const Printer* p : printers)
        p->print("report.docx");
}

void scanAll(const std::vector<const Scanner*>& scanners) {
    for (const Scanner* s : scanners)
        s->scan("passport.pdf");
}

int main() {
    SimplePrinter simple;
    DocumentScanner scanner;
    AllInOnePrinter allInOne;

    printAll({&simple, &allInOne});
    std::cout << "---\n";

    scanAll({&scanner, &allInOne});
    std::cout << "---\n";

    allInOne.fax("contract.pdf");

    return 0;
}