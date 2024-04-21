#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <vector>
#include <unordered_map>

std::unordered_map<unsigned char, int> CountUniqueValueFrequencies(
    const std::vector<unsigned char>& values);

#endif // HUFFMAN_H