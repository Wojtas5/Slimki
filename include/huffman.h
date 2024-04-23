#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <vector>
#include <queue>
#include <unordered_map>
#include "huffman_tree.h"

struct LessFrequency
{
    bool operator()(const std::shared_ptr<HuffmanTreeNode>& a,
                    const std::shared_ptr<HuffmanTreeNode>& b) const
    {
        return a->frequency > b->frequency;
    }
};

using HuffmanTreeNodePriorityQueue =
    std::priority_queue<std::shared_ptr<HuffmanTreeNode>,
        std::vector<std::shared_ptr<HuffmanTreeNode>>,
        LessFrequency>;

class Huffman
{
public:
    HuffmanTreeNodePriorityQueue CreateNodesQueue(
        const std::unordered_map<unsigned char, int>& value_frequency_map);
};

std::unordered_map<unsigned char, int> CountUniqueValueFrequencies(
    const std::vector<unsigned char>& values);

#endif // HUFFMAN_H