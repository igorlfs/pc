#include <bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int n, p;
    while (cin >> n >> p) {
        vector<pair<int, int>> spells(n);
        for (int i = 0; i < n; ++i) {
            cin >> spells[i].first >> spells[i].second;
        }
        vector<vector<int>> dp(n);
        for (int j = 0; j < n; ++j) {
            dp[j].resize(p, INF);
        }
        for (int j = 0; j < spells[0].first; ++j) {
            dp[0][j] = spells[0].second;
        }
        for (int j = 1; j < n; ++j) {
            int mana_atual = spells[j].second;
            int dano_atual = spells[j].first;
            for (int k = 0; k < p; ++k) {
                int min_anterior = dp[j - 1][k];
                int min_atual = INF;
                int buff = k - dano_atual >= 0 ? dp[j - 1][k - dano_atual] : 0;
                if (dano_atual + buff >= k + 1) {
                    min_atual = mana_atual + buff;
                }
                dp[j][k] = min(min_anterior, min_atual);
            }
        }
        dp[n - 1][p - 1] == INF ? cout << -1 : cout << dp[n - 1][p - 1];
        cout << endl;
    }
    return 0;
}
