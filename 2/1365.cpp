#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

constexpr int INF = 0x3f3f3f3f;

int main() {
    int R, C, K;
    char x;
    while (true) {
        cin >> R >> C >> K;
        if (R == 0 && C == 0 && K == 0) break;
        vector<vector<bool>> t(R, vector<bool>(C));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                cin >> x;
                if (x == '.') t[i][j] = true;
            }
        }
        int ans = INF;
        for (int i = 0; i < R; i++) {
            vector<int> dp(C);
            for (int j = i; j < R; ++j) {
                for (int k = 0; k < C; ++k) dp[k] += (int)(t[j][k]);
                for (int l = 0, sum = 0, r = 0; r < C; ++r) {
                    for (sum += dp[r]; l < r && sum - dp[l] >= K; ++l) sum -= dp[l];
                    if (sum >= K) ans = min(ans, (abs(l - r) + 1) * (abs(i - j) + 1));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
