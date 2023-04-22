/**
 * Cracking the coding interview 1-9
 * You have a function "isSubstring" which checks whether a string is substring of another.
 * Given two strings s1 and s2, write code to check if s2 is a rotation of s1 using only one call to "isSubstring".
 *
 * Approach:
 * example s1 = "waterbottle", and s2 = "erbottlewat", clearly s2 is rotation of s1.
 * lets say s1 = xy ==> wat + erbottle
 * similarly s2 = yx ==> erbottle + wat
 * Therefore s1s1 = "waterbottlewaterbottle", clearly s2 is substring of s1s1
 * So if a string is formed by rotation of another string, it will always be substring of concatenated original string to itself.
 */

#include <iostream>
#include <string>

/*
If the lengths are equal, the function concatenates s1 with itself to form a new string s1s1,
 and then checks if s2 is a substring of s1s1 using the find function. If s2 is found within s1s1,
  it means that s2 is a rotation of s1, and the function returns true. 
  Otherwise, the function returns false.
*/

bool isRotation(const std::string& s1, const std::string& s2) {
    return s1.length() == s2.length() && (s1 + s1).find(s2) != std::string::npos;
}

int main() {
	std::string s1, s2;
	std::cout << "Enter string 1 : ";
	std::cin >> s1;
	std::cout << "Enter string 2 : ";
	std::cin >> s2;
    std::cout << (isRotation(s1, s2) ? "Yes! " : "No! ") << s2 << " is" << (isRotation(s1, s2) ? " " : " not ") << "a rotation of " << s1 << std::endl;
	return 0;
}
