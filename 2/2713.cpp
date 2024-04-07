#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

constexpr double INF = numeric_limits<double>::max();

int n, v;
vector<int> x, d;

double func(int k, int p, vector<vector<double>> &dp) {
    if (p == n) return 0.;
    if (dp[k][p] != INF) return dp[k][p];
    if (k != 0) dp[k][p] = (double)x[p] / (v + d[p]) + func(k - 1, p + 1, dp);
    dp[k][p] = min(dp[k][p], (double)x[p] / v + func(k, p + 1, dp));
    return dp[k][p];
}

int main() {
    int k;
    while (true) {
        cin >> n >> k >> v;
        if (cin.eof()) break;
        x.resize(n);
        d.resize(n);
        for (int i = 0; i < n; ++i) cin >> x[i] >> d[i];
        vector<vector<double>> dp(k + 1, vector<double>(n + 1, INF));
        cout << fixed << showpoint << setprecision(4) << func(k, 0, dp) << endl;
    }
    return 0;
}
