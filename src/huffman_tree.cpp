#include "huffman_tree.h"

HuffmanTree::HuffmanTree() : m_root(nullptr)
{}

HuffmanTree::HuffmanTree(HuffmanTreeNodePriorityQueue nodes_queue)
    : m_root(nullptr)
{
    if (nodes_queue.size() == 1)
    {
        m_root = nodes_queue.top();
        nodes_queue.pop();
        return;
    }

    while (nodes_queue.size() > 1)
    {
        std::shared_ptr<HuffmanTreeNode> left_child = nodes_queue.top();
        nodes_queue.pop();
        std::shared_ptr<HuffmanTreeNode> right_child = nodes_queue.top();
        nodes_queue.pop();

        std::shared_ptr<HuffmanTreeNode> internal_node = std::make_shared<HuffmanTreeNode>(
            HuffmanTreeNode({ 0, left_child->frequency + right_child->frequency }));
        internal_node->left = left_child;
        internal_node->right = right_child;
        nodes_queue.push(internal_node);

        m_root = internal_node;
    }
}
