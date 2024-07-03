#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

constexpr int INF = 0x3f3f3f3f;

int N, L, M, P;
vector<int> C, V;

int func(int t, int l, vector<vector<int>> &dp, vector<vector<int>> &r) {
    if (t == N + 1) return 0;
    if (dp[t][l] != -1) return dp[t][l];

    int a = P + C[0] - V[l - 1] + func(t + 1, 1, dp, r);
    int b = l < M ? C[l] + func(t + 1, l + 1, dp, r) : INF;

    r[t][l] = (a <= b) ? 1 : l + 1;

    return dp[t][l] = min(a, b);
}

int main() {
    while (true) {
        cin >> N >> L >> M >> P;

        if (cin.eof()) break;

        C.resize(M);
        V.resize(M);

        for (int i = 0; i < M; ++i) cin >> C[i];
        for (int i = 0; i < M; ++i) cin >> V[i];

        vector<vector<int>> dp(N + 1, vector<int>(M + 1, -1)), r(N + 1, vector<int>(M + 1, -1));

        cout << func(1, L, dp, r) << endl;

        bool used = false;
        for (int i = 1, j = L; i <= N; j = r[i][j], ++i) {
            if (r[i][j] == 1) {
                if (used) cout << ' ';
                cout << i;
                used = true;
            }
        }
        if (!used) cout << 0;
        cout << endl;
    }
    return 0;
}
