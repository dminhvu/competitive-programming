/*
    Task: AtCoder ABC436E
    Date: 26.12.2025
    Time: 21:59:10 CET
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
    A swap can be replaced with another swap if it doesn't change the minimum
    steps needed. Because each number from 1..n appears once in the permutation,
    and its position also appears once
    -> we could build a graph, where swappable pairs will be in the same
    connected component

    */
    int n;
    cin >> n;
    int p[n];
    rep(i, 0, n - 1) {
        cin >> p[i];
        --p[i];
    }

    int component[n];
    memset(component, -1, sizeof(component));
    ll ans = 0;
    int componentCount = 0;

    rep(i, 0, n - 1) {
        if (component[i] != -1) {
            continue;
        }
        componentCount += 1;
        ll verticesCount = 0;
        int cur = i;
        while (true) {
            verticesCount += 1;
            component[cur] = componentCount;
            cur = p[cur];
            if (cur == i) {
                break;
            }
        }

        ans += verticesCount * (verticesCount - 1) / 2;
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
