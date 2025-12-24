/*
    Task: Codeforces 2157C
    Date: 24.12.2025
    Time: 16:25:51 CET
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
6 2 2
1 1 3
2 2 6

op 1: in the range, there must be values from k to inf
op 2: in the range, there must be values from 0 up to k - 1 and k + 1 to inf

2 2 2 0 0 0
2 2 2 2 0 0

op 2: if a[i] == k: a[i] += 1
else if a[i] == -1 (unassiged) -> set all unassigned a[i] to 0 -> k - 1
-> how to know which position to assign which value?


4 2 4
2 1 2
2 2 3
2 3 4
2 1 3
0 1 0 1
---

4 2 5
2 1 5
2 1 2
2 2 3
2 3 4
2 4 5

iterations:
0 1 -1 -1 -1
0 1 0 -1 -1
0 1 0 1 -1
0 1 0 0 1 -> does not satisfy

    */
    int n, k, q;
    cin >> n >> k >> q;
    vector<tuple<int, int, int>> v(q);
    vi a(n, -1);
    rep(i, 0, q - 1) {
        int c, l, r;
        cin >> c >> l >> r;
        v[i] = {c, l, r};
    }

    sort(v.begin(), v.end());

    for (auto q : v) {
        int c = get<0>(q);
        int l = get<1>(q);
        int r = get<2>(q);

        --l, --r;

        if (c == 1) {
            rep(i, l, r) a[i] = k;
        } else {
            rep(i, l, r) {
                if (a[i] == -1) {
                    a[i] = (i + 1) % k;
                } else if (a[i] == k) {
                    a[i] += 1;
                }
            }
        }
    }

    rep(i, 0, n - 1) {
        if (a[i] == -1) {
            a[i] = 0;
        }
    }

    for (int v : a) cout << v << " ";
    cout << '\n';
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
