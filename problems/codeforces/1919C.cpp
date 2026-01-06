/*
    Task: Codeforces 1919C
    Date: 06.01.2026
    Time: 13:54:23 CET
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
#include <unordered_map>
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

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (b); i >= (a); --i)

const int INF = 1e9 + 210903;
const ll LINF = 1e18 + 210903;
const ld EPS = 1e-9;
const ll MOD = 998244353;

template <typename T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

ll binpow(ll a, ll b, ll mod = LINF) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

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
TODO: Reimplement
given an array a[i]

find an optimal split into s and t such that

p(s) + p(t) is minimal
where p(b) = count of positions where b[i] < b[i + 1]

idea 1: try to find the longest decreasing subsequence?
-> O(n^2)

we'll try to split the increasing subsequence into two parts
score = length of LIS - 2
-> WA

idea 2: greedy approach
given two lists s and t
assume that x and y are the last elements of s and t
and x <= y

if a[i] <= x -> insert a[i] to s
if a[i] > y -> insert a[i] to s -> this is to have more chance to have smaller
elements after this a[i]
if x < a[i] <= y -> insert a[i] to t
    */
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n - 1) cin >> a[i];
    int ans = 0;
    int x = INF, y = INF;
    rep(i, 0, n - 1) {
        if (x > y) {
            swap(x, y);
        }

        if (a[i] <= x) {
            x = a[i];
        } else if (a[i] <= y) {
            y = a[i];
        } else {
            ans++;
            x = a[i];
        }
    }

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
