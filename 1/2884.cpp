#include <bits/stdc++.h>

using namespace std;

using graph = vector<vector<bool>>;

int main() {
    int n, m, l, x, k, y;
    cin >> n >> m;
    cin >> l;
    vector<bool> lamp(m);
    for (int j = 0; j < l; ++j) {
        cin >> x;
        lamp[x - 1] = true;
    }
    graph g(n, vector<bool>(m));
    for (int i = 0; i < n; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> y;
            g[i][y - 1] = true;
        }
    }
    auto pred = [](const auto &v) { return v; };
    set<pair<vector<bool>, int>> s;
    int acc = 0;
    bool any_on = any_of(lamp.begin(), lamp.end(), pred);
    while (any_on) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j]) lamp[j] = !lamp[j];
            }
            any_on = any_of(lamp.begin(), lamp.end(), pred);
            if (s.contains(make_pair(lamp, i))) {
                acc = -1;
                any_on = false;
                break;
            }
            s.insert(make_pair(lamp, i));
            acc++;
            if (!any_on) break;
        }
    }
    cout << acc << endl;
    return 0;
}
