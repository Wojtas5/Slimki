#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <queue>
#include <unordered_map>
#include <memory>

struct HuffmanTreeNode
{
    unsigned char value;
    unsigned int frequency;
    std::shared_ptr<HuffmanTreeNode> left;
    std::shared_ptr<HuffmanTreeNode> right;

    HuffmanTreeNode(std::pair<unsigned char, unsigned int> value_freq_pair)
        : value(value_freq_pair.first), frequency(value_freq_pair.second),
          left(nullptr), right(nullptr)
    {}

    bool IsLeaf() const { return left == nullptr && right == nullptr; }
};

class HuffmanTree
{
public:
    HuffmanTree(const std::unordered_map<unsigned char, unsigned int>& value_frequency_map);
    std::shared_ptr<HuffmanTreeNode> GetRoot() const { return m_root; }

private:
    struct LessFrequency
    {
        bool operator()(const std::shared_ptr<HuffmanTreeNode>& node1,
                        const std::shared_ptr<HuffmanTreeNode>& node2) const
        {
            return node1->frequency > node2->frequency;
        }
    };

    using NodePriorityQueue =
        std::priority_queue<std::shared_ptr<HuffmanTreeNode>,
                            std::vector<std::shared_ptr<HuffmanTreeNode>>,
                            LessFrequency>;

    std::shared_ptr<HuffmanTreeNode> m_root;

    NodePriorityQueue CreateNodesQueue(
        const std::unordered_map<unsigned char, unsigned int>& value_frequency_map) const;
};

#endif // HUFFMAN_TREE_H