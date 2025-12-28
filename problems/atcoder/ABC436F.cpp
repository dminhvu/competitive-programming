/*
    Task: AtCoder ABC436F
    Date: 27.12.2025
    Time: 00:13:28 CET
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
TODO: Rethink
Given a permutation a[i]

Count all unique sets produced by tripples of l, r, b
such that: given l, r, b
-> a set is produced as: a[l], a[l + 1], ..., a[r]
if a[i] <= b for l <= i <= r

3 1 4 2
l, r, b = 1, 1, 1
set is empty as a[1] > 1 -> need to increase b
l, r, b = 1, 1, 3
a set is produced: {3}

obs: if b is greater than max of the values in current pair of l, r
-> no new set will be produced
l, r, b = 1, 2, 1

given the max value and min value in a range l, r
how many choices of b will make a different set?
e.g.
l, r = 1, 4
max = 4
min = 1
-> 4 choices of b: 1, 2, 3, 4
l, r = 1, 3
max = 4
min = 1

1
1 2
1 3
1 4
1 2 3
1 2 4
1 3 4
1 2 3 4
2
2 4
3
4

sort by index

3 1 4 2
1 2 3 4
->
1 2 3 4
2 4 1 3

for x:
find y < x such that abs(pos[x] - pos[y]) is minimum

7
1 2 3 4 5 6 7
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
1 2 3 4 5 6
1 2 3 4 5 6 7
2
2 3
2 3 4
2 3 4 5


15 5 13 17 9 11 20 4 14 16 6 3 8 19 12 7 10 18 2 1
1  2  3
20 19

    */
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n - 1) cin >> a[i];
    int b[n];
    rep(i, 0, n - 1) b[--a[i]] = i;
    ll ans = 0;
    // rep(i, 0, n - 1) cout << b[i] << " ";
    rep(i, 0, n - 1) {
        ll val = min(n - a[i], n - b[i]);
        ans += val;
    }

    cout << ans << '\n';
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
