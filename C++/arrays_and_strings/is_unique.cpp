#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm> // for sort() 
#include <unordered_set>

using namespace std;


/**
 * @brief Checks if a string contains only unique characters.
 * 
 * @param str The string to check.
 * @return true if the string contains only unique characters, false otherwise.
 */
bool isUniqueChars(const std::string_view& str) {
    std::unordered_set<char> char_set; // create an unordered_set to store seen characters
    // iterate over each character in the string, using std::all_of
    // and insert the character into the set
    // return false if the insert function returns false, indicating a duplicate character
    return std::all_of(str.begin(), str.end(),
                       [&](char c) { return char_set.insert(c).second; });
}



int main(){
		vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
		for (auto word : words)
		{
			cout << word << string(": ") << boolalpha << isUniqueChars(word) <<endl;
		}
		
		return 0;
}