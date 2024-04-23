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

TEST(HuffmanTreeTest, RootIsNullOnEmptyQueue)
{
    HuffmanTreeNodePriorityQueue empty_queue;
    HuffmanTree huffman_tree(empty_queue);

    ASSERT_EQ(huffman_tree.GetRoot(), nullptr);
}

TEST(HuffmanTreeTest, ReturnsNotNullIfQueueIsNotEmpty)
{
    HuffmanTreeNodePriorityQueue nodes_queue;
    nodes_queue.push(std::make_shared<HuffmanTreeNode>(HuffmanTreeNode { { 0, 0 } }));
    HuffmanTree huffman_tree(nodes_queue);

    ASSERT_NE(huffman_tree.GetRoot(), nullptr);
}

TEST(HuffmanTreeTest, CreatesHuffmanTree)
{
    HuffmanTreeNodePriorityQueue nodes_queue;
    std::shared_ptr<HuffmanTreeNode> node1 =
        std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 255, 1 }));
    std::shared_ptr<HuffmanTreeNode> node2 =
        std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 0, 2 }));
    nodes_queue.push(node1);
    nodes_queue.push(node2);

    HuffmanTree huffman_tree(nodes_queue);

    std::shared_ptr<HuffmanTreeNode> output_tree_root =
        std::make_shared<HuffmanTreeNode>(HuffmanTreeNode { { 0, 3 } });
    output_tree_root->left = node1;
    output_tree_root->right = node2;

    ASSERT_TRUE(TreesEqual(huffman_tree.GetRoot(), output_tree_root));
}

TEST(HuffmanTreeTest, CreatesBigHuffmanTree)
{
    HuffmanTreeNodePriorityQueue nodes_queue;
    std::shared_ptr<HuffmanTreeNode> node1 =
        std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 'a', 5 }));
    std::shared_ptr<HuffmanTreeNode> node2 =
        std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 'b', 9 }));
    std::shared_ptr<HuffmanTreeNode> node3 =
        std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 'c', 12 }));
    std::shared_ptr<HuffmanTreeNode> node4 =
        std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 'd', 13 }));
    std::shared_ptr<HuffmanTreeNode> node5 =
        std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 'e', 16 }));
    nodes_queue.push(node1);
    nodes_queue.push(node2);
    nodes_queue.push(node3);
    nodes_queue.push(node4);
    nodes_queue.push(node5);

    HuffmanTree huffman_tree(nodes_queue);

    std::shared_ptr<HuffmanTreeNode> output_tree_root =
        std::make_shared<HuffmanTreeNode>(HuffmanTreeNode { { 0, 55 } });
    output_tree_root->left = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 0, 25 }));
    output_tree_root->left->left = node3;
    output_tree_root->left->right = node4;

    output_tree_root->right = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 0, 30 }));
    output_tree_root->right->left = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 0, 14 }));
    output_tree_root->right->left->left = node1;
    output_tree_root->right->left->right = node2;
    output_tree_root->right->right = node5;

    ASSERT_TRUE(TreesEqual(huffman_tree.GetRoot(), output_tree_root));
}
