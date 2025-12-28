/*
    Task: Codeforces 2179D
    Date: 23.12.2025
    Time: 16:04:23 CET
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
5
4 15 1 7 9

diff | pref
0       0
11      11
14      25
6       31
2       33
0       33

pref[i - 2] + abs(a[i - 1] - a[i + 1]) + pref[n] - pref[i]
    */

    int n;
    cin >> n;
    vi a(n + 2);
    rep(i, 1, n) cin >> a[i];
    a[0] = a[n + 1] = 0;
    vi pref(n + 2, 0);
    rep(i, 1, n - 1) pref[i] = pref[i - 1] + abs(a[i] - a[i + 1]);
    pref[n] = pref[n - 1];
    int ans = INF;
    rep(i, 1, n) {
        int cost = 0;
        if (i >= 2 && i < n) cost += abs(a[i - 1] - a[i + 1]);
        cost += pref[n] - pref[i];
        if (i >= 2) cost += pref[i - 2];

        ans = min(ans, cost);
    }
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
