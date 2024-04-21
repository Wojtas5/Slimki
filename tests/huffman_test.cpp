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
