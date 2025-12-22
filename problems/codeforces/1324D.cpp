/*
    Task: Codeforces 1324D
    Date: 22.12.2025
    Time: 21:55:03 CET
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
4 8 2 6 2
4 5 4 1 3

a[i] + a[j] > b[i] + b[j]

O(n^2) -> TLE due to n <= 2*10^5
for i = 0..n
    for j = 0..i - 1
        if a[i] + a[j] > b[i] + b[j]
            count += 1

# sample input 1
# idea 1: sort by a[i]
8 6 4 2 2
5 1 4 3 4
2 4 1 5 3

# idea 2: sort by a[i] - b[i]
a[i] - b[i] > b[j] - a[j]
a[i] - b[i] > -(a[j] - b[j])

a[i] - b[i]: 0 3 -2 5 -1
index:       0 1  2 3  4

sorted:
-2 -1 0 3 5
2   4 0 1 3

2 + 2 + 2 + 1

-> index does not matter

# sample input 2
1 3 2 4
1 3 2 4

0 0 0 0
    */

    int n;
    cin >> n;
    vpii a(n + 1);
    rep(i, 1, n) {
        int v;
        cin >> v;
        a[i].first = v;
    }
    rep(i, 1, n) {
        int v;
        cin >> v;
        a[i].second = v;
    }

    sort(a.begin() + 1, a.end(), [](pii a, pii b) {
        return (a.first - a.second) < (b.first - b.second);
    });

    // rep(i, 1, n) { cout << a[i].first << " " << a[i].second << "\n"; }

    ll ans = 0;
    rep(i, 1, n) {
        auto it =
            upper_bound(a.begin() + i + 1, a.end(), -(a[i].first - a[i].second),
                        [](int value, const pii& p) {
                            return value < (p.first - p.second);
                        });

        if (it != a.end()) {
            int j = it - a.begin();
            // cout << i << " " << -(a[i].first - a[i].second) << " " << j <<
            // "\n";
            ans += (n - j + 1);
        }
    }

    cout << ans;
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
