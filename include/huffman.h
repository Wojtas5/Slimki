#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <vector>
#include <string>
#include <unordered_map>
#include "huffman_tree.h"

class Huffman
{
public:
    std::unordered_map<unsigned char, std::string> DetermineCodes(
        std::shared_ptr<HuffmanTreeNode>& root);

    std::vector<unsigned char> ReplaceDataForCodes(
        const std::vector<unsigned char>& data,
        std::unordered_map<unsigned char, std::string>& huffman_codes);

private:
    std::unordered_map<unsigned char, std::string> m_huffman_codes_map;
    std::string m_huffman_code;
};

std::unordered_map<unsigned char, int> CountUniqueValueFrequencies(
    const std::vector<unsigned char>& values);

#endif // HUFFMAN_H