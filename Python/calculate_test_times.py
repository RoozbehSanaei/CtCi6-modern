from collections import defaultdict
import time
import unittest

def calculate_test_times(test_cases, test_functions):
    num_runs = 1000
    function_runtimes = {func.__name__: sum(
        (time.perf_counter() - start) * 1000
        for args in test_cases
        for _ in range(num_runs)
        for start in [time.perf_counter()]
        if func(*args[:-1]) == args[-1]
    ) for func in test_functions}

    print(f"\n{num_runs} runs")
    for function_name, runtime in function_runtimes.items():
        print(f"{function_name}: {runtime:.1f}ms")
