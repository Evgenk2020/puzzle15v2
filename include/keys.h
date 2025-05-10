#ifndef KEYS_H
#define KEYS_H

#include <termios.h>
#include <array>
#include <map>
#include <string>

class keyboard_mode
{
private:
    struct termios oldt, newt;
    int flags;
    std::array<int, 4> key_code;

public:
    keyboard_mode();
    void take_symbol();
    std::array<int, 4> get_symbol();
    ~keyboard_mode();
};

class keyboard_set
{
private:
    std::map<std::array<int, 4>, std::string> keyboard;
    std::string keyboard_manage_key;
    keyboard_mode *kmode;

public:
    keyboard_set();
    std::string get_keyboard_manage_key();
    ~keyboard_set();
};

#endif // KEYS_H
