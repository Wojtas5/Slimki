#include <gtest/gtest.h>
#include "algo_utils.h"

TEST(AlgoUtilsTest, CountsFrequenciesOfAllUniqueValues)
{
    std::vector<unsigned char> test_values { 0, 1, 255, 1, 0 };
    std::unordered_map<unsigned char, int> output { { 0, 2 }, { 1, 2 }, { 255, 1 } };
    ASSERT_EQ(algo_utils::CountUniqueValueFrequencies(test_values), output);
}

TEST(AlgoUtilsTest, ReturnEmptyMapOnEmptyInput)
{
    ASSERT_TRUE(algo_utils::CountUniqueValueFrequencies({}).empty());
}
