#include <gtest/gtest.h>
#include "huffman.h"

TEST(HuffmanTest, CountsFrequenciesOfAllUniqueValues)
{
    std::vector<unsigned char> test_values { 0, 1, 255, 1, 0 };
    std::unordered_map<unsigned char, int> output { { 0, 2 }, { 1, 2 }, { 255, 1 } };
    ASSERT_EQ(CountUniqueValueFrequencies(test_values), output);
}

TEST(HuffmanTest, ReturnEmptyMapOnEmptyInput)
{
    ASSERT_TRUE(CountUniqueValueFrequencies({}).empty());
}

bool AreNodesEqual(const HuffmanTreeNode& node1, const HuffmanTreeNode& node2)
{
    return ((node1.value == node2.value) && (node1.frequency == node2.frequency));
}

bool NodeQueuesEqual(HuffmanTreeNodePriorityQueue queue1,
    std::queue<std::shared_ptr<HuffmanTreeNode>> queue2)
{
    if (queue1.size() != queue2.size())
    {
        return false;
    }

    while (!queue1.empty() && !queue2.empty())
    {
        std::shared_ptr<HuffmanTreeNode> node1 = queue1.top();
        std::shared_ptr<HuffmanTreeNode> node2 = queue2.front();
        if (!AreNodesEqual(*node1, *node2))
        {
            return false;
        }

        queue1.pop();
        queue2.pop();
    }

    return true;
}

TEST(HuffmanTest, CreatesPriorityQueueOfNodesFromMapSortedBySmallestFrequency)
{
    Huffman huffman;
    std::unordered_map<unsigned char, int> value_frequency_map { { 0, 2 }, { 1, 2 }, { 255, 1 } };
    std::queue<std::shared_ptr<HuffmanTreeNode>> output_queue;

    output_queue.push(std::make_shared<HuffmanTreeNode>(HuffmanTreeNode { { 255, 1 } }));
    output_queue.push(std::make_shared<HuffmanTreeNode>(HuffmanTreeNode { { 1, 2 } }));
    output_queue.push(std::make_shared<HuffmanTreeNode>(HuffmanTreeNode { { 0, 2 } }));

    ASSERT_TRUE(NodeQueuesEqual(huffman.CreateNodesQueue(value_frequency_map), output_queue));
}
