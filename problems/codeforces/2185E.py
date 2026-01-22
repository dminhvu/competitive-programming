# Task: Codeforces 2185E
# Date: 22.01.2026
# Time: 18:15:28 CET
# Author: https://www.linkedin.com/in/dminhvu02

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
MOD = 998244353

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
        print(f"[{names}]:", *args, file=sys.stderr)


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
    n, m, k = read_ints()
    a = read_list()
    b = read_list()
    s = read_str()

    mp = {}
    c = [0] * (k + 1)
    cur = 0
    for i, char in enumerate(s):
        cur += -1 if char == "L" else 1
        debug(cur)
        if cur not in mp:
            mp[cur] = i + 1

    b.sort()
    for x in a:
        right = bisect.bisect_right(b, x)
        debug(s, right)
        minToDie = INF

        if right < m:
            rightToDie = b[right] - x
            if rightToDie in mp:
                minToDie = min(minToDie, mp[rightToDie])

        if right > 0:
            left = right - 1
            leftToDie = b[left] - x
            if leftToDie in mp:
                minToDie = min(minToDie, mp[leftToDie])

        if minToDie <= k:
            c[minToDie] += 1

    for i in range(1, k + 1):
        c[i] += c[i - 1]

    for i in range(1, k + 1):
        print(n - c[i], end=" ")
    print()


def main():
    t = 1
    t = read_int()

    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
