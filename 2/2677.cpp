#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

using ii = pair<int, int>;

int main() {
    int x;
    ulong n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        vector<bool> v(2 * n);
        for (ulong i = 0; i < 2 * n; ++i) {
            cin >> x;
            v[i] = x % 2 == 0;
        }
        vector<vector<ii>> dp(2 * n, vector<ii>(2 * n));
        for (ulong i = 0; i < 2 * n; i++) {
            for (ulong j = 0; j < 2 * n - i; j++) {
                if (i == 0) {
                    dp[j][j] = make_pair(v[j], 0);
                } else {
                    int p = int(v[j]) + dp[j + 1][j + i].second;
                    int q = int(v[j + i]) + dp[j][j + i - 1].second;
                    if (p > q) {
                        dp[j][i + j] = make_pair(p, dp[j + 1][j + i].first);
                    } else {
                        dp[j][i + j] = make_pair(q, dp[j][j + i - 1].first);
                    }
                }
            }
        }
        cout << dp[0][2 * n - 1].first << endl;
    }
    return 0;
}
