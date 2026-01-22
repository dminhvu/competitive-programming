"""
Segment Tree for Range Max Query (RMQ) and Point Updates
Supports: O(log n) query, O(log n) update, O(n) build

References:
1. https://vnoi.info/wiki/algo/data-structures/segment-tree-extend.md
2. https://cp-algorithms.com/data_structures/segment_tree.html
"""


class SegmentTree:
    """Segment Tree for range maximum queries with point updates."""

    def __init__(self, arr):
        self.n = len(arr)
        self.tree = [0] * (4 * self.n)
        if arr:
            self._build(arr, 0, 0, self.n - 1)

    def _build(self, arr, v, tl, tr):
        """Build tree from array. v=node, tl/tr=range [tl, tr]"""
        if tl == tr:
            self.tree[v] = arr[tl]
        else:
            tm = (tl + tr) >> 1
            self._build(arr, v * 2 + 1, tl, tm)
            self._build(arr, v * 2 + 2, tm + 1, tr)
            self.tree[v] = max(self.tree[v * 2 + 1], self.tree[v * 2 + 2])

    def _query(self, v, tl, tr, l, r):
        """Query max in range [l, r]"""
        if l > r:
            return -float("inf")
        if l == tl and r == tr:
            return self.tree[v]
        tm = (tl + tr) >> 1
        return max(
            self._query(v * 2 + 1, tl, tm, l, min(r, tm)),
            self._query(v * 2 + 2, tm + 1, tr, max(l, tm + 1), r),
        )

    def _update(self, v, tl, tr, pos, val):
        """Update position pos to value val"""
        if tl == tr:
            self.tree[v] = val
        else:
            tm = (tl + tr) >> 1
            if pos <= tm:
                self._update(v * 2 + 1, tl, tm, pos, val)
            else:
                self._update(v * 2 + 2, tm + 1, tr, pos, val)
            self.tree[v] = max(self.tree[v * 2 + 1], self.tree[v * 2 + 2])

    def query(self, l, r):
        """Query maximum in range [l, r] (0-indexed)"""
        return self._query(0, 0, self.n - 1, l, r)

    def update(self, pos, val):
        """Update position pos to value val (0-indexed)"""
        self._update(0, 0, self.n - 1, pos, val)


# ===== Alternative: Compact inline version for contests =====
def seg_tree_compact(arr):
    """Ultra-compact segment tree (copy-paste friendly)"""
    n = len(arr)
    t = [0] * (4 * n)

    def build(v, tl, tr):
        if tl == tr:
            t[v] = arr[tl]
        else:
            tm = (tl + tr) >> 1
            build(v * 2 + 1, tl, tm)
            build(v * 2 + 2, tm + 1, tr)
            t[v] = max(t[v * 2 + 1], t[v * 2 + 2])

    def query(v, tl, tr, l, r):
        if l > r:
            return -float("inf")
        if l == tl and r == tr:
            return t[v]
        tm = (tl + tr) >> 1
        return max(
            query(v * 2 + 1, tl, tm, l, min(r, tm)),
            query(v * 2 + 2, tm + 1, tr, max(l, tm + 1), r),
        )

    def update(v, tl, tr, pos, val):
        if tl == tr:
            t[v] = val
        else:
            tm = (tl + tr) >> 1
            update(v * 2 + 1, tl, tm, pos, val) if pos <= tm else update(
                v * 2 + 2, tm + 1, tr, pos, val
            )
            t[v] = max(t[v * 2 + 1], t[v * 2 + 2])

    build(0, 0, n - 1)
    return lambda l, r: query(0, 0, n - 1, l, r), lambda pos, val: update(
        0, 0, n - 1, pos, val
    )


if __name__ == "__main__":
    # Example usage
    n, q = map(int, input().split())
    arr = list(map(int, input().split()))

    st = SegmentTree(arr)

    for i in range(q):
        query_type = input().split()
        if query_type[0] == "q":  # query
            l, r = int(query_type[1]), int(query_type[2])
            print(f"Max in [{l}, {r}]: {st.query(l, r)}")
        else:  # update
            pos, val = int(query_type[1]), int(query_type[2])
            st.update(pos, val)
            print(f"Updated position {pos} to {val}")
