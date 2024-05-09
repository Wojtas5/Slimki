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

TEST(HuffmanTest, ReplacesDataForHuffmanCodeforSingleValue)
{
    std::unordered_map<unsigned char, std::string> huffman_codes { {0, "01"} };
    std::vector<unsigned char> test_data { 0 };
    std::vector<unsigned char> compressed_data { 0b01000000 };
    Huffman huffman;

    ASSERT_EQ(huffman.ReplaceDataForCodes(test_data, huffman_codes), compressed_data);
}

TEST(HuffmanTest, ReplacesDataForHuffmanCodes)
{
    std::unordered_map<unsigned char, std::string> huffman_codes { {255, "00"}, {0, "01"}, {11, "1"} };
    std::vector<unsigned char> test_data { 255, 0, 0, 11, 11, 11, 11 };
    std::vector<unsigned char> compressed_data { 0b00010111, 0b11000000 };
    Huffman huffman;

    ASSERT_EQ(huffman.ReplaceDataForCodes(test_data, huffman_codes), compressed_data);
}
