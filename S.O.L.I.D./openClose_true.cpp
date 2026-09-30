#include <iostream>

class Discount {
public:
    virtual double apply(double price) const = 0;   
    virtual ~Discount() = default;
};

class NoDiscount : public Discount {
public:
    double apply(double price) const override {
        return price;
    }
};

class StudentDiscount : public Discount {
public:
    double apply(double price) const override {
        return price * 0.8;
    }
};

class VipDiscount : public Discount {
public:
    double apply(double price) const override {
        return price * 0.7;
    }
};

//New Discount without changing code in the begenning
class PensionerDiscount : public Discount {
public:
    double apply(double price) const override {
        return price * 0.5;
    }
};


class DiscountCalculator {
public:
    double calculate(double price, const Discount& discount) const {
        return discount.apply(price);
    }
};

int main() {
    DiscountCalculator calc;

    NoDiscount noDiscount;
    StudentDiscount student;
    VipDiscount vip;
    PensionerDiscount pensioner;

    std::cout << calc.calculate(1000, noDiscount) << "\n";
    std::cout << calc.calculate(1000, student) << "\n";
    std::cout << calc.calculate(1000, vip) << "\n";
    std::cout << calc.calculate(1000, pensioner) << "\n";
    return 0;
}
