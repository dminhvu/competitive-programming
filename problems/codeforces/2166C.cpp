/*
    Task: Codeforces 2166C
    Date: 25.12.2025
    Time: 00:55:20 CET
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
a[1] a[2] ... a[n]

merge: a[1], a[2]
cost: max(a[1], a[2])
max(a[1], a[2]) ... a[n]
max(a[1], a[2] ... a[n])

sorty by max(a[i], a[(i + 1) mod n])
    */

    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];

    vi mx(n, 0);
    rep(i, 0, n - 1) mx[i] = max(a[i], a[(i + 1) % n]);
    sort(mx.begin(), mx.end());
    ll ans = 0;
    rep(i, 0, n - 2) ans += mx[i];
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
