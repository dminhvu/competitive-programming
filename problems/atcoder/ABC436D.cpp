/*
    Task: AtCoder ABC436D
    Date: 26.12.2025
    Time: 19:15:51 CET
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
        BFS
    */
    int h, w;
    cin >> h >> w;
    int dist[h][w];
    char c[h][w];
    memset(dist, -1, sizeof(dist));
    vector<vpii> pos(26);
    rep(i, 0, h - 1) {
        rep(j, 0, w - 1) {
            cin >> c[i][j];
            pos[c[i][j] - 'a'].pb({i, j});
        }
    }
    queue<pii> q;

    q.push({0, 0});
    dist[0][0] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x - 1 >= 0 && dist[x - 1][y] == -1 && c[x - 1][y] != '#') {
            q.push({x - 1, y});
            dist[x - 1][y] = dist[x][y] + 1;
        }
        if (x + 1 < h && dist[x + 1][y] == -1 && c[x + 1][y] != '#') {
            q.push({x + 1, y});
            dist[x + 1][y] = dist[x][y] + 1;
        }
        if (y - 1 >= 0 && dist[x][y - 1] == -1 && c[x][y - 1] != '#') {
            q.push({x, y - 1});
            dist[x][y - 1] = dist[x][y] + 1;
        }
        if (y + 1 < w && dist[x][y + 1] == -1 && c[x][y + 1] != '#') {
            q.push({x, y + 1});
            dist[x][y + 1] = dist[x][y] + 1;
        }
        if (c[x][y] - 'a' >= 0 && c[x][y] - 'a' <= 26) {
            while (pos[c[x][y] - 'a'].size()) {
                auto [i, j] = pos[c[x][y] - 'a'].back();
                pos[c[x][y] - 'a'].pop_back();
                if (dist[i][j] == -1) {
                    q.push({i, j});
                    dist[i][j] = dist[x][y] + 1;
                }
            }
        }
    }

    cout << dist[h - 1][w - 1] << '\n';
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
