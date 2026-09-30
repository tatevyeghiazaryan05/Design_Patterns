#include <iostream>
#include <string>

class MySQLDatabase {
public:
    void save(const std::string& data) const {
        std::cout << "[MySQL] saved: " << data << "\n";
    }
};

class UserService {
private:
    MySQLDatabase db;

public:
    void registerUser(const std::string& username) {
        if (username.empty()) {
            std::cout << "Error: username is empty\n";
            return;
        }
        db.save("user:" + username);
    }
};

int main() {
    UserService service;
    service.registerUser("Tatev");
    service.registerUser("");
    return 0;
}