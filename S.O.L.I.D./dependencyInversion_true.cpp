#include <iostream>
#include <string>
#include <vector>

class Database {
public:
    virtual void save(const std::string& data) = 0;
    virtual ~Database() = default;
};

class MySQLDatabase : public Database {
public:
    void save(const std::string& data) override {
        std::cout << "[MySQL] saved: " << data << "\n";
    }
};

class PostgresDatabase : public Database {
public:
    void save(const std::string& data) override {
        std::cout << "[Postgres] saved: " << data << "\n";
    }
};

class FakeDatabase : public Database {
private:
    std::vector<std::string> records;

public:
    void save(const std::string& data) override {
        records.push_back(data);
    }

    int count() const {
        return records.size();
    }
};

class UserService {
private:
    Database& db;   

public:
    UserService(Database& db) : db(db) {}   

    void registerUser(const std::string& username) {
        if (username.empty()) {
            std::cout << "Error: username is empty\n";
            return;
        }
        db.save("user:" + username);
    }
};

int main() {
    MySQLDatabase mysql;
    PostgresDatabase postgres;
    FakeDatabase fake;

    UserService service1(mysql);
    service1.registerUser("Tatev");

    UserService service2(postgres);
    service2.registerUser("Arthur");

    UserService testService(fake);
    testService.registerUser("test1");
    testService.registerUser("test2");
    testService.registerUser("");
    std::cout << "Fake DB records: " << fake.count() << "\n";

    return 0;
}