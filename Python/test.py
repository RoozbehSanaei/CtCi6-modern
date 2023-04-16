from collections import defaultdict
import time
import unittest

def calculate_time(test_cases,test_functions):
    num_runs = 1000
    function_runtimes = defaultdict(float)

    for _ in range(num_runs):
        for args in test_cases:
            for test_func in test_functions:
                start = time.perf_counter()
                assert (
                    test_func(*args[:-1]) == args[-1]
                ), f"{test_func.__name__} failed for value: {text}"
                function_runtimes[test_func.__name__] += (
                    time.perf_counter() - start
                ) * 1000

    print(f"\n{num_runs} runs")
    for function_name, runtime in function_runtimes.items():
        print(f"{function_name}: {runtime:.1f}ms")
