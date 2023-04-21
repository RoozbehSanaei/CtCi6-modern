/*
 * Cracking the coding interview edition 6
 * Problem 1-6 Implement a method to perform basic string compression.
 * Example string aabcccccaaa should be compressed to a2b1c5a3,
 * however if compressed string is bigger than original string, return original string
 */

#include <iostream>
#include <numeric>
#include <string>
#include <sstream>
#include <tuple>

// This function takes a string as input and compresses it using a simple algorithm
std::string compress(std::string str)
{
    // If the length of the string is less than 2, there is nothing to compress
    if (str.length() < 2) return str;

    // Create an output stringstream to store the compressed string
    std::stringstream out;

    // Initialize a counter to keep track of the number of consecutive characters
    int count = 1;

    // Iterate over the characters of the string starting from the second character
    for (auto it = str.begin() + 1; it <= str.end(); ++it) {
        // If the current character is different from the previous character, write the previous character
        // and the count to the output stringstream, reset the counter, and continue iterating
        if (*it != *(it-1)) {
            out << *(it-1) << count;
            count = 1;
        }
        // If the current character is the same as the previous character, increment the counter
        else {
            ++count;
        }
    }

    // Check if the length of the compressed string is less than the length of the input string
    // If it is, return the compressed string. Otherwise, return the input string.
    return out.str().length() < str.length() ? out.str() : str;
}


int main() {
    std::string str;
    std::cout << "Enter a string: ";
    std::cin >> str;

    auto compressed = compress(str);
    std::cout << str << (str != compressed ? " can be compressed to " + compressed : " can not be compressed") << std::endl;

    return 0;
}