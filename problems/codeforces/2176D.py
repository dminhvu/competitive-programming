"""
Docstring for problems.codeforces.2176D

Find longest path with a starting unvisited edge, denote edge_count = total edge in the path
-> The number of generalized Fibo paths = edge_count * (edge_count + 1) / 2
"""

import sys
from collections import defaultdict

input = sys.stdin.readline
print = sys.stdout.write

MOD = 998_244_353
output = []

t = int(input())


def solve(n: int, cost: list[int], edges_uv: list[tuple[int, int]]):
    ans = 0

    edges = [(cost[u] + cost[v], u, v) for u, v in edges_uv]
    edges.sort(reverse=True)

    dp = [defaultdict(int) for _ in range(n)]
    # dp[u][x] = number of paths starting from vertex u
    # where next any vertex's value is x
    for cost_uv, u, v in edges:
        cur = dp[v].get(cost_uv, 0)
        cur += 1  # for path (u, v)
        cur %= MOD

        dp[u][cost[v]] = dp[u].get(cost[v], 0) + cur
        dp[u][cost[v]] %= MOD

        ans += cur
        ans %= MOD

    return ans


for _ in range(t):
    edges_uv: list[tuple[int, int]] = []
    cost: list[int] = []

    n, m = map(int, input().split())
    cost = list(map(int, input().split()))
    for __ in range(m):
        u, v = map(int, input().split())
        edges_uv.append((u - 1, v - 1))

    output.append(solve(n, cost, edges_uv))

print("\n".join(map(str, output)))
