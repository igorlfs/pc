#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m = 0;
    cin >> n;
    vector<pair<int, int>> u(n);
    for (int i = 0; i < n; ++i) cin >> u[i].first >> u[i].second;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (u[i].first == u[j].second) {
                m++;
            }
        }
    }

    cout << m;

    return 0;
}
