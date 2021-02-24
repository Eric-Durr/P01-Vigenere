/**
 * BDD Testing file for the vigenere's ciphering 
 * functions set.
 * 
 * Author: Eric Dürr Sierra | eric.durr.20@ull.edu.es
 * 
 * Created: 23/02/2021
 * Modified: 23/02/2021
 * 
 * 
 */

#include "../include/Catch2/catch.h"
#include "../include/vigenere_functions.h"

SCENARIO("Encoding strings")
{
    GIVEN("An input string and a keyword")
    {
        std::string keyword = "MISION";
        std::string input_text = "ESTE MENSAJE SE AUTODESTRUIRA";
        std::vector<std::vector<std::string>> splitted_input;
        std::vector<std::vector<std::string>> ciphered_output;
        std::string formated_input;
        std::string formated_output;
        WHEN("initial formatting is applied")
        {
            formated_input = compact(input_text);
            THEN("Result must not contain spaces")
            {
                REQUIRE(formated_input == "ESTEMENSAJESEAUTODESTRUIRA");
            }
            splitted_input = v_split(formated_input, keyword);
            AND_THEN("The formated result must be splitted correctly")
            {
                //  Each block length can't exceed the keyword length
                for (auto block : splitted_input)
                {
                    REQUIRE(block.size() <= keyword.size());
                }

                std::vector<std::vector<std::string>> expected_map = {
                    {"E", "S", "T", "E", "M", "E"},
                    {"N", "S", "A", "J", "E", "S"},
                    {"E", "A", "U", "T", "O", "D"},
                    {"E", "S", "T", "R", "U", "I"},
                    {"R", "A"}};
                CHECK(splitted_input == expected_map);
            }
        }
        AND_WHEN("Encription is aplied")
        {
            formated_input = compact(input_text);
            splitted_input = v_split(formated_input, keyword);
            ciphered_output = v_cipher(splitted_input, keyword);
            THEN("the split must follow vigenere rules through encoding")
            {
                std::vector<std::vector<std::string>> expected_endoded_map = {
                    {"Q", "A", "L", "M", "A", "R"},
                    {"Z", "A", "S", "R", "S", "F"},
                    {"Q", "I", "M", "B", "C", "Q"},
                    {"Q", "A", "L", "Z", "I", "V"},
                    {"D", "I"}};
                REQUIRE(ciphered_output == expected_endoded_map);
            }

            formated_output = join(ciphered_output);
            AND_THEN("the formated output must be right")
            {
                REQUIRE(formated_output == "QALMARZASRSFQIMBCQQALZIVDI");
            }
        }
    }
}

SCENARIO("Decoding strings")
{
    GIVEN("An encoded string and the original string")
    {
        std::string keyword = "MISION";
        std::string original = "ESTEMENSAJESEAUTODESTRUIRA";
        std::string ciphered = "QALMARZASRSFQIMBCQQALZIVDI";
        WHEN("Passed into decoder")
        {
            std::string deciphered = decipher(ciphered, keyword);
            THEN("Original string and the decoded result must be the same")
            {
                REQUIRE(deciphered == original);
            }
        }
    }
}