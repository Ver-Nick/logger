#include <iostream>

#include "Logger.cpp"

int main() {
    Logger logger("output.txt");
    logger << Message("File Info Message");
    logger << DebugMessage("File Debug Message");
    logger << WarningMessage("File Warning Message");
    logger << ErrorMessage("File Error Message");
    logger.close();

    Logger logger2;
    logger2 << Message("Console Info Message");
    logger2 << DebugMessage("Console Debug Message");
    logger2 << WarningMessage("Console Warning Message");
    logger2 << ErrorMessage("Console Error Message");
}