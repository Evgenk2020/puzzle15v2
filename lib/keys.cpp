#include "../include/keys.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

//---------------------------------------------------------------------------------------------------

keyboard_mode::keyboard_mode() { flags = fcntl(0, F_GETFL, 0); }
keyboard_mode::~keyboard_mode() {}

void keyboard_mode::take_symbol()
{
    key_code = {0, 0, 0, 0};

    for (int i = 0; i < 4; i++)
    {
        // set keypress
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        // get symbols step by step
        key_code[i] = getchar();

        // reset keypress
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

        // set unblock input for the rest of codes [0...4]
        if (i == 0)
        {
            fcntl(0, F_SETFL, flags | O_NONBLOCK);
        }
    }

    // reset unblock
    fcntl(0, F_SETFL, flags & ~O_NONBLOCK);
}

std::array<int, 4> keyboard_mode::get_symbol() { return key_code; }

//---------------------------------------------------------------------------------------------------

keyboard_set::keyboard_set()
{
    keyboard = {
        {{27, 91, 65, -1}, "up"},
        {{27, 91, 66, -1}, "down"},
        {{27, 91, 67, -1}, "right"},
        {{27, 91, 68, -1}, "left"},
        {{27, -1, -1, -1}, "esc"},
        {{27, 79, 80, -1}, "F1"},
    };
}

std::string keyboard_set::get_keyboard_manage_key()
{
    kmode = new keyboard_mode();
    kmode->take_symbol();

    auto _find = [](const std::map<std::array<int, 4>, std::string> &_mm, std::array<int, 4> key)
    {
        if (auto it = _mm.find(key); it != _mm.end())
        {
            return it->second;
        }

        else
        {
            return (std::string) "error";
        }
    };

    keyboard_manage_key = _find(keyboard, kmode->get_symbol());

    delete kmode;
    kmode = nullptr;

    return keyboard_manage_key;
}

keyboard_set::~keyboard_set() {}