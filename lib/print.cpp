#include "../include/print.h"
#include <iostream>

[[nodiscard]] std::string print::tile_top(bool highlight) const { return std::string(highlight ? color_purple : color_cyan) + "████████" + std::string(color_end); }

[[nodiscard]] std::string print::tile_middle(int val) const
{
    std::string value_;
    bool is_empty = (val == 0);

    if (is_empty)
    {
        value_ = "  ";
    }

    else
    {
        value_ = std::to_string(val);
    }

    if (value_.length() == 1)
    {
        value_ = " " + value_;
    }

    std::string color = is_empty ? std::string(color_purple) : std::string(color_cyan);

    return color + "██ " + value_ + " ██" + std::string(color_end);
}

void print::set_board(std::vector<int> temp)
{
    board.resize(4, std::vector<int>(4));

    for (int i = 0; i < 16; ++i)
    {
        board[i / 4][i % 4] = temp[i];
    }
}

void print::get_board() const
{
    for (const auto &row : board)
    {
        // top printing
        for (const auto &val : row)
        {
            std::cout << tile_top(val == 0) << " ";
        }

        std::cout << std::endl;

        // middle printing
        for (const auto &val : row)
        {
            std::cout << tile_middle(val) << " ";
        }

        std::cout << std::endl;

        // bottom printing
        for (const auto &val : row)
        {
            std::cout << tile_top(val == 0) << " ";
        }

        std::cout << std::endl
                  << std::endl;
    }
}

void print::print_head() const
{
    std::cout << std::string(80, '=') << std::endl;
    std::cout << color_yellow << "<ESC>" << color_end << " exit | " << color_yellow << "<F1>" << color_end << " restart | "
              << color_yellow << "<up>" << color_end << " | " << color_yellow << "<down>" << color_end << " | "
              << color_yellow << "<left>" << color_end << " | " << color_yellow << "<right>" << color_end << std::endl;
    std::cout << std::string(80, '=') << std::endl;
}

void print::print_score(int score) const
{
    std::cout << std::string(80, '=') << std::endl;
    std::cout << "total score: " << color_green << score << color_end << std::endl;
    std::cout << std::string(80, '=') << std::endl;
}

void print::game_over() const
{
    std::cout << std::string(80, '=') << std::endl;
    std::cout << color_purple << "game over" << color_end << std::endl;
    std::cout << std::string(80, '=') << std::endl;
}

print::~print() {}