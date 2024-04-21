#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <utility>
#include <memory>

struct HuffmanTreeNode
{
    unsigned char value;
    int frequency;
    std::shared_ptr<HuffmanTreeNode> left;
    std::shared_ptr<HuffmanTreeNode> right;

    HuffmanTreeNode(std::pair<unsigned char, int> value_freq_pair)
        : value(value_freq_pair.first), frequency(value_freq_pair.second),
        left(nullptr), right(nullptr)
    {}
};

#endif // HUFFMAN_TREE_H