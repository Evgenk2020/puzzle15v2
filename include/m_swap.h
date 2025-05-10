#ifndef M_SWAP_H
#define M_SWAP_H

#include <vector>
#include <string>

class game
{
private:
    std::vector<int> values;
    int score;

public:
    game(std::vector<int> temp);
    void swapping(std::string key);
    bool is_solved();
    std::vector<int> get_board();
    int get_score();
    ~game();
};

#endif // M_SWAP_H