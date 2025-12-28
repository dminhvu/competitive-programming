/*
    Task: LeetCode 1186
    Date: 28.12.2025
    Time: 15:03:06 CET
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

class Solution {
   public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int pref[n], suff[n];
        pref[0] = arr[0];
        suff[n - 1] = arr[n - 1];
        for (int i = 1; i < n; i++) {
            pref[i] = max(arr[i], pref[i - 1] + arr[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            suff[i] = max(arr[i], suff[i + 1] + arr[i]);
        }

        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (i > 0 && i + 1 < n) {
                ans = max(ans, pref[i - 1] + suff[i + 1]);
            }
            ans = max(ans, pref[i]);
            ans = max(ans, suff[i]);
        }

        return ans;
    }
};

void solve() {
    /*
        Solution goes here
    */
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
