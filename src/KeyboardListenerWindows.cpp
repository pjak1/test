#ifdef _WIN32
#include "KeyboardListenerWindows.h"

char KeyboardListenerWindows::getKeyPress() {
    for (int key = 8; key <= 255; key++) {
        if (GetAsyncKeyState(key) & 0x0001) {
            return static_cast<char>(key);
        }
    }
    return '\0';
}
#endif