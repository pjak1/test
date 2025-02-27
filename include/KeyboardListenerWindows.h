#pragma once


#include "KeyboardListener.h"
#include <windows.h>

class KeyboardListenerWindows : public KeyboardListener {
public:
    char getKeyPress() override;
};

