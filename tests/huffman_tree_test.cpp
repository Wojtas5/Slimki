#include <gtest/gtest.h>
#include "huffman_tree.h"

TEST(HuffmanTreeTest, ObjectCanBeCreatedOutOfMapEntry)
{
    std::unordered_map<unsigned char, int> value_frequency_map { { 0, 2 } };
    auto map_entry = *value_frequency_map.begin();
    HuffmanTreeNode node(map_entry);
    ASSERT_EQ(node.value, map_entry.first);
    ASSERT_EQ(node.frequency, map_entry.second);
    ASSERT_EQ(node.left, nullptr);
    ASSERT_EQ(node.right, nullptr);
}
