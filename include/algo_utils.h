#ifndef ALGO_UTILS_H
#define ALGO_UTILS_H

#include <unordered_map>

namespace algo_utils
{

std::unordered_map<unsigned char, int> CountUniqueValueFrequencies(
    const std::vector<unsigned char>& values);

}

#endif // ALGO_UTILS_H