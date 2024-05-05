#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <queue>
#include <unordered_map>
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

    bool IsLeaf() { return left == nullptr && right == nullptr; }
};

class HuffmanTree
{
public:
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

    HuffmanTree(const std::unordered_map<unsigned char, int>& value_frequency_map);
    std::shared_ptr<HuffmanTreeNode> GetRoot() const { return m_root; }

private:
    std::shared_ptr<HuffmanTreeNode> m_root;

    NodePriorityQueue CreateNodesQueue(
        const std::unordered_map<unsigned char, int>& value_frequency_map);
};

#endif // HUFFMAN_TREE_H