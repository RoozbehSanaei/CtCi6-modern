# O(N)
import unittest

def string_rotation(s1: str, s2: str) -> bool:
    """
    Check if s2 is a rotation of s1 by concatenating s1 with itself and checking whether s2 is a substring of the resulting string.

    Args:
        s1 (str): The original string.
        s2 (str): The potentially rotated string.

    Returns:
        bool: True if s2 is a rotation of s1, False otherwise.
    """
    return len(s1) == len(s2) and s2 in s1*2



class Test(unittest.TestCase):

    test_cases = [
        {("waterbottle", "erbottlewat"): True},
        {("foo", "bar"): False},
        {("foo", "foofoo"): False},
    ]

    def test_string_rotation(self):
        for args, expected in self.test_cases.items(): 
            assert string_rotation(*args) == expected, f"Failed {string_rotation.__name__} for: {[*args]}"


if __name__ == "__main__":
    unittest.main()