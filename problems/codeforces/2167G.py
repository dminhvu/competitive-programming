"""
Docstring for problems.codeforces.2167G
Solution is correct but getting TLE. Trying C++ instead.
"""

import sys

input = sys.stdin.readline

INF = float("inf")


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    c = list(map(int, input().split()))

    # Prefix sum for costs (0-indexed)
    pref_c = [0] * n
    for i in range(n):
        pref_c[i] = c[i]
        if i > 0:
            pref_c[i] += pref_c[i - 1]

    # dp[i] = minimum cost to make array non-decreasing up to position i,
    # where position i is KEPT (not changed)
    dp = [INF] * n

    # Base case: keep position 0, change nothing before it
    dp[0] = 0

    # For each position i, try keeping it
    for i in range(n):
        # Option 1: Keep position i as an anchor
        # We need to find all previous positions j where a[j] <= a[i]
        for j in range(i):
            if a[j] <= a[i]:
                # Keep both j and i, change everything between them
                cost_between = pref_c[i - 1] - pref_c[j]
                dp[i] = min(dp[i], dp[j] + cost_between)

        # Option 2: This is the first position we keep (change all before it)
        if i > 0:
            dp[i] = min(dp[i], pref_c[i - 1])

    # Find the answer: keep position i as last anchor, change everything after
    ans = INF
    for i in range(n):
        cost_after = pref_c[n - 1] - pref_c[i]
        ans = min(ans, dp[i] + cost_after)

    # Also consider changing everything
    ans = min(ans, pref_c[n - 1])

    return ans


t = int(input())
output = []
for _ in range(t):
    output.append(solve())

print(*output, sep="\n")
