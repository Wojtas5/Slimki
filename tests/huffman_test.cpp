#include <gtest/gtest.h>
#include "huffman.h"

TEST(HuffmanTest, EncodesData)
{
    std::vector<unsigned char> test_data { 255, 0, 0, 11, 11, 11, 11 };
    std::vector<unsigned char> compressed_data { 0b00010111, 0b11000000 };
    Huffman huffman;

    ASSERT_EQ(huffman.Encode(test_data), compressed_data);
}
