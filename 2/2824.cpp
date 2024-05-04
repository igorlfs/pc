#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int lcs(string &s, string &t, uint m, uint n, vector<vector<int>> &dp) {
    if (dp[m][n] != -1) return dp[m][n];
    if (m == 0 || n == 0) return 0;
    if (s[m - 1] == t[n - 1]) return dp[m][n] = 1 + lcs(s, t, m - 1, n - 1, dp);
    return dp[m][n] = max(lcs(s, t, m, n - 1, dp), lcs(s, t, m - 1, n, dp));
}

int main() {
    string s, t;
    cin >> s >> t;

    uint m = s.length();
    uint n = t.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    cout << lcs(s, t, m, n, dp) << endl;

    return 0;
}
