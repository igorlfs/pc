#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

using ll = long long;

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
        vector<vector<ll>> d(n, vector<ll>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ll x = p[i].first - p[j].first;
                ll y = p[i].second - p[j].second;
                d[i][j] = x * x + y * y;
                d[j][i] = d[i][j];
            }
        }
        int m = 0;
        for (int i = 0; i < n; ++i) {
            map<ll, int> dup;
            for (ll &j : d[i]) {
                ++dup[j];
            }
            for (auto &[o, c] : dup) {
                if (o == 0) continue;
                if (c == 2) {
                    m++;
                } else if (c > 2) {
                    m += (c * (c - 1)) / 2;
                }
            }
        }
        cout << m << endl;
    }
    return 0;
}
