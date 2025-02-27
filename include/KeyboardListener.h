#pragma once

class KeyboardListener {
    public:
        virtual ~KeyboardListener() = default;
        virtual char getKeyPress() = 0;
    };