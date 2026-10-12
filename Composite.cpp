#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Component {
public:
    virtual int getSize() const = 0;
    virtual void show() const = 0;

    virtual ~Component() = default;
};


class File : public Component {
private:
    string name;
    int size;

public:
    File(string n, int s)
        : name(n), size(s) {}

    int getSize() const override {
        return size;
    }

    void show() const override {
        cout << "File: " << name
             << ", Size: " << size << " KB" << endl;
    }
};


class Folder : public Component {
private:
    string name;
    vector<unique_ptr<Component>> children;

public:
    Folder(string n) : name(n) {}

    void add(unique_ptr<Component> component) {
        children.push_back(move(component));
    }

    int getSize() const override {
        int total = 0;

        for (const auto& child : children) {
            total += child->getSize();
        }

        return total;
    }

    void show() const override {
        cout << "Folder: " << name
             << ", Total size: "
             << getSize() << " KB" << endl;

        for (const auto& child : children) {
            child->show();
        }
    }
};


int main() {
    auto documents = make_unique<Folder>("Documents");

    documents->add(make_unique<File>("report.pdf", 100));
    documents->add(make_unique<File>("notes.txt", 50));

    auto university = make_unique<Folder>("University");

    university->add(make_unique<File>("diploma.pdf", 200));
    university->add(make_unique<File>("algorithms.pdf", 150));

    documents->add(move(university));

    documents->show();

    cout << "Documents total: "
         << documents->getSize() << " KB" << endl;

    return 0;
}