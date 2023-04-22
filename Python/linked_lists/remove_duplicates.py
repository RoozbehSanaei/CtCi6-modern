import time

from linked_list import LinkedList

# import necessary modules and classes


def remove_dups(ll):
    # function to remove duplicates from a linked list
    current = ll.head
    previous = None
    seen = set()

    while current:
        # iterate over the linked list
        if current.value in seen:
            # if current value is in the set, it means it's a duplicate, so remove it from the linked list
            previous.next = current.next
        else:
            # if current value is not in the set, it's the first time we're seeing it, so add it to the set
            seen.add(current.value)
            previous = current
        current = current.next
    # update the tail of the linked list
    ll.tail = previous
    return ll


def remove_dups_followup(ll):
    # a function that removes duplicates from a linked list without using additional buffer
    runner = current = ll.head
    while current:
        runner = current
        while runner.next:
            # iterate over the linked list for each value of current
            if runner.next.value == current.value:
                # if next value is equal to current value, remove it from the linked list
                runner.next = runner.next.next
            else:
                # otherwise, move to the next node
                runner = runner.next
        current = current.next
    # update the tail of the linked list
    ll.tail = runner
    return ll


testable_functions = (remove_dups, remove_dups_followup)
# a tuple containing two functions to test

test_cases = (
    ([], []),
    ([1, 1, 1, 1, 1, 1], [1]),
    ([1, 2, 3, 2], [1, 2, 3]),
    ([1, 2, 2, 3], [1, 2, 3]),
    ([1, 1, 2, 3], [1, 2, 3]),
    ([1, 2, 3], [1, 2, 3]),
)
# a tuple containing test cases for both functions

def test_remove_dupes():
    # a function to test both functions
    for f in testable_functions:
        # iterate over the functions to test
        start = time.perf_counter()
        # measure the start time
        for _ in range(100):
            # repeat each test 100 times
            for values, expected in test_cases:
                expected = expected.copy()
                # copy expected output to prevent it from being modified
                deduped = f(LinkedList(values))
                assert deduped.values() == expected
                # assert that the output of the function matches the expected output

                deduped.add(5)
                expected.append(5)
                assert deduped.values() == expected
                # assert that adding 5 to the linked list doesn't affect the output

        duration = time.perf_counter() - start
        # measure the end time and calculate duration
        print(f"{f.__name__} {duration * 1000:.1f}ms")
        # print the name of the function and its duration


def example():
    # an example function to show how the functions work
    ll = LinkedList.generate(100, 0, 9)
    print(ll)
    remove_dups(ll)
    print(ll)

    ll = LinkedList.generate(100, 0, 9)
    print(ll)
    remove_dups_followup(ll)
    print(ll)


if __name__ == "__main__":
    example()