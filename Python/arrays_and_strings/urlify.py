# O(N)
import unittest




def urlify_algo(string, length):
    """
    Convert a string to a URL-friendly string by replacing spaces with '%20'.

    Parameters:
    string (str): The input string to be processed.
    length (int): The length of the string to be processed.

    Returns:
    str: The processed string with spaces replaced by '%20'.
    """
    # Split the string into words and join them with '%20'
    # Only process the first "length" characters of the string
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