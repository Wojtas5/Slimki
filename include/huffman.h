#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <vector>
#include <unordered_map>
#include "huffman_tree.h"

class Huffman
{
public:
    HuffmanTreeNodePriorityQueue CreateNodesQueue(
        const std::unordered_map<unsigned char, int>& value_frequency_map);
};

std::unordered_map<unsigned char, int> CountUniqueValueFrequencies(
    const std::vector<unsigned char>& values);

#endif // HUFFMAN_H