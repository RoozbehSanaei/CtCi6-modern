#include <string>
#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm> // for std::accumulate
#include <cctype>    // for std::isalpha, std::tolower
#include <numeric>


using namespace std;

/**
 * @brief Build a character frequency table for a given input phrase.
 *
 * This function takes a std::string argument and returns a std::vector<int> containing the frequency of each letter in the
 * English alphabet in the input phrase. The character frequency table is case-insensitive, so upper and lower case letters are
 * treated as the same letter.
 *
 * @param phrase The input phrase for which to build the character frequency table.
 * @return A std::vector<int> containing the frequency of each letter in the English alphabet in the input phrase.
 */
std::vector<int> buildCharFrequencyTable(const std::string &phrase)
{
    // Create a std::vector<int> of size 26, with each element initialized to 0.
    std::vector<int> table(26, 0);

    // Iterate over each character in the input phrase.
    for (char c : phrase)
    {
        // Check if the character is a letter.
        if (std::isalpha(c))
        {
            // Convert the character to lower case and update the corresponding frequency in the character frequency table.
            table[std::tolower(c) - 'a']++;
        }
    }

    // Return the character frequency table.
    return table;
}


/**
 * @brief Check if a character frequency table contains at most one odd number.
 *
 * This function takes a std::vector<int> argument and returns a bool value indicating whether the frequency table contains at most
 * one odd number. A frequency table is an array of integers where the index corresponds to the character and the value corresponds
 * to the number of times the character appears in a given input phrase.
 *
 * @param table A std::vector<int> representing the character frequency table to check.
 * @return True if the frequency table contains at most one odd number, false otherwise.
 */
bool checkMaxOneOdd(const std::vector<int> &table)
{
    // Use std::count_if to count the number of odd counts in the table vector.
    int oddCount = std::count_if(table.begin(), table.end(), [](int count)
                                 { return count % 2 == 1; });

    // Return true if the number of odd counts is less than or equal to 1, false otherwise.
    return oddCount <= 1;
}


/**
 * @brief Check if a string is a permutation of a palindrome.
 *
 * This function takes a std::string argument and returns a bool value indicating whether the input string is a permutation of a
 * palindrome. A string is a permutation of a palindrome if and only if the frequency table of its characters contains at most one
 * odd number.
 *
 * @param phrase The input string to check.
 * @return True if the input string is a permutation of a palindrome, false otherwise.
 */
bool isPermutationOfPalindrome(const std::string &phrase)
{
    // Build a character frequency table for the input phrase.
    std::vector<int> table = buildCharFrequencyTable(phrase);

    // Check if the frequency table contains at most one odd number.
    return checkMaxOneOdd(table);
}


/**
 * @brief Check if a string is a permutation of a palindrome using bitwise operations.
 *
 * This function takes a std::string_view argument and returns a bool value indicating whether the input string is a permutation of
 * a palindrome. A string is a permutation of a palindrome if and only if each character in the string appears an even number of
 * times or at most one character appears an odd number of times.
 *
 * @param phrase The input string to check.
 * @return True if the input string is a permutation of a palindrome, false otherwise.
 */
bool isPermutationOfPalindrome_bitwise(std::string_view phrase)
{
    // Create a bitset with 26 bits, all initially set to 0.
    std::bitset<26> table;

    // Iterate over each character in the input phrase.
    for (const char c : phrase)
    {
        // If the character is a letter, flip the corresponding bit in the bitset.
        if (std::isalpha(c))
        {
            table.flip(std::tolower(c) - 'a');
        }
    }

    // Return true if the number of bits that are set to 1 is less than or equal to 1.
    return table.count() <= 1;
}

#define TEST(pFunc, pattern)                 \
    cout << "[" #pFunc "]\n"                 \
         << "- Pattern: " << pattern << "\n" \
         << "- Result : " << pFunc(pattern) << "\n"

int main(int argc, const char *argv[])
{
    // Create a vector of input patterns to test.
    std::vector<std::string> patterns{"", "a", "ab", "Tact Coa", "Rats live on no evil st", "Rats live on no evil star"};

    // Test the isPermutationOfPalindrome function for each input pattern.
    for (auto &pattern : patterns)
    {
        TEST(isPermutationOfPalindrome, pattern);
    }

    // Test the isPermutationOfPalindrome_bitwise function for each input pattern.
    for (auto &pattern : patterns)
    {
        TEST(isPermutationOfPalindrome_bitwise, pattern);
    }

    return 0;
}