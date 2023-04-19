#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
#include <cassert>

using namespace std;


bool arePermutation(const std::string& str1, const std::string& str2)
{
  if (str1.size() != str2.size()) return false;

  std::string sorted_str1 = str1;
  std::sort(sorted_str1.begin(), sorted_str1.end());
  std::string sorted_str2 = str2;
  std::sort(sorted_str2.begin(), sorted_str2.end());

  return sorted_str1 == sorted_str2;
}

bool arePermutation_2(const std::string &str1, const std::string &str2)
{
  if (str1.length() != str2.length())
  {
    return false;
  }

  std::array<int, 256> count{};
  for (char c : str1)
  {
    count[static_cast<unsigned char>(c)]++;
  }
  for (char c : str2)
  {
    count[static_cast<unsigned char>(c)]--;
    if (count[static_cast<unsigned char>(c)] < 0)
    {
      return false;
    }
  }

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
    int output = arePermutation_2(a, b);
    assert(output == expected_output);
    std::cout << "Method 2, Test case " << i++ << " passed\n";
  }

  std::cout << "All tests passed\n";

  return 0;
}
