#include "huffman.h"

std::unordered_map<unsigned char, int> CountUniqueValueFrequencies(
    const std::vector<unsigned char>& values)
{
    std::unordered_map<unsigned char, int> value_frequency_map;
    for (auto value : values)
    {
        ++value_frequency_map[value];
    }
    return value_frequency_map;
}
