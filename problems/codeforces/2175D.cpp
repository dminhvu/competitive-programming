/*
    Task: Codeforces 2175D
    Date: 24.12.2025
    Time: 21:03:14 CET
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

void setup() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    /* Solution goes here */
    /*

TODO: Incomplete solution, not AC yet

Restate the problem:

Find b[i], such that:
- sum(b) <= k
- b[i] <= a[i]
- maximize: sigma(i=0..n-1) sum(max(b[0]..b[i]))

dp[i][j]: maximum happiness gained at i-th friend, and have j cards left

at i-th friend:
take: j = 0..k
k - j

max[i][k - j] = max(max[i - 1][k], j)
dp[i][k - j] = dp[i - 1][k] + max[i][k - j]

optimal = dp[n][j] -> maximized score at i-th friend and used j gifts
(not 0 here because the friends may not use all k gifts)

6 8
1 2 0 5 1 8
dp:
i:1..6
take:0..8

i=1: a[i]=1
if take 0: mx[1][8] = max(mx[0][8], 0) = 0
dp[1][8] = max(dp[1][8], dp[0][8] + mx[1][8]) = 0
if take 1: mx[1][7] = max(mx[0][8], 1) = 1
dp[1][7] = max(dp[1][7], dp[0][8] + mx[1][7]) = 1

i=2: a[i] = 2
if take 0: mx[2]



---


dp[i][j][l]

l = sum of used cards so far
j = max card used by a friend so far
next friend should benefit if use > j card, call x
dp[i + 1][x][l + x] = dp[i][j][l] + x, for x > j

    */

    int n, k;
    cin >> n >> k;
    vector<int> a;
    set<int> s;
    rep(i, 1, n) {
        int x;
        cin >> x;
        // cout << x << '\n';
        if (s.empty() || s.find(x) == s.end()) {
            a.pb(x);
            s.insert(x);
        }
    }
    n = a.size();
    vector<vector<vi>> dp(n, vector<vi>(k + 1, vi(k + 1, 0)));
    // vector<vi> mx(n, vi(k + 1, 0));
    rep(i, 0, n - 2) {
        rep(j, 0, min(k, a[i])) {
            rep(l, j + 1, k - j) {
                dp[i + 1][l][j + l] = max(dp[i + 1][l][j + l], dp[i][l][j] + l);
            }
            rep(l, 0, j) {
                dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][l] + j);
            }
        }
    }

    int ans = 0;
    rep(i, 0, k) rep(j, 0, k) ans = max(ans, dp[n - 1][i][j]);

    cout << ans << '\n';
}

int main() {
    setup();

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
