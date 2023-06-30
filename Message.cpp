//
// Created by veren on 30.06.2023.
//

#include "Message.h"


class Message {
protected:
    enum MessageType {
        WARNING,
        ERROR,
        DEBUG,
        INFO
    };
    Message(std::string _message, time_t _datetime, MessageType _type) {
        message = std::move(_message);
        datetime = _datetime;
        type = _type;
    }
    Message(std::string _message, MessageType _type) :
            Message(std::move(_message), time(nullptr), _type){};
    [[nodiscard]] std::string convertType() const {
        switch(type) {
            case WARNING:
                return "WARNING";
            case ERROR:
                return "ERROR";
            case DEBUG:
                return "DEBUG";
            case INFO:
                return "INFO";
            default:
                return "GENERAL";
        }
    }
private:
    time_t datetime;
    std::string message;
    MessageType type;
public:

    explicit Message(std::string _message) :
            Message(std::move(_message), time(nullptr), MessageType::INFO){};

    [[nodiscard]] std::string format() const {
        std::string dt = ctime(&datetime);
        std::stringstream ss;
        ss << dt;
        std::string date = ss.str();
        date.pop_back();

        return "[" + date + "] [" + convertType() + "] " + this->message;
    }
};
class ErrorMessage : public Message {
public:
    explicit ErrorMessage(std::string message) :
            Message(std::move(message), MessageType::ERROR) {}
};
class WarningMessage : public Message {
public:
    explicit WarningMessage(std::string message) :
            Message(std::move(message), MessageType::WARNING) {}
};
class DebugMessage : public Message {
public:
    explicit DebugMessage(std::string message) :
            Message(std::move(message), MessageType::DEBUG) {}
};