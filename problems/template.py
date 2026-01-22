import sys
import os
import bisect  # noqa: F401
from collections import defaultdict, deque, Counter  # noqa: F401
from heapq import heappush, heappop, heapify  # noqa: F401
from math import gcd, lcm, inf, ceil, floor, sqrt  # noqa: F401
from functools import lru_cache  # noqa: F401


# Constants
INF = int(1e9 + 210903)
LINF = int(1e18 + 210903)
MOD = 998_244_353

# Debug mode (set LOCAL=1 environment variable)
LOCAL = os.getenv("LOCAL") is not None

# File I/O setup (must be before input redirection)
if LOCAL:
    sys.stdin = open("input.txt", "r")
    sys.stdout = open("output.txt", "w")

# Fast I/O
input = sys.stdin.readline


def debug(*args):
    """Print variable names and values for debugging (LOCAL mode only)"""
    if LOCAL:
        import inspect

        frame = inspect.currentframe().f_back
        line = inspect.getframeinfo(frame).code_context[0].strip()
        # Extract what's inside debug(...)
        start = line.find("debug(") + 6
        end = line.rfind(")")
        names = line[start:end]
        print(f"DEBUG [{names}]:", *args, file=sys.stderr)


def binpow(a, b, mod=MOD):
    """Binary exponentiation: a^b % mod"""
    res = 1
    a %= mod
    while b > 0:
        if b & 1:
            res = res * a % mod
        a = a * a % mod
        b >>= 1
    return res


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


def read_list():
    return list(map(int, input().split()))


def read_str():
    return input().strip()


def read_strs():
    return input().split()


def solve():
    """SOLUTION GOES HERE
    *****
    THOUGHT PROCESS
    ----

    *****
    """


def main():
    t = 1
    t = read_int()

    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
