/**
 * Function development file for 
 * Vigenere's ciphering ~refered at vigenere.cpp (main file)
 * 
 * Author: Eric Dürr Sierra | eric.durr.20@ull.edu.es
 * 
 * Created: 23/02/2021
 * Modified: 23/02/2021
 * 
 * 
 */

#include <string>
#include <sstream>
#include <iostream>

const std::vector<std::pair<std::string, int>> alphabet_key_map = {
    {"A", 0}, {"B", 1}, {"C", 2}, {"D", 3}, {"E", 4}, {"F", 5}, {"G", 6}, {"H", 7}, {"I", 8}, {"J", 9}, {"K", 10}, {"L", 11}, {"M", 12}, {"N", 13}, {"O", 14}, {"P", 15}, {"Q", 16}, {"R", 17}, {"S", 18}, {"T", 19}, {"U", 20}, {"V", 21}, {"W", 22}, {"X", 23}, {"Y", 24}, {"Z", 25}};

const int mod = alphabet_key_map.size();

std::string compact(const std::string &input)
{
    std::string result = "";
    std::stringstream s_input(input);
    for (const auto letter : input)
    {
        if (letter != ' ')
            result += letter;
    }
    return result;
}
std::vector<std::vector<std::string>> v_split(std::string input,
                                              const std::string &keyword)
{
    std::vector<std::vector<std::string>> result;
    while (!input.empty())
    {
        if (!input.empty())
        {
            std::vector<std::string> tmp_str_block;
            for (int i = 0; i < keyword.size(); i++)
            {
                if (input.empty())
                {
                    break;
                }
                tmp_str_block.push_back(std::string{input.at(0)});
                input.erase(input.begin());
            }
            result.push_back(tmp_str_block);
        }
    }

    return result;
}

std::string cipher(const std::string &letter,
                   const std::string &keyword_letter)
{
    int letter_pos = -1;
    for (auto element : alphabet_key_map)
    {
        if (element.first == letter)
            letter_pos = element.second;
    }
    int key_letter_pos = -1;
    for (auto element : alphabet_key_map)
    {
        if (element.first == keyword_letter)
            key_letter_pos = element.second;
    }

    if (letter_pos == -1 || key_letter_pos == -1)
    {
        return "?";
    }
    else
    {
        std::string ciphered_letter;
        for (auto element : alphabet_key_map)
        {
            if (element.second == (letter_pos + key_letter_pos) % mod)
                ciphered_letter = element.first;
        }
        return ciphered_letter;
    }
}

std::string decipher_element(const std::string &letter,
                             const std::string &keyword_letter)
{
    int letter_pos = -1;
    for (auto element : alphabet_key_map)
    {
        if (element.first == letter)
            letter_pos = element.second;
    }
    int key_letter_pos = -1;
    for (auto element : alphabet_key_map)
    {
        if (element.first == keyword_letter)
            key_letter_pos = element.second;
    }
    if (letter_pos == -1 || key_letter_pos == -1)
    {
        return "?";
    }
    else
    {
        std::string deciphered_letter;
        for (auto element : alphabet_key_map)
        {
            if ((letter_pos - key_letter_pos) >= 0)
            {
                if (element.second == (letter_pos - key_letter_pos) % mod)
                    deciphered_letter = element.first;
            }
            else if ((letter_pos - key_letter_pos) < 0)
            {

                if (element.second == (letter_pos - key_letter_pos + mod) % mod)
                    deciphered_letter = element.first;
            }
        }
        return deciphered_letter;
    }
}

std::vector<std::vector<std::string>> v_cipher(
    std::vector<std::vector<std::string>> input,
    const std::string &keyword)
{

    std::vector<std::vector<std::string>> result;
    for (auto block : input)
    {
        std::vector<std::string> ciphered_block;
        int offset = 0;
        for (auto letter : block)
        {
            ciphered_block.push_back(cipher(letter, std::string{keyword[offset]}));
            offset++;
        }
        result.push_back(ciphered_block);
    }

    return result;
}

std::string join(const std::vector<std::vector<std::string>> &ciphered_output)
{
    std::string output = "";

    for (auto block : ciphered_output)
    {
        for (auto element : block)
        {
            output += element;
        }
    }
    return output;
}

std::string decipher(const std::string encoded_str, const std::string keyword)
{
    std::vector<std::vector<std::string>> temporal;
    std::vector<std::vector<std::string>> splitted = v_split(encoded_str, keyword);
    for (auto block : splitted)
    {
        std::vector<std::string> dechipered_block;
        int offset = 0;
        for (auto letter : block)
        {
            dechipered_block.push_back(decipher_element(letter, std::string{keyword[offset]}));
            offset++;
        }
        temporal.push_back(dechipered_block);
    }

    return join(temporal);
}
