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

HuffmanTreeNodePriorityQueue Huffman::CreateNodesQueue(
    const std::unordered_map<unsigned char, int>& value_frequency_map)
{
    HuffmanTreeNodePriorityQueue nodes_priority_queue;
    for (auto entry : value_frequency_map)
    {
        nodes_priority_queue.push(std::make_shared<HuffmanTreeNode>(entry));
    }
    return nodes_priority_queue;
}
