#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

long long solve() {
    int n;
    cin >> n;

    vector<long long> a(n), c(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> c[i];

    // Prefix sum for costs (0-indexed)
    vector<long long> pref_c(n);
    for (int i = 0; i < n; ++i) {
        pref_c[i] = c[i];
        if (i > 0) pref_c[i] += pref_c[i - 1];
    }

    const long long INF = (long long) 4e18;

    // dp[i] = minimum cost to make array non-decreasing up to position i,
    // where position i is KEPT (not changed)
    vector<long long> dp(n, INF);

    // Base case: keep position 0, change nothing before it
    dp[0] = 0;

    // For each position i, try keeping it
    for (int i = 0; i < n; ++i) {
        // Option 1: Keep position i as an anchor
        // We need to find all previous positions j where a[j] <= a[i]
        for (int j = 0; j < i; ++j) {
            if (a[j] <= a[i]) {
                // Keep both j and i, change everything between them
                long long cost_between = (i - 1 >= 0 ? pref_c[i - 1] : 0) - pref_c[j];
                dp[i] = min(dp[i], dp[j] + cost_between);
            }
        }

        // Option 2: This is the first position we keep (change all before it)
        if (i > 0) {
            dp[i] = min(dp[i], pref_c[i - 1]);
        }
        // For i == 0, dp[0] is already 0 (change nothing before it).
    }

    // Find the answer: keep position i as last anchor, change everything after
    long long ans = INF;
    for (int i = 0; i < n; ++i) {
        long long cost_after = pref_c[n - 1] - pref_c[i];
        ans = min(ans, dp[i] + cost_after);
    }

    // Also consider changing everything
    ans = min(ans, pref_c[n - 1]);

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }

    return 0;
}
