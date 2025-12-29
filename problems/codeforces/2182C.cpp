/*
    Task: Codeforces 2182C
    Date: 29.12.2025
    Time: 15:06:19 CET
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

Given three arrays: a[i], b[j], c[k];


Find combinations of (i, j, k) such that:
a[i] < b[j] < c[k]
a[i + 1] < b[j + 1] < c[k + 1]
and so on
upto a[i + n - 1] < b[j + n - 1] < c[k + n - 1]

n <= 5000 -> Max can be O(n^2)

Given a[i]
-> check if all b[j] > a[i]

answer: combinations of (i, j) * (j, k)

count combination of (i, j):
a[0]<b[0], a[1]<b[1],...
a[0]<b[1], a[1]<b[2],...
a[0]<b[2]


for i: 0..n-1
    check if (i, j) is valid:
    for j:i..i+n-1:
        if all a[i] < b[j]: valid = true

        cnt += 1

    */

    int n;
    cin >> n;
    int a[n], b[n], c[n];

    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) cin >> b[i];
    rep(i, 0, n - 1) cin >> c[i];

    ll cnt1 = 0;
    rep(i, 0, n - 1) {
        bool valid = true;
        rep(j, 0, n - 1) {
            // debug2((i + j) % n, j % n);
            if (b[j % n] <= a[(i + j) % n]) {
                valid = false;
                break;
            }
        }
        cnt1 += 1ll * n * (valid == true);
    }

    ll cnt2 = 0;
    rep(i, 0, n - 1) {
        bool valid = true;
        rep(j, 0, n - 1) {
            if (c[j % n] <= b[(i + j) % n]) {
                valid = false;
                break;
            }
        }
        cnt2 += (valid == true);
    }

    cout << cnt1 * cnt2 << '\n';
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
