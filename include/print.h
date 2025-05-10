#ifndef PRINT_H
#define PRINT_H

#include <string>
#include <vector>

// define terminal colors
constexpr std::string_view color_cyan = "\033[36m";
constexpr std::string_view color_purple = "\033[35;1m";
constexpr std::string_view color_end = "\033[0m";
constexpr std::string_view color_yellow = "\033[33m";
constexpr std::string_view color_green = "\033[32m";


class print
{
private:
    std::vector<std::vector<int>> board;
    [[nodiscard]] std::string tile_top(bool highlight) const;
    [[nodiscard]] std::string tile_middle(int val) const;

public:
    void set_board(std::vector<int> temp);
    void get_board() const;
    void print_head() const;
    void game_over() const;
    void print_score(int score) const;
    ~print();
};
#endif // PRINT_H