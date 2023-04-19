#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
#include <cassert>
#include <array>

using namespace std;

/*

This function takes in two strings and checks if they are permutations of each other by comparing their sorted versions. 
It first checks if the strings have the same length, and if not, returns false. Then it creates two copies of the input strings, sorts them, and checks if they are equal.
 If they are equal, the function returns true, indicating that the two strings are permutations of each other. Otherwise, it returns false.
*/

bool arePermutation(const std::string& str1, const std::string& str2)
{
  if (str1.size() != str2.size()) return false;

  std::string sorted_str1 = str1;
  std::sort(sorted_str1.begin(), sorted_str1.end());
  std::string sorted_str2 = str2;
  std::sort(sorted_str2.begin(), sorted_str2.end());

  return sorted_str1 == sorted_str2;
}


/*
This code snippet defines a function named arePermutation2 that takes two input strings and returns true if they are permutations of each other.
 It first checks if the length of the two strings are equal and returns false if they are not. 
 It then creates an array named count with 256 elements (one for each possible ASCII character) and initializes it to all zeros.
  The function then loops through each character in the first string str1, increments the corresponding count in the count array for that character, 
  and then loops through each character in the second string str2. For each character in str2, the function decrements the corresponding count in the count array for that character. 
  If at any point the count goes below zero, 
  it means that str2 has a character that str1 doesn't have, so the function immediately returns false. 
  If the loop completes without returning false, the function returns true, indicating that the two strings are permutations of each other. 
  This algorithm has a time complexity of O(n).
*/

bool arePermutation2(const std::string& str1, const std::string& str2)
{
  if (str1.length() != str2.length()) return false;
  
  std::array<int, 256> count;   

  for (char c : str1) ++count[static_cast<unsigned char>(c)];
  for (char c : str2) if (--count[static_cast<unsigned char>(c)] < 0) return false;

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
