#include <gtest/gtest.h>
#include "huffman_tree_utils.h"

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

bool TreesEqual(const std::shared_ptr<HuffmanTreeNode> first_tree,
    const std::shared_ptr<HuffmanTreeNode> second_tree)
{
    if (first_tree == nullptr && second_tree == nullptr)
    {
        return true;
    }

    if ((first_tree == nullptr && second_tree != nullptr) ||
        (first_tree != nullptr && second_tree == nullptr))
    {
        return false;
    }

    if (!AreNodesEqual(*first_tree, *second_tree))
    {
        return false;
    }

    return TreesEqual(first_tree->left, second_tree->left) &&
        TreesEqual(first_tree->right, second_tree->right);
}

TEST(TreesEqualTest, ReturnsTrueWhenBothTreesAreNull)
{
    ASSERT_TRUE(TreesEqual(nullptr, nullptr));
}

TEST(TreesEqualTest, ReturnsTrueWhenTheSameNodeIsPassed)
{
    std::shared_ptr<HuffmanTreeNode> test_node =
        std::make_shared<HuffmanTreeNode>(HuffmanTreeNode { { 0, 0 } });
    ASSERT_TRUE(TreesEqual(test_node, test_node));
}

TEST(TreesEqualTest, ReturnsTrueWhenTheSameTreeIsPassed)
{
    std::shared_ptr<HuffmanTreeNode> test_root =
        std::make_shared<HuffmanTreeNode>(HuffmanTreeNode { { 0, 0 } });
    test_root->left = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 1, 1 }));
    test_root->right = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 255, 2 }));

    ASSERT_TRUE(TreesEqual(test_root, test_root));
}

TEST(TreesEqualTest, ReturnsTrueWhenTheTwoIdenticalTreesArePassed)
{
    std::shared_ptr<HuffmanTreeNode> test_root1 =
        std::make_shared<HuffmanTreeNode>(HuffmanTreeNode { { 0, 0 } });
    test_root1->left = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 1, 1 }));
    test_root1->right = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 255, 2 }));

    std::shared_ptr<HuffmanTreeNode> test_root2 =
        std::make_shared<HuffmanTreeNode>(HuffmanTreeNode { { 0, 0 } });
    test_root2->left = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 1, 1 }));
    test_root2->right = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 255, 2 }));

    ASSERT_TRUE(TreesEqual(test_root1, test_root2));
}

TEST(TreesEqualTest, ReturnsFalseWhenTheDifferentTreesArePassed)
{
    std::shared_ptr<HuffmanTreeNode> test_root1 =
        std::make_shared<HuffmanTreeNode>(HuffmanTreeNode { { 0, 0 } });
    test_root1->left = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 1, 1 }));
    test_root1->right = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 255, 2 }));

    std::shared_ptr<HuffmanTreeNode> test_root2 =
        std::make_shared<HuffmanTreeNode>(HuffmanTreeNode { { 11, 11 } });
    test_root2->left = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 22, 22 }));
    test_root2->right = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 33, 33 }));

    ASSERT_FALSE(TreesEqual(test_root1, test_root2));
}

TEST(TreesEqualTest, ReturnsFalseWhenOneTreeIsMissingRightNode)
{
    std::shared_ptr<HuffmanTreeNode> test_root1 =
        std::make_shared<HuffmanTreeNode>(HuffmanTreeNode { { 0, 0 } });
    test_root1->left = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 1, 1 }));
    test_root1->right = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 255, 2 }));

    std::shared_ptr<HuffmanTreeNode> test_root2 =
        std::make_shared<HuffmanTreeNode>(HuffmanTreeNode { { 0, 0 } });
    test_root2->left = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 1, 1 }));

    ASSERT_FALSE(TreesEqual(test_root1, test_root2));
}

TEST(TreesEqualTest, ReturnsFalseWhenOneTreeIsMissingLeftNode)
{
    std::shared_ptr<HuffmanTreeNode> test_root1 =
        std::make_shared<HuffmanTreeNode>(HuffmanTreeNode { { 0, 0 } });
    test_root1->left = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 1, 1 }));
    test_root1->right = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 255, 2 }));

    std::shared_ptr<HuffmanTreeNode> test_root2 =
        std::make_shared<HuffmanTreeNode>(HuffmanTreeNode { { 0, 0 } });
    test_root2->right = std::make_shared<HuffmanTreeNode>(HuffmanTreeNode({ 255, 2 }));

    ASSERT_FALSE(TreesEqual(test_root1, test_root2));
}
