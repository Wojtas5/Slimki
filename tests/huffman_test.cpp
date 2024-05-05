#include <gtest/gtest.h>
#include "huffman.h"
#include "huffman_tree_utils.h"

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

TEST(HuffmanTest, GathersHuffmanCodesFromTree)
{
    std::unordered_map<unsigned char, std::string> expected_codes { {255, "00"}, {0, "01"}, {11, "1"} };
    std::unordered_map<unsigned char, int> value_frequency_map { {255, 1}, {0, 2}, {11, 4} };
    HuffmanTree huffman_tree(value_frequency_map);
    Huffman huffman;

    ASSERT_EQ(huffman.DetermineCodes(huffman_tree.GetRoot()), expected_codes);
}

/* Creating huffman code
1. Traverse the tree to gather the codes for a specific value and save them as a map {val(char), code(string)}
2. Iterate over the input and replace the values for codes
   - At each iteration append bits to a byte variable
   - When the full byte is filled append it to a vector
   - Carry over the remaining bits for next iteration
*/