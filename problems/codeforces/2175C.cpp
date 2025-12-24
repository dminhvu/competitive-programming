/*
    Task: Codeforces 2175C
    Date: 24.12.2025
    Time: 20:45:41 CET
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
    string s, t;
    cin >> s >> t;
    vi need(26, 0), have(26, 0);
    int n = s.size();
    int m = t.size();
    rep(i, 0, n - 1) { need[s[i] - 'a'] += 1; }
    rep(i, 0, m - 1) { have[t[i] - 'a'] += 1; }
    int j = 0;
    string ans = "";
    bool yes = true;
    rep(i, 0, n - 1) {
        while (j < int(s[i] - 'a')) {
            if (have[j] >= need[j]) {
                int addCount = have[j] - need[j];
                have[j] -= addCount;
                while (addCount > 0) {
                    ans += char(j + 'a');
                    --addCount;
                }
            }
            j += 1;
        }
        if (have[s[i] - 'a'] >= need[s[i] - 'a'] && have[s[i] - 'a'] > 0) {
            ans += s[i];
            have[s[i] - 'a']--;
            need[s[i] - 'a']--;
        } else {
            yes = false;
            break;
        }
        // cout << ans << '\n';
    }

    rep(i, 0, 25) {
        rep(k, 1, have[i]) { ans += char(i + 'a'); }
    }

    cout << (yes ? ans : "Impossible") << '\n';
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
