#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <vector>
#include <unordered_map>
#include "huffman_tree.h"

class Huffman
{

};

std::unordered_map<unsigned char, int> CountUniqueValueFrequencies(
    const std::vector<unsigned char>& values);

#endif // HUFFMAN_H