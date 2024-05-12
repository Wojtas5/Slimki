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

TEST(HuffmanTest, EncodesData)
{
    std::vector<unsigned char> test_data { 255, 0, 0, 11, 11, 11, 11 };
    std::vector<unsigned char> compressed_data { 0b00010111, 0b11000000 };
    Huffman huffman;

    ASSERT_EQ(huffman.Encode(test_data), compressed_data);
}
