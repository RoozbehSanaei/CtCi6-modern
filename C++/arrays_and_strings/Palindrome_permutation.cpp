#include <string>
#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm> // for std::accumulate
#include <cctype>    // for std::isalpha, std::tolower
#include <numeric>


using namespace std;

/*
The function buildCharFrequencyTable takes a constant reference to a std::string object named phrase.
This is done to avoid making a copy of the original string, w
hich can be expensive for large strings.

The function creates a std::vector<int> object named table with 26 elements, all initialized to 0.
The size of the vector is fixed to 26, which corresponds to the 26 letters in the English alphabet.

The function then uses a range-based for loop to iterate over each character c in the input phrase.
For each character, it checks if it is an alphabetic character by calling the std::isalpha function.
This function returns a non-zero value if the character is alphabetic, and 0 otherwise.
 If c is an alphabetic character, the function converts it to lowercase using the std::tolower function.

The expression std::tolower(c) - 'a' calculates the index of the letter in the table vector that corresponds to the lowercase version of c.
Since the ASCII code for the lowercase letter 'a' is 97,
subtracting 'a' from the ASCII code of the lowercase version of c gives an integer in the range 0-25,
which is used as the index of the corresponding element in the table vector.

The function then increments the frequency of the corresponding
letter in the table vector using the ++ operator. This is equivalent to
writing table[std::tolower(c) - 'a'] = table[std::tolower(c) - 'a'] + 1.

Finally, the function returns the resulting table
 vector containing the frequencies of the letters in the input phrase.



*/

std::vector<int> buildCharFrequencyTable(const std::string &phrase)
{
    std::vector<int> table(26, 0);
    for (char c : phrase)
    {
        if (std::isalpha(c))
        {
            table[std::tolower(c) - 'a']++;
        }
    }
    return table;
}

/*
The function takes in a constant reference to a vector of integers called "table".
The function uses the "std::count_if" algorithm from the <algorithm> header file
to count the number of elements in the "table" vector that satisfy the condition given in the lambda function.
The lambda function takes an integer "count" and returns true if "count" is odd
(i.e., "count % 2 == 1").

If the number of odd elements in "table" is less than or equal to 1,
the function returns true, indicating that there is at most one odd element in the vector.
If the number of odd elements is greater than 1, the function returns false,
indicating that there are more than one odd elements in the vector.


*/

bool checkMaxOneOdd(const std::vector<int> &table)
{
    return std::count_if(table.begin(), table.end(), [](int count)
                         { return count % 2 == 1; }) <= 1;
}

bool isPermutationOfPalindrome(const string &phrase)
{
    vector<int> table = buildCharFrequencyTable(phrase);
    return checkMaxOneOdd(table);
}

/*
he function isPermutationOfPalindrome_bitwise takes a std::string_view argument phrase.
This is a lightweight object that provides a view of a sequence of characters in memory,
 without actually owning or copying the characters. Since the function only needs to
  read the characters in phrase, using a std::string_view instead of a std::string
  avoids unnecessary copying and memory allocation.

A std::bitset is created with 26 bits, which is enough to represent all the lowercase
letters of the English alphabet. The std::bitset is initialized with all bits set to zero
by default.

The for loop iterates over each character in phrase.
The loop variable c is declared as a const char, which means that its value
cannot be modified within the loop. This is a good practice to avoid unintentional side effects.

The std::isalpha function is used to check if the character c is an alphabetic character.
 This function returns true if the character is a letter of the alphabet (uppercase or lowercase),
 and false otherwise.

If c is an alphabetic character, its case is normalized to lowercase using the std::tolower function.
 This is done to treat uppercase and lowercase versions of the same letter as the same character.

The ASCII value of the lowercase letter 'a' is subtracted from the normalized character,
which results in a zero-based index into the std::bitset. For example, the character 'a'
maps to index 0, 'b' maps to index 1, and so on. This mapping is possible because the ASCII
 codes for the lowercase letters of the alphabet are contiguous and start at 97.

The flip function is used to toggle the bit at the computed index in the std::bitset.
If the bit was previously set to 0, it becomes 1, and vice versa. This is an efficient
way to count the frequency of each letter in phrase.

After the loop, the count function of the std::bitset is used to count the number of bits
 set to 1. This corresponds to the number of letters in phrase that have an odd frequency.
 If this count is at most 1, phrase is a permutation of a palindrome, and the function returns
 true. Otherwise, the function returns false.

The time complexity of the function is O(n), where n is the length of phrase. The space complexity
 is O(1), since the std::bitset has a fixed size of 26 bits.
 The function is therefore very efficient in terms of time and space,
  and can handle long input strings without causing memory or performance issues.
*/

bool isPermutationOfPalindrome_bitwise(std::string_view phrase)
{
    std::bitset<26> table;
    for (const char c : phrase) if (std::isalpha(c)) table.flip(std::tolower(c) - 'a');
    return table.count() <= 1;
}

#define TEST(pFunc, pattern)                 \
    cout << "[" #pFunc "]\n"                 \
         << "- Pattern: " << pattern << "\n" \
         << "- Result : " << pFunc(pattern) << "\n"

int main(int argc, const char *argv[])
{
    vector<string> patterns{"", "a", "ab", "Tact Coa", "Rats live on no evil st", "Rats live on no evil star"};
    for (auto &pattern : patterns)
        TEST(isPermutationOfPalindrome, pattern);
    for (auto &pattern : patterns)
        TEST(isPermutationOfPalindrome_bitwise, pattern);

    return 0;
}