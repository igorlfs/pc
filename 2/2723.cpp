#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int n;
vector<int> p;

int func(int l, int r, int q, vector<vector<int>> &dp) {
    int d = abs(l - r);
    if (d > 5) return 0;
    if (q == n) return 1;
    if (dp[d][q] != -1) return dp[d][q];
    dp[d][q] = max(func(l + p[q], r, q + 1, dp), func(l, r + p[q], q + 1, dp));
    return dp[d][q];
}

int main() {
    int t;
    cin >> t;
    while (t-- != 0) {
        cin >> n;
        p.resize(n);
        for (int i = 0; i < n; ++i) cin >> p[i];
        vector<vector<int>> dp(6, vector<int>(n, -1));
        int x = func(0, 0, 0, dp);
        x == 0 ? cout << "Ho Ho Ho!" : cout << "Feliz Natal!";
        cout << endl;
    }
    return 0;
}
