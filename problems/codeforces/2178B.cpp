/*
    Task: Codeforces 2178B
    Date: 27.12.2025
    Time: 15:19:39 CET
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
    /*
        Solution goes here


    */
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    rep(i, 0, n - 1) {
        if (s[i] == 'u') {
            if (i == 0) {
                s[i] = 's';
                ans += 1;
                continue;
            }
            if (i == n - 1) {
                s[i] = 's';
                ans += 1;
                continue;
            }
            if (i > 0 && s[i - 1] == 'u') {
                s[i - 1] = 's';
                ans += 1;
            }
            if (i + 1 < n && s[i + 1] == 'u') {
                s[i + 1] = 's';
                ans += 1;
            }
            if (i > 0 && i + 1 < n && s[i - 1] != 's' && s[i + 1] != 's') {
                s[i] = 's';
                ans += 1;
            }
        }
        // cout << ans << " ";
        // cout << s << " ";
    }

    cout << ans << '\n';
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
