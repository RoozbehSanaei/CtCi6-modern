# O(N)
import unittest


def string_rotation(s1, s2):
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