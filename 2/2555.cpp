#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

using matrix = vector<vector<double>>;

int N, K;
vector<double> P, C;

double func(matrix &dp, int k, int p) {
    if (p == N) return 0;
    double &ans = dp[p][k];
    if (ans != -1) return ans;
    ans = C[p] * P[p] + C[p] * func(dp, k, p + 1);
    if (k != 0) ans = max(ans, P[p] + func(dp, k - 1, p + 1));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (true) {
        cin >> N >> K;
        if (cin.eof()) break;
        P.resize(N);
        C.resize(N);
        for (int i = 0; i < N; ++i) cin >> P[i];
        for (int i = 0; i < N; ++i) {
            cin >> C[i];
            C[i] *= 0.01;
        }
        matrix dp(N + 1, vector<double>(K + 1, -1));
        cout << fixed << setprecision(2) << func(dp, K, 0) << endl;
    }
    return 0;
}
