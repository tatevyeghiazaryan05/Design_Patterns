#include <iostream>
#include <string>
using namespace std;

class Computer {
public:
    string cpu;
    int ram;
    int storage;

    Computer(string c, int r, int s)
        : cpu(c), ram(r), storage(s) {}

    void show() {
        cout << "CPU: " << cpu << endl;
        cout << "RAM: " << ram << " GB" << endl;
        cout << "Storage: " << storage << " GB" << endl;
    }
};

class ComputerBuilder {
private:
    string cpu = "Unknown";
    int ram = 8;
    int storage = 256;

public:
    ComputerBuilder& setCPU(string c) {
        cpu = c;
        return *this;
    }

    ComputerBuilder& setRAM(int r) {
        ram = r;
        return *this;
    }

    ComputerBuilder& setStorage(int s) {
        storage = s;
        return *this;
    }

    Computer build() {
        return Computer(cpu, ram, storage);
    }
};

int main() {
    Computer computer = ComputerBuilder()
        .setCPU("Intel")
        .setRAM(32)
        .setStorage(1000)
        .build();

    computer.show();

    return 0;
}