#include "huffman_tree.h"

HuffmanTree::HuffmanTree(const std::unordered_map<unsigned char, unsigned int>& value_frequency_map)
    : m_root(nullptr)
{
    NodePriorityQueue nodes_queue = CreateNodesQueue(value_frequency_map);

    while (nodes_queue.size() > 1)
    {
        auto left_child = nodes_queue.top();
        nodes_queue.pop();
        auto right_child = nodes_queue.top();
        nodes_queue.pop();

        auto internal_node = std::make_shared<HuffmanTreeNode>(
            HuffmanTreeNode({ 0, left_child->frequency + right_child->frequency }));
        internal_node->left = left_child;
        internal_node->right = right_child;
        nodes_queue.push(internal_node);

        m_root = internal_node;
    }
}

HuffmanTree::NodePriorityQueue HuffmanTree::CreateNodesQueue(
    const std::unordered_map<unsigned char, unsigned int>& value_frequency_map) const
{
    NodePriorityQueue nodes_priority_queue;
    for (auto entry : value_frequency_map)
    {
        nodes_priority_queue.push(std::make_shared<HuffmanTreeNode>(entry));
    }
    return nodes_priority_queue;
}
