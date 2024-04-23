#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <queue>
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

class HuffmanTree
{
public:
    HuffmanTree();
    HuffmanTree(HuffmanTreeNodePriorityQueue nodes_queue);

    std::shared_ptr<HuffmanTreeNode> GetRoot() { return m_root; }

private:
    std::shared_ptr<HuffmanTreeNode> m_root;
};

#endif // HUFFMAN_TREE_H