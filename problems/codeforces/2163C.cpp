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
    */

    int n;
    cin >> n;
    vector<vi> a(2, vi(n));
    rep(i, 0, n - 1) cin >> a[0][i];
    rep(i, 0, n - 1) cin >> a[1][i];

    int l = 1, r = a[0][0];
    int min_possible = 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        vector<vector<bool>> dp(2, vector<bool>(n, false));
        dp[0][0] = true;
        rep(i, 0, 1) {
            rep(j, 0, n - 1) {
                if (a[i][j] < mid) {
                    continue;
                }
                if (i > 0) {
                    dp[i][j] = dp[i][j] | dp[i - 1][j];
                }
                if (j > 0) {
                    dp[i][j] = dp[i][j] | dp[i][j - 1];
                }
            }
        }

        if (dp[1][n - 1]) {
            l = mid + 1;
            min_possible = mid;
        } else {
            r = mid - 1;
        }
    }

    l = max(min_possible, a[1][n - 1]), r = 2 * n;
    int max_possible = 2 * n;
    while (l <= r) {
        int mid = (l + r) / 2;
        vector<vector<bool>> dp(2, vector<bool>(n, false));
        dp[0][0] = true;
        rep(i, 0, 1) {
            rep(j, 0, n - 1) {
                if (a[i][j] > mid) {
                    continue;
                }
                if (i > 0) {
                    dp[i][j] = dp[i][j] | dp[i - 1][j];
                }
                if (j > 0) {
                    dp[i][j] = dp[i][j] | dp[i][j - 1];
                }
            }
        }
        if (dp[1][n - 1]) {
            r = mid - 1;
            max_possible = mid;
        } else {
            l = mid + 1;
        }
    }
    // cout << r << '\n';
    min_possible = min(min_possible, max_possible);
    cout << (min_possible * (2 * n - max_possible + 1)) << '\n';
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
