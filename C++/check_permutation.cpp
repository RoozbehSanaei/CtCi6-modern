#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
#include <ranges>
#include <cassert>


using namespace std;
bool arePermutation(string str1,string str2)
{
    // Get lengths of both strings
    int n1 = str1.length();
    int n2 = str2.length();

    // If length of both strings is not same, then they
    // cannot be anagram
    if (n1 != n2)
      return false;

    // Sort both strings
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    // Compare sorted strings
    for (int i = 0; i < n1;  i++)
       if (str1[i] != str2[i])
         return false;

    return true;
}

bool arePermutation_2(const string &str1, const string &str2) {
  if(str1.length() != str2.length()) 
    return false;
  int count[256]={0};
  for(int i = 0; i < str1.length(); i++) {
    int val = str1[i];
    count[val]++;
  }
  for(int i = 0; i < str2.length(); i++) {
    int val = str2[i];
    count[val]--;
    if(count[val]<0) 
      return false;
  }
  return true;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {

        std::vector<std::tuple<string, string, bool>> test_cases = {
        {"testest", "estxest", false},
        {"hello", "oellh", true},
    };



    // perform tests using assert and range-based for loop
    int i = 1;
    for (auto [a, b, expected_output] : test_cases) {
        int output = arePermutation(a, b);
        assert(output == expected_output);
        std::cout << "Method 1, Test case " << i++ << " passed\n";
    }

        // perform tests using assert and range-based for loop
    i = 1;
    for (auto [a, b, expected_output] : test_cases) {
        int output = arePermutation_2(a, b);
        assert(output == expected_output);
        std::cout << "Method 2, Test case " << i++ << " passed\n";
    }

    std::cout << "All tests passed\n";

    return 0;


}
