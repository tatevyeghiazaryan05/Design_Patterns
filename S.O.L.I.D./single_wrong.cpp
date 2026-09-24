#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

class StudentReport{
    private:
        std::string name;
        std::vector<int> grades;
    public:
        StudentReport(const std::string& name, const std::vector<int>& grades)
            : name(name), grades(grades) {}
        double calculateAverage() const {
            int sum = 0;
            for (int g : grades)
                sum += g;
            return static_cast<double>(sum) / grades.size();
        }
        void saveToFile() const {
            std:: ofstream file(name + "_report.txt");
            file << name << ": " << std::fixed << std::setprecision(2)
                << calculateAverage() << "\n";
        }
        void sendMessage() const {
            std::cout << "Sent: " << name << "'s average"
                    << std::fixed << std::setprecision(2)
                    << " here it is :" << calculateAverage() ;
        }
};

int main() {
    StudentReport report ("Tatev", {85, 90, 78});
    report.saveToFile();
    report.sendMessage();
    return 0;
}
