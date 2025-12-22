"""
The solution below is partially corrected (60%).

# n: nodes
# n - 1 edges & any u, v is accessible -> tree structure
# k queries: each query contains u, v
# find maximum value among the path from u -> v
# i-th query can do if current vertex = ku[i]


4
1 2 3 4
1 2
2 3
3 4
4
1 3
1 2
2 3
2 4


1 -> 2
dp[2] = max_weight[1] + max_path_weight(1, 2)

2 -> 3
dp[3] = max_weight[2] + max_path_weight(2, 3)

2 -> 4
dp[4] = max_weight[2] + max_path_weight(2, 4)

"""


def solve():
    n: int
    weight: list[int] = []
    max_weight: list[int] = []
    graph: dict[int, list[int]] = {}
    queries: list[tuple[int, int]] = []
    with open("SHIP.inp", "r") as f:
        n = int(f.readline())
        weight = list(map(int, f.readline().split()))
        max_weight = [-1] * n
        max_weight[0] = 0

        for _ in range(n - 1):
            u, v = map(int, f.readline().split())
            u -= 1
            v -= 1

            if u in graph:
                graph[u].append(v)
            else:
                graph[u] = [v]

            if v in graph:
                graph[v].append(u)
            else:
                graph[v] = [u]

        k = int(f.readline())
        for _ in range(k):
            u, v = map(int, f.readline().split())
            u -= 1
            v -= 1
            queries.append((u, v))

    def max_path_weight(u: int, v: int) -> int:
        max_weight = max(weight[u], weight[v])

        queue = [u]
        visited = set([u])
        prev = [-1] * n
        while len(queue) > 0:
            cur = queue.pop(0)
            if cur == v:
                tmp_cur = cur
                while tmp_cur != u:
                    max_weight = max(max_weight, weight[tmp_cur])
                    tmp_cur = prev[tmp_cur]
                break

            for nxt in graph[cur]:
                if nxt in visited:
                    continue
                queue.append(nxt)
                visited.add(nxt)
                prev[nxt] = cur

        # print(u + 1, v + 1, max_weight)
        return max_weight

    for u, v in queries:
        if max_weight[u] == -1:
            continue

        max_weight[v] = max(max_weight[v], max_weight[u] + max_path_weight(u, v))
        # print(v + 1, max_weight[v])

    ans = max(max_weight)
    with open("SHIP.out", "w") as f:
        f.write(str(ans))


solve()
