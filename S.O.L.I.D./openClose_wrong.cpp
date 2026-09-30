#include <iostream>
#include <string>

class DiscountCalculator {
public:
    double calculate(double price, const std::string& customerType) const {
        if (customerType == "regular")
            return price;
        else if (customerType == "student")
            return price * 0.8;
        else if (customerType == "vip")
            return price * 0.7;
        else
            return price;
    }
};

int main() {
    DiscountCalculator calc;
    std::cout << calc.calculate(1000, "regular") << "\n";
    std::cout << calc.calculate(1000, "student") << "\n";
    std::cout << calc.calculate(1000, "vip") << "\n";
    return 0;
}
