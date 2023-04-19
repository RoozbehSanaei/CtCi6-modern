#include <string>
#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>  // for std::accumulate
#include <cctype>     // for std::isalpha, std::tolower
#include <numeric>

using namespace std;

#include <iostream>
#include <vector>


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


std::vector<int> buildCharFrequencyTable(const std::string& phrase){
    std::vector<int> table(26, 0);
    for(char c : phrase){
        if(std::isalpha(c)){
            table[std::tolower(c) - 'a']++;
        }
    }
    return table;
}


bool checkMaxOneOdd(const std::vector<int>& table) {
    return std::count_if(table.begin(), table.end(), [](int count) {
        return count % 2 == 1;
    }) <= 1;
}

bool isPermutationOfPalindrome(const string &phrase)
{
    vector<int> table = buildCharFrequencyTable(phrase);
    return checkMaxOneOdd(table);
}


bool isPermutationOfPalindrome_bitwise(std::string_view phrase) {
    std::bitset<26> table;
    for (const char c : phrase) {
        if (std::isalpha(c)) {
            table.flip(std::tolower(c) - 'a');
        }
    }
    return table.count() <= 1;
}

#define TEST(pFunc, pattern) \
    cout << "[" #pFunc "]\n" \
         << "- Pattern: " << pattern << "\n" \
         << "- Result : " << pFunc(pattern) << "\n"

int main(int argc, const char *argv[])
{
    vector<string> patterns{"","a","ab","Tact Coa","Rats live on no evil st","Rats live on no evil star"};
    for (auto& pattern: patterns) TEST(isPermutationOfPalindrome, pattern);
    for (auto& pattern: patterns) TEST(isPermutationOfPalindrome_bitwise, pattern);
    
    return 0;
}