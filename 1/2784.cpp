#include <bits/stdc++.h>

using namespace std;

using graph = vector<vector<int>>;

const int INF = numeric_limits<int>::max();

int min_dist(vector<int> &dist, vector<bool> &visited, int n) {
    int aux = INF;
    int idx;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < aux) {
            aux = dist[i];
            idx = i;
        }
    }

    return idx;
}

int func(const graph &g, const int src) {
    int n = (int)g.size();
    vector<int> dist(n, INF);
    vector<bool> visited(n);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++) {
        int u = min_dist(dist, visited, n);
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && g[u][v] && dist[u] != INF &&
                dist[u] + g[u][v] < dist[v]) {
                dist[v] = dist[u] + g[u][v];
            }
        }
    }
    int ma = *max_element(dist.begin(), dist.end());
    dist[src] = INF;
    int mi = *min_element(dist.begin(), dist.end());
    return ma - mi;
}

int main() {
    int n, m, u, v, w, x;
    cin >> n >> m;
    graph g(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        g[u - 1][v - 1] = g[v - 1][u - 1] = w;
    }
    cin >> x;
    cout << func(g, x - 1) << endl;
    return 0;
}
