#include <iostream>
#include <numeric>
#include <string>
#include <sstream>
#include <tuple>

/**
 * Compresses a string using a simple algorithm.
 *
 * The algorithm works by counting the number of consecutive characters
 * and writing them to the output stringstream when the current character
 * is different from the previous one.
 *
 * If the length of the compressed string is less than the length of the
 * input string, the function returns the compressed string. Otherwise,
 * it returns the input string.
 *
 * @param str The string to compress.
 * @return The compressed string, or the input string if compression is not beneficial.
 */
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