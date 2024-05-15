#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <vector>
#include <string>
#include <unordered_map>
#include "huffman_tree.h"

class Huffman
{
public:
    std::vector<unsigned char> Encode(const std::vector<unsigned char>& data);

private:
    std::unordered_map<unsigned char, std::string> m_huffman_codes_map;
    std::string m_huffman_code;

    void DetermineCodes(std::shared_ptr<HuffmanTreeNode>& root);
    std::vector<unsigned char> ReplaceDataForCodes(const std::vector<unsigned char>& data);
};

#endif // HUFFMAN_H