#include <string>
#include <iostream>

/**
 * @brief Checks if two strings are one edit away from each other.
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @return True if the two strings are one edit away from each other, false otherwise.
 */
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


int main(void)
{
    // Read two strings from the console.
    std::string s1, s2;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);

    // Check if the two strings are one edit away and print a message to the console.
    std::cout << (isOneAway(s1, s2) ? "One edit away." : "Not one edit away.") << std::endl;

    return 0;
}