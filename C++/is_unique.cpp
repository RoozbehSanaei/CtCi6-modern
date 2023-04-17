#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm> // for sort() 
#include <unordered_set>

using namespace std;



/*
std::string_view is a lightweight object that provides read-only access to a string without copying it. 


In this version of the function, the std::all_of algorithm is used to check whether all characters 
in the input string str are unique. The algorithm takes two iterators (str.begin() and str.end()) 
and a predicate function as arguments. The predicate function is a lambda function that takes 
a character c as input and returns a boolean value indicating whether c was successfully inserted 
into the char_set using char_set.insert(c).second. If the insertion was successful (i.e., c is not already in the set), the function returns true.
 If the insertion was not successful (i.e., c is already in the set), the function returns false.

an empty unordered_set called char_set that will be used to store the characters in the string.

If the std::find_if algorithm reaches the end of the string without finding a repeated character, it returns an iterator to str.end(), which is compared to the result of the expression std::find_if(...) using the == operator. If they are equal, it means that there are 
no repeated characters in the string, so the function returns true. Otherwise, it returns false.

[&] is called the capture list, which defines how the lambda function captures variables from the enclosing scope. In this case, & indicates that we want to capture all variables by reference.

(const char c) is the parameter list, which specifies the parameters that the lambda function will accept. In this case, the lambda function takes a single parameter of type char named c.

Overall, &([&](const char c) { ... }) defines a lambda function that captures the 
char_set variable by reference and takes a single char argument named c. 

The insert function returns a pair of values: 
the first value is an iterator pointing to the inserted element  (or the already existing element in the set), 
and the second value is a bool indicating whether the insertion was successful.
In this case, the ! operator negates the second value, so the expression !char_set.insert(c).second returns true
if the insertion was not successful, which means that the character is already in the set (i.e., it is not unique).

The lambda function tries to insert the char argument c into the char_set and 
returns true if the insertion fails, indicating that the character is not unique. 

Therefore, this line of code effectively checks whether the current character in the string is unique or not, based on whether it can be inserted into the set or not.

*/

bool isUniqueChars(const std::string_view &str){
    unordered_set<char> char_set;
    return std::all_of(str.begin(), str.end(), [&](char c) { return char_set.insert(c).second; });

}



int main(){
		vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
		for (auto word : words)
		{
			cout << word << string(": ") << boolalpha << isUniqueChars(word) <<endl;
		}
		
		return 0;
}