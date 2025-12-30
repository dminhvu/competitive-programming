/*
    Task: CSES 1072
    Date: 30.12.2025
    Time: 19:05:19 CET
    Author: https://www.linkedin.com/in/dminhvu02
*/

#include <algorithm>
#include <climits>
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

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl
#define debug2(x, y) \
    cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#else
#define debug(x)
#define debug2(x, y)
#endif

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

const int INF = INT_MAX;
const int NINF = INT_MIN;
const ll LINF = LLONG_MAX;
const ll NLINF = LLONG_MIN;
const ld EPS = 1e-9;
const int MOD = 998244353;

void setup() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    if (!freopen("input.txt", "r", stdin)) {
        cerr << "Warning: Could not open input.txt" << endl;
    }
    if (!freopen("output.txt", "w", stdout)) {
        cerr << "Warning: Could not open output.txt for writing" << endl;
    }
#endif
}

void solve() {
    /* SOLUTION GOES HERE */
    /* ================== */
    /*
n = 1: 0
n = 2: 6
n = 3:

4 * (n - 3 + 1) * (n - 2 + 1)

x x x
x x x
x x x
36 - 8 = 28


4 * (4 - 3 + 1) * (4 - 2 + 1)
120 - 24 = 96

-> ans = (n*n)C2 - 4 * (n - 3 + 1) * (n - 2 + 1)
    */
    int n;
    cin >> n;

    rep(i, 1, n) {
        if (i == 1) {
            cout << 0 << '\n';
        } else if (i == 2) {
            cout << 6 << '\n';
        } else {
            ll m = i * i;
            cout << (m * (m - 1)) / 2ll - 4ll * (i - 3 + 1) * (i - 2 + 1)
                 << '\n';
        }
    }
}

int main() {
    setup();

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
