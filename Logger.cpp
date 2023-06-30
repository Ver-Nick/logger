//
// Created by veren on 30.06.2023.
//

#include "Logger.h"

class Logger {
protected:
    std::ofstream file;
    bool outputFile;
public:
    Logger(const std::string& filename) {
        file.open(filename);
        outputFile = file.is_open();
    }

    Logger() {
        outputFile = false;
        file = nullptr;
    }

    ~Logger() {
        if (outputFile) {
            file.close();
        }
    }

    void close() {
        if (outputFile) {
            file.close();
            outputFile = false;
        }
    }

    Logger& operator<<(const Message& message) {
        if (outputFile) {
            file << message.format() << std::endl;
        }
        else {
            std::cout << message.format() << std::endl;
        }
        return *this;
    }
};