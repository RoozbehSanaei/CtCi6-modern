#include <iostream>
#include <string>


/**
 * @brief Checks if s2 is a rotation of s1.
 * 
 * A string s2 is considered a rotation of s1 if it is obtained by 
 * splitting s1 into two parts and swapping them. For example, "llohe" 
 * is a rotation of "hello".
 * 
 * @param s1 The first string.
 * @param s2 The second string.
 * @return True if s2 is a rotation of s1, false otherwise.
 */
bool isRotation(const std::string& s1, const std::string& s2) {
    // Check if s1 and s2 are of the same length
    if (s1.length() != s2.length()) {
        return false;
    }
    
    // Check if s2 is a substring of the concatenation of s1 with itself
    if ((s1 + s1).find(s2) != std::string::npos) {
        return true;
    }
    
    // s2 is not a rotation of s1
    return false;
}

int main() {
    // Declare two strings to hold the user input
    std::string s1, s2;

    // Prompt the user to enter string 1
    std::cout << "Enter string 1 : ";
    std::cin >> s1;

    // Prompt the user to enter string 2
    std::cout << "Enter string 2 : ";
    std::cin >> s2;

    // Call the isRotation function to check if s2 is a rotation of s1
    if (isRotation(s1, s2)) {
        // If s2 is a rotation of s1, print "Yes!"
        std::cout << "Yes! " << s2 << " is a rotation of " << s1 << std::endl;
    } else {
        // If s2 is not a rotation of s1, print "No!"
        std::cout << "No! " << s2 << " is not a rotation of " << s1 << std::endl;
    }

    // Return 0 to indicate success
    return 0;
}

