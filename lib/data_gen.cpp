#include "../include/data_gen.h"
#include <random>
#include <algorithm>

std::vector<int> game_data()
{
    std::vector<int> values(16);

    std::iota(values.begin(), values.end(), 0);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(values.begin(), values.end(), g);

    return values;
}