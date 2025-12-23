/*
    Task: Codeforces 1195C
    Date: 23.12.2025
    Time: 11:43:34 CET
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
dp[i][j] = maximum score if keep i-th member of row j (i = 1..n, j = 0..1)
if keep a[i][j]: cannot be consecutive -> cannot keep a[i - 1][j]
previous states could be:
- a[i - 1][1 - j] (kept the member of the other row)
- a[i - 2][j] (ignored the previous member of the same row)
    */
    int n;
    cin >> n;

    vector<vll> dp(n + 1, vll(2, -INF));
    dp[0][0] = dp[0][1] = 0;
    vpii a(n + 1);
    rep(i, 1, n) cin >> a[i].first;
    rep(i, 1, n) cin >> a[i].second;

    ll ans = 0;
    rep(i, 1, n) {
        dp[i][0] = max(dp[i][0], dp[i - 1][1] + a[i].first);
        dp[i][1] = max(dp[i][1], dp[i - 1][0] + a[i].second);
        if (i >= 2) {
            dp[i][0] = max(dp[i][0], dp[i - 2][1] + a[i].first);
            dp[i][1] = max(dp[i][1], dp[i - 2][0] + a[i].second);
        }

        rep(j, 0, 1) { ans = max(ans, dp[i][j]); }
    }

    cout << ans << '\n';
}

int main() {
    fastIO();

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
