#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm> // for sort() 

using namespace std;


/*
std::string_view is a lightweight object that provides read-only access to a string without copying it. 

We  use the constexpr specifier to make the function's size check a compile-time constant expression.
This can help with optimization and avoid unnecessary checks at runtime. 

an empty unordered_set called char_set that will be used to store the characters in the string.

If the std::find_if algorithm reaches the end of the string without finding a repeated character, it returns an iterator to str.end(), which is compared to the result of the expression std::find_if(...) using the == operator. If they are equal, it means that there are 
no repeated characters in the string, so the function returns true. Otherwise, it returns false.

[&] is called the capture list, which defines how the lambda function captures variables from the enclosing scope. In this case, & indicates that we want to capture all variables by reference.

(const char c) is the parameter list, which specifies the parameters that the lambda function will accept. In this case, the lambda function takes a single parameter of type char named c.

Overall, &([&](const char c) { ... }) defines a lambda function that captures the 
char_set variable by reference and takes a single char argument named c. 
The lambda function tries to insert the char argument c into the char_set and 
returns true if the insertion fails, indicating that the character is not unique. 

The insert function returns a pair of values: 
the first value is an iterator pointing to the inserted element  (or the already existing element in the set), 
and the second value is a bool indicating whether the insertion was successful.
In this case, the ! operator negates the second value, so the expression !char_set.insert(c).second returns true
if the insertion was not successful, which means that the character is already in the set (i.e., it is not unique).
Therefore, this line of code effectively checks whether the current character in the string is unique or not, based on whether it can be inserted into the set or not.

*/
constexpr bool isUniqueChars(const std::string_view &str){
    unordered_set<char> char_set;
    return std::find_if(str.begin(), str.end(), [&](const char c) { return !char_set.insert(c).second;
    }) == str.end();
}



int main(){
		vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
		for (auto word : words)
		{
			cout << word << string(": ") << boolalpha << isUniqueChars(word) <<endl;
		}
		
		return 0;
}