/*
    Task: Codeforces 1201C
    Date: 23.12.2025
    Time: 13:01:54 CET
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
5 5
1 2 1 1 1

1 1 1 1 2
mid = 3
i = 5
numCount = 2
need = numCount * (2 - 1) = 2

1 1 2 2 2
i = 6
k = 3
numCount = 3
need = numCount * (inf - 2) = inf
need > k -> need = (k / numCount) * k = 3
k >= need -> k -= 3; a[mid] += 1
    */
    int n;
    ll k;
    cin >> n >> k;
    vll a(n + 2);
    rep(i, 1, n) cin >> a[i];
    a[n + 1] = 2 * INF;
    sort(a.begin() + 1, a.begin() + n + 1);

    int mid = (n + 1) / 2;
    int i = mid;
    while (k > 0) {
        while (i <= n && a[i] == a[mid]) {
            i += 1;
        }

        ll numCount = i - mid;
        // cout << numCount << " " << a[i] << " " << a[mid] << '\n';
        ll need = numCount * (a[i] - a[mid]);
        // cout << need << '\n';
        if (need > k) {
            need = (k / numCount);
            need *= numCount;
        }

        if (k >= need && need > 0) {
            // cout << i << " " << numCount << " " << need << " " << k << '\n';
            k -= need;
            a[mid] += need / numCount;
        } else {
            break;
        }
    }
    // rep(i, 1, n) cout << a[i] << " ";
    cout << a[mid] << '\n';
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
