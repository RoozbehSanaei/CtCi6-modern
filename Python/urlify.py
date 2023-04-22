# O(N)
import unittest


'''
The urlify_algo function implements an in-place algorithm for replacing spaces with "%20" 
and removing trailing spaces in a given string. The algorithm works by first converting 
the string to a list of characters, since Python strings are immutable, and initializing 
new_index to the end of the list. It then iterates over the characters of the string in reverse
 order, starting from the last character before the trailing spaces, and for each character 
 it checks whether it is a space or not.

If the character is a space, the algorithm replaces it with "%20" by using slice assignment to 
replace the next three positions in the list with the characters "%20". It then updates new_index 
to point to the next position after the inserted "%20". If the character is not a space,
 the algorithm moves it to the position pointed to by new_index and updates new_index to point 
 to the next position.

The algorithm then uses slice notation to extract the modified portion of the list and joins it
 back into a string using the join method. The final string is returned.

This algorithm has a time complexity of O(n) where n is the length of the string
 (excluding any trailing spaces), since it iterates over the string once in reverse order. 
 The space complexity is also O(n) since it creates a new list of characters with the same
 length as the input string. However, since the algorithm modifies the string in place, 
 it is more space-efficient than algorithms that create a new string to hold the modified result.
'''

def urlify_algo(string, length):
    """replace spaces with %20 and removes trailing spaces"""
    # convert to list because Python strings are immutable
    char_list = list(string)
    new_index = len(char_list)

    for i in reversed(range(length)):
        if char_list[i] == " ":
            # Replace spaces
            char_list[new_index - 3 : new_index] = "%20"
            new_index -= 3
        else:
            # Move characters
            char_list[new_index - 1] = char_list[i]
            new_index -= 1
    # convert back to string
    return "".join(char_list[new_index:])



'''
The parameter "string" is the original string that needs to be transformed.
The parameter "length" is the maximum length of the string that needs to be transformed.
 Any characters in the original string beyond this length will be ignored.

The function uses the string method "split()" to split the string into a list of words, 
based on the spaces in the original string.
It then uses the string method "join()" to join the words in the list back together, 
using '%20' as the separator.
The final result is the transformed string with spaces replaced by '%20'.
'''
def urlify_algo(string, length):
    return '%20'.join(string[:length].split()) 

class Test(unittest.TestCase):
    """Test Cases"""

    test_cases = {
        ("much ado about nothing      ", 22): "much%20ado%20about%20nothing",
        ("Mr John Smith       ", 13): "Mr%20John%20Smith",
        (" a b    ", 4): "%20a%20b",
        (" a b       ", 5): "%20a%20b%20",
    }
    testable_functions = [urlify_algo]

    def test_urlify(self):
        for urlify in self.testable_functions:
            for args, expected in self.test_cases.items():
                assert urlify(*args) == expected, f"Failed {urlify.__name__} for: {[*args]}"


if __name__ == "__main__":
    unittest.main()