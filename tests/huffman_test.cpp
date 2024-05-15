#include <gtest/gtest.h>
#include "huffman.h"

class HuffmanTest : public testing::Test
{
protected:
    Huffman huffman;
};

TEST_F(HuffmanTest, EncodesData)
{
    std::vector<unsigned char> test_data { 255, 0, 0, 11, 11, 11, 11 };
    std::vector<unsigned char> compressed_data { 0b00010111, 0b11000000 };

    ASSERT_EQ(huffman.Encode(test_data), compressed_data);
}

TEST_F(HuffmanTest, EncodesDataWhereAllValuesHaveSameFrequency)
{
    std::vector<unsigned char> test_data { 0, 1, 2, 0, 1, 2, 0, 1, 2 };
    std::vector<unsigned char> compressed_data { 0b10110101, 0b10101100 };

    ASSERT_EQ(huffman.Encode(test_data), compressed_data);
}

TEST_F(HuffmanTest, ReturnsEmptyVectorOnSingleByteOfData)
{
    std::vector<unsigned char> test_data { 255 };

    ASSERT_EQ(huffman.Encode(test_data), std::vector<unsigned char>{});
}

TEST_F(HuffmanTest, ReturnsEmptyVectorIfInputConsistsOfARepeatedSingleValue)
{
    std::vector<unsigned char> test_data(20, 255);

    ASSERT_EQ(huffman.Encode(test_data), std::vector<unsigned char>{});
}

TEST_F(HuffmanTest, ReturnsEmptyVectorOnEmptyData)
{
    std::vector<unsigned char> empty_data;

    ASSERT_EQ(huffman.Encode(empty_data), std::vector<unsigned char>{});
}
