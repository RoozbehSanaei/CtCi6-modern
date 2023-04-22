import unittest

def isOneAway(s1: str, s2: str) -> bool:
    """
    Determines whether two given strings are one edit away from each other.
    
    Args:
    s1 (str): the first string being compared
    s2 (str): the second string being compared
    
    Returns:
    bool: True if the two strings are one edit away from each other, False otherwise
    
    """
    
    # Check if the absolute difference between the lengths of the two strings is greater than 1
    if abs(len(s1) - len(s2)) > 1: 
        return False
    
    # Initialize the variable mismatch to 0 and two pointers i and j to 0
    mismatch = i = j = 0
    
    # Iterate over the characters of s1 and s2 using two pointers i and j
    while i < len(s1) and j < len(s2):
        # If the current characters at i and j are not equal
        if s1[i] != s2[j]:
            # If this is the first mismatch, set the flag mismatch to True
            if mismatch:
                return False
                
            mismatch = True
            
            # If s1 is longer than s2, decrement j by 1
            # so that the next comparison is between s1[i] and s2[j+1]
            if len(s1) > len(s2): 
                j -= 1
            # If s2 is longer than s1, decrement i by 1
            # so that the next comparison is between s1[i+1] and s2[j]
            elif len(s1) < len(s2): 
                i -= 1
        
        # Increment the pointers i and j
        i, j = i + 1, j + 1
        
    return True


class Test(unittest.TestCase):
    test_cases = {
        # no changes
        ("pale", "pale"): True,
        ("", ""): True,
        # one insert
        ("pale", "ple"): True,
        ("ple", "pale"): True,
        ("pales", "pale"): True,
        ("ples", "pales"): True,
        ("pale", "pkle"): True,
        ("paleabc", "pleabc"): True,
        ("", "d"): True,
        ("d", "de"): True,
        # one replace
        ("pale", "bale"): True,
        ("a", "b"): True,
        ("pale", "ble"): False,
        # multiple replace
        ("pale", "bake"): False,
        # insert and replace
        ("pale", "pse"): False,
        ("pale", "pas"): False,
        ("pas", "pale"): False,
        ("pkle", "pable"): False,
        ("pal", "palks"): False,
        ("palks", "pal"): False,
        # permutation with insert shouldn't match
        ("ale", "elas"): False
        }

    testable_functions = [isOneAway]

    def test_string_rotation(self):
        for testable_function in self.testable_functions:
            for args, expected in self.test_cases.items():
                assert testable_function(*args) == expected, f"Failed {testable_function.__name__} for: {[*args]}"


if __name__ == "__main__":
    unittest.main()