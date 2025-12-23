/*
    Task: Codeforces 2171D
    Date: 23.12.2025
    Time: 14:13:46 CET
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

5
4 3 1 5 2

[(4)]
[(4), (3)]
[(4), (3, 5)]
[(3, 4, 5), (1)]
[(3, 4, 5), (1, 2)]

    */
    int n;
    cin >> n;
    vi a(n), pref_min(n, INF), suff_max(n, -INF);
    rep(i, 0, n - 1) cin >> a[i];
    pref_min[0] = a[0];
    suff_max[n - 1] = a[n - 1];
    rep(i, 1, n - 1) pref_min[i] = min(pref_min[i - 1], a[i]);
    per(i, 0, n - 2) suff_max[i] = max(suff_max[i + 1], a[i]);

    bool yes = true;

    rep(i, 1, n - 1) {
        if (pref_min[i - 1] > suff_max[i]) {
            yes = false;
            break;
        }
    }

    cout << (yes ? "Yes" : "No") << '\n';
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
