#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

using graph = vector<vector<int>>;

constexpr int INF = 0x3f3f3f3f;

bool bfs(graph &rg, uint s, uint t, vector<uint> &p) {
    uint n = rg.size();
    vector<bool> vis(n);
    queue<uint> q;
    q.push(s);
    vis[s] = true;
    p[s] = -1;
    while (not q.empty()) {
        uint u = q.front();
        q.pop();
        for (uint v = 0; v < n; v++) {
            if (not vis[v] and rg[u][v] > 0) {
                if (v == t) {
                    p[v] = u;
                    return true;
                }
                q.push(v);
                p[v] = u;
                vis[v] = true;
            }
        }
    }
    return false;
}

int edmond_karp(graph &g, uint s, uint t) {
    graph rg = g;
    vector<uint> p(g.size());
    int ans = 0;
    while (bfs(rg, s, t, p)) {
        int f = INF;
        for (uint v = t; v != s; v = p[v]) {
            uint u = p[v];
            f = min(f, rg[u][v]);
        }
        for (uint v = t; v != s; v = p[v]) {
            uint u = p[v];
            rg[u][v] -= f;
            rg[v][u] += f;
        }
        ans += f;
    }
    return ans;
}

int main() {
    int n, m, k, u, v, j = 1;
    while (true) {
        cin >> n >> m >> k;
        if (cin.eof()) break;

        graph g(n + m + 2, vector<int>(n + m + 2));

        // Each horse has a "capacity" linked to S
        for (int i = 1; i <= n; ++i) cin >> g[0][i];

        // Link cops to T
        for (int i = 1; i <= m; ++i) {
            g[n + i][n + m + 1] = 1;
        }

        for (int i = 0; i < k; ++i) {
            cin >> u >> v;
            g[u][n + v] = 1;
        }

        int ans = edmond_karp(g, 0, n + m + 1);
        cout << "Instancia " << j << endl;
        cout << ans << endl;
        cout << endl;
        j++;
    }
    return 0;
}
