/*
    Task: Codeforces 2175B
    Date: 24.12.2025
    Time: 18:35:40 CET
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
f(x, y) = a[x] ^ ... ^ a[y]

f(1, 3) = a[1] ^ a[2] ^ a[3]

f(l, r) = 0 -> a[l] ^ ... ^ a[r] = 0

1 ^ 1 = 0
1 ^ 2 ^ 3 = 0
1 ^ 2 ^ 1 ^ 2  = 0
1 ^ 2 ^ 1 ^ 4 ^ 6 = 0
1 ^ 2 ^ 1 ^ 4 ^ 1 ^ 7 = 0
1 ^ 2 ^ 1 ^ 4 ^ 1 ^ 2 ^ 5 = 0
3 ^ 4 ^ 5 ^ 6 ^ 4  = 0
3 ^ 4 ^ 5 ^ 6 ^ 3 = 0
3 ^ 4 ^ 5 ^ 6 ^ 0 ^ 4 ^ 4 = 0


// NOTE: knowledge required is prefix XOR
so, pref[i] = a[0] ^ ... ^ a[i]
we want a[l] ^ ... ^ a[r] = 0 -> pref[r] ^ pref[l - 1] = 0
-> assign pref[i] = i -> pref[l - 1] = l - 1
assign pref[r] = l - 1 so that pref[r] ^ pref[l - 1] = (l - 1) ^ (l - 1) = 0
we can retrieve the original a[i], by: a[i] = pref[i] ^ pref[i - 1]
    */

    int n, l, r;
    cin >> n >> l >> r;
    vi pref(n + 1);
    rep(i, 1, n) { pref[i] = i; }
    pref[r] = l - 1;
    vi a(n + 1);
    a[1] = pref[1];
    rep(i, 2, n) { a[i] = pref[i] ^ pref[i - 1]; }
    rep(i, 1, n) cout << a[i] << " ";
    cout << '\n';
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
