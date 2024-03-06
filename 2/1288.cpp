#include <bits/stdc++.h>

using namespace std;

const string SUC = "Missao completada com sucesso\n";
const string FAL = "Falha na missao\n";

int main() {
    int num_casos;
    cin >> num_casos;
    for (int i = 0; i < num_casos; ++i) {
        bool sucesso = false;
        int n, K, r;
        cin >> n;
        vector<pair<int, int>> bolas(n);
        for (int j = 0; j < n; ++j) {
            cin >> bolas[j].first >> bolas[j].second;
        }
        cin >> K >> r;
        vector<vector<int>> dp(n + 1);
        dp[0].resize(K + 1, 0);
        for (int j = 1; j <= n; ++j) {
            dp[j].resize(K + 1);
        }
        for (int j = 1; j <= n && !sucesso; ++j) {
            int peso_atual = bolas[j - 1].second;
            for (int k = 1; k <= K && !sucesso; ++k) {
                int max_anterior = dp[j - 1][k];
                int max_atual = 0;
                if (peso_atual <= k) {
                    max_atual += bolas[j - 1].first + dp[j - 1][k - peso_atual];
                }
                dp[j][k] = max(max_anterior, max_atual);
                if (dp[j][k] >= r) sucesso = true;
            }
        }
        sucesso ? cout << SUC : cout << FAL;
    }
    return 0;
}
