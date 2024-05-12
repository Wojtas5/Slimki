#include "huffman.h"
#include "algo_utils.h"

std::vector<unsigned char> Huffman::Encode(const std::vector<unsigned char>& data)
{
    HuffmanTree tree(algo_utils::CountUniqueValueFrequencies(data));
    DetermineCodes(tree.GetRoot());
    return ReplaceDataForCodes(data, m_huffman_codes_map);
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

std::vector<unsigned char> Huffman::ReplaceDataForCodes(
    const std::vector<unsigned char>& data,
    std::unordered_map<unsigned char, std::string>& huffman_codes)
{
    std::vector<unsigned char> compressed_data;
    unsigned char compressed_byte = 0;
    unsigned char compressed_bits_count = 0;

    for (auto value : data)
    {
        const std::string& code = huffman_codes[value];
        for (char bit : code)
        {
            compressed_byte <<= 1;
            if (bit == '1')
            {
                compressed_byte |= 1;
            }

            ++compressed_bits_count;
            if (compressed_bits_count == std::numeric_limits<unsigned char>::digits)
            {
                compressed_data.push_back(compressed_byte);
                compressed_byte = 0;
                compressed_bits_count = 0;
            }
        }
    }

    if (compressed_bits_count > 0)
    {
        compressed_byte <<= (std::numeric_limits<unsigned char>::digits - compressed_bits_count);
        compressed_data.push_back(compressed_byte);
    }

    return compressed_data;
}
