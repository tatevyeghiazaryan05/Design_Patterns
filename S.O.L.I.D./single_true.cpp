#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

class Student {
    private:
        std::string name;
        std::vector <int> grades;
    public:
        Student(const std::string& name, const std::vector<int>& grades)
            : name(name), grades(grades) {}
        const std::string& getName() const {return name; }
        double average() const {
            int sum = 0;
            for (int g : grades)
                sum += g;
            return static_cast<double>(sum) / grades.size();
        }
}

class ReportSaver{
    public:
        void save(const Student& student) const {
            std::string filename = student.getName() + "_report.txt";
            std::ofstream file(filename);
            file << student.getName() << ": " << std::fixed
                << std::setprecision(2) << student.average() << "\n";
            std::cout << "Saved in " << filename << "file\n"; 
        }
}

class MessageSender {
public:
    void send(const Student& student) const {
        std::cout << "Sended: " << student.getName() << "'s average"
                  << std::fixed << std::setprecision(2)
                  << "average is : " << student.average() << "\n";
    }
};

int main() {
    Student student("Tatev", {85, 90, 78});

    ReportSaver saver;
    MessageSender sender;

    saver.save(student);
    sender.send(student);
    return 0;
}