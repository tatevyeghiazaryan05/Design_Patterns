#include <iostream>
using namespace std;

class ATMHandler {
    private:
        int denomination;
        ATMHandler* next;

    public:
    ATMHandler(int value) {
    denomination = value;
    next = nullptr;
    }

    ATMHandler* setNext(ATMHandler* handler) {
        next = handler;
        return handler;
    }

    ATMHandler* getNext() {
        return next;
    }

    void withdraw(int amount) {
        int count = amount / denomination;
        int remaining = amount % denomination;

        if (count > 0) {
            cout << count << " x "
                 << denomination << " AMD\n";
        }

        if (remaining > 0 && next != nullptr) {
            next->withdraw(remaining);
        }
        else if (remaining > 0) {
            cout << "Cannot dispense remaining "
                 << remaining << " AMD\n";
        }
    }
};

int main() {
ATMHandler* head = new ATMHandler(50000);
ATMHandler* second = new ATMHandler(20000);
ATMHandler* third = new ATMHandler(10000);
ATMHandler* fourth = new ATMHandler(5000);

head->setNext(second)->setNext(third)->setNext(fourth);

int amount = 85002;

head->withdraw(amount);

delete fourth;
delete third;
delete second;
delete head;

return 0;
}