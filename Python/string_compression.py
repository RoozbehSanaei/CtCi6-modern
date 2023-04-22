import time
import unittest
from itertools import groupby

def compress1(s):
    # Check if the length of the string is less than 2
    if len(s) < 2:
        return s

    # Initialize variables to store compressed string and count of consecutive characters
    compressed = ""
    count = 1
    
    # Iterate through the string
    for i in range(1, len(s)+1):
        # If the current character is different from the previous character, append the previous character and its count to the compressed string
        if ((i==len(s)) or (s[i] != s[i-1])):
            compressed += s[i-1] + str(count)
            count = 1
        # If the current character is the same as the previous character, increment the count
        else:
            count += 1
    
    # If the length of the compressed string
    return compressed if len(compressed) < len(s) else s





def compress2(s):
    # Group consecutive identical characters using itertools.groupby
    groups = groupby(s)
    
    # Create a list of tuples containing the label and count of each group
    result = [(label, len(list(group))) for label, group in groups]
    
    # Concatenate the label and count of each group into a compressed string
    compressed = "".join([f"{label}{count}" for label, count in result])
    
    # Return the compressed string if it's shorter than the original string, otherwise return the original string
    return compressed if len(compressed) < len(s) else s




class Test(unittest.TestCase):
    test_cases = [
        ("aabcccccaaa", "a2b1c5a3"),
        ("abcdef", "abcdef"),
        ("aabb", "aabb"),
        ("aaa", "a3"),
        ("a", "a"),
        ("", ""),
    ]
    testable_functions = [
        compress1,compress2
    ]

    def test(self):
        for test_function in self.testable_functions:
            for args, expected in self.test_cases:
                assert test_function(args) == expected, f"Failed {test_function.__name__} for: {[*args]}"


if __name__ == "__main__":
    unittest.main()