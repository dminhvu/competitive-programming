/*
    Task: Codeforces 2163C
    Date: 25.12.2025
    Time: 16:26:33 CET
    Author: https://www.linkedin.com/in/dminhvu02
*/

#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (b); i >= (a); --i)

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const ld EPS = 1e-9;
const int MOD = 998244353;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    /* Solution goes here */
    /*
TODO: Incomplete solution
1 2 3 4
5 6 7 8

1 <= l <= r <= 8
b[i][j] = 1 if l <= a[i][j] <= r
l, r = 3, 6
b[i][j] = 1 if 3 <= a[i][j] <= 6

if l <= a <= r -> set b to 1

1 2 3 4
5 6 7 8
l = 3, r = 6

b:
0 0 1 1
1 1 0 0

1 3
3 1

l, r = 1, 1
1 0
0 1

l, r = 1, 2
1 0
0 1

l, r = 1, 3
1 1
1 1

l, r = 1, 4
1 1
1 1

so, at the i-th, j-th cell a[i][j]
can only move to next cells:
- a[i + 1][j] if l <= a[i + 1][j] <= r
- a[i][j + 1] if l <= a[i][j + 1] <= r

first, let's simplify by counting ways to reach from 1,1 to 2,n
dp[i + 1][j] += dp[i][j] if l <= a[i + 1][j] <= r else 0
dp[i][j + 1] += dp[i][j] if l <= a[i][j + 1] <= r else 0
dp[0][0] = 1
dp[i][j] = count of ways to reach cell i,j
ans = dp[1][n - 1]
we need dp[1][n - 1] > 0

but, we must count the number of pairs of (l, r)
= 1 if f(l, r) has path to reach 2,n
= 0 if f(l, r) has no path to reach 2,n

1 <= l <= r <= n


obs:
1 <= l <= a[0][0]
a[1][n - 1] <= r <= 2n

---

for each l:1..2n -> find smallest r such that there's a valid path
so, we're finding r[l] (l:1..2n), ans += 2n - r[l] + 1
obs:
if (l, r) is valid, then (l, r + 1) is also valid
-> r[l] <= r[l + 1], or r[1] <= r[2] <= r[3] <= ... <= r[2n]

for each l=1..2n:
    while (no valid path) r++
    ans += 2 * n - r + 1

how to check "valid path" in at most O(logn)?
if we increase l -> all positions of l will be 0
if we increase r -> all positions of r + 1 will be 1
initially: (1, 1) -> all positions of 1 will be 1
we use something to store the positions of a number
pos[num] = [(x[0], y[0]), ...]
when increase l to l + 1: we fill all positions of pos[l] to 0
when increase r to r + 1: we fill all positions of pos[r + 1] to 1
let s0, s1 = set of positions of 0s in row 0, row 1
initially s0 and s1 both contains 0..n-1
a valid path appears when:
- s0 does not contain 0 (the beginning of the path, i.e. at (0, 0))
- s1 does not contain n - 1 (the end of the path, i.e. at (1, n - 1))
- first position in s0 > last position in s1 + 1 (so that there're 1s between
them that make a valid path) i.e. there are 1s from 0 to first position in s0 -
1 there are 1s from last positions in s1 + 1 to n - 1


1 2 3 2
2 3 2 1

(1, 2)
1 1 0 1
1 0 1 1

---

AINOTES:
Optimizing tool selection...Looking at this problem carefully, let me analyze
your solution and extract the key lessons.

## Problem Understanding

**Codeforces 2163C - Monopati**: Given a 2×n grid with values 1 to 2n, count
pairs (l, r) where the binary grid f(l,r) (cells = 1 if value in [l,r]) has a
valid down-right path from (1,1) to (2,n).

## Your Solution Analysis

Your approach is elegant and correct:

1. **Two-pointer with monotonicity**: If (l, r) is valid, then (l, r+1) is also
valid. This means for each l, we find the minimum r, and r is non-decreasing as
l increases.

2. **Tracking blocked positions**: Instead of tracking 1s, you track 0s (blocked
cells) in sets `s[0]` and `s[1]` for each row.

3. **Path validity check in O(1)**: A valid path exists when:
   - `s[0]` doesn't contain 0 (start cell must be 1)
   - `s[1]` doesn't contain n-1 (end cell must be 1)
   - `*s[0].begin() > *s[1].rbegin() + 1` (first blocked in row 0 comes after
last blocked in row 1 + 1)

The third condition is the clever insight: in a 2×n grid, you can reach from
top-left to bottom-right if there's a "gap" where you can descend — i.e., all 1s
from column 0 to some column k in row 0, and all 1s from column k to n-1 in
row 1.

---

## 📚 Learnable Lessons

### 1. **Two-Pointer on "Range Queries" with Monotonicity**
```
Pattern: For each L, find minimum R where condition holds
If valid(L, R) → valid(L, R+1), then R[L] ≤ R[L+1]
→ Use two pointers: O(n) instead of O(n²)
```
This pattern appears frequently when counting valid (l, r) pairs.

### 2. **Track the Complement (Obstacles vs Path)**
Instead of tracking which cells are passable, you tracked **blocked positions**.
This made updates simple:
- Increase r → remove positions of value r from blocked set
- Increase l → add positions of value l-1 to blocked set

### 3. **2×n Grid Path Condition (Reusable Pattern)**
For a 2-row grid with only right/down moves, a valid path from (0,0) to (1,n-1)
exists iff:
```
first_blocked_row0 > last_blocked_row1 + 1
```
This is because you need a "staircase" — go right in row 0, drop down at some
column k, then go right in row 1. The condition ensures there exists such a
column k where both rows are unblocked.

### 4. **Sentinel Values in Sets**
You used `s[0].insert(INF)` and `s[1].insert(-INF)` to avoid edge cases when
sets become empty. This is a clean trick to ensure `begin()` and `rbegin()`
always work safely.

### 5. **Value-Position Mapping for Range Updates**
Pre-computing `pos[value] = list of (row, col)` allows O(1) lookup when toggling
cells as l/r changes.

---

## 🔑 Summary Pattern Card

| Aspect | Technique |
|--------|-----------|
| **Problem Type** | Count valid (l, r) pairs |
| **Key Observation** | Monotonicity: valid(l,r) → valid(l,r+1) |
| **Algorithm** | Two-pointer O(n) |
| **Data Structure** | Sets to track blocked positions |
| **Path Condition** | 2×n grid: `first_block_row0 > last_block_row1 + 1` |
| **Complexity** | O(n log n) per test case |

This is a great example of combining **two-pointer technique** with **smart
state tracking** to transform an O(n²) brute force into an efficient O(n log n)
solution.
    */

    int n;
    cin >> n;
    vector<vi> a(2, vi(n));
    rep(i, 0, n - 1) cin >> a[0][i];
    rep(i, 0, n - 1) cin >> a[1][i];
    vector<vpii> pos(2 * n + 1);
    rep(i, 0, n - 1) {
        pos[a[0][i]].pb({0, i});
        pos[a[1][i]].pb({1, i});
    }

    ll ans = 0;

    // s = set contains positions of 0s
    // s[0] = on row 0, s[1] = on row 1
    vector<set<int>> s(2, set<int>());
    s[0].insert(INF);
    s[1].insert(-INF);
    rep(i, 0, n - 1) {
        s[0].insert(i);
        s[1].insert(i);
    }

    auto hasValidPath = [&]() {
        if (s[0].find(0) == s[0].end() && *s[0].begin() > *s[1].rbegin() + 1 &&
            s[1].find(n - 1) == s[1].end()) {
            return true;
        }

        return false;
    };
    int r = 0;
    rep(l, 1, 2 * n) {
        while (r + 1 <= 2 * n && !hasValidPath()) {
            r++;
            for (auto [x, y] : pos[r]) {
                s[x].erase(y);
            }
        }

        // if after increasing r to 2 * n but still cannot find a valid path ->
        // there's no valid path anymore
        if (!hasValidPath()) {
            break;
        }

        ans += 2 * n - r + 1;
        for (auto [x, y] : pos[l]) {
            s[x].insert(y);
        }
    }
    cout << ans << '\n';
}

int main() {
    fastIO();

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
