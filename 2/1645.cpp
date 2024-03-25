#include <bits/stdc++.h>

#define endl '\n'

using ll = long long;

int n, k;

using namespace std;

ll func(vector<vector<ll>> &dp, vector<int> x, int u, int v) {
    if (v == k) return 1;
    if (dp[u][v] != -1) return dp[u][v];
    dp[u][v] = 0;
    for (int i = u + 1; i < n; ++i) {
        if (x[u] < x[i]) dp[u][v] += func(dp, x, i, v + 1);
    }
    return dp[u][v];
}

int main() {
    while (true) {
        cin >> n >> k;
        if (n == 0 && k == 0) break;
        vector<int> x(n);
        vector<vector<ll>> dp(n, vector<ll>(k, -1));
        for (int i = 0; i < n; ++i) cin >> x[i];

        ll s = 0;
        for (int i = 0; i < n; ++i) s += func(dp, x, i, 1);
        cout << s << endl;
    }

    return 0;
}
