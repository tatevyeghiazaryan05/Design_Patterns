#include <iostream>
#include <fstream>
#include <string>
#include <mutex>

class Logger {
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;

    void log(const std::string& msg) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_file << msg << std::endl;
    }

private:
    Logger() {
        m_file.open("app.log", std::ios::out | std::ios::app);
    }

    ~Logger() {
        if (m_file.is_open()) {
            m_file.close();
        }
    }

    std::ofstream m_file;
    std::mutex m_mutex;
};