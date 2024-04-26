#include <gtest/gtest.h>
#include "huffman_tree_utils.h"

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

TEST(HuffmanTreeTest, RootIsNullOnEmptyMap)
{
    std::unordered_map<unsigned char, int> empty_map;
    HuffmanTree huffman_tree(empty_map);

    ASSERT_EQ(huffman_tree.GetRoot(), nullptr);
}

TEST(HuffmanTreeTest, ReturnsNotNullIfMapIsNotEmpty)
{
    std::unordered_map<unsigned char, int> value_frequency_map { { 0, 0 } };
    HuffmanTree huffman_tree(value_frequency_map);

    ASSERT_NE(huffman_tree.GetRoot(), nullptr);
}

TEST(HuffmanTreeTest, CreatesHuffmanTree)
{
    std::unordered_map<unsigned char, int> value_frequency_map { {255, 1}, {0, 2} };
    int value1_frequency = value_frequency_map[0];
    int value2_frequency = value_frequency_map[255];

    HuffmanTree huffman_tree(value_frequency_map);

    ASSERT_EQ(huffman_tree.GetRoot()->frequency, value1_frequency + value2_frequency);
    ASSERT_EQ(huffman_tree.GetRoot()->left->frequency, value2_frequency);
    ASSERT_EQ(huffman_tree.GetRoot()->right->frequency, value1_frequency);
}

TEST(HuffmanTreeTest, CreatesBigHuffmanTree)
{
    auto value_frequency_pair1 = std::make_pair<unsigned char, int>('a', 5);
    auto value_frequency_pair2 = std::make_pair<unsigned char, int>('b', 9);
    auto value_frequency_pair3 = std::make_pair<unsigned char, int>('c', 12);
    auto value_frequency_pair4 = std::make_pair<unsigned char, int>('d', 13);
    auto value_frequency_pair5 = std::make_pair<unsigned char, int>('e', 16);
    std::unordered_map<unsigned char, int> value_frequency_map {
        value_frequency_pair1,
        value_frequency_pair2,
        value_frequency_pair3,
        value_frequency_pair4,
        value_frequency_pair5
    };

    HuffmanTree huffman_tree(value_frequency_map);

    std::shared_ptr<HuffmanTreeNode> output_tree_root =
        std::make_shared<HuffmanTreeNode>(HuffmanTreeNode { { 0, 55 } });
    output_tree_root->left = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 0, 25 }));
    output_tree_root->left->left = std::make_shared<HuffmanTreeNode>(value_frequency_pair3);
    output_tree_root->left->right = std::make_shared<HuffmanTreeNode>(value_frequency_pair4);

    output_tree_root->right = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 0, 30 }));
    output_tree_root->right->left = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 0, 14 }));
    output_tree_root->right->left->left = std::make_shared<HuffmanTreeNode>(value_frequency_pair1);
    output_tree_root->right->left->right = std::make_shared<HuffmanTreeNode>(value_frequency_pair2);
    output_tree_root->right->right = std::make_shared<HuffmanTreeNode>(value_frequency_pair5);

    ASSERT_TRUE(TreesEqual(huffman_tree.GetRoot(), output_tree_root));
}
