#include "../include/m_swap.h"
#include <algorithm>
#include <unordered_map>
#include <functional>

game::game(std::vector<int> temp) : values(temp) { score = 0; }

bool game::is_solved()
{
    return std::equal(values.begin(), values.end() - 2, std::next(values.begin()), [](int a, int b) -> bool
                      { return (a + 1 == b); }) &&
           values.back() == 0;
}

std::vector<int> game::get_board() { return values; }
int game::get_score() { return score; }
game::~game() {}

void game::swapping(std::string key)
{
    auto fish = std::find(values.begin(), values.end(), 0);
    int index = std::distance(values.begin(), fish);

    std::vector<int> before = values;

    auto move_up = [this, index]() -> void
    {
        if (index >= 4)
        {
            std::swap(values[index], values[index - 4]);
        }
    };

    auto move_down = [this, index]() -> void
    {
        if (index < 12)
        {
            std::swap(values[index], values[index + 4]);
        }
    };

    auto move_left = [this, index]() -> void
    {
        if (index % 4 != 0)
        {
            std::swap(values[index], values[index - 1]);
        }
    };

    auto move_right = [this, index]() -> void
    {
        if (index % 4 != 3)
        {
            std::swap(values[index], values[index + 1]);
        }
    };

    std::unordered_map<std::string, std::function<void()>> actions = {
        {"up", move_up},
        {"down", move_down},
        {"left", move_left},
        {"right", move_right}};

    if (auto a = actions.find(key); a != actions.end())
    {
        a->second();

        if (values != before)
        {
            score++;
        }
    }
}