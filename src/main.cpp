#include <iostream>
#include <memory>
#include <thread>

#ifdef _WIN32
#include "KeyboardListenerWindows.h"
#else
#include "KeyboardListenerUnix.h"
#endif
#include "KeyLogger.h"

int main() {
    // Inicializace listeneru podle platformy
#ifdef _WIN32
    auto keyboardListener = std::make_unique<KeyboardListenerWindows>();
#else
    auto keyboardListener = std::make_unique<KeyboardListenerUnix>();
#endif

    // Inicializace KeyLogger
    KeyLogger keyLogger(std::move(keyboardListener));

    // Spuštění KeyLoggeru v samostatném vlákně
    std::thread keyLoggerThread([&keyLogger]() {
        keyLogger.start();
    });

    // Po určité době (např. 10 sekund) zastavit KeyLogger
    std::this_thread::sleep_for(std::chrono::seconds(10));
    keyLogger.stop();

    // Čekání na dokončení vlákna
    keyLoggerThread.join();

    return 0;
}
