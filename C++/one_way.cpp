#include <string>
#include <iostream>
/*
This code appears to implement a function isOneAway that takes
 two constant string references s1 and s2 as input parameters and 
 returns a Boolean value indicating whether the two strings are at most
  one edit operation away from each other. An edit operation in this context 
  is defined as the insertion, deletion, or substitution of a single character 
  in one of the strings.

The function first determines which of the two input strings is longer by 
using the ternary operator to assign the longer string to the reference variable 
a and the shorter string to the reference variable b. The function then checks if
 the difference in length between a and b is greater than 1, in which case the function 
 returns false.

The function then uses a loop to iterate through the characters of both strings. 
If the character at the current position in a is different from the character at 
the current position in b, the function checks whether an edit operation has already 
been performed by checking the Boolean variable mismatch. If mismatch is true, this means that
 an edit operation has already been performed, so the function returns false. 
 If mismatch is false, this means that no edit operation has been performed yet, 
 so the function sets mismatch to true and checks whether a is longer than b.
  If a is longer than b, the function decrements j to effectively skip 
  over the current character in b. This allows the function to handle 
  the case where an edit operation involves deleting a character from a.

If the loop completes without returning false, the function returns true, 
indicating that the two input strings are at most one edit operation away from each other.

*/

// Check if two strings are one edit away from each other
bool isOneAway(const std::string& s1, const std::string& s2){
    // Determine which string is longer and which is shorter
    const std::string& a = (s1.length() >= s2.length()) ? s1 : s2;
    const std::string& b = (s1.length() < s2.length()) ? s1 : s2;

    // Check if the length difference between the two strings is greater than 1
    if (a.length() - b.length() > 1) return false;

    // Iterate through both strings and check for differences
    bool mismatch = false;
    for (auto i = 0u, j = 0u; i < a.length() && j < b.length(); ++i, ++j)
        if (a[i] != b[j]) {
            // If a difference is found, set the 'mismatch' variable to true
            if (mismatch) return false; // If there's already been a mismatch, return false
            mismatch = true;
            if (a.length() > b.length()) --j; // Adjust the index of the shorter string to continue checking for differences
        }

    // If at most one difference was found, return true
    return true;
}


int main(void){
	std::string s1,s2;
	std::getline(std::cin,s1);
	std::getline(std::cin,s2);
    std::cout << (isOneAway(s1, s2) ? "One edit away." : "Not one edit away.") << std::endl;
	return 0;
}