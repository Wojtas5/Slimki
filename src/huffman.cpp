#include "huffman.h"

std::unordered_map<unsigned char, int> CountUniqueValueFrequencies(
    const std::vector<unsigned char>& values)
{
    std::unordered_map<unsigned char, int> value_frequency_map;
    for (auto value : values)
    {
        ++value_frequency_map[value];
    }
    return value_frequency_map;
}

std::unordered_map<unsigned char, std::string> Huffman::DetermineCodes(
    std::shared_ptr<HuffmanTreeNode>& node)
{
    if (node->left != nullptr)
    {
        m_huffman_code += "0";
        DetermineCodes(node->left);
        m_huffman_code.pop_back();
    }

    if (node->right != nullptr)
    {
        m_huffman_code += "1";
        DetermineCodes(node->right);
        m_huffman_code.pop_back();
    }

    if (node->IsLeaf())
    {
        m_huffman_codes_map[node->value] = m_huffman_code;
    }

    return m_huffman_codes_map;
}
}
