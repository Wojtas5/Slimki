#ifndef UTILS_H
#define UTILS_H

#include "huffman_tree.h"

bool AreNodesEqual(const HuffmanTreeNode& node1, const HuffmanTreeNode& node2);
bool TreesEqual(const std::shared_ptr<HuffmanTreeNode> first_tree,
                const std::shared_ptr<HuffmanTreeNode> second_tree);

#endif // UTILS_H