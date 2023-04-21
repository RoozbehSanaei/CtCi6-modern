#include <iostream>
#include <string>

/*
The function takes a reference to a std::string object as its argument. It defines a 
constant std::string object named "replaceWith" that contains the replacement string "%20". 
It also initializes a size_t variable "i" to 0, which will be used to keep track of the current 
position in the string.

The while loop continues to execute as long as the "find" function returns a valid position 
(i.e., not std::string::npos), which indicates that there is at least one space character
 in the string that needs to be replaced. The "find" function takes two arguments: 
 the character to search for, which in this case is ' ', 
 and the starting position in the string, which is initially 0 and is incremented by the 
 length of the replacement string on each iteration.

When a space character is found, the "replace" function is called on the original string object,
 replacing the space character with the replacement string. The "replace" function takes three 
 arguments: the position of the character to replace 
 (i.e., the index returned by the "find" function), 
 the length of the substring to replace (which is 1 in this case since we are 
 replacing a single character), and the replacement string itself.

After all space characters have been replaced, the function returns, 
and the original string object passed as an argument 
now contains the modified URL-encoded string.
*/


void urlify(std::string& str)
{
    const std::string replaceWith = "%20";
    size_t i = 0;
    while ((i = str.find(' ', i)) != std::string::npos) {
        str.replace(i, 1, replaceWith);
        i += replaceWith.length();
    }
}

int main()
{
    std::string myString = "This is a test string";
    std::cout << "Original string: " << myString << std::endl;
    urlify(myString);
    std::cout << "URLified string: " << myString << std::endl;
    return 0;
}