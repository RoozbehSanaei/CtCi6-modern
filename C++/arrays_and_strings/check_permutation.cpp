#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
#include <cassert>
#include <array>

using namespace std;


/**
 * Checks if two strings are permutations of each other.
 *
 * @param str1 The first string.
 * @param str2 The second string.
 *
 * @return true if str1 and str2 are permutations of each other, false otherwise.
 */
bool arePermutation(const std::string& str1, const std::string& str2)
{
  // If the two strings have different lengths, they cannot be permutations of each other
  if (str1.size() != str2.size()) return false;

  // Create sorted versions of the input strings
  std::string sorted_str1 = str1;
  std::sort(sorted_str1.begin(), sorted_str1.end());
  std::string sorted_str2 = str2;
  std::sort(sorted_str2.begin(), sorted_str2.end());

  // If the sorted strings are equal, the original strings are permutations of each other
  return sorted_str1 == sorted_str2;
}


/**
 * @brief Check if two strings are permutations of each other
 *
 * @param str1 The first string
 * @param str2 The second string
 * @return True if str1 and str2 are permutations of each other, false otherwise
 */
bool arePermutation2(const std::string& str1, const std::string& str2)
{
  // Check if the two strings have different lengths
  if (str1.length() != str2.length()) return false;
  
  // Create an array to store the count of each character in str1
  std::array<int, 256> count;

  // Count the number of occurrences of each character in str1
  for (char c : str1) ++count[static_cast<unsigned char>(c)];

  // Decrement the count for each character in str2
  // If any count becomes negative, it means that str2 has more of that character than str1
  for (char c : str2) if (--count[static_cast<unsigned char>(c)] < 0) return false;

  // If all counts are non-negative, str1 and str2 are permutations of each other
  return true;
}


int main()
{

  std::vector<std::tuple<string, string, bool>> test_cases = {
      {"testest", "estxest", false},
      {"hello", "oellh", true},
  };

  // perform tests using assert and range-based for loop
  int i = 1;
  for (auto [a, b, expected_output] : test_cases)
  {
    int output = arePermutation(a, b);
    assert(output == expected_output);
    std::cout << "Method 1, Test case " << i++ << " passed\n";
  }

  // perform tests using assert and range-based for loop
  i = 1;
  for (auto [a, b, expected_output] : test_cases)
  {
    int output = arePermutation2(a, b);
    assert(output == expected_output);
    std::cout << "Method 2, Test case " << i++ << " passed\n";
  }

  std::cout << "All tests passed\n";

  return 0;
}
