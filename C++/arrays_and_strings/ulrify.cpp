#include <iostream>
#include <string>


/**
 * @brief Replaces all spaces in the input string with "%20".
 * @param str The input string to be modified.
 */
void urlify(std::string& str)
{
    const std::string replaceWith = "%20"; // The string to replace spaces with.
    size_t i = 0; // Initialize index to keep track of last space found.

    // While loop to replace all spaces with "%20".
    while ((i = str.find(' ', i)) != std::string::npos) {
        str.replace(i, 1, replaceWith); // Replace the space with "%20".
        i += replaceWith.length(); // Move index past the "%20" string.
    }
}


int main()
{
    std::string myString = "This is a test string";
    std::cout << "Original string: " << myString << std::endl;

    // Call the urlify function to modify the input string
    urlify(myString);

    std::cout << "URLified string: " << myString << std::endl;

    return 0;
}