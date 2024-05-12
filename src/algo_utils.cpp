#include "algo_utils.h"

namespace algo_utils
{

std::unordered_map<unsigned char, unsigned int> CountUniqueValueFrequencies(
    const std::vector<unsigned char>& values)
{
    std::unordered_map<unsigned char, unsigned int> value_frequency_map;
    for (auto value : values)
    {
        ++value_frequency_map[value];
    }
    return value_frequency_map;
}

}
