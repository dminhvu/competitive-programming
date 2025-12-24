/*
    Task: Codeforces 2164C
    Date: 24.12.2025
    Time: 15:35:11 CET
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


    */

    int n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];

    vpii b(m);
    rep(i, 0, m - 1) cin >> b[i].first;
    rep(i, 0, m - 1) cin >> b[i].second;
    vector<bool> killed(m, false);

    sort(b.begin(), b.end(),
         [](const pii a, const pii b) { return a.first < b.first; });

    // rep(i, 0, m - 1) cout << b[i].first << " " << b[i].second << '\n';

    multiset<int> ms;

    rep(i, 0, n - 1) { ms.insert(a[i]); }

    rep(i, 0, m - 1) {
        if (b[i].second == 0) {
            continue;
        }
        auto it = ms.lower_bound(b[i].first);
        if (it != ms.end()) {
            int val = *it;
            ms.erase(it);
            ms.insert(max(val, b[i].second));
            killed[i] = true;
        }
    }
    rep(i, 0, m - 1) {
        if (killed[i]) {
            continue;
        }
        auto it = ms.lower_bound(b[i].first);
        if (it != ms.end()) {
            ms.erase(it);
            killed[i] = true;
        }
    }

    cout << accumulate(killed.begin(), killed.end(), 0) << '\n';
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
