#include <bits/stdc++.h>

using namespace std;

using graph = vector<vector<int>>;

const int INF = numeric_limits<int>::max();
const int NINF = numeric_limits<int>::min();

int get(vector<int> &weights, vector<bool> &visited, int n, bool inc) {
    int aux = inc ? NINF : INF;
    int idx;

    if (inc) {
        for (int i = 0; i < n; i++) {
            if (!visited[i] && weights[i] > aux) {
                aux = weights[i];
                idx = i;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (!visited[i] && weights[i] < aux) {
                aux = weights[i];
                idx = i;
            }
        }
    }

    return idx;
}

int func(const graph &g, bool inc) {
    int n = (int)g.size();
    vector<bool> visited(n);
    vector<int> parent(n);
    vector<int> weights(n, inc ? NINF : INF);
    weights[0] = inc ? INF : 0;
    parent[0] = -1;
    for (int i = 0; i < n - 1; i++) {
        int u = get(weights, visited, n, inc);
        visited[u] = true;
        for (int v = 0; v < n; v++)
            if (g[u][v] && !visited[v]) {
                if (inc) {
                    if (g[u][v] > weights[v]) {
                        parent[v] = u;
                        weights[v] = g[u][v];
                    }
                } else {
                    if (g[u][v] < weights[v]) {
                        parent[v] = u;
                        weights[v] = g[u][v];
                    }
                }
            }
    }
    int acc = 0;
    for (int i = 1; i < n; ++i) acc += g[i][parent[i]];
    return acc;
}

int main() {
    int n, m = 0, aux;

    cin >> n;
    vector<pair<pair<int, int>, int>> e(n);
    for (int i = 0; i < n; ++i) {
        cin >> e[i].first.first >> e[i].first.second >> e[i].second;
        aux = max(e[i].first.first, e[i].first.second);
        if (aux > m) m = aux;
    }
    graph g(m);
    for (auto &p : g) p.resize(m, 0);
    for (const auto &p : e) {
        g[p.first.first - 1][p.first.second - 1] = p.second;
        g[p.first.second - 1][p.first.first - 1] = p.second;
    }
    cout << func(g, true) << endl;
    cout << func(g, false) << endl;
    return 0;
}
